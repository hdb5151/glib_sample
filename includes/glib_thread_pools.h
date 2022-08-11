#ifndef __GLIB_THREAD_POOLS_H__
#define __GLIB_THREAD_POOLS_H__
#include <glib.h>
#include <glib/gprintf.h>
#include <unistd.h>
#include <sys/syscall.h>

/**
 *          -->   如果exclusive为TRUE，则max_threads线程立即启动，它们将专门为该线程池运行，直到被g_thread_pool_free（）销毁。
 *                如果exclusive是FALSE，则在需要时创建线程，并在所有非独占线程池之间共享。 这意味着max_threads对于独占线程池不可能是-1。
 *                此外，独占线程池不受g_thread_pool_set_max_idle_time（）影响，因为它们的线程永远不会被视为空闲并返回到全局池。
 *                error 可以是NULL来忽略错误，或者是非NULL来报告错误。 只有将exclusive设置为TRUE时才会出现错误，并且不能创建所有的max_thread线程。
 *                请参阅GThreadError，了解可能发生的错误。 请注意，即使发生错误，也会返回有效的GThreadPool。
 *    GThreadPool *   g_thread_pool_new               (GFunc            func,
                                                      gpointer         user_data,
                                                      gint             max_threads,
                                                      gboolean         exclusive,
                                                      GError         **error);
 *
 *          -->   将数据插入池中要执行的任务列表。
 *                当前正在运行的线程的数量低于最大允许的线程数时，将使用给g_thread_pool_new（）的属性启动（或重用）一个新的线程。
 *                否则，数据将保留在队列中，直到此池中的线程完成其之前的任务并处理数据。
 *    gboolean        g_thread_pool_push              (GThreadPool     *pool,
                                                      gpointer         data,
                                                      GError         **error);
 *
 *          -->   设置池的最大允许线程数。 值-1意味着线程的最大数目是无限的。 如果池是独占线程池，则不允许将最大线程数设置为-1。
 *                将max_threads设置为0意味着停止池的所有工作。 它被有效地冻结，直到max_threads再次被设置为非零值。
 *                调用func时线程永远不会被终止，就像g_thread_pool_new（）所提供的那样。 相反，最大线程数只对g_thread_pool_push（）中的新线程分配有效。
 *                只要当前正在运行的线程数量小于最大数量，就会分配一个新的线程
 *    gboolean        g_thread_pool_set_max_threads   (GThreadPool     *pool,
                                                      gint             max_threads,
                                                      GError         **error);
 *
 *          -->   返回池的最大线程数。
 *    gint            g_thread_pool_get_max_threads   (GThreadPool     *pool);
 *
 *          -->   返回当前在池中运行的线程数
 *    guint           g_thread_pool_get_num_threads   (GThreadPool     *pool);
 *
 *          -->   返回池中尚未处理的任务数。
 *    guint           g_thread_pool_unprocessed       (GThreadPool     *pool);
 *
 *          -->   释放为池分配的所有资源。
 *                如果immediate为TRUE，则不会为池处理新的任务。否则，在最后一个任务被处理之前，池不会被释放。但请注意，正在处理的任务，线程不会中断。
 *                也就是说，所有仍在运行的线程都可以在释放池之前完成任务。如果wait_为TRUE，则在所有要处理的任务（取决于immediate，
 *                无论是全部还是仅当前正在运行）都完成之前，函数不会返回。 否则，函数立即返回。
 *    void            g_thread_pool_free              (GThreadPool     *pool,
                                                      gboolean         immediate,
                                                      gboolean         wait_);
 *
 *          -->   将未使用线程的最大数量设置为max_threads。 如果max_threads为-1，则不会对未使用的线程数量施加任何限制。
 *                默认值是2。
 *    void            g_thread_pool_set_max_unused_threads (gint  max_threads);
 *
 *          -->   返回未使用线程的最大允许数量。
 *    gint            g_thread_pool_get_max_unused_threads (void);
 *
 *          -->   返回当前未使用线程的数量。
 *    guint           g_thread_pool_get_num_unused_threads (void);
 *
 *          -->   停止当前所有未使用的线程。 这不会更改未使用的线程的最大数量。 这个功能可以用来定期停止所有未使用的线程，例如 来自g_timeout_add（）。
 *    void            g_thread_pool_stop_unused_threads    (void);
 *
 *          -->   设置用于排序任务列表的函数。
 *                这允许按照func确定的优先级处理任务，而不仅仅是按照将其添加到池中的顺序处理。请注意，如果最大线程数大于1，则执行线程的顺序不能保证100％。
 *                线程由操作系统调度并随机执行。 不能认为线程按照它们创建的顺序执行
 *    void            g_thread_pool_set_sort_function (GThreadPool      *pool,
                                                      GCompareDataFunc  func,
                                                      gpointer          user_data);
 *
 *
 *          -->   这个函数将设置一个在新池中等待新任务的线程在停止之前可以空闲的最大时间间隔。
 *                这个函数类似于在正常超时时调用g_thread_pool_stop_unused_threads（），除了这是在每个线程的基础上完成的。
 *                通过设置间隔为0，空闲线程不会停止。默认值是15000（15秒）。
 *    void            g_thread_pool_set_max_idle_time      (guint interval)
 *
 *          -->   此函数将返回线程在线程池中等待新任务的最大间隔，然后才能停止。如果这个函数返回0，那么在线程池中等待新工作的线程不会停止。
 *    guint           g_thread_pool_get_max_idle_time      (void)
 *
 *          -->   将项目移动到未处理项目的队列的前面，以便接下来处理。
 *    gboolean        g_thread_pool_move_to_front     (GThreadPool      *pool,
                                                      gpointer          data);
 */

gint data[10];
typedef gint (*thread_func)(gpointer data);
struct thread_func_data {
    thread_func func;
    gpointer data;
};

struct add_data {
    gint a;
    gint b;
};
struct square_data {
    gint a;
};
struct mix_data {
    gint a;
    gint b;
    gint c;
};

gint compare_data(gconstpointer a, gconstpointer b, gpointer user_data);
void thread_execute(gpointer data, gpointer user_data);

gint add_func(gpointer data);
gint square_func(gpointer data);
gint mix_func(gpointer data);
void thread_execute_2(gpointer data, gpointer user_data);

#endif