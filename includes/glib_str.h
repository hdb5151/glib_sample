#pragma once
#include <glib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief
"ASCII字符判断"
      gboolean 	g_str_is_ascii ()       // 判断一个字符串是否全部由ascii字符组成
      gboolean 	g_ascii_isalnum ()      // 一个字符是否为字母或数字组成
      gboolean 	g_ascii_isalpha ()      // 一个字符是否为字母
      gboolean 	g_ascii_iscntrl ()      // 一个字符是否为控制字符
      gboolean 	g_ascii_isdigit ()      // 一个字符是否为数字
      gboolean 	g_ascii_isgraph ()      // 一个字符是否为图形字符
      gboolean 	g_ascii_islower ()      // 一个字符是否为小写字母
      gboolean 	g_ascii_isprint ()      // 一个字符是否为可打印字符
      gboolean 	g_ascii_ispunct ()      // 一个字符是否为标点符号
      gboolean 	g_ascii_isspace ()      // 一个字符是否为空格
      gboolean 	g_ascii_isupper ()      // 一个字符是否为大写字母
      gboolean 	g_ascii_isxdigit ()     // 一个字符是否为十六进制数字

"格式化字符串"
      g_printf_xxx函数族，类似于printf。
      引用本函数族，需要包含glib/gprintf.h头文件
      gint 	g_printf ()
      gint 	g_vprintf ()
      gint 	g_fprintf ()
      gint 	g_vfprintf ()
      gint 	g_sprintf ()
      gint 	g_vsprintf ()
      gint 	g_snprintf ()
      gint 	g_vsnprintf ()
      gint 	g_vasprintf ()

"复制"
      gchar * 	g_strnfill (gsize length, gchar fill_char)  // 申请指定长度的字符串，以给定的字符进行填充。注意返回值需要自行释放！
      gchar * 	g_stpcpy (gchar *dest, const char *src)  // 类似于strcpy()，会将字符串结束符也拷贝进去。如果dest长度小于src，则会导致内存泄露。
      gchar * 	g_strdup (const gchar *str)  // 同strdup --> 申请一定长度的字符串，复制*str内容到 申请的字符串中， 返回 申请的字符串，通常需要手动调用函数g_free(gchar *)释放内存
      gchar * 	g_strndup ()  // 同strndup
      gchar ** 	g_strdupv (gchar **str_array)  // 深拷贝一个数组，返回的数组不使用时一定要释放内存。可以使用g_strfreev函数。
      gsize 	g_strlcpy (gchar *dest, const gchar *src, gsize dest_size) //安全拷贝一个字符串。dest_size指dest的长度，最多拷贝dest_size-1个长度的字节到dest，结尾补'\0'，如果src长度小于dest_size，则只会拷贝strlen(src)长度。
      gchar * 	g_strdup_printf (const gchar *format, ...)  // 字符串拼接然后复制。注意返回值需要释放。
      gchar * 	g_strdup_vprintf (const gchar *format,va_list args)  // 多字符串拼接然后复制。注意返回值需要释放。

"查找"
      gchar * 	g_strstr_len (const gchar *haystack, gssize haystack_len, const gchar *needle) // 同strstr，在haystack中遍历haystack_len长度，如果找到了needle字串，则返回这个位置的指针，如果没有找到则返回NULL。
      gchar * 	g_strrstr (const gchar *haystack, const gchar *needle) // 同strrstr
      gchar * 	g_strrstr_len (gchar *haystack, gssize haystack_len, gchar *needle) // 同strrstr，在前 haystack_len 个字符中进行查找，如果haystack_len=-1，则在整个字符串中查找
      gboolean 	g_str_has_prefix (const gchar *str, const gchar *prefix) // 字符串str是否有前缀 prefix
      gboolean 	g_str_has_suffix () // 字符串是否有后缀
      gboolean 	g_strv_contains (const gchar * const *strv, const gchar *str) // 在数组中查找是否有指定字符串。注意此接口在2.44版本之后才有。
      gboolean 	g_str_match_string (const gchar *search_term, const gchar *potential_hit, gboolean accept_alternates)  // 字符串匹配。注意此接口并不仅仅支持ASCII字符串，还可支持非ASCII字符，还可识别单词。

