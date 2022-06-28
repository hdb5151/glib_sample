#include <glib_str.h>

gint main_str(gint argc, gchar **argv) {
    gint x = g_strcmp0(NULL, "aabb");

    g_test_init(&argc, &argv, NULL);

    g_test_add_func("/str/strnfill", test_str_strnfill_func);
    g_test_add_func("/str/stpcpy", test_str_stpcpy_func);
    g_test_add_func("/str/strlcpy", test_str_strlcpy_func);
    g_test_add_func("/str/strdup_printf", test_str_strdup_printf_func);
    g_test_add_func("/str/strstr_len", test_str_strstr_len_func);
    g_test_add_func("/str/strrstr", test_str_strrstr_func);
    g_test_add_func("/str/strrstr_len", test_str_strrstr_len_func);
    g_test_add_func("/str/str_prefix", test_str_has_prefix_func);
    g_test_add_func("/str/str_suffix", test_str_has_suffix_func);
    g_test_add_func("/str/str_trans", test_str_trans_func);
    g_test_add_func("/str/str_strlcat", test_str_strlcat_func);
    g_test_add_func("/str/str_strconcat", test_str_strconcat_func);
    g_test_add_func("/str/str_strjoin", test_str_strjoin_func);
    g_test_add_func("/str/str_strjoinv", test_str_strjoinv_func);
    g_test_add_func("/str/str_stripspace", test_str_strip_space_func);
    g_test_add_func("/str/str_split", test_str_split_func);
    g_test_add_func("/str/str_splitset", test_str_split_set_func);
    g_test_add_func("/str/str_strcanon", test_str_strcanon_func);
    g_test_add_func("/str/str_strdelimit", test_str_strdelimit_func);
    g_test_add_func("/str/str_strescape", test_str_strescape_func);

    return g_test_run();
}

void test_str_strnfill_func(void) {
    gchar *str1 = "aaaa";
    gchar *str2 = NULL;

    str2 = g_strnfill(4, 'a');

    g_assert_cmpstr(str1, ==, str2);

    g_free(str2);
}

void test_str_stpcpy_func(void) {
    gchar buff1[8] = {0};
    //    gchar buff2[4] = {0};

    gchar *s1;
    //    gchar *s2;

    g_stpcpy(buff1, "ABCDEF");
    //    g_stpcpy(buff2, "ABCDEF");

    s1 = g_strdup(buff1);
    //    s2 = g_strndup(buff1, 3);

    g_free(s1);
    //    g_free(s2);
}

void test_str_strlcpy_func(void) {
    gchar *str = "abcdeABCDE";
    gchar buf1[8] = {0};
    gchar buf2[16] = {0};
    gchar buf3[32] = {0};

    g_strlcpy(buf1, str, 8);
    g_strlcpy(buf2, str, 16);
    g_strlcpy(buf3, str, 32);

    g_assert(7 == strlen(buf1));
    g_assert(10 == strlen(buf2));
    g_assert(10 == strlen(buf3));
}

void test_str_strdup_printf_func(void) {
    gchar *str0 = "AB10CDefgEND";
    gchar *str = NULL;

    str = g_strdup_printf("AB%dCD%sEND", 10, "efg");

    g_assert_cmpstr(str0, ==, str);

    g_free(str);
}

void test_str_strstr_len_func(void) {
    gchar *str0 = "ABCDabcdABCD";
    gchar *str = NULL;

    str = g_strstr_len(str0, strlen(str0), "CD");

    g_assert_cmpstr("CDabcdABCD", ==, str);
}

void test_str_strrstr_func(void) {
    gchar *str0 = "ABCDabcdABCD";
    gchar *str = NULL;

    str = g_strrstr(str0, "cd");
    g_assert_cmpstr("cdABCD", ==, str);
}

void test_str_strrstr_len_func(void) {
    gchar *str0 = "ABCDabcdABCD";
    gchar *str = NULL;

    str = g_strrstr_len(str0, 4, "cd");
    g_assert(NULL == str);
}

void test_str_has_prefix_func(void) {
    gchar *str0 = "ABCDabcdABCD";
    gboolean flag = FALSE;
    // g_str_match_string
    // g_str_to_ascii
    // g_ascii_strup
    // g_ascii_strdown
    // g_ascii_toupper
    // g_string_ascii_up
    // g_strcmp0
    flag = g_str_has_prefix(str0, "ABCD");
    g_assert(flag);

    flag = g_str_has_prefix(str0, "abcd");
    g_assert(!flag);
}

void test_str_has_suffix_func(void) {
    gchar *str0 = "ABCDabcdABCD";
    gboolean flag = FALSE;

    flag = g_str_has_suffix(str0, "ABCD");
    g_assert(flag);

    flag = g_str_has_suffix(str0, "abcd");
    g_assert(!flag);
}

void test_str_trans_func(void) {
    gchar *s1, *s2;
    gchar *str1 = "ABCDabcd";
    GString *string = NULL;

    string = g_string_new("ABab");

    s1 = g_ascii_strup(str1, 8);
    s2 = g_ascii_strdown(str1, 8);
    g_assert_cmpstr(s1, ==, "ABCDABCD");
    g_assert_cmpstr(s2, ==, "abcdabcd");

    g_string_ascii_up(string);
    g_assert_cmpstr(string->str, ==, "ABAB");

    g_string_ascii_down(string);
    g_assert_cmpstr(string->str, ==, "abab");

    g_free(s1);
    g_free(s2);
    g_string_free(string, TRUE);
}

