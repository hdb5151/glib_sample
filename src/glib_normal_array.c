#include "glib_normal_array.h"

typedef struct foobar_tag {
    gint foo;
    gchar bar[4];
} foobar_t;

typedef struct employee_info_tag {
    gint id;
    gchar *name;
} employee_info_t;

gint main_array(gint argc, gchar **argv) { //------------------------------------main--------------------
    //     array_creat_free_();
    array_insert_index();
    //     main_array_test();
    return 0;
}

void array_creat_free_(void) {
    GArray *arr = NULL;
    guint n = 0;

    arr = g_array_new(FALSE, FALSE, sizeof(gint));
    n = g_array_get_element_size(arr);
    g_print("element size:%d, array len:%d \n", n, arr->len);
    g_array_free(arr, TRUE);

    arr = g_array_new(TRUE, TRUE, sizeof(gint));
    n = g_array_get_element_size(arr);
    g_print("element size:%d, array len:%d \n", n, arr->len);
    g_array_free(arr, TRUE);

    arr = g_array_new(FALSE, TRUE, sizeof(employee_info_t));
    n = g_array_get_element_size(arr);
    g_print("element size:%d, array len:%d \n", n, arr->len);
    g_array_free(arr, TRUE);

    arr = g_array_sized_new(FALSE, TRUE, sizeof(employee_info_t), 100);
    n = g_array_get_element_size(arr);
    g_print("element size:%d, array len:%d \n", n, arr->len);
    g_array_free(arr, TRUE);
}

void array_insert_index(void) {
    GArray *arr = NULL;
    GArray *struct_arr = NULL;
    gint i = 0;
    gint x = 0;
    guint n = 0;
    gint a[3] = {0, 0, 0};

    employee_info_t emp1 = {1, "hdb"};
    employee_info_t emp2 = {2, "hello"};
    employee_info_t emp3 = {3, "world"};
    employee_info_t empArr[5] = {{50, "50"}, {51, "51"}, {52, "52"}, {53, "53"}, {54, "54"}};

    employee_info_t VempArr[5] = {{54, "54"}, {53, "53"}, {52, "52"}, {51, "51"}, {50, "50"}};

    employee_info_t VVempArr[5] = {{54, "home"}, {53, "taday"}, {52, "time"}, {51, "space"}, {50, "money"}};
    struct_arr = g_array_new(FALSE, FALSE, sizeof(employee_info_t));
    g_array_append_val(struct_arr, emp1);

    g_array_append_vals(struct_arr, VVempArr, 3);
    for (guint i = 0; i < 4; i++) {
        g_print("struct_arr[%d]-- the value == %s \n", i, g_array_index(struct_arr, employee_info_t, i).name);
    }
    g_array_sort(struct_arr, sort);

    for (guint i = 0; i < 4; i++) {
        g_print("struct_arr[%d]-- the value == %s \n", i, g_array_index(struct_arr, employee_info_t, i).name);
    }
    /*    arr = g_array_new(FALSE, FALSE, sizeof(gint));

        n = g_array_get_element_size(arr);
        g_print("element size:%d, array len:%d \n", n, arr->len);

        x = 1;
        g_array_append_val(arr, x);
        x = 3;
        g_array_append_val(arr, x);

        n = g_array_get_element_size(arr);
        g_print("element size:%d, array len:%d \n", n, arr->len);

        for (i = 0; i < arr->len; i++) {
            g_print("append-val arr[%d]:%d \n", i, g_array_index(arr, gint, i));
        }

        a[0] = 5;
        a[1] = 7;
        g_array_append_vals(arr, a, 2);

        for (i = 0; i < arr->len; i++) {
            g_print("append-vals arr[%d]:%d \n", i, g_array_index(arr, gint, i));
        }

        x = 2;
        g_array_prepend_val(arr, x);
        x = 4;
        g_array_prepend_val(arr, x);

        for (i = 0; i < arr->len; i++) {
            g_print("prepend-val arr[%d]:%d \n", i, g_array_index(arr, gint, i));
        }

        a[0] = 8;
        a[1] = 6;
        g_array_prepend_vals(arr, a, 2);

        for (i = 0; i < arr->len; i++) {
            g_print("prepend-vals arr[%d]:%d \n", i, g_array_index(arr, gint, i));
        }

        x = 9;
        g_array_insert_val(arr, arr->len, x);
        x = 10;
        g_array_insert_val(arr, 0, x);

        for (i = 0; i < arr->len; i++) {
            g_print("insert-val arr[%d]:%d \n", i, g_array_index(arr, gint, i));
        }

        a[0] = 12;
        a[1] = 11;
        g_array_insert_vals(arr, 5, a, 2);

        for (i = 0; i < arr->len; i++) {
            g_print("insert-vals arr[%d]:%d \n", i, g_array_index(arr, gint, i));
        }

        g_array_free(arr, TRUE);*/
}

