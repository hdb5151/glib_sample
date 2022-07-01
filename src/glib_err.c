#include <stdio.h>
#include <glib.h>

void _print_func(const gchar *string) {
    printf("[in _print_func]: %s", string);
}

void _printerr_func(const gchar *string) {
    printf("[in _printerr_func]: %s", string);
}

gint main(gint argc, gchar **argv) {
    g_print("call g_print \n");
    g_printerr("call g_printerr \n");

    g_set_print_handler(_print_func);
    g_set_printerr_handler(_printerr_func);

    g_print("print handler set! \n");
    g_printerr("printerr handler set! \n");

    g_set_print_handler(NULL);
    g_set_printerr_handler(NULL);

    g_print("after unset g_print handler \n");
    g_printerr("after unset g_printerr handler \n");

    return 0;
}