"比较"
      int 	g_strcmp0 (const char *str1, const char *str2)  //同strcmp，但允许参数为空。注意C语言标准strcmp函数如果传入的参数为空可能会产生段错误。
      gint 	g_strcasecmp () // 已废弃，请使用以下两个接口
      gint 	g_strncasecmp () // 已废弃，请使用以下两个接口
      gint 	g_ascii_strcasecmp (const gchar *s1, const gchar *s2) // 同strcasecmp和strncasecmp。允许参数为空。
      gint 	g_ascii_strncasecmp (const gchar *s1, const gchar *s2,gsize n)  // 同strcasecmp和strncasecmp。允许参数为空。

"格式转换"
      gchar * 	g_str_to_ascii (const gchar *str, const gchar *from_locale) // utf-8字符串转换成纯ascii字符串
      gchar * 	g_ascii_strup (const gchar *str, gssize len)  // 字符串里面的小写字母全部转换成大写。返回的字符串是新的内存空间，需要调用者自己释放该内存。
      gchar * 	g_ascii_strdown (const gchar *str, gssize len)  // 字符串里面的大写字母全部转换成小写。返回的字符串是新的内存空间，需要调用者自己释放该内存。
      gchar 	g_ascii_toupper (gchar c)  // 单个字符转换成大写
      gchar 	g_ascii_tolower (gchar c)  // 单个字符转换成小写
      GString * 	g_string_ascii_up (GString *string)  // 将GString类型的字符串所有小写字母转换成大写，转换完之后的字符串仍保存在GString变量，没有申请新的内存空间。
      GString * 	g_string_ascii_down (GString *string)  // 将GString类型的字符串所有大写字母转换成小写，转换完之后的字符串仍保存在GString变量，没有申请新的内存空间。

      gchar * 	g_strup ()  // 已废弃函数，请使用g_ascii_strup()或g_utf8_strup()
      gchar * 	g_strdown ()  // 已废弃函数，请使用g_ascii_strdown()或g_utf8_strdown()

"进制转换"
      gint64 	g_ascii_strtoll ()  // 字符串转换成64位整数
      guint64 	g_ascii_strtoull ()  // 字符串转换成64位无符号整数
      gdouble 	g_ascii_strtod () // 字符串转换成浮点型
      gchar * 	g_ascii_dtostr ()  // 浮点型转换成字符串
      gchar * 	g_ascii_formatd ()  // 浮点型转换成字符串，且可以按照指定格式转换
      gdouble 	g_strtod ()  // 类似于g_ascii_strtod，但本接口不如g_ascii_strtod常用

"反转-逆序"
      gchar * 	g_strreverse ()  // 字符串逆序

"连接"
      gsize 	g_strlcat (gchar *dest,const gchar  *src,gsize dest_size)  // 将src拷贝到dest中，最后一个参数是dest的长度，如果dest_size长度超过dest的实际长度，则会导致内存泄露。如果多次调用strlcat，则需要保证dest内存足够。如果src过长，则只会拷贝dest_size-1长度到dest，结尾补'\0'。
      gchar * 	g_strconcat (const gchar *string1, ...)  // 将多个字符串拼接到一起，注意最后一个参数要为NULL。本函数会开辟新的内存空间，返回的字符串需要调用者自行释放内存。
      gchar * 	g_strjoin (const gchar  *separator, ..)  // 与g_strconcat相似，将多个字符串拼接到一起，但比g_strconcat多一个功能，即在每个拼接处插入一个分隔字符串。注意最后一个参数要为NULL。本函数也需要使用者自行释放返回的内存。
      gchar * 	g_strjoinv (const gchar  *separator,gchar **str_array)  // 同g_strjoin，参数为字符串数组，该数组的最后一个元素需要为NULL，否则得到的字符串不是以'\0'结尾。返回值需要自行释放。

