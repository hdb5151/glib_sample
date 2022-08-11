#ifndef __GLIB_THREAD_ASYN_QUEUES_H__
#define __GLIB_THREAD_ASYN_QUEUES_H__
#include <glib.h>
#include <glib/gprintf.h>
#include <unistd.h>
#include <sys/syscall.h>

/**
 *          -->   创建一个新的异步队列。
 *                返回:一个新的GAsyncQueue。 使用g_async_queue_unref（）释放
 *    GAsyncQueue *g_async_queue_new                  (void);
 *
 *          -->   创建一个新的异步队列并设置一个destroy通知函数，该函数用于在队列在最终unref之后销毁时释放任何剩余的队列项。
 *    GAsyncQueue *g_async_queue_new_full             (GDestroyNotify item_free_func);
 *
 *          -->   将异步队列的引用计数增加1。您不需要保持锁来调用此函数。
 *    GAsyncQueue *g_async_queue_ref                  (GAsyncQueue      *queue);
 *
 *          -->   将异步队列的引用计数减1
 *                如果引用计数为0，则队列将被销毁并分配的内存将被释放。 所以你不能使用队列，因为它可能已经消失了。 你不需要保持锁来调用这个函数。
 *    void         g_async_queue_unref                (GAsyncQueue      *queue);
 *
 *          -->   使用func将数据插入队列以确定新的位置。这个函数需要在推入新元素之前对队列进行排序，请参阅g_async_queue_sort（）。
 *                这个函数会在对队列进行排序之前锁定队列，并在完成时将其解锁。
 *    void         g_async_queue_push_sorted          (GAsyncQueue      *queue,
                                                      gpointer          data,
                                                      GCompareDataFunc  func,
                                                      gpointer          user_data);
 *
 *          -->   将项目推入队列。 项目不能为NULL。 与g_async_queue_push（）不同的是，这个函数在队列中已经存在的项目之前压入新的项目，这样它将成为下一个从队列中弹出的项目。
 *    void         g_async_queue_push_front           (GAsyncQueue      *queue,
                                                      gpointer          item);
 *
 *          -->   从队列中弹出数据。 如果队列为空，则此功能会阻塞，直到数据可用。
 *    gpointer     g_async_queue_pop                  (GAsyncQueue      *queue);
 *
 *          -->   试图从队列中弹出数据。 如果没有数据可用，则返回NULL。
 *    gpointer     g_async_queue_try_pop              (GAsyncQueue      *queue);
 *
 *          -->   从队列中弹出数据。 如果队列为空，则超时微秒或直到数据可用。如果在超时之前没有收到数据，则返回NULL。
 *    gpointer     g_async_queue_timeout_pop          (GAsyncQueue      *queue,
                                                      guint64           timeout);
 *
 *          -->   返回队列的长度。实际上这个函数返回队列中数据项的数量减去等待线程的数量，所以负值表示等待线程，正值表示队列中可用的项。
 *                返回值0可以表示队列中的n个条目和n个等待的线程。 这可能是由于队列锁定或调度造成的。
 *    gint         g_async_queue_length               (GAsyncQueue      *queue);
 *
 *          -->   使用func对队列进行排序。
 *                sort函数func传递队列的两个元素。 如果它们相等，它应该返回0，如果第一个元素应该在队列中更高，则返回负值;如果队列中第一个元素应该比第二个元素低，则返回正值。
 *                这个函数会在对队列进行排序之前锁定队列，并在完成时将其解锁。如果您正在排序优先级编号列表以确保最低优先级位于队列顶部，则可以使用：
 *    void         g_async_queue_sort                 (GAsyncQueue      *queue,
                                                      GCompareDataFunc  func,
                                                      gpointer          user_data);
 *
 *          -->   获取队列的锁。 如果另一个线程已经持有该锁，则该呼叫将被阻塞，直到该锁可用。调用g_async_queue_unlock（）再次放下锁。
 *                在按住锁的同时，您只能调用队列上的g_async_queue _ * _ unlocked（）函数。 否则，可能会发生死锁。
 *    void         g_async_queue_lock                 (GAsyncQueue      *queue);
 *
 *          -->   释放队列的锁定。当你没有获得g_async_queue_lock（）时调用这个函数会导致未定义的行为。
 *    void         g_async_queue_unlock               (GAsyncQueue      *queue);
 *
 *          -->   将数据推入队列。 数据不能为NULL。这个函数必须在持有队列锁的时候被调用。
 *    void         g_async_queue_push_unlocked        (GAsyncQueue      *queue,
                                                      gpointer          data);
 *
 *          -->   使用func将数据插入队列以确定新的位置。sort函数func传递队列的两个元素。 如果它们相等，它应该返回0，如果第一个元素应该在队列中更高，则返回负值;
 *                如果队列中第一个元素应该比第二个元素低，则返回正值。这个函数需要在推入新元素之前对队列进行排序，请参阅g_async_queue_sort（）。
 *                这个函数必须在持有队列锁的时候被调用。
 *    void         g_async_queue_push_sorted_unlocked (GAsyncQueue      *queue,
                                                      gpointer          data,
                                                      GCompareDataFunc  func,
                                                      gpointer          user_data);
 *
 *          -->   将项目推入队列。 项目不能为NULL。 与g_async_queue_push_unlocked（）相比，此函数将新项目推到队列中已有的项目之前，这样它将成为下一个从队列中弹出的项目。
 *                这个函数必须在持有队列锁的时候被调用。
 *    void         g_async_queue_push_front_unlocked  (GAsyncQueue      *queue,
                                                 gpointer          item);
 *
 *
 *
 *
 *
 *
 */

#endif
