#include "glib_timer.h"

gint main_timer(gint argc, gchar **argv) {
    g_test_init(&argc, &argv, NULL);

    g_test_add_func("/timer/basic", test_timer);

    return g_test_run();
}

static void test_timer(void) {
    GTimer *timer = NULL;

    g_print("\n");

    timer = g_timer_new();

    g_timer_start(timer);
    g_print("start, elapsed: %f \n", g_timer_elapsed(timer, NULL));

    g_timer_stop(timer);
    g_usleep(100 * 1000);
    g_print("stop, elapsed: %f \n", g_timer_elapsed(timer, NULL));

    g_timer_continue(timer);
    g_usleep(200 * 1000);
    g_print("continue, elapsed: %f \n", g_timer_elapsed(timer, NULL));

    g_usleep(300 * 1000);
    g_print("continue2, elapsed: %f \n", g_timer_elapsed(timer, NULL));

    g_timer_reset(timer);
    g_print("reset, elapsed: %f \n", g_timer_elapsed(timer, NULL));

    g_timer_destroy(timer);

    return;
}