"去除空格"
      // 去除头、尾、头和尾的空格
      gchar * 	g_strchug ()
      gchar * 	g_strchomp ()
      #define 	g_strstrip()

"分隔"

      gchar ** g_strsplit (const gchar *string,const gchar *delimiter,gint max_tokens);  // 字符串分隔，返回的是字符串数组，需要用户自行释放内存。delimiter是分隔符，可以是单个字符，也可以是多个字符，如果是多个字符，需要保证字符的唯一性，如：不能以;;这种作为分隔符，否则会有意想不到的效果。max_tokens是最大分隔数，如果string中有多个分隔符，分隔到max_tokens个数后后面的就不再分隔，作为一个整体串存到字符串数组中。
      gchar **g_strsplit_set (const gchar *string,const gchar *delimiters,gint max_tokens);  // g_strsplit_set和g_strsplit具有相同的参数，但第二个参数含义是分隔符集，每一个字符都是一个分隔符，其他和g_strsplit相同。

"替换"
      gchar * g_strcanon (gchar *string,const gchar *valid_chars,gchar substitutor);  // 如果string中的字符是valid_chars字符串中的字符，则不替换，否则逐个替换成新的substitutor字符。本接口不申请新的内存，第一个参数请不要传入常量字符串，返回值是string字符串的地址。
      gchar * g_strdelimit (gchar *string,const gchar *delimiters,char new_delimiter);  // 如果string中的字符是delimiters字符串中的字符，则替换成新的new_delimiter字符，否则不替换。本接口不申请新的内存，第一个参数请不要传入常量字符串，返回值是string字符串地址。

"字符串数组测长"
      guint 	g_strv_length ()  // 对字符串数组进行测长

"转义字符处理"
      // g_strescape是将字符串中的'\b', '\f', '\n', '\r', '\t', '\v', '\' '"'这些特殊字符前面加一个'\'。如char str[16] = {'a', '\n', 'b'};，调用g_strescape后，返回的数组为str_ret[]={'a', '\\', 'n', 'b'};。由于转义前后字符串长度发生了变化，因此返回的字符串是一个新的字符串，需要调用者自行释放内存。g_strescape的第二个参数是指在转义过程中保留的特殊字符，即这些字符不会被转义保存。g_strcompress是g_strescape的逆运算，将转义后的字符串再重新转回去。
      gchar * 	g_strescape ()
      gchar * 	g_strcompress ()

"其他"
      void 	g_strfreev ()  // 释放字符串数组专用函数
      const gchar * 	g_strerror ()  // 同strerror，将errno转换为字符串形式
      const gchar * 	g_strsignal ()
      gchar ** 	g_str_tokenize_and_fold ()
      gsize 	g_printf_string_upper_bound ()
      gint 	g_ascii_digit_value ()
      gint 	g_ascii_xdigit_value ()

可在 网址： https : // blog.csdn.net/andylauren/article/details/79383437 中查询API使用
*/
/* -------------------------------------------------------------*/