void array_clear(void) {
    GArray *arr = NULL;
    foobar_t *foobar[5] = {NULL, NULL, NULL, NULL, NULL};
    gint i = 0;
    guint n = 0;

    arr = g_array_new(FALSE, FALSE, sizeof(foobar_t));
    n = g_array_get_element_size(arr);
    g_print("element size:%d, array len:%d \n", n, arr->len);

    foobar[0] = g_new0(foobar_t, 1);
    foobar[1] = g_new0(foobar_t, 1);
    foobar[2] = g_new0(foobar_t, 1);
    foobar[3] = g_new0(foobar_t, 1);
    foobar[4] = g_new0(foobar_t, 1);

    foobar[0]->foo = 2;
    foobar[1]->foo = 3;
    foobar[2]->foo = 1;
    foobar[3]->foo = 2;
    foobar[4]->foo = 3;

    g_strlcpy(foobar[0]->bar, "AA", 4);
    g_strlcpy(foobar[1]->bar, "BBB", 4);
    g_strlcpy(foobar[2]->bar, "C", 4);
    g_strlcpy(foobar[3]->bar, "DD", 4);
    g_strlcpy(foobar[4]->bar, "EEE", 4);

    g_array_append_val(arr, *foobar[0]); // Not foobar[0]
    g_array_append_val(arr, *foobar[1]);
    g_array_append_val(arr, *foobar[2]);
    g_array_append_val(arr, *foobar[3]);
    g_array_append_val(arr, *foobar[4]);

    // Caution: only the first element can be added success
    // g_array_append_vals(arr, *foobar, 3);

    n = g_array_get_element_size(arr);
    g_print("element size:%d, array len:%d \n", n, arr->len);

    for (i = 0; i < arr->len; i++) {
        g_print("arr[%d]:foo=%d,bar=%s(addr:%p) \n", i,
                (g_array_index(arr, foobar_t, i)).foo,
                (g_array_index(arr, foobar_t, i)).bar,
                &g_array_index(arr, foobar_t, i));
    }

    arr = g_array_remove_index(arr, 1);

    for (i = 0; i < arr->len; i++) {
        g_print("[remove(1)] arr[%d]:foo=%d,bar=%s(addr:%p) \n", i,
                (g_array_index(arr, foobar_t, i)).foo,
                (g_array_index(arr, foobar_t, i)).bar,
                &g_array_index(arr, foobar_t, i));
    }

    arr = g_array_remove_index_fast(arr, 0);

    for (i = 0; i < arr->len; i++) {
        g_print("[remove-fast(0)] arr[%d]:foo=%d,bar=%s(addr:%p) \n", i,
                (g_array_index(arr, foobar_t, i)).foo,
                (g_array_index(arr, foobar_t, i)).bar,
                &g_array_index(arr, foobar_t, i));
    }

    arr = g_array_remove_range(arr, 0, 2);

    for (i = 0; i < arr->len; i++) {
        g_print("[remove-range(0,2)] arr[%d]:foo=%d,bar=%s(addr:%p) \n", i,
                (g_array_index(arr, foobar_t, i)).foo,
                (g_array_index(arr, foobar_t, i)).bar,
                &g_array_index(arr, foobar_t, i));
    }

    g_free(foobar[0]);
    g_free(foobar[1]);
    g_free(foobar[2]);
    g_free(foobar[3]);
    g_free(foobar[4]);
    g_array_free(arr, TRUE);
}

static gint _array_cmp_func(gconstpointer a, gconstpointer b) {
    gint x, y;

    x = *(gint *)a;
    y = *(gint *)b;

    return (x > y ? +1 : x == y ? 0 :
                                  -1);
}
void array_unref_sort(void) {
    GArray *arr = NULL;
    gint i = 0;
    gint x = 0;

    arr = g_array_new(FALSE, FALSE, sizeof(gint));

    x = 1;
    g_array_append_val(arr, x);
    x = 5;
    g_array_append_val(arr, x);
    x = 3;
    g_array_append_val(arr, x);

    for (i = 0; i < arr->len; i++) {
        g_print("arr[%d]:%d(addr:%p) \n", i, g_array_index(arr, gint, i), &g_array_index(arr, gint, i));
    }

    g_array_sort(arr, _array_cmp_func);

    for (i = 0; i < arr->len; i++) {
        g_print("arr[%d]:%d(addr:%p) \n", i, g_array_index(arr, gint, i), &g_array_index(arr, gint, i));
    }

    g_array_free(arr, TRUE);
}

#include <glib.h>

