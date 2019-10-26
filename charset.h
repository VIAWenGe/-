
#ifndef __CHARSET_H__
#define __CHARSET_H__

/* 以下这些宏用来判断一个UTF-8字符所占字节数 */
#define IS_ONE_BYTE(ch) 	((ch) >> 7 ? 0 : 1)
#define IS_TWO_BYTE(ch) 	((((ch) & 0xE0) == 0xC0) ? 1 : 0)
#define IS_THREE_BYTE(ch) 	((((ch) & 0xF0) == 0xE0) ? 1 : 0)
#define IS_FOUR_BYTE(ch) 	((((ch) & 0xF8) == 0xF0) ? 1 : 0)
#define IS_FIVE_BYTE(ch) 	((((ch) & 0xFC) == 0xF8) ? 1 : 0)
#define IS_SIX_BYTE(ch) 	((((ch) & 0xFE) == 0xFC) ? 1 : 0)

/* UNICODE BOM  与 错误代码 宏*/
#define	UNICODE_BE	1
#define	UNICODE_LE	2
#define	STR_NULL	3
#define	UNKNOW_CODE_TYPE	4
#define	BUF_TOO_FEW	5

typedef int codetype_t;

//显示无符号字符的二进制序列
extern void show_bits(const unsigned char c);

//获得UTF-8编码的字符串的字符个数
extern int get_utf8_length(const void *utf8_str);

//获得UNICODE转为utf8所需要的最少字节数
extern int unicode_to_utf8_need_bytes(const void *unicode_str,
			const int char_number, /* 要转换的字符数 */ 
			codetype_t ct);

//utf8编码转为UNICODE编码
extern int utf8_to_unicode(void *unicode_buf,
		const int byte_len, /* unicode 缓冲区字节数 */
		const void *utf8_buf, 
		codetype_t ct);

//UNICODE编码转为utf8编码
extern int unicode_to_utf8(void *utf8_buf, 
		const int utf8_bytes, /* utf8 缓冲区字节数 */
		const void *unicode_buf, 
		const int char_number, /* 要转换的字符数 */
		codetype_t ct);

#endif
