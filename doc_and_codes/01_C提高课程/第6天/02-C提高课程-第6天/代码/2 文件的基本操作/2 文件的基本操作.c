#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//����һ�� �ļ�ָ��
	FILE *fp = NULL;

	//fp = fopen("c:\\test\\test1.txt", "w"); // \ ֻ��windows���� 
	fp = fopen("c:/test/test1.txt", "w");//   ��/��  ��windosw��linux ������
	if (fp == NULL) {
		fprintf(stderr, "open file error\n");
		return 0;
	}
	else {
		printf("open file succ!\n");
	}

	if (fp != NULL) {
		fclose(fp);
	}

	fp = fopen("c:/test/test2.txt", "r+");
	if (fp == NULL) {
		fprintf(stderr, "open file test2.txt error\n");
		return 0;
	}
	else {
		printf("open text2 succ!\n");
	}
	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}