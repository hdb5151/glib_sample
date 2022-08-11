#include "glib_thread_pools.h"

int main(int argc, char **argv) {
    g_printf("main in\n");

    gint count;
    GError *gerr = NULL;
    GThreadPool *gpool = NULL;
    //最大同时执行2个线程，由于exclusive设置为FALSE，所以不会有错误发生，error被设置为NULL
    gpool = g_thread_pool_new(thread_execute, NULL, 2, FALSE, NULL);

    g_printf("thread pool max threads is %d\n", g_thread_pool_get_max_threads(gpool));
    g_printf("thread pool num threads is %d\n", g_thread_pool_get_num_threads(gpool));

    //线程池中最大允许线程数3个
    if (!g_thread_pool_set_max_threads(gpool, 3, &gerr))
        g_printf("g_thread_pool_set_max_threads is error: %s\n", gerr->message);

    g_printf("thread pool max threads is %d\n", g_thread_pool_get_max_threads(gpool));
    g_printf("thread pool num threads is %d\n", g_thread_pool_get_num_threads(gpool));

    /**
     * 实际线程池中最多有3个线程同时运行
     */
    for (count = 0; count < (sizeof(data) / sizeof(gint)); count++) {
        data[count] = count;
        g_thread_pool_push(gpool, (gpointer)(&(data[count])), &gerr);
        if (gerr != NULL) {
            g_printf("g_thread_pool_push is error: %s\n", gerr->message);
        }
    }

    g_usleep(100000);
    g_printf("thread pool num threads is %d\n", g_thread_pool_get_num_threads(gpool));
    g_printf("thread pool unprocessed num is %d\n", g_thread_pool_unprocessed(gpool));
    g_printf("thread pool num unused threads is %d\n", g_thread_pool_get_num_unused_threads());

    //插入优先级高的新任务
    if (g_thread_pool_move_to_front(gpool, (gpointer)(&(data[9]))))
        g_printf("g_thread_pool_move_to_front is 9\n");

    //立即释放，不继续执行任务队列
    // g_thread_pool_free (gpool, TRUE, TRUE);
    //等待任务队列中的任务全部执行完成
    g_thread_pool_free(gpool, FALSE, TRUE);
    g_printf("thread pool num unused threads is %d\n", g_thread_pool_get_num_unused_threads());

    //设置最大空闲时间2s
    g_thread_pool_set_max_idle_time(2000);

    g_usleep(5000000);
    g_printf("thread pool num unused threads is %d\n", g_thread_pool_get_num_unused_threads());

    //最大同时执行1个线程，由于exclusive设置为FALSE，所以不会有错误发生，error被设置为NULL
    gpool = g_thread_pool_new(thread_execute, NULL, 1, FALSE, NULL);

    /**
     * 实际线程池中最多有3个线程同时运行
     */
    for (count = 0; count < (sizeof(data) / sizeof(gint)); count++) {
        data[count] = count;
        g_thread_pool_push(gpool, (gpointer)(&(data[count])), &gerr);
        if (gerr != NULL) {
            g_printf("g_thread_pool_push is error: %s\n", gerr->message);
        }
    }

    // 从小到大
    // g_thread_pool_set_sort_function (gpool, compare_data, NULL);
    // 从大到小
    g_thread_pool_set_sort_function(gpool, compare_data, (gpointer)(1));

    // 等待任务队列中的任务全部执行完成
    g_thread_pool_free(gpool, FALSE, TRUE);
    // while(1);
    g_printf("main out\n");
    return 0;
}

//用来排序任务列表
gint compare_data(gconstpointer a, gconstpointer b, gpointer user_data) {
    if (user_data == NULL) { //从小到大
        if (*((gint *)a) > *((gint *)b))
            return 1;
        else
            return -1;
    } else { //从大到小
        if (*((gint *)a) < *((gint *)b))
            return 1;
        else
            return -1;
    }
}

