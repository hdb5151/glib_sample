#include <glib.h>
#define TEST_KEY_FILE_BASIC_FILE "./configs/key_val.txt"
gint main_key(gint argc, gchar *argv) {
    gboolean ret = FALSE;
    GKeyFile *key_file = NULL;
    gchar *first_group_name_val = NULL;
    gint i = 0;
    gchar **group_names;
    gsize len = 0;
    gint *int_val = NULL;
    key_file = g_key_file_new();
    if (NULL == key_file) {
        g_print("key file new failed! \n");
    }
    ret = g_key_file_load_from_file(key_file, TEST_KEY_FILE_BASIC_FILE, 0, NULL);
    if (FALSE == ret) {
        g_print("key file load failed \n");
        return -1;
    }
    /* get value */
    g_print("******************** \n");
    g_print("get value \n");
    first_group_name_val = g_key_file_get_value(key_file, "First Group", "Name", NULL);
    if (NULL == first_group_name_val) {
        return -1;
    }
    g_print("(get value)first_group_name_val is %s \n", first_group_name_val);
    g_free(first_group_name_val);
    /* get string */
    g_print("******************** \n");
    g_print("get string \n");
    first_group_name_val = g_key_file_get_string(key_file, "First Group", "Name", NULL);
    if (NULL == first_group_name_val) {
        return -1;
    }
    g_print("(get string)first_group_name_val is %s \n", first_group_name_val);
    g_free(first_group_name_val);
    /* get groups */
    g_print("******************** \n");
    g_print("get groups \n");
    group_names = g_key_file_get_groups(key_file, &len);
    while (NULL != group_names[i]) {
        g_print("group_name[%d] is: %s \n", i++, group_names[i]);
    }
    g_strfreev(group_names);
    /* get interger list */
    g_print("******************** \n");
    g_print("get interger list \n");
    len = 0;
    i = 0;
    int_val = g_key_file_get_integer_list(key_file, "Another Group", "Numbers", &len, NULL);
    for (i = 0; i < len; i++) {
        g_print("int_val[%d]:%d \n", i, int_val[i]);
    }
    g_free(int_val);
    g_key_file_free(key_file);
    return 0;
}