#pragma once
#include <glib.h>
/*
      GByteArray* g_byte_array_new(void);

            // 创建字节数组，并预分配内存空间。避免之后添加元素而多次内存申请或重新调整大小。注意此时字节数组的实际长度仍为0
      GByteArray* g_byte_array_sized_new(guint reserved_size);

            // 创建字节数组，并填充为data指定的值。数组创建完后，其长度即为len
      GByteArray *g_byte_array_new_take (guint8 *data,gsize len);

            // 函数g_byte_array_new和g_byte_array_set_size组合使用等效于g_byte_array_sized_new
      GByteArray *g_byte_array_set_size (GByteArray *array,guint length);

            // 字节数组只有头插和尾插两种操作，没有insert操作
      GByteArray* g_byte_array_append (GByteArray *array,const guint8 *data,guint len);

      GByteArray* g_byte_array_prepend(GByteArray *array,const guint8 *data,guint len);

      GByteArray* g_byte_array_remove_index (GByteArray *array,guint index_);

      GByteArray* g_byte_array_remove_index_fast(GByteArray *array,guint index_);

      GByteArray* g_byte_array_remove_range (GByteArray *array,guint index_,guint length);

      void g_byte_array_sort (GByteArray *array,GCompareFunc compare_func);

      void g_byte_array_sort_with_data (GByteArray *array,GCompareDataFunc compare_func,gpointer user_data);

      GByteArray* g_byte_array_set_size (GByteArray *array,guint length);

            // 字节数组释放，如果free_segment设置为TRUE，其实际字节内容也会被释放
      guint8* g_byte_array_free (GByteArray *array,gboolean free_segment);

*/