#ifdef hello
https : // www.cnblogs.com/tears-of-ramos/p/3929175.html
#define MAX_LEN 100
        gchar *
        demo(char *msg, ...)
{
      gchar *pcfgfile = NULL, *para = NULL;
      va_list argp;
      va_start(argp, msg); // msg其实指的是第一个参数，这个函数是让argp指向demo实参的栈底，参数是按从右往左的顺序压入栈的，argp不包含msg
      pcfgfile = g_strdup_vprintf("%s %s %s %d", argp);
      va_end(argp);
      return pcfgfile;
}
int main(void)
{
      gchar *pfilename = "houjiao";
      gchar *strdouble = "11.11";
      gchar *strint = "123456;8910";
      gchar *test_str = NULL, *hj = NULL;
      gint len = 0;
      gchar buff_str[MAX_LEN + 1];
      guint64 imsi = 123456789;
      gdouble test_duble = 0.0;
      gchar **str_array = NULL;

      //----------------------------------------------------------一 ------------------------------------------------------------------------
      //下面的这些函数会返回一个新的字符串缓冲区的指针，所以你在使用完后必须要释放它们。
      //--------------------------------------------------------------------------------------------------------------------------------------
      /*
      gchar *g_strdup(const gchar *str)
      复制str并返回它的一个拷贝。并非返回原来字符串的指针而是重新申请一块内存将其指针返回。
  hj = g_strdup(pfilename);
  test_str = g_strdup(hj);
  g_free(hj);
  hj = NULL;
  g_print("%s\n", test_str); //输出good

  /*
  gchar *strnfill(gsize length, gchar *fill_char)
  创建一个长度为length并被fill_char填充的字符串。如果fill_char为0则创建一个空字符串 */
      test_str = g_strnfill(10, 0);
      g_print("%s\n", test_str);
      g_free(test_str);
      test_str = NULL;

      /*
      gchar *g_strdup_printf(const gchar *format, ...)
      像sprintf()一样格式化字符串和参数。但是，你没必要像sprintf()一样创建和指定一个缓冲区，GLib将这些自动做了。适合用于字符串拼 */
      test_str = g_strdup_printf("%s_%u", pfilename, 1);
      g_print("%s\n", test_str);

      /*测试g_strdup_vprintf的拼接功能 类似上面g_strdup_printf函数的功能*/
      test_str = demo("", "hj", "is", "number", 1); //输出this is a demo！
      g_print("%s\n", test_str);
      g_free(test_str);
      test_str = NULL;

      /*
      gchar *g_strconcat(const gchar *string1, ..., NULL)
      它接受任意数量的string作为参数，并返回它们的连接后的字符串。必须将NULL作为这个函数的最后一个参数 */
      hj = g_strdup(pfilename);
      test_str = g_strconcat("   ", hj, ":", "good person", NULL); //输出   houjiao:good person
      g_print("%s\n", test_str);
      g_free(test_str);
      test_str = NULL;

      //----------------------------------------------------------二 ------------------------------------------------------------------------
      //在下面的函数中，你应该为返回的结果申请空间。GLib并不会返回一个拷贝给你。它们与C相对应的函数非常像，参数要包含一个足够大的缓冲区来进行字符串处理。
      //--------------------------------------------------------------------------------------------------------------------------------------
      /*
      gchar *g_stpcpy(gchar *dest, const gchar *src)
      拷贝src到dest，包括最后的NULL字符。如果它执行成功，会返回dest中结束符拷贝的指针。*/
      test_str = (gchar *)g_malloc0(strlen(hj));
      g_stpcpy(test_str, hj);    //函数返回的是结束符拷贝的指针这里即返回空字符串
      g_print("%s\n", test_str); //输出，good
      g_slice_free1(strlen(hj), test_str);
      test_str = NULL;

      /*
      gint g_snprintf(gchar *string, gulong n, const gchar *format, ...)
      你必须确保string有足够大的空间。而且你必须要用n来指定这个缓冲区的大小。返回值是输出字符串的长度，也有可能这个输出字符串为了适应缓冲区的大小而被截断 */
      len += g_snprintf(buff_str + len, MAX_LEN - len, "%d,%d,%d,%" G_GINT64_FORMAT "", 1, 2, 3, imsi);
      g_print("%s\n", buff_str); //输出1，2,3,123456789

      /*测试g_strchug删除字符串开始的空格*/
      test_str = g_strconcat("   ", hj, ":", "good person     ", NULL);
      test_str = g_strchug(test_str); //输出houjiao:good person     光标在这
      g_print("%s\n", test_str);

      /*
      gchar *g_strchomp(gchar *string)
      将string结尾的空格都删掉，返回string */
      test_str = g_strchomp(test_str);
      g_print("%s\n", test_str); // houjiao:good person
      g_free(test_str);
      test_str = NULL;

      /*
      gchar *g_strstrip(gchar *string)
      将string开头和结尾的空白字符都删掉，返回string。*/
      test_str = g_strconcat("   ", hj, ":", "good person     ", NULL);
      test_str = g_strstrip(test_str);
      g_print("%s\n", test_str); //输出houjiao:good person

      /*
      gchar *g_strdelimit(gchar *string, const gchar *delimiters, gchar *new_delimiter)
      将string中的delimiters各个字符都替换为new_delimiter这一个字符 */
      test_str = g_strdelimit(test_str, "good", 'a');
      g_print("%s\n", test_str); // haujiaa:aaaa persan
      g_free(test_str);
      test_str = NULL;

      //----------------------------------------------------------三、 ------------------------------------------------------------------------
      //在下面的函数中，除了g_ascii_dtostr()之外，都不改变它们的参数。
      //--------------------------------------------------------------------------------------------------------------------------------------

      /*
      gchar *g_strstr_len(const gchar *haystack, gssize haystack_len, const gchar *needle)
      在haystack中遍历haystack_len长度，如果找到了needle字串，则返回这个位置的指针，如果没有找到则返回NULL。*/
      test_str = g_strstr_len(pfilename, strlen(pfilename), "jia");
      g_print("%s\n", test_str); //输出jiao
      test_str = NULL;

      /*
      gchar *g_strrstr(const gchar *haystack, const gchar *needle)
      类似于g_strstr_len，这个函数将会从后面开始查找，但是它并没有haystack_len参数。 */
      test_str = g_strrstr(pfilename, "jia");
      g_print("%s\n", test_str); //输出jiao
      test_str = NULL;

      /*
      gchar *g_strrstr_len(gchar *haystack, gssize haystack_len, gchar *needle)
      与g_strrstr()相同，但是它只在前haystack_len个字符中查找,第二个参数是-1表示在整个字符串中找*/
      test_str = g_strrstr_len(pfilename, -1, "a");
      g_print("%s\n", test_str);
      test_str = g_strrstr_len(pfilename, 5, "a");
      g_print("%s\n", test_str); //输出(null)

      /*
      gdouble g_ascii_strtod(const gchar *nptr, gchar **endptr)
      将string转为双字长度的浮点数。如果你提供了一个有效的endptr指针地址，这个函数会将指针设置到string中被转换的最后一个字符的位置*/
      test_duble = g_ascii_strtod(strdouble, NULL);
      g_print("%.2f\n", test_duble); //输出11.11

      /*
      gchar **g_strsplit(const gchar *string, const gchar *delimiter, gint max_tokens)
      使用delimiter来将string切割成至多max_tokens个部分。返回值是新申请的一个字符串数组，用来保存被切割的这些部分。
      这个字符串数组必须由你自己释放。 如果输入字符串是空的，这个返回值也是一个空的数组。 该法不改变原string */
      str_array = g_strsplit(strint, ";", 3);
      g_print("%s,%s\n", str_array[0], str_array[1]); // 123456,8910

      /*
      gchar *g_str_joinv(const gchar *separator, gchar **str_array)
      将字符串数组组合成单个字符串，并将这个新申请的字符串返回。如果separator不空，g_str_joinv()会在每个字符串之间添加上一个separator分隔符。*/
      test_str = g_strjoinv(",", str_array);
      g_print("%s\n", test_str); // 123456,8910
      g_strfreev(str_array);
      str_array = NULL;
      g_free(test_str);
      test_str = NULL;

      /*测试g_ascii_strtoll将字符串转成对应整形的功能第三个参数是指的几进制*/
      test_str = strchr(strint, ';');
      len = (gint)g_ascii_strtoll(strint, NULL, 10);
      g_print("%d\n", len); //输出123456
      strint = test_str + 1;
      len = (gint)g_ascii_strtoll(strint, NULL, 10);
      g_print("%d\n", len); //输出8910
      g_free(test_str);
      test_str = NULL;
      return TRUE;
}
二、glib的主循环功能主要是为了看看主循环的串行

    /*
    自定义的事件源是一个继承 GSource 的结构体,即自定义事件源的结构体 的第一个成员是 GSource 结构体, 其后便可放置程序所需数据, 例如:*/
    typedef struct _MySource MySource;
