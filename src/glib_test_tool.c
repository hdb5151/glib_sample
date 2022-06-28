#include <gst/gst.h>
#include <glib.h>
#include <stdio.h>
/**
 *g_assert()：期望表达式为真，如果表达式为假则产生断言      --------
 *g_assert_not_reached：期望不运行到此处，如果运行到此函数则产生断言
 *g_assert_cmpstr()：期望两个字符串比较结果为真，如果字符串比较结果为假则产生断言   --------
 *g_assert_cmpint()：期望两个int值比较(大于小于等于)结果为真，如果结果为假则产生断言    --------
 *g_assert_cmpuint()：期望两个uint值比较结果为真，如果结果为假则产生断言
 *g_assert_cmphex()：期望两个十六进制值比较结果为真，如果结果为假则产生断言
 *g_assert_cmpfloat()：期望两个float值比较结果为真，如果结果为假则产生断言
 *g_assert_cmpmem()：期望两段内存比较结果为真，如果结果为假则产生断言
 *g_assert_no_error()：期望GError没有被赋值，如果GError被赋值了则产生断言
 *g_assert_error()：判断GError的值是否为期望值，如果和期望值不同则产生断言  --------
 *g_assert_true()：期望表达式为真，如果表达式为假则产生断言     --------
 *g_assert_false()：期望表达式为假，如果表达式为真则产生断言
 *g_assert_null()：期望表达值为空，如果表达式非空则产生断言     --------
 *g_assert_nonnull()：期望表达式非空，如果表达式为空则产生断言
 */
static void test_case(void) {
    gint x = 2, y = 3, z = 1;

    g_print("%s \n", x + y == z ? "Equal" : "Not equal");
}
/*----------------------断言（assert） 测试-------------------------*/
static void test_assert(void) {
    guint a = 1, n = 2;
    g_assert_true(a == n);
    g_print("err\r\n");
}

static void test_assert_not_reached(void) {
    g_assert_not_reached();
}

static void test_assert_cmpstr(void) {
    gchar *s1 = "abcd";
    g_assert_cmpstr(s1, ==, "abcd");
}

static void test_assert_cmpint(void) {
    gint n1 = 100;
    g_assert_cmpint(n1, ==, 100);
}

static void test_assert_cmpuint(void) {
    guint n1 = 200;
    g_assert_cmpuint(n1, ==, 200);
}

static void test_assert_cmphex(void) {
    guint n1 = 0xdeadbeef;
    g_assert_cmphex(n1, ==, 0xdeedbeef);
}

static void test_assert_cmpfloat(void) {
    gfloat n1 = 0.00001;
    g_assert_cmpfloat(n1, ==, 0.00001);
}

static void test_assert_no_error(void) {
    GDir *dir = NULL;
    GError *err = NULL;

    dir = g_dir_open("/tmp", 0, &err);
    g_assert(dir != NULL);
    g_assert_no_error(err);
    if (NULL != err) {
        g_error_free(err);
    }
}

static void test_assert_error(void) {
    GDir *dir;
    GError *error;

    error = NULL;
    dir = g_dir_open("/pfrkstrf", 0, &error);
    g_assert(dir == NULL);
    g_assert_error(error, G_FILE_ERROR, G_FILE_ERROR_NOENT);
    if (NULL != error) {
        g_error_free(error);
    }
}

static void test_assert_true(void) {
    g_assert_true(TRUE);
}

static void test_assert_false(void) {
    g_assert_false(FALSE);
}

static void test_assert_null(void) {
    gpointer *p = NULL;
    g_assert_null(p);
}

static void test_assert_nonnull(void) {
    gpointer *p = NULL;
    g_assert_nonnull(p);
}
/*------------------------------------*/
gint main_tool(gint argc, gchar **argv) {
    // g_test_init(&argc, &argv, NULL);

    // g_test_add_func("/test/aaa", test_case);

    // g_test_add_func("/test/test_assert", test_assert);
    test_assert();
    // g_test_add_func("/test/test_assert_not_reached", test_assert_not_reached);
    // g_test_add_func("/test/test_assert_cmpstr", test_assert_cmpstr);
    // g_test_add_func("/test/test_assert_cmpint", test_assert_cmpint);
    // g_test_add_func("/test/test_assert_cmpuint", test_assert_cmpuint);
    // g_test_add_func("/test/test_assert_cmphex", test_assert_cmphex);
    // g_test_add_func("/test/test_assert_cmpfloat", test_assert_cmpfloat);
    // g_test_add_func("/test/test_assert_no_error", test_assert_no_error);
    // g_test_add_func("/test/test_assert_error", test_assert_error);
    // g_test_add_func("/test/test_assert_true", test_assert_true);
    // g_test_add_func("/test/test_assert_false", test_assert_false);
    // g_test_add_func("/test/test_assert_null", test_assert_null);
    // g_test_add_func("/test/test_assert_nonnull", test_assert_nonnull);
    // return g_test_run();
}