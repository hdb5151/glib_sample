#include "glib_hook.h"

typedef struct my_data_tag {
    int id;
    char *name;
} my_data_t;

int main(int argc, char **argv) {
    /**
     * @brief Construct a new test glib ghook insert object
     *
     *      hook节点插入-头插及尾插
     *
     */
    test_glib_ghook_insert(); //演示将一个hook节点插入到hook链表中

    /**
     * @brief Construct a new test glib ghook exec object
     *
     * hook函数的重要功能就是使用对应的数据处理函数处理数据，g_hook_list_invoke和g_hook_list_marshal都可以对数据进行处理，
     * 链表内的所有节点都会被执行到。invoke函数和marshal函数的区别是，invoke在处理数据时使用的是hook节点添加时指定的处理函数，
     * marshal在处理数据时，使用的是新的数据处理函数，此时将忽略默认数据处理函数。invoke的数据处理函数可以不同，但marshal的数据处理函数只有一个，
     * 即调用marshal函数时指定的数据处理函数，对每个hook节点的数据处理，都使用此函数。
     */
    test_glib_ghook_exec(); // 数据处理函数的执行

    /**
     * @brief Construct a new test glib ghook exec part object
     *
     *g_hook_list_invoke_check 和g_hook_list_marshal_check 可实现对指定特征的数据进行处理，其实现方式为，当数据处理函数返回FALSE时，
     *该数据不被处理，当数据处理函数返回TRUE时，才处理该数据。本程序演示g_hook_list_marshal_check处理部分数据的效果，当数据为偶数时，
     *跳过不处理，当数据为奇数时，才进行乘10的处理
     */
    //     test_glib_ghook_exec_part(); // 只处理部分数据

    return 0;
}

static void hook_func(gpointer data) {
    my_data_t *d = (my_data_t *)data;
    g_print("(hook_func)data->id:%d, data->name:%s \n", d->id, d->name);
}

static void hook_destroy(gpointer data) {
    my_data_t *d = (my_data_t *)data;
    if (NULL != d) {
        if (NULL != d->name) {
            g_print("(hook_destroy) %s \n", d->name);
            g_free(d->name);
        }
        g_free(d);
    }
}

static void test_glib_ghook_insert(void) {
    GHookList *hl;
    GHook *hook1, *hook2;
    my_data_t *d1, *d2;

    d1 = g_new(my_data_t, 1);
    d1->id = 100;
    d1->name = g_strdup_printf("name-%d", d1->id);

    d2 = g_new(my_data_t, 1);
    d2->id = 200;
    d2->name = g_strdup_printf("name-%d", d2->id);

    hl = g_new(GHookList, 1);
    g_hook_list_init(hl, sizeof(GHook));

    hook1 = g_hook_alloc(hl);
    hook1->data = d1;
    hook1->func = hook_func;
    hook1->flags = G_HOOK_FLAG_ACTIVE;
    hook1->destroy = hook_destroy;
    g_hook_append(hl, hook1);

    hook2 = g_hook_alloc(hl);
    hook2->data = d2;
    hook2->func = hook_func;
    hook2->flags = G_HOOK_FLAG_ACTIVE;
    hook2->destroy = hook_destroy;
    g_hook_prepend(hl, hook2);

    g_hook_list_clear(hl);
    g_free(hl);
}

static void hook_marshaller_func(GHook *hook, gpointer marshal_data) {
    my_data_t *d = (my_data_t *)hook->data;
    d->id = d->id * GPOINTER_TO_INT(marshal_data);
}

static void hook1_func(gpointer data) {
    my_data_t *d = (my_data_t *)data;
    g_print("(hook1)data->id:%d, data->name:%s \n", d->id, d->name);
    d->id = d->id * 10;
    g_free(d->name);
    d->name = g_strdup_printf("new-name-%d", d->id);
}

static void hook1_destroy(gpointer data) {
    my_data_t *d = (my_data_t *)data;
    if (NULL != d) {
        if (NULL != d->name) {
            g_free(d->name);
        }
        g_free(d);
    }
}

static void hook2_func(gpointer data) {
    my_data_t *d = (my_data_t *)data;
    g_print("(hook2)data->id:%d, data->name:%s \n", d->id, d->name);
}

static void hook2_destroy(gpointer data) {
    my_data_t *d = (my_data_t *)data;
    if (NULL != d) {
        if (NULL != d->name) {
            g_free(d->name);
        }
        g_free(d);
    }
}

