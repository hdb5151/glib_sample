#include "glib_thread.h"

G_LOCK_DEFINE(thread_mutex);
gint mutex_count = 0;

gint main(gint argc, char **argV) {
    g_printf("main in\n");

    // GThread *gthread_mutex1 = NULL, *gthread_mutex2 = NULL;
    // gthread_mutex1 = g_thread_new("func_mutex1", mutex_func1, NULL);
    // gthread_mutex2 = g_thread_new("func_mutex2", mutex_func2, NULL);
    // g_thread_join(gthread_mutex1);
    // g_thread_join(gthread_mutex2);

    GThread *gthread_cond1 = NULL, *gthread_cond2 = NULL;
    cond1 = g_new(GCond, 1);
    g_cond_init(cond1);
    thread_cond_mutex = g_new(GMutex, 1);
    g_mutex_init(thread_cond_mutex);

    gthread_cond1 = g_thread_new("func_decrement", decrement, NULL);
    g_usleep(2000000);
    gthread_cond2 = g_thread_new("func_increment", increment, NULL);
    g_thread_join(gthread_cond1);
    g_thread_join(gthread_cond2);

    g_mutex_clear(thread_cond_mutex);
    g_cond_clear(cond1);

    g_printf("----------broadcast cond test-----------\n");
    GThread *gthread_cond3 = NULL, *gthread_cond4 = NULL;
    broad_cond = g_new(GCond, 1);
    g_cond_init(broad_cond);
    broad_mutex = g_new(GMutex, 1);
    g_mutex_init(broad_mutex);

    gthread_cond1 = g_thread_new("broadcast", broadcast, NULL);
    gthread_cond2 = g_thread_new("trigger1", trigger1, NULL);
    gthread_cond3 = g_thread_new("trigger2", trigger2, NULL);
    gthread_cond4 = g_thread_new("trigger3", trigger3, NULL);
    g_thread_join(gthread_cond1);
    g_thread_join(gthread_cond2);
    g_thread_join(gthread_cond3);
    g_thread_join(gthread_cond4);

    g_mutex_clear(broad_mutex);
    g_cond_clear(broad_cond);

        g_printf("main out\n");
    return 0;
}

gpointer mutex_func1(gpointer data) {
    gint tmp;
    while (1) {
        G_LOCK(thread_mutex);
        g_printf("%s %ld count: %d\n", __func__, syscall(__NR_gettid), mutex_count);
        tmp = mutex_count;
        mutex_count++;
        g_usleep(2000000);
        g_printf("%s %ld count++ tmp: %d count: %d\n", __func__, syscall(__NR_gettid), tmp, mutex_count);
        G_UNLOCK(thread_mutex);
        g_usleep(20000);
    }
}

gpointer mutex_func2(gpointer data) {
    gint tmp;
    while (1) {
        G_LOCK(thread_mutex);
        g_printf("%s %ld count: %d\n", __func__, syscall(__NR_gettid), mutex_count);
        tmp = mutex_count;
        count++;
        g_usleep(2000000);
        g_printf("%s %ld count++ tmp: %d count: %d\n", __func__, syscall(__NR_gettid), tmp, mutex_count);
        G_UNLOCK(thread_mutex);
        g_usleep(20000);
    }
}

gpointer decrement(gpointer data) {
    g_printf("%s in\n", __func__);

    g_mutex_lock(thread_cond_mutex);

    while (count == 0)
        g_cond_wait(cond1, thread_cond_mutex);

    count--;
    g_printf("%s decrement:%d.\n", __func__, count);
    g_printf("out decrement.\n");

    g_mutex_unlock(thread_cond_mutex);

    g_printf("%s out\n", __func__);
    return NULL;
}

gpointer increment(gpointer data) {
    g_printf("%s in\n", __func__);

    g_mutex_lock(thread_cond_mutex);
    count++;
    g_printf("%s increment:%d.\n", __func__, count);
    if (count != 0)
        g_cond_signal(cond1);

    g_mutex_unlock(thread_cond_mutex);

    g_printf("%s out\n", __func__);
    return NULL;
}

gpointer broadcast(gpointer data) {
    g_printf("%s in\n", __func__);

    g_usleep(5000000);
    g_mutex_lock(broad_mutex);

    // todo something
    broad_flag = 1;
    g_cond_broadcast(broad_cond);

    g_mutex_unlock(broad_mutex);

    g_printf("%s out\n", __func__);
    return NULL;
}

gpointer trigger1(gpointer data) {
    g_printf("%s in\n", __func__);
    g_mutex_lock(broad_mutex);

    while (broad_flag == 0)
        g_cond_wait(broad_cond, broad_mutex);
    g_printf("%s recv broad_cond\n", __func__);

    g_mutex_unlock(broad_mutex);
    g_printf("%s out\n", __func__);
}

gpointer trigger2(gpointer data) {
    g_printf("%s in\n", __func__);
    g_mutex_lock(broad_mutex);

    while (broad_flag == 0)
        g_cond_wait(broad_cond, broad_mutex);
    g_printf("%s recv broad_cond\n", __func__);

    g_mutex_unlock(broad_mutex);
    g_printf("%s out\n", __func__);
}

gpointer trigger3(gpointer data) {
    g_printf("%s in\n", __func__);
    g_mutex_lock(broad_mutex);

    while (broad_flag == 0)
        g_cond_wait(broad_cond, broad_mutex);
    g_printf("%s recv broad_cond\n", __func__);

    g_mutex_unlock(broad_mutex);
    g_printf("%s out\n", __func__);
}