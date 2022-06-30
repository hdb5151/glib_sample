#include <gst/gst.h>
#include <glib.h>
#include <stdio.h>
#include <cuda_runtime_api.h>
#include "gstnvdsmeta.h"

typedef struct {
    guint original_idx;
    guint data;
} splitType;

typedef struct {
    guint int_num;
    guint str_num;
    guint ori_idx[9];
    gchar *str[9];
    splitType int_[9];
    gboolean full_to_int;
    gboolean is_equals;
} splitToint;

splitToint strsplit_toint(gchar *str, const gchar *split, guint splitLen, gboolean doSort) {
    splitToint tempsplit;
    tempsplit.int_num = 0;
    tempsplit.str_num = 0;
    tempsplit.is_equals = false;
    guint int_temp;
    guint ori_idx;
    gchar *str_temp;
    gchar **t_str, **gie_str;
    gchar *end_ptr = NULL;

    t_str = g_strsplit(str, split, splitLen);
    for (guint idx = 0; t_str[idx] != NULL; idx++) { //字符串 切片
        // tempsplit.ori_idx = idx;                     //原始序列
        tempsplit.str_num++;
        tempsplit.str[idx] = g_strdup(t_str[idx]);
        if (g_ascii_isdigit(tempsplit.str[idx][0])) {
            tempsplit.int_[idx].data = g_ascii_strtoull(tempsplit.str[idx], &end_ptr, 10); //字符串转换为 整形
            tempsplit.int_num++;
            tempsplit.int_[idx].original_idx = idx;
        }
        // if (tempsplit.int_[idx].data) {
        //     tempsplit.int_num++;
        //     tempsplit.int_[idx].original_idx = idx;
        // }
        // g_print("the split -- strr[%d] = %d\n", idx, tempsplit.int_[idx]);
    }
    if (tempsplit.str_num != tempsplit.int_num) {
        tempsplit.full_to_int = FALSE;
    } else if (doSort == true) { // 切片获取的字符串 都可以转换成 整形. 则对获得的整形进行 "由小到大"的排序, 如果过程中发现有两个相同的数据
        tempsplit.full_to_int = true;
        for (guint i = 0; i < tempsplit.int_num; i++) { // 进行排序
            for (guint j = 0; j < tempsplit.int_num - i - 1; j++) {
                if (tempsplit.int_[j].data > tempsplit.int_[j + 1].data) {
                    int_temp = tempsplit.int_[j].data;
                    tempsplit.int_[j].data = tempsplit.int_[j + 1].data;
                    tempsplit.int_[j + 1].data = int_temp;
                    ori_idx = tempsplit.int_[j].original_idx;
                    tempsplit.int_[j].original_idx = tempsplit.int_[j + 1].original_idx;
                    tempsplit.int_[j + 1].original_idx = ori_idx;

                    str_temp = tempsplit.str[j];
                    tempsplit.str[j] = tempsplit.str[j + 1];
                    tempsplit.str[j + 1] = str_temp;
                } else if (tempsplit.int_[j].data == tempsplit.int_[j + 1].data) {
                    tempsplit.is_equals = true;
                }
            }
        }
    }
    g_strfreev(t_str);
    return tempsplit;
}

gchar *stream_type_list = "4,3";
gchar *gie_id_list = "1:2,3:0:0";

int main_test(int argc, char *argv[]) {
    GMainLoop *loop = NULL;

    splitToint spt_stream_type, spt_gie_list, spt_gie_id;
    guint a = 1, b = 2, c = 3, d = 4;
    // gchar *strr = "2,aa,17";
    spt_stream_type = strsplit_toint(stream_type_list, ",", 5, TRUE);
    if (spt_stream_type.full_to_int == true) {
        if (spt_stream_type.is_equals == false) {
        } else {
            g_print("stream_type_list quantity mismatch\r\n");
        }
    } else {
        g_print("stream_type_list has invalid value \r\n");
    }

    spt_gie_list = strsplit_toint(gie_id_list, ",", 5, FALSE);
    if (spt_gie_list.full_to_int == true) {
        if (spt_gie_list.is_equals == false && spt_gie_list.int_num == spt_stream_type.int_num) {
        } else {
            g_print("gie_id_list quantity mismatch \r\n");
        }
    } else {
        g_print("gie_id_list has invalid value \r\n");
    }

    // spt_gie_id = strsplit_toint();

    for (guint ii = 0; ii < spt_stream_type.int_num; ii++) {
        guint gie_idx = spt_stream_type.int_[ii].original_idx;
        spt_gie_id = strsplit_toint(spt_gie_list.str[gie_idx], ":", 5, TRUE);
        if (spt_gie_id.full_to_int == true) {
            if (spt_gie_id.is_equals == false) {
            } else {
                g_print("-----------gie_id quantity mismatch \r\n");
            }
        } else {
            g_print("---------------gie_id has invalid value \r\n");
        }
        g_print("the spt_stream_type[%d] = %d -- %s .!. int-num= %d -- str-num= %d .!. full_to_int= %d -- is_equals= %d -- ori-idx=%d\r\n",
                ii, spt_stream_type.int_[ii].data, spt_stream_type.str[ii], spt_stream_type.int_num, spt_stream_type.str_num, spt_stream_type.full_to_int, spt_stream_type.is_equals, spt_stream_type.int_[ii].original_idx);
        for (guint jj = 0; jj < spt_gie_id.int_num; jj++) {
            g_print("the spt_gie_id[%d] = %d -- %s .!. int-num= %d -- str-num= %d .!. full_to_int= %d -- is_equals= %d -- ori-idx=%d\r\n",
                    jj, spt_gie_id.int_[jj].data, spt_gie_id.str[jj], spt_gie_id.int_num, spt_gie_id.str_num, spt_gie_id.full_to_int, spt_gie_id.is_equals, spt_gie_id.int_[jj].original_idx);
        }
    }
    // g_assert_cmpuint(1, ==, 3);
    g_assert_false(false);
    if (a == 1)
        goto A;
A : {
    g_print("do A \n");
}

    // if (b == 12)
    //     goto B;
B : {
    g_print("do B \n");
}
    if (c == 3)
        goto C;

    if (d == 4)
        goto D;
D : {
    g_print("do D \n");
}
C : {
    g_print("do C \n");
    // return 0;
}
    g_print("ending\n");
    gst_init(&argc, &argv);
    loop = g_main_loop_new(NULL, FALSE);

    // g_main_loop_run(loop);
    // g_main_loop_unref(loop);
}
