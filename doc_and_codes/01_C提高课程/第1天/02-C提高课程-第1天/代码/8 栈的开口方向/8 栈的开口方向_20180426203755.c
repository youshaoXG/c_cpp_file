#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a; //a����ջ�� ����ջ��Զ
	int b; //b����ջ   ����վ�ڽ�

	printf("&a: %p\n", &a);
	printf("&b: %p\n", &b);

	int buf[4] = { 0 };

	printf("&buf[0] : %p\n", &buf[0]);
	printf("&buf[1] : %p\n", &buf[1]);
	printf("&buf[2] : %p\n", &buf[2]);
	printf("&buf[3] : %p\n", &buf[3]);




	return 0;
}