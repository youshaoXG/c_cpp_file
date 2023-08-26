/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
	printf("hello...\n");
	system("pause");
	return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int demo_fgetc() {
	//定义一个 文件指针
	FILE *fp = NULL;
	char *fileName = "E:\\Repository\\myPrivateRepository\\studynotes\\c_cpp\\文件操作专题\\02.按照字符读写文件\\1.txt";	// \ 只对windows可用
	char *fileName2 = "E:/Repository/myPrivateRepository/studynotes/c_cpp/文件操作专题/02.按照字符读写文件/1.txt";	// 以后统一用45°
	char *fileName3 = "./1.txt";	// 相对路径
	char arr[50] = "asdhjkcjzdsadasd123.;',";
	fp = fopen(fileName3, "w");
	if (fp == NULL) {
		//printf("func fopen() err:%d \n", fp);
		fprintf(stderr, "open file error\n");
		return -1;
	}
	else {
		printf("open file success!\n");
	}

	if (fp != NULL) {
		fclose(fp);
	}

	fp = fopen(fileName3, "r+");
	if (fp == NULL) {
		fprintf(stderr, "open file test2.txt error\n");
		return -1;
	}
	else {
		printf("open file success!\n");
	}

	while (!feof(fp)) {
		char tmpc = fgetc(fp);
		printf("%c", tmpc);
	}

	if (fp != NULL) {
		fclose(fp);
	}
}

int main() {
	demo_fgetc();

	printf("hello...\n");
	system("pause");
	return 0;
}