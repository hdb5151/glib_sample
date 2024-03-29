#include "glib_byte_array.h"

static gint
sort(gconstpointer p1, gconstpointer p2) {
    char a, b;

    a = *(char *)(p1);
    b = *(char *)(p2);

    return (a > b ? +1 : a == b ? 0 :
                                  -1);
}

static gint
sort_r(gconstpointer p1, gconstpointer p2, gpointer user_data) {
    char a, b;

    a = *(char *)(p1);
    b = *(char *)(p2);

    return (a < b ? +1 : a == b ? 0 :
                                  -1);
}

static void test_array(void) {
    GByteArray *gbarray = NULL;
    gint i;

    gbarray = g_byte_array_new();

    g_byte_array_append(gbarray, (guint8 *)"abcde1234569 ", 10);

    g_print("There should be '%d' items now.\t\tResult: %d.\n", 10, gbarray->len);
    g_print("All of items:\n");
    g_print("%s\n", gbarray->data);

    g_print("All of items[after append]: len:%d\n", gbarray->len);
    g_byte_array_append(gbarray, (guint8 *)"append!", 7);
    g_print("%s\n", gbarray->data);

    g_print("All of items[after prepend]: len:%d\n", gbarray->len);
    g_byte_array_prepend(gbarray, (guint8 *)"prepend!", 8);
    g_print("%s\n", gbarray->data);

    g_byte_array_remove_index(gbarray, 1);
    g_print("All of items[exclude the second item]: len:%d\n", gbarray->len);
    g_print("%s\n", gbarray->data);

    g_byte_array_remove_index_fast(gbarray, 1);
    g_print("All of items[exclude the second item]: len:%d\n", gbarray->len);
    g_print("%s\n", gbarray->data);

    g_byte_array_remove_range(gbarray, 2, 2);
    g_print("All of items[after remove 2 items from the third item]: len:%d\n", gbarray->len);
    g_print("%s\n", gbarray->data);

    g_byte_array_sort(gbarray, sort);
    g_print("All of items[sorted]: len:%d\n", gbarray->len);
    g_print("%s\n", gbarray->data);

    g_byte_array_sort_with_data(gbarray, sort_r, NULL);
    g_print("All of items[sorted reversed]: len:%d\n", gbarray->len);
    g_print("%s\n", gbarray->data);

    g_byte_array_free(gbarray, TRUE);
}

int main(void) {
    g_print("BEGIN:\n************************************************************\n");
    test_array();
    g_print("\n************************************************************\nDONE\n");

    return 0;
}