//线程执行函数，进入后打印数据，并睡眠5秒
void thread_execute(gpointer data, gpointer user_data) {
    g_printf("thread_execute %ld in\n", syscall(__NR_gettid));
    g_printf("thread_execute %ld data is : %d\n", syscall(__NR_gettid), *((gint *)data));
    g_usleep(5000000);
    g_printf("thread_execute %ld out\n", syscall(__NR_gettid));
}

/*--------------------------------------------------------------------------------------------*/

// add
gint add_func(gpointer data) {
    struct add_data *arg = (struct add_data *)data;
    gint c;
    c = arg->a + arg->b;
    g_printf("add_func: %d+%d = %d\n", arg->a, arg->b, c);
    g_usleep(3000000);
    g_free(data);
    return c;
}

// square
gint square_func(gpointer data) {
    struct square_data *arg = (struct square_data *)data;
    gint c;
    c = arg->a * arg->a;
    g_printf("square_data: %d^2 = %d\n", arg->a, c);
    g_usleep(5000000);
    g_free(data);
    return c;
}

// Mixed operations
gint mix_func(gpointer data) {
    struct mix_data *arg = (struct mix_data *)data;
    gint c;
    c = arg->a * arg->b + arg->c;
    g_printf("mix_data: %d*%d+%d = %d\n", arg->a, arg->b, arg->c, c);
    g_usleep(7000000);
    g_free(data);
    return c;
}

//线程执行函数，进入后打印数据，并睡眠5秒
void thread_execute_2(gpointer data, gpointer user_data) {
    g_printf("thread_execute %ld in\n", syscall(__NR_gettid));
    struct thread_func_data *arg = (struct thread_func_data *)data;
    (*(arg->func))(arg->data);
    g_free(data);
    g_printf("thread_execute %ld out\n", syscall(__NR_gettid));
}

// gint data_2[10];
// int main(int argc, char **argv) {
//     g_printf("main in\n");

//     GError *gerr = NULL;
//     GThreadPool *gpool = NULL;

//     //最大同时执行1个线程，由于exclusive设置为FALSE，所以不会有错误发生，error被设置为NULL
//     gpool = g_thread_pool_new(thread_execute, NULL, 1, FALSE, NULL);

//     struct add_data *ad = (struct add_data *)g_malloc(sizeof(struct add_data));
//     ad->a = 5;
//     ad->b = 6;
//     struct thread_func_data *tfd_a = (struct thread_func_data *)g_malloc(sizeof(struct thread_func_data));
//     tfd_a->func = add_func;
//     tfd_a->data = ad;

//     g_thread_pool_push(gpool, (gpointer)(tfd_a), &gerr);
//     if (gerr != NULL) {
//         g_printf("g_thread_pool_push is error: %s\n", gerr->message);
//     }

//     struct square_data *sd = (struct square_data *)g_malloc(sizeof(struct square_data));
//     sd->a = 77;
//     struct thread_func_data *tfd_s = (struct thread_func_data *)g_malloc(sizeof(struct thread_func_data));
//     tfd_s->func = square_func;
//     tfd_s->data = sd;

//     g_thread_pool_push(gpool, (gpointer)(tfd_s), &gerr);
//     if (gerr != NULL) {
//         g_printf("g_thread_pool_push is error: %s\n", gerr->message);
//     }

//     struct mix_data *md = (struct mix_data *)g_malloc(sizeof(struct mix_data));
//     md->a = 2;
//     md->b = 3;
//     md->c = 4;
//     struct thread_func_data *tfd_m = (struct thread_func_data *)g_malloc(sizeof(struct thread_func_data));
//     tfd_m->func = mix_func;
//     tfd_m->data = md;

//     g_thread_pool_push(gpool, (gpointer)(tfd_m), &gerr);
//     if (gerr != NULL) {
//         g_printf("g_thread_pool_push is error: %s\n", gerr->message);
//     }

//     //等待任务队列中的任务全部执行完成
//     g_thread_pool_free(gpool, FALSE, TRUE);
//     // while(1);
//     g_printf("main out\n");
//     return 0;
// }