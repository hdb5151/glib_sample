#pragma once
#include <glib.h>

/*
// hook链表初始化
      g_hook_list_init ()

// hook节点申请
      g_hook_alloc ()

// 节点插入
      g_hook_append()
      g_hook_prepend ()
      g_hook_insert_before ()
      g_hook_insert_sorted ()

// 节点查找
      g_hook_get ()     // 通过hook_id查找一个hook节点
      g_hook_find ()    // 查找hook节点，查找函数用户自己提供

// 查找给定的data是否在hook列表中，如果有则返回该hook节点。
      g_hook_find_data ()           // 由于本函数内部比较是直接指针比较，所以要求传入的data只能是hook节点中的对象，值相等的变量不一定是同一个变量，会导致查找失败。
      g_hook_find_func ()           // 给定func查找hook列表中是否有hook节点与此func相同(地址和值完全相等)
      g_hook_find_func_data ()      // 给定func和data，查找hook列表中是否有hook节点与此func和data都相同(地址和值都相等)
      g_hook_first_valid ()         // 返回第一个活动状态的hook节点。hook节点有活动及正在执行两种状态。
      g_hook_next_valid ()          // 返回下一个活动状态的hook节点。

// 遍历
      g_hook_list_invoke ()         // invoke函数对每个hook节点的data数据执行一遍func函数
      g_hook_list_invoke_check ()   // invoke_check函数和invoke相似，但hook回调函数返回失败则将该hook节点移出hook链表
      g_hook_list_marshal ()        // marshal函数对每个hook节点的data数据执行用户指定的marshal函数，而hook节点自身的函数不会被执行到。
      g_hook_list_marshal_check ()  // marshal_check函数和marshal函数相似，但hook回调函数返回失败则将该hook节点移出hook链表

// hook节点销毁
      g_hook_destroy () // 给定hook_id销毁一个hook节点，并调用该节点的释放函数。如果用户自定义的节点有内存，应在节点初始化时提供释放函数以释放内存。
      g_hook_destroy_link ()  // 给定一个hook节点将其移出hook链表，并调用该节点释放函数。

// 清空
      g_hook_list_clear ()    // 将hook链表中所有节点全部移出hook链表，每个节点的释放函数均被调用。

// 释放
      g_hook_free ()    // 释放一个hook链表

// 引用
      g_hook_ref ()
      g_hook_unref ()   // 计数加减一，如果引用计数为0，则该节点被释放，且节点的destroy释放函数会被调用。

// 标识
      G_HOOK_FLAGS()  // 获取一个hook节点的标识（VALID、ACTIVE、IN_CALL、UNLINKED）
      G_HOOK_IS_VALID() // hook节点是否有效（活动状态切未被销毁）
      G_HOOK_ACTIVE()   // hook节点释放为活动状态
      G_HOOK_IN_CALL()  // hook节点是否正在被执行
      G_HOOK_IS_UNLINKED()    // hook节点是否已经被销毁
*/

static void hook_func(gpointer data);
static void hook_destroy(gpointer data);
static void test_glib_ghook_insert(void);

static void hook_marshaller_func(GHook *hook, gpointer marshal_data);
static void hook1_func(gpointer data);
static void hook1_destroy(gpointer data);
static void hook2_func(gpointer data);
static void hook2_destroy(gpointer data);
static void test_glib_ghook_exec(void);

gboolean hook_marshal_func(GHook *hook, gpointer marshal_data);
static void hook3_func(gpointer data);
static void hook3_destroy(gpointer data);
static void test_glib_ghook_exec_part(void);
