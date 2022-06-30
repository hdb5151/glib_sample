#include "glib_ptr_array.h"

typedef struct {
    guint id;
    gchar *name;
} DATA_;

guint main_ptrArray(gint argc, gchar **argv) { //------------------------------------main--------------------
    //     ptr_array_creat_foreach();
    //     ptr_array_remove();
    ptr_array_find();
}

static void _ptr_array_free_func(gpointer data) {
    if (NULL != data) {
        g_free(data);
    }
}

static void _ptr_array_foreach_print_func(gpointer data, gpointer user_data) {
    g_print("%s: %s \n", (gchar *)user_data, (gchar *)data);
}

static void stru_parr_array_foreach_print_func(gpointer data, gpointer user_data) {
    DATA_ *tt = (DATA_ *)data;
    g_print("%s: %s \n", (gchar *)user_data, tt->name);
}
void ptr_array_creat_foreach(void) {
    GPtrArray *parr = NULL;
    gint i = 0;
    gchar *str1 = "one";
    gchar *str2 = "two";
    gchar *str3 = "three";

    parr = g_ptr_array_sized_new(10);

    g_ptr_array_add(parr, (gpointer)str1);
    g_ptr_array_add(parr, (gpointer)str3);
    g_ptr_array_insert(parr, 1, (gpointer)str2);

    for (i = 0; i < parr->len; i++) {
        g_print("parr[%d]:%s \n", i, (gchar *)g_ptr_array_index(parr, i));
    }

    g_ptr_array_foreach(parr, _ptr_array_foreach_print_func, "foreach");

    g_ptr_array_free(parr, TRUE);
}

void ptr_array_remove(void) {
    GPtrArray *parr = NULL;
    gboolean ret = FALSE;
    gpointer p = NULL;
    gchar str0[8] = {0};
    gchar str1[8] = {0};
    gchar str2[8] = {0};
    gchar str3[8] = {0};
    gchar str4[8] = {0};
    gchar str5[8] = {0};
    gchar str6[8] = {0};

    g_strlcpy(str0, "one", 8);
    g_strlcpy(str1, "two", 8);
    g_strlcpy(str2, "two", 8);
    g_strlcpy(str3, "three", 8);
    g_strlcpy(str4, "four", 8);
    g_strlcpy(str5, "five", 8);
    g_strlcpy(str6, "six", 8);

    parr = g_ptr_array_sized_new(10);

    g_ptr_array_add(parr, (gpointer)g_strdup(str0));
    g_ptr_array_add(parr, (gpointer)g_strdup(str1));
    g_ptr_array_add(parr, (gpointer)g_strdup(str2));
    g_ptr_array_add(parr, (gpointer)g_strdup(str3));
    g_ptr_array_add(parr, (gpointer)g_strdup(str4));
    g_ptr_array_add(parr, (gpointer)g_strdup(str5));
    g_ptr_array_add(parr, (gpointer)g_strdup(str6));

    g_ptr_array_foreach(parr, _ptr_array_foreach_print_func, "ori");

    g_ptr_array_set_free_func(parr, _ptr_array_free_func);

    ret = g_ptr_array_remove(parr, "two");
    g_print("remove(two) ret: %s \n", ret ? "TRUE" : "FALSE");
    g_ptr_array_foreach(parr, _ptr_array_foreach_print_func, "remove(two)");

    p = g_ptr_array_remove_index(parr, 1);
    g_print("remove_index(1) p:%p \n", p);
    g_ptr_array_foreach(parr, _ptr_array_foreach_print_func, "remove_index(1)");

    ret = g_ptr_array_remove_fast(parr, "three");
    g_print("remove_fast(three) ret: %s \n", ret ? "TRUE" : "FALSE");
    g_ptr_array_foreach(parr, _ptr_array_foreach_print_func, "remove_fast(three)");

    p = g_ptr_array_remove_index_fast(parr, 2);
    g_print("remove_index_fast(2) p:%p \n", p);
    g_ptr_array_foreach(parr, _ptr_array_foreach_print_func, "remove_index_fast(2)");

    g_ptr_array_remove_range(parr, 0, 2);
    g_ptr_array_foreach(parr, _ptr_array_foreach_print_func, "remove_range(0,2)");

    g_ptr_array_free(parr, TRUE);
}

static gint sort(gconstpointer p1, gconstpointer p2) {
    //     gint32 a, b;
    DATA_ *A = *(DATA_ **)p1;
    DATA_ *B = *(DATA_ **)p2;
    guint a = A->id;
    guint b = B->id;

    return (a > b ? +1 : a == b ? 0 :
                                  -1);
}

void ptr_array_find(void) {
    GPtrArray *parr = NULL, *stru_parr = NULL;
    guint idx = 0;
    gboolean ret = FALSE;

    DATA_ str_dat[5] = {{10, "glib"},
                        {23, "gst"},
                        {13, "GTK"},
                        {44, "deepstream"},
                        {5, g_strdup("TTT")}};

    DATA_ *STRU_[5] = {&str_dat[0], &str_dat[1], &str_dat[2], &str_dat[3], &str_dat[4]};
    stru_parr = g_ptr_array_sized_new(10);
    for (guint i = 0; i < 5; i++) {
        g_ptr_array_add(stru_parr, (gpointer)STRU_[i]);
    }
    g_ptr_array_foreach(stru_parr, stru_parr_array_foreach_print_func, "ori");
    g_ptr_array_sort(stru_parr, sort);
    g_ptr_array_foreach(stru_parr, stru_parr_array_foreach_print_func, "after_sort");
    g_ptr_array_set_free_func(stru_parr, _ptr_array_free_func);
    //     gchar str0[8] = {0};
    //     gchar str1[8] = {0};
    //     gchar str2[8] = {0};
    //     gchar str3[8] = {0};
    //     gchar str4[8] = {0};
    //     gchar str5[8] = {0};
    //     gchar str6[8] = {0};
    //     gchar *str[8] = {NULL};

    //     g_strlcpy(str0, "one", 8);
    //     g_strlcpy(str1, "two", 8);
    //     g_strlcpy(str2, "two", 8);
    //     g_strlcpy(str3, "three", 8);
    //     g_strlcpy(str4, "four", 8);
    //     g_strlcpy(str5, "five", 8);
    //     g_strlcpy(str6, "six", 8);

    //     str[0] = g_strdup(str0);
    //     str[1] = g_strdup(str1);
    //     str[2] = g_strdup(str2);
    //     str[3] = g_strdup(str3);
    //     str[4] = g_strdup(str4);
    //     str[5] = g_strdup(str5);
    //     str[6] = g_strdup(str6);

    //     parr = g_ptr_array_sized_new(10);

    //     g_ptr_array_add(parr, (gpointer)str[0]);
    //     g_ptr_array_add(parr, (gpointer)str[1]);
    //     g_ptr_array_add(parr, (gpointer)str[2]);
    //     g_ptr_array_add(parr, (gpointer)str[3]);
    //     g_ptr_array_add(parr, (gpointer)str[4]);
    //     g_ptr_array_add(parr, (gpointer)str[5]);
    //     g_ptr_array_add(parr, (gpointer)str[6]);

    //     g_ptr_array_foreach(parr, _ptr_array_foreach_print_func, "ori");

    //     g_ptr_array_set_free_func(parr, _ptr_array_free_func);

    //     ret = g_ptr_array_find(parr, str[3], NULL);
    //     g_print("find three? %s \n", ret ? "TRUE" : "FALSE");

    //     ret = g_ptr_array_find(parr, str[4], &idx);
    //     g_print("find four? %s, pos:%d \n", ret ? "TRUE" : "FALSE", idx);

    //     g_ptr_array_free(parr, TRUE);
}