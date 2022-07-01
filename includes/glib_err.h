#include "glib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
struct GError {
  GQuark       domain;
  gint         code;
  gchar       *message;
};




# 错误系统:
            // 创建一个GError对象
      GError * 	g_error_new ()
            // 创建一个GError对象，可包含非printf打印字符
      GError * 	g_error_new_literal ()
            // 创建一个GError对象，参数来自va_list
      GError * 	g_error_new_valist ()
            // 释放一个创建的GError对象
      void 	g_error_free ()
            // 拷贝一个GError对象。注意这是一个深拷贝，由于GError的message成员是一个指针，因此在进行拷贝时，会申请新的内存。
      GError * 	g_error_copy ()
            // 是否匹配给定的错误域及错误码
      gboolean 	g_error_matches ()
            // 向GError系统设置一个错误对象
      void 	g_set_error ()
            // 设置错误对象，可包含非printf打印字符
      void 	g_set_error_literal ()
            // 传递一个错误对象，如果目的参数参数为空，则释放源错误，如果目的参数非空，则将源参数地址赋值给目的参数
      void 	g_propagate_error ()
            // 清空GError对象
      void 	g_clear_error ()
            // 将字符串加到一个已存在的GError对象上
      void 	g_prefix_error ()
            // g_propagate_error与g_prefix_error的组合
      void 	g_propagate_prefixed_error ()


# 警告和断言：

            // 输出，默认输出到stdout，如果设置了输出句柄函数，则调用该句柄函数，由句柄函数决定输出到何处
      void 	g_print ()
            // 设置输出句柄，改变默认输出行为
      GPrintFunc 	g_set_print_handler ()
      void 	(*GPrintFunc) ()
            // 错误输出，默认输出到stderr，如果设置了错误信息输出句柄，则调用该句柄函数，由句柄函数决定输出到何处
      void 	g_printerr ()
            // 设置错误输出句柄，改变默认错误输出行为
      GPrintFunc 	g_set_printerr_handler ()
            // 如果表达式为假则返回，无返回值，在void类型的函数中被调用。
      #define 	g_return_if_fail()
            // 如果表达式为假则返回，带返回值
      #define 	g_return_val_if_fail()
            // 当运行到本句时立即返回，无返回值，在void类型的函数中被调用。
      #define 	g_return_if_reached
            // 当运行到本句时立即返回，有返回值
      #define 	g_return_val_if_reached()
            // 不返回，只告警
      #define 	g_warn_if_fail()
            // 运行到本句时不返回，只告警
      #define 	g_warn_if_reached
            // 出现错误时提示，退出，挂起，打印堆栈，返回
      void 	g_on_error_query ()
            // 跟踪堆栈信息
      void 	g_on_error_stack_trace ()
            // 打印一个断点，当运行到本句时，产生一个SIGRAP的信号，并退出函数。
      #define 	G_BREAKPOINT
*/