void test_str_strlcat_func(void) {
    gchar dest[8] = {0};

    g_strlcat(dest, "ABCDabcdABCD", 8);
    g_assert_cmpstr(dest, ==, "ABCDabc");

    memset(dest, 0, 8);
    g_strlcat(dest, "AB", 8);
    g_assert_cmpstr(dest, ==, "AB");

    g_strlcat(dest, "CD", 8);
    g_assert_cmpstr(dest, ==, "ABCD");
}

void test_str_strconcat_func(void) {
    gchar *str = NULL;
    gchar *s = "AABB";
    str = g_strconcat("aaaa", s, "1234", NULL);
    g_assert_cmpstr(str, ==, "aaaaAABB1234");
    g_free(str);
}

void test_str_strjoin_func(void) {
    gchar *str = NULL;
    gchar *s = "AND";

    str = g_strjoin(s, "aa", "bb", "cc", NULL);
    g_assert_cmpstr(str, ==, "aaANDbbANDcc");
    g_free(str);
}

void test_str_strjoinv_func(void) {
    gchar *str = NULL;
    gchar *s = "AND";
    gchar *arr[] = {"aa", "bb", "cc", NULL};

    str = g_strjoinv(s, arr);
    g_assert_cmpstr(str, ==, "aaANDbbANDcc");
    g_free(str);
}

void test_str_strip_space_func(void) {
    gchar str1[16] = "  abcd";
    gchar str2[16] = "abcd  ";
    gchar *str3 = g_strdup("  abcd  ");

    g_strchug(str1);
    g_strchomp(str2);
    g_strstrip(str3);

    g_assert_cmpstr(str1, ==, "abcd");
    g_assert_cmpstr(str2, ==, "abcd");
    g_assert_cmpstr(str3, ==, "abcd");

    g_free(str3);
}

void test_str_split_func(void) {
    gchar *str1 = "doc;xls;ppt";
    gchar *str2 = "docANDxlsANDppt";
    gchar **strv = NULL;
    gint i = 0;

    strv = g_strsplit(str1, ";", -1);
    g_assert_cmpstr(strv[0], ==, "doc");
    g_assert_cmpstr(strv[1], ==, "xls");
    g_assert_cmpstr(strv[2], ==, "ppt");
    g_strfreev(strv);

    strv = g_strsplit(str1, ";", 2);
    g_assert_cmpstr(strv[0], ==, "doc");
    g_assert_cmpstr(strv[1], ==, "xls;ppt");
    g_strfreev(strv);

    strv = g_strsplit(str2, "AND", -1);
    g_assert_cmpstr(strv[0], ==, "doc");
    g_assert_cmpstr(strv[1], ==, "xls");
    g_assert_cmpstr(strv[2], ==, "ppt");
    g_strfreev(strv);
}

void test_str_split_set_func(void) {
    gchar *str1 = "doc;xls,ppt";
    gchar *str2 = "doc;,xls;,ppt";
    gchar **strv = NULL;
    gint i = 0;

    strv = g_strsplit_set(str1, ";,", -1);
    g_assert_cmpstr(strv[0], ==, "doc");
    g_assert_cmpstr(strv[1], ==, "xls");
    g_assert_cmpstr(strv[2], ==, "ppt");
    g_strfreev(strv);

    strv = g_strsplit(str2, ";,", -1);
    g_assert_cmpstr(strv[0], ==, "doc");
    g_assert_cmpstr(strv[1], ==, "xls");
    g_assert_cmpstr(strv[2], ==, "ppt");
    g_strfreev(strv);

    strv = g_strsplit_set(str2, ";,", -1);
    g_assert_cmpstr(strv[0], ==, "doc");
    g_assert_cmpstr(strv[1], ==, "");
    g_assert_cmpstr(strv[2], ==, "xls");
    g_assert_cmpstr(strv[3], ==, "");
    g_assert_cmpstr(strv[4], ==, "ppt");
    g_strfreev(strv);
}

void test_str_strcanon_func(void) {
    gchar str[16] = "abcdefg";

    g_strcanon(str, "acdf", '?');
    g_assert_cmpstr(str, ==, "a?cd?f?");
}

void test_str_strdelimit_func(void) {
    gchar str[16] = "abcdABcdEFacbd";

    g_strdelimit(str, "cd", 'X');
    g_assert_cmpstr(str, ==, "abXXABXXEFaXbX");
}

void test_str_strescape_func(void) {
    gint i = 0;
    gchar ori[16] = "a\rb\nc\td";
    gchar *s1 = NULL, *s2 = NULL;

    s1 = g_strescape(ori, "\t");
    for (i = 0; i < 32; i++) {
        // g_print("%d ", s1[i]);
    }
    // g_print("str:%s \n", s1);
    g_assert_cmpstr(s1, ==, "a\\rb\\nc\td");

    s2 = g_strcompress(s1);
    for (i = 0; i < 32; i++) {
        // g_print("%d ", s2[i]);
    }
    g_assert_cmpstr(s2, ==, ori);

    g_free(s1);
    g_free(s2);
}