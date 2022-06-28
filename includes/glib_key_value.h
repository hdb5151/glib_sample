#pragma once
#include <glib.h>

/*

      GKeyFile *	g_key_file_new ()       // 创建GKeyFile对象
      void	g_key_file_free ()            // 释放GKeyFile对象
      GKeyFile *	g_key_file_ref ()       // 引用
      void	g_key_file_unref ()           // 解引用
      void	g_key_file_set_list_separator ()    // 设置值分隔符，默认分隔符为分号

// 加载数据
      gboolean	g_key_file_load_from_file ()  // 从文件加载
      gboolean	g_key_file_load_from_data ()  // 从内存加载
      gboolean	g_key_file_load_from_bytes () // 从GBytes加载
      gboolean	g_key_file_load_from_data_dirs ()   // 从默认用户目录或系统目录查找文件并加载
      gboolean	g_key_file_load_from_dirs ()  // 从指定目录搜索文件文件并加载
      gchar *	g_key_file_to_data ()   // key_file转换成字符串

// 保存
      gboolean	g_key_file_save_to_file ()    // 将key_file保存到文件

// 查找
      gboolean	g_key_file_has_group () // 是否有指定的组
      gboolean	g_key_file_has_key ()   // 是否有指定的key

// 获取get
      gchar *	g_key_file_get_start_group ()  // 获取第一个组的组名
      gchar **	g_key_file_get_groups ()       // 获取所有的组
      gchar **	g_key_file_get_keys ()         // 获取一个组下的所有键


      gchar *	g_key_file_get_value ()       // 获取本地化字符串
      gchar *	g_key_file_get_string ()

      gchar *	g_key_file_get_locale_string ()     // 获取本地化字符串

      gchar *	g_key_file_get_locale_for_key ()    // 获取键的本地化值

// 根据键获取不同类型的值
      gboolean	g_key_file_get_boolean ()
      gint	      g_key_file_get_integer ()
      gint64	g_key_file_get_int64 ()
      guint64	g_key_file_get_uint64 ()
      gdouble	g_key_file_get_double ()
// 根据键获取不同类型的多个值
      gchar **	g_key_file_get_string_list ()
      gchar **	g_key_file_get_locale_string_list ()
      gboolean *	g_key_file_get_boolean_list ()
      gint *	g_key_file_get_integer_list ()
      gdouble *	g_key_file_get_double_list ()

      gchar *	g_key_file_get_comment ()     // 获取注释

// 设置set

      void	g_key_file_set_value () // 设置值

      void	g_key_file_set_string ()      // 设置字符串

      void	g_key_file_set_locale_string ()     // 设置本地化字符串
// 设置不同格式的值
      void	g_key_file_set_boolean ()
      void	g_key_file_set_integer ()
      void	g_key_file_set_int64 ()
      void	g_key_file_set_uint64 ()
      void	g_key_file_set_double ()

// 设置不同格式的一组值
      void	g_key_file_set_string_list ()
      void	g_key_file_set_locale_string_list ()
      void	g_key_file_set_boolean_list ()
      void	g_key_file_set_integer_list ()
      void	g_key_file_set_double_list ()

      gboolean	g_key_file_set_comment ()     // 设置注释

// 删除

      gboolean	g_key_file_remove_group ()    // 删除一个组
      gboolean	g_key_file_remove_key ()      // 删除一个键
      gboolean	g_key_file_remove_comment ()  // 删除注释

*/