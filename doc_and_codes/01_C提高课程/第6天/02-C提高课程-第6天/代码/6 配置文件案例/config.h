#ifndef _CONFIG_H_
#define _CONFIG_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define IN
#define OUT
#define KEY_LEN			(64)
#define VALUE_LEN		(128)
#define FILE_MAX_LEN	(4096*100)
#define LINE_MAX_LEN (4096)


	//写配置文件的接口 key=value的格式 
/*
写配置文件  key=value 格式
file_name:
key:
value:
value_len:

return -1 失败 
           0 成功
*/
int write_config(IN const char *file_name, IN const char *key, IN const char *value, IN const int value_len);
 int read_config(IN const char *file_name, IN const char *key, OUT char *value, OUT int *value_len);

 int getKeyByValue(char *keyvaluebuf, const char *keybuf, char *valuebuf, int *valuebuflen);
 int trimSpace(char *inbuf, char *outbuf);



#endif