struct _MySource
{
      GSource source;
      gchar text[256];
};
/*
实现了事件源数据结构的定义之后,还需要实现事件源所规定的接口,主要为 prepare, check, dispatch, finalize 等事件处理函数(回调函数),它们包含于 GSourceFuncs 结构体中。
将 GSourceFuncs 结构以及事件源结构的存储空间宽度作为参数传给 g_source_new 便可构造一个新的事件源,继而可使用 g_source_attach 函数将新的事件源添加到主循环上下文中
*/
static gboolean prepare(GSource *source, gint *timeout)
{
      *timeout = 0;

      return TRUE;
}

static gboolean check(GSource *source)
{
      return TRUE;
}

static gboolean dispatch(GSource *source, GSourceFunc callback, gpointer user_data)
{
      int i = 0;
      MySource *mysource = (MySource *)source;

      for (; i < 6; i++)
      {
            g_print("%s%d\n", mysource->text, i);
      }

      return TRUE;
}

g_main_loop_run 函数运行时, 会迭代访问 GMainContext 的事件源列表, 步骤大致如下 : a.g_main_loop_run 通过调用事件源的 prepare 接口并判断其返回值以确定各事件源是否作好准备。如果各事件源的 prepare 接口的返回值为 TRUE, 即表示该事件源已经作好准备, 否则表示尚未做好准备。显然, 上述程序所定义的事件源是已经作好了准备。 b.若某事件源尚未作好准备, 那么 g_main_loop 会在处理完那些已经准备好的事件后再次询问该事件源是否作好准备, 这一过程是通过调用事件源的 check 接口而实现的, 如果事件源依然未作好准备, 即 check 接口的返回 FALSE, 那么 g_main_loop_run 会让主事件循环进入睡眠状态。 主事件循环的睡眠时间是步骤 a 中遍历时间源时所统计的最小时间间隔, 例如在 prepare 接口中可以像下面这样设置时间间隔。到达一定时间后, g_main_loop_run 会唤醒主事件循环, 再次询问。如此周而复始, 直至事件源的 prepare 接口返回值为 TRUE。 int main1(void)
{
      GMainLoop *loop = g_main_loop_new(NULL, TRUE);
      GMainContext *context = g_main_loop_get_context(loop);
      GSourceFuncs source_funcs = {prepare, check, dispatch, NULL};
      GSource *source = g_source_new(&source_funcs, sizeof(MySource));

      g_sprintf(((MySource *)source)->text, "Hello world");

      g_timeout_add(100, timeout_func, loop);
      g_source_attach(source, context);
      g_source_unref(source);

      g_main_loop_run(loop);

      g_main_context_unref(context);
      g_main_loop_unref(loop);

      return 0;
}

#endif

void test_str_strnfill_func(void);
void test_str_stpcpy_func(void);
void test_str_strlcpy_func(void);
void test_str_strdup_printf_func(void);
void test_str_strstr_len_func(void);
void test_str_strrstr_func(void);
void test_str_strrstr_len_func(void);
void test_str_has_prefix_func(void);
void test_str_has_suffix_func(void);
void test_str_trans_func(void);
void test_str_strlcat_func(void);
void test_str_strconcat_func(void);
void test_str_strjoin_func(void);
void test_str_strjoinv_func(void);
void test_str_strip_space_func(void);
void test_str_split_func(void);
void test_str_split_set_func(void);
void test_str_strcanon_func(void);
void test_str_strdelimit_func(void);
void test_str_strescape_func(void);