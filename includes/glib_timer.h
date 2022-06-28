#pragma once
#include <glib.h>

/*
// 创建，创建一个计时器，当计时器不再使用时需要调用g_timer_destroy销毁计时器。
GTimer * 	g_timer_new (void)

// 启动。启动计时器，开始计时。
void 	g_timer_start (GTimer *timer)

// 停止。停止对计时器的计时，如果需要恢复，可以使用g_timer_continue函数。
void 	g_timer_stop (GTimer *timer)

// 继续。对已经停止的计时器重新计时。
void 	g_timer_continue (GTimer *timer)

// 历时。返回计时器从开始计时到现在为止运行的总时间(单位为 ”秒“)。如果计时器被停止过，停止期间的时间不会被计算在内。
gdouble 	g_timer_elapsed (GTimer *timer, gulong *microseconds)

// 重置。重置一个计时器。本函数完全可以被g_timer_start替代。当对一个正在运行的计时器调用g_timer_start时，会重置该计时器并重新计时。
void 	g_timer_reset ()

// 销毁。销毁一个计时器。
void 	g_timer_destroy (GTimer *timer)

*/

static void test_timer(void);