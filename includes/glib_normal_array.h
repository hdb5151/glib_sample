#pragma once
#include <glib.h>

/**
 *
 *
 * 创建
 *
 *          //第一个参数表示该数组是否为0结尾，第二个参数表示是否清空数组，第三个参数表示每个元素的长度
 *    GArray *g_array_new (gboolean zero_terminated,gboolean clear_,guint element_size);
 *
 *          //与g_array_new相似，但可以预分配数组长度，避免多次插入数组元素时导致的内存频繁申请问题。但注意此时数组的实际长度仍是0。
 *    GArray *g_array_sized_new (gboolean zero_terminated,gboolean clear_,guint element_size,guint reserved_size);
 *
 *          //设置数组的长度。本函数和g_array_new函数相结合可以起到与g_array_sized_new相同的效果。
 *    GArray *g_array_set_size (GArray *array,guint length);
 *
 *
 * 测长
 *          //注意本函数不是得到数组的长度，而是得到数组中每一个元素的长度
 *    guint g_array_get_element_size ()
 *
 * 释放
 *          //本函数不会自动释放数组元素中的数据,如果第二个参数设置为FALSE，则需要用户自行释放数组元素，如果第二个参数设置为TRUE，则需要先调用g_array_set_clear_func函数设置数组元素的释放函数。
 *    gchar *g_array_free (GArray *array,gboolean free_segment);
 *
 *          //释放函数。当g_array_free的第二个参数设置为TRUE时，本函数将被设置，用来释放数组元素中的某些内存空间(后面有例子会讲到)。
 *    void g_array_set_clear_func ()
 *
 * 插入
 *
 *    #define g_array_append_val(a,v)        GArray * g_array_append_vals (GArray *array,gconstpointer data,guint len)
 *    #define g_array_prepend_val(a,v)       GArray * g_array_prepend_vals (GArray *array,gconstpointer data,guint len)
 *    #define g_array_insert_val(a,i,v)      GArray * g_array_insert_vals (GArray *array,guint index_,gconstpointer data,guint len)
 *
 * 访问
 *    #define g_array_index(a,t,i)
 *
 * 移除
 *    GArray *	g_array_remove_index ()
 *    GArray *	g_array_remove_index_fast ()
 *    GArray *	g_array_remove_range ()
 *
 * 引用
 *    GArray *	g_array_ref ()
 *
 * 解引用
 *    void	g_array_unref ()
 *
 * 排序
 *    void	g_array_sort ()
 *    void	g_array_sort_with_data ()
 *
 *
 *
 *
 */

void array_creat_free_(void);
void array_insert_index(void);
void array_unref_sort(void);
void array_clear(void);

static gint sort_r(gconstpointer p1, gconstpointer p2, gpointer user_data);
static gint sort(gconstpointer p1, gconstpointer p2);
static void main_array_test(void);