static void test_glib_ghook_exec(void) {
    GHookList *hl;
    GHook *hook1, *hook2;
    my_data_t *d1, *d2;

    d1 = g_new(my_data_t, 1);
    d1->id = 100;
    d1->name = g_strdup_printf("name-%d", d1->id);

    d2 = g_new(my_data_t, 1);
    d2->id = 200;
    d2->name = g_strdup_printf("name-%d", d2->id);

    hl = g_new(GHookList, 1);
    g_hook_list_init(hl, sizeof(GHook));

    hook1 = g_hook_alloc(hl);
    hook1->data = d1;
    hook1->func = hook1_func;
    hook1->flags = G_HOOK_FLAG_ACTIVE;
    hook1->destroy = hook1_destroy;
    g_hook_append(hl, hook1);

    hook2 = g_hook_alloc(hl);
    hook2->data = d2;
    hook2->func = hook2_func;
    hook2->flags = G_HOOK_FLAG_ACTIVE;
    hook2->destroy = hook2_destroy;
    g_hook_prepend(hl, hook2);

    g_hook_list_invoke(hl, TRUE);

    g_print("after invoke: data1->id:%d, data1->name:%s \n",
            ((my_data_t *)(hook1->data))->id, ((my_data_t *)(hook1->data))->name);
    g_print("after invoke: data2->id:%d, data2->name:%s \n",
            ((my_data_t *)(hook2->data))->id, ((my_data_t *)(hook2->data))->name);

    g_hook_list_marshal(hl, TRUE, hook_marshaller_func, GINT_TO_POINTER(3));

    g_print("after marshal: data1->id:%d, data1->name:%s \n",
            ((my_data_t *)(hook1->data))->id, ((my_data_t *)(hook1->data))->name);
    g_print("after marshal: data2->id:%d, data2->name:%s \n",
            ((my_data_t *)(hook2->data))->id, ((my_data_t *)(hook2->data))->name);

    g_hook_list_clear(hl);
    g_free(hl);
}
/*--------------------------------*/
gboolean hook_marshal_func(GHook *hook, gpointer marshal_data) {
    my_data_t *d = (my_data_t *)hook->data;
    if ((d->id / 10) % 2) {
        return FALSE;
    }

    return TRUE;
}

static void hook3_func(gpointer data) {
    my_data_t *d = (my_data_t *)data;
    g_print("(hook3_func)data->id:%d, data->name:%s \n", d->id, d->name);
    d->id = d->id * 10;
}

static void hook3_destroy(gpointer data) {
    my_data_t *d = (my_data_t *)data;
    if (NULL != d) {
        if (NULL != d->name) {
            g_print("(hook3_destroy) id:%d, name:%s \n", d->id, d->name);
            g_free(d->name);
        }
        g_free(d);
    }
}

static void test_glib_ghook_exec_part(void) {
    GHookList *hl;
    GHook *hook1, *hook2, *hook3, *hook4;
    my_data_t *d1, *d2, *d3, *d4;

    d1 = g_new(my_data_t, 1);
    d1->id = 1;
    d1->name = g_strdup_printf("name-%d", d1->id);

    d2 = g_new(my_data_t, 1);
    d2->id = 2;
    d2->name = g_strdup_printf("name-%d", d2->id);

    d3 = g_new(my_data_t, 1);
    d3->id = 3;
    d3->name = g_strdup_printf("name-%d", d3->id);

    d4 = g_new(my_data_t, 1);
    d4->id = 4;
    d4->name = g_strdup_printf("name-%d", d4->id);

    hl = g_new(GHookList, 1);
    g_hook_list_init(hl, sizeof(GHook));

    hook1 = g_hook_alloc(hl);
    hook1->data = d1;
    hook1->func = hook3_func;
    hook1->flags = G_HOOK_FLAG_ACTIVE;
    hook1->destroy = hook3_destroy;
    g_hook_append(hl, hook1);

    hook2 = g_hook_alloc(hl);
    hook2->data = d2;
    hook2->func = hook3_func;
    hook2->flags = G_HOOK_FLAG_ACTIVE;
    hook2->destroy = hook3_destroy;
    g_hook_append(hl, hook2);

    hook3 = g_hook_alloc(hl);
    hook3->data = d3;
    hook3->func = hook3_func;
    hook3->flags = G_HOOK_FLAG_ACTIVE;
    hook3->destroy = hook3_destroy;
    g_hook_append(hl, hook3);

    hook4 = g_hook_alloc(hl);
    hook4->data = d4;
    hook4->func = hook3_func;
    hook4->flags = G_HOOK_FLAG_ACTIVE;
    hook4->destroy = hook3_destroy;
    g_hook_append(hl, hook4);

    g_print("invoke 1st \n");
    g_hook_list_invoke(hl, TRUE);

    g_print("marshal_check \n");
    g_hook_list_marshal_check(hl, TRUE, hook_marshal_func, NULL);

    g_print("invoke 2nd \n");
    g_hook_list_invoke(hl, TRUE);

    g_hook_list_clear(hl);
    g_free(hl);
}