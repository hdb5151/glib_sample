#pragma once
#include <glib.h>

/**
 *
 * 创建
 *    // 创建指针数组
 * GPtrArray *	g_ptr_array_new ()
 *    // 创建指针数组，但先设置最大长度，此举可以避免在添加元素时频繁的内存申请。
 * GPtrArray *	g_ptr_array_sized_new ()
 *    // 创建带有释放函数的指针数组，当g_ptr_array_free释放数组时，释放函数会被调到。
 * GPtrArray *	g_ptr_array_new_with_free_func ()
 *    // 相当于g_ptr_array_sized_new+g_ptr_array_new_with_free_func
 * GPtrArray *	g_ptr_array_new_full ()
 *    // 设置指针数组的最大长度，g_ptr_array_new和g_ptr_array_set_size等价于g_ptr_array_sized_new
 * void	g_ptr_array_set_size ()
 *
 * 释放
 *    // 数组释放，本函数不会自动释放数组元素中的数据。
 * gpointer *	g_ptr_array_free ()
 *
 * 插入
 *    // 将数据data追加到数组尾。数组会自动扩容。
 * void g_ptr_array_add (GPtrArray *array,gpointer data);
 *    // 将数据data插入到指定下标位置。数组会自动扩容。
 * void g_ptr_array_insert (GPtrArray *array,gint index_,gpointer data);
 *
 * 访问
 *    // 根据数组元素的下标得到数组元素的值
 * #define	g_ptr_array_index()
 *
 * 遍历
 *    // 对指针数组按照给定的遍历函数进行遍历
 * void g_ptr_array_foreach (GPtrArray *array,GFunc func,gpointer user_data);
 *
 *
 * 移除
 *    // 移除第一次出现的数组元素，后面的元素依次补齐。如果GDestroyNotify释放函数不为空，则该释放函数会被调用。
 * gboolean g_ptr_array_remove (GPtrArray *array,gpointer data);
 *    // 按数组下标移除元素，后面的元素依次补齐。如果GDestroyNotify释放函数不为空，则该释放函数会被调用。
 * gpointer g_ptr_array_remove_index (GPtrArray *array,guint index_);
 *    // 快速移除第一次出现的数组元素，后面的元素不会依次补齐，而是最后一个元素直接补此空缺。如果GDestroyNotify释放函数不为空，则该释放函数会被调用。
 * gboolean g_ptr_array_remove_fast (GPtrArray *array,gpointer data);
 *    // 按数组下标快速移除第一次出现的数组元素，后面的元素不会依次补齐，而是最后一个元素直接补此空缺。如果GDestroyNotify释放函数不为空，则该释放函数会被调用。
 * gpointer g_ptr_array_remove_index_fast (GPtrArray *array,guint index_);
 *    // 按数组下标移除多个数组元素，后面的元素会补齐被移除后的空缺位置。如果GDestroyNotify释放函数不为空，则该释放函数会被调用。
 * GPtrArray *    g_ptr_array_remove_range (GPtrArray *array,guint index_,guint length);
 *
 *
 * 查找
 *
 * gboolean g_ptr_array_find ()
 * gboolean g_ptr_array_find_with_equal_func ()
 *
 * 排序
 *    // 对指针数组进行排序，排序函数由用户指定。
 * void	g_ptr_array_sort ()     // * 比较函数不将数组中的指针作为参数，而是将指向数组中指针的指针作为参数。
 *    // 与g_ptr_array_sort功能相同，排序函数带用户自定义参数。
 * void	g_ptr_array_sort_with_data ()
 *
 *
 *
 *
 */

static void _ptr_array_free_func(gpointer data);
static void _ptr_array_foreach_print_func(gpointer data, gpointer user_data);
void ptr_array_creat_foreach(void);
void ptr_array_remove(void);
void ptr_array_find(void);