struct map {
    int key;
    char *value;
} m[10] = {
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"}};
typedef struct map map;

static gint sort(gconstpointer p1, gconstpointer p2) {
    gint32 a, b;

    a = *(gint *)(p1);
    b = *(gint *)(p2);

    return (a > b ? +1 : a == b ? 0 :
                                  -1);
}

static gint sort_r(gconstpointer p1, gconstpointer p2, gpointer user_data) {
    gint32 a, b;

    a = *(gint *)(p1);
    b = *(gint *)(p2);

    return (a < b ? +1 : a == b ? 0 :
                                  -1);
}

static void print(GArray *array) {
    gint i;
    for (i = 0; i < array->len; i++)
        g_print("%d,", g_array_index(array, int, i));
    g_print("\n");
}

static void main_array_test(void) {
    GArray *array = NULL;
    gint i;

    // GArray* g_array_new(gboolean zero_terminated, gboolean clear_, guint element_size);
    //创建动态数组指针，zero_terminated如果为true表示使用额外的一个元素0作为数组的结尾
    // clear_为true表示再分配元素的时候清0分配空间，element_size表示需要保存的一个元素占用多少字节空间
    array = g_array_new(FALSE, FALSE, sizeof(int));
    // #define g_array_append_val(a,v)  添加v到数组a的后面，需要注意的是这个是一个宏，所以v不能是一个常量，必须要一个变量
    for (i = 0; i < sizeof(m) / sizeof(m[0]); i++)
        g_array_append_val(array, m[i].key);

    g_print("There should be '%d' items now.\t\tResult: %d.\n", 10, array->len);
    g_print("All of items:\n");
    // #define g_array_index(a, t, i)       返回数组a中第i个的值，t是值的类型
    for (i = 0; i < sizeof(m) / sizeof(m[0]); i++)
        g_print("%d,", g_array_index(array, int, i));
    g_print("\n");

    // GArray* g_array_remove_index(GArray *array, guint index_);   删除数组中的第index_值，并将后面的元素向前移动，对应的g_array_remove_index_fast函数的删除元素，然后使用最后一个元素填充，其他不移动，这样会执行的很快
    array = g_array_remove_index(array, 1);
    g_print("All of items[exclude the second item]:\n");
    for (i = 0; i < sizeof(m) / sizeof(m[0]) - 1; i++)
        g_print("%d,", g_array_index(array, int, i));
    g_print("\n");

    // GArray* g_array_remove_index_fast(GArray *array, guint index_);  删除元素，然后使用最后一个元素填充，其他不移动
    array = g_array_remove_index_fast(array, 1);
    g_print("All of items[exclude the second item]:\n");
    for (i = 0; i < sizeof(m) / sizeof(m[0]) - 1 - 1; i++)
        g_print("%d,", g_array_index(array, int, i));
    g_print("\n");

    // GArray* g_array_remove_range(GArray *array, guint index_, guint length);     删除数组中从第index_开始的length多个元素，后面的元素被顺序下移
    array = g_array_remove_range(array, 2, 2);
    g_print("All of items[after remove 2 items from the third item]:\n");
    for (i = 0; i < sizeof(m) / sizeof(m[0]) - 1 - 1 - 2; i++)
        g_print("%d,", g_array_index(array, int, i));
    g_print("\n");

    // void g_array_sort(GArray *array, GCompareFunc compare_func); 通过compare_func函数规则进行排序
    g_array_sort(array, sort);
    g_print("All of items[sorted]:\n");
    for (i = 0; i < sizeof(m) / sizeof(m[0]) - 1 - 1 - 2; i++)
        g_print("%d,", g_array_index(array, int, i));
    g_print("\n");

    // void g_array_sort_with_data(GArray *array, GCompareDataFunc compare_func, gpointer user_data); compare_func函数带输入参数  user_data的排序
    g_array_sort_with_data(array, sort_r, NULL);
    g_print("All of items[sorted reversed]:\n");
    for (i = 0; i < sizeof(m) / sizeof(m[0]) - 1 - 1 - 2; i++)
        g_print("%d,", g_array_index(array, int, i));
    g_print("\n");

    int x[4] = {2, 3, 4, 5};
    // GArray* g_array_append_vals(GArray *array, gconstpointer data, guint len);   在数组后面添加长度为len的数据，data是数据的首地址指针
    array = g_array_append_vals(array, x, 4);
    g_print("All of items[after append all 2,3,4,5]:\n");
    for (i = 0; i < array->len; i++)
        g_print("%d,", g_array_index(array, int, i));
    g_print("\n");

    g_print("All of items[after prepend one by one 2,3,4,5]:\n");
    // #define g_array_prepend_val(a,v) 与g_array_append_val相似，在数组最前面插入一个数据
    for (i = 0; i < 4; i++)
        g_array_prepend_val(array, x[i]);
    print(array);

    g_print("All of items[after prepend all 2,3,4,5]:\n");
    // GArray* g_array_prepend_vals(GArray *array, gconstpointer data, guint len); 与g_array_append_vals相似，在数组前面插入len多个的数据
    array = g_array_prepend_vals(array, x, 4);
    print(array);

    int t = 0;
    // #define g_array_insert_val(a, i, v)  在数组a中第i个位置插入数据v，由于是宏定义，所以v必须是变量
    g_array_insert_val(array, 0, t);
    g_print("All of items[after insert 0 at the first index]:\n");
    print(array);

    g_array_sort(array, sort);
    g_print("All of items[sorted]:\n");
    print(array);

    // gchar* g_array_free(GArray *array, gboolean free_segment);   释放动态数组，如果free_segment是true会同时把数据也释放掉
    g_array_free(array, TRUE);
}

// int main(void) {
//     g_print("BEGIN:\n************************************************************\n");
//     test_array();
//     g_print("\n************************************************************\nDONE\n");

//     return 0;
// }