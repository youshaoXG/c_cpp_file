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
	//����һ�� �ļ�ָ��
	FILE *fp = NULL;
	char *fileName = "E:\\Repository\\myPrivateRepository\\studynotes\\c_cpp\\�ļ�����ר��\\02.�����ַ���д�ļ�\\1.txt";	// \ ֻ��windows����
	char *fileName2 = "E:/Repository/myPrivateRepository/studynotes/c_cpp/�ļ�����ר��/02.�����ַ���д�ļ�/1.txt";	// �Ժ�ͳһ��45��
	char *fileName3 = "./1.txt";	// ���·��
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