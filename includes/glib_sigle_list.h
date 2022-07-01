#include "glib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

struct _GSList
{
  gpointer data;
  GSList *next;
};


      GSList* g_slist_alloc (void);

# 插入：
            // 头插
      GSList* g_slist_append(GSList *list,gpointer data);
            // 尾插
      GSList* g_slist_prepend (GSList *list,gpointer data);
            // 注意：返回的是新链表首地址，但此时旧链表其实也已经发生变化了 g_slist_insert(slist, GINT_TO_POINTER(70), 3);    position=0：在头部插入，position=-1：在尾部插入
      GSList* g_slist_insert(GSList *list,gpointer data,gint position);
            // 在第二个参数的节点之前添加一个节点， slist = g_slist_insert_before(slist, slist->next, GINT_TO_POINTER(32));
      GSList* g_slist_insert_before (GSList *slist,GSList *sibling,gpointer data);
            // 排序的区别是可以插入一个数据节点
      GSList* g_slist_insert_sorted (GSList *list,gpointer data,GCompareFunc func);


# 删除：
            // 以值方式从链表中删除一个节点，如果链表中有多个节点相同的值，则只删除第一个
      GSList* g_slist_remove(GSList *list,gconstpointer data);
            // 以节点方式从链表中删除一个节点，但并不会释放该节点的内存
      GSList* g_slist_remove_link (GSList *list,GSList *link_);
            // 以节点方式从链表中删除一个节点，并且该节点的内存会被自动释放
      GSList* g_slist_delete_link (GSList *list,GSList *link_);
            // 以值方式从链表中删除一个节点，如果有多个节点相同的值则会全部删除
      GSList* g_slist_remove_all(GSList *list,gconstpointer data);


# 释放：
            // 释放一个链表，如果节点有手动分配的内存，则需要调用g_slist_free_full函数自行释放。单链表没有创建，但append,prepend,insert动作均暗含创建操作，因此只要链表不为空，就需要调用本接口释放该链表
      void g_slist_free(GSList *list);
            // 释放一个节点，该节点往往来自g_slist_remove_link，因为后者不会自动释放内存
      void g_slist_free_1(GSList *list);
            // 释放一个链表，且自定义释放节点中的内存
      void g_slist_free_full (GSList *list,GDestroyNotify free_func);

# 测长：
            // 链表中节点的个数
      guint g_slist_length(GSList *list);


# 拷贝：
            // 链表浅拷贝，如果节点有手动分配的内存，则必须使用深拷贝
      GSList* g_slist_copy(GSList *list);
            // 链表深拷贝，拷贝的具体实现函数由使用者提供。使用本函数拷贝的链表，必须使用g_slist_free_full释放链表节点
      GSList* g_slist_copy_deep(GSList *list,GCopyFunc func,gpointer user_data);


# 反转：
            // 反转链表，slist = g_slist_reverse(slist);返回值可以返回给原链表头
      GSList* g_slist_reverse (GSList *list);


# 排序：
            // 和g_slist_sort_with_data非常相似
      GSList* g_slist_insert_sorted_with_data (GSList *list,gpointer data,GCompareDataFunc func,gpointer user_data);
            // 使用给定的比较函数对链表进行排序
      GSList* g_slist_sort(GSList *list,GCompareFunc compare_func);
            // 使用给定的比较函数对链表进行排序，在比较时接受用户传入数据
      GSList* g_slist_sort_with_data(GSList *list,GCompareDataFunc compare_func,gpointer user_data);
            // 将两个链表合并成一个链表，合并后的链表可以直接释放
      GSList* g_slist_concat(GSList *list1,GSList *list2);


# 遍历：
            // 遍历方法自己实现，原型为void(*GFunc)(gpointer data, gpointer user_data);第一个参数为GSList节点的data元素，第二个参数由g_slist_foreach传入
      void g_slist_foreach (GSList *list,GFunc func,gpointer user_data);


#查找：
            // 节点查找
      GSList* g_slist_find(GSList *list,gconstpointer data);
            // 节点查找，自定义查找方式
      GSList* g_slist_find_custom (GSList *list,gconstpointer data,GCompareFunc func);
            // 返回某一节点的位置，在对比时由于采用的是list==llink方式，因此对于自定义数据无法支持，需要自己扩充实现一个g_slist_position_custom函数
      gint g_slist_position(GSList *list,GSList *llink);
            // 根据节点值返回某一节点在链表中的位置，该函数不能很好地支持自定义数据，需要扩充一个g_slist_index_custom函数
      gint g_slist_index (GSList *list,gconstpointer data);
            // 单链表遍历到尾部获取到最后一个节点
      GSList* g_slist_last(GSList *list);
            // 返回下一个节点
      GSList* g_slist_next(GSList *list);
            // 查找第n个节点，节点从0开始计数
      GSList* g_slist_nth (GSList *list,guint n);
            // 同g_slist_nth_data，返回的是节点的数据而非整个节点
      gpointer g_slist_nth_data(GSList *list,guint n);


      void g_slist_push_allocator(gpointer dummy);
      void g_slist_pop_allocator (void);
*/

void test_slist_1(void);
void test_slist_2(void);
void test_slist_3(void);
gint find_num(gconstpointer l, gconstpointer data);
void test_slist_4(void);
gint sort(gconstpointer p1, gconstpointer p2);
gint sort_r(gconstpointer p1, gconstpointer p2);
void test_slist_5(void);
void print(gpointer p1, gpointer p2);
void test_slist_6(void);
