#ifndef __GLIB_THREAD_H__
#define __GLIB_THREAD_H__
#include <glib.h>
#include <glib/gprintf.h>
#include <unistd.h>
#include <sys/syscall.h>
/**
 *          //创建线程 name：表示线程名称可以为空； func 入口函数； data 函数func的参数
 *    GThread *g_thread_new(const gchar *name, GThreadFunc func, gpointer data);
 *          //创建线程 name：表示线程名称可以为空； func 入口函数； data 函数func的参数。。 如果创建失败，error返回失败消息。
 *    GThread *g_thread_try_new(const gchar *name, GThreadFunc func, gpointer data,GError **error);
 *
 *          --> 增加线程的引用计数。
 *    GThread *g_thread_ref(GThread *thread);
 *          --> 减少线程的引用计数，可能释放与之关联的所有资源。
 *    void g_thread_unref(GThread *thread);
 *
 *          --> 等待线程完成，即函数func，给g_thread_new（），返回或调用g_thread_exit（）。 如果线程已经终止，那么g_thread_join（）立即返回。
 *    gpointer g_thread_join(GThread *thread);
 *
 *          --> 使调用线程自动放弃CPU，以便其他线程可以运行。这个功能经常被用来作为一个方法使忙碌等待更少的占用。
 *    void g_thread_yield(void);
 *
 *          --> 终止当前线程。
 *    void g_thread_exit(gpointer retval);
 *
 *          --> 这个函数返回对应于当前线程的GThread。 请注意，该函数不会增加返回结构的引用计数。
 *    GThread * g_thread_self(void)
 *
 *
 *
 *    void g_cond_init(GCond *cond);
 *
 *          --> 用g_cond_init（）释放分配给GCond的资源。这个函数不应该与静态分配的GCond一起使用。
 *    void g_cond_clear(GCond *cond);
 *
 *          --> 原子级释放互斥锁并等待直到cond被发信号。 当这个函数返回时，互斥锁再次被锁定，并由调用线程拥有。
 *              使用条件变量时，可能会发生虚假唤醒（即：即使未调用g_cond_signal（），也会返回g_cond_wait（））。
 *              被盗的唤醒也有可能发生。 这是当调用g_cond_signal（）时，另一个线程在该线程之前获取互斥体，
 *              并以g_cond_wait（）能够返回的方式修改程序的状态时，不再满足预期的条件。
 *              为此，g_cond_wait（）必须始终在循环中使用。
 *    void g_cond_wait (GCond *cond, GMutex *mutex)
 *
 *          --> 等待直到任何cond被发信号或者end_time已经过去。可能会发生虚假或被盗的唤醒。
 *              出于这个原因，等待一个条件变量应该总是在一个循环中，基于一个显式检查的谓词。
 *              如果条件变量被发送（或者在虚假唤醒的情况下），则返回TRUE。 如果end_time已过，则返回FALSE。
 *    gboolean  g_cond_wait_until(GCond *cond, GMutex *mutex, gint64 end_time)
 *
 *          --> 如果线程正在等待cond，至少其中一个被解锁。
 *              如果没有线程在等待cond，这个函数不起作用。 虽然不需要，但在调用此函数的同时保持与等待线程相同的锁定是个好习惯。
 *    void g_cond_signal(GCond *cond);
 *
 *          --> 如果线程正在等待cond，它们全部被解除阻塞。
 *              如果没有线程在等待cond，这个函数不起作用。 虽然不需要，但在调用此函数的同时锁定与等待线程相同的互斥锁是一个好习惯。
 *    void g_cond_broadcast(GCond *cond);
 */

GMutex *thread_cond_mutex, *broad_mutex;
GCond *cond1, *broad_cond;
gint count = 0, broad_flag = 0;

gpointer mutex_func1(gpointer data);
gpointer mutex_func2(gpointer data);

gpointer trigger1(gpointer data);
gpointer trigger2(gpointer data);
gpointer trigger3(gpointer data);

gpointer broadcast(gpointer data);
gpointer increment(gpointer data);
gpointer decrement(gpointer data);
#endif
