#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void const_test(const int *a/* ֻ���� �������*/)
{
	*((int*)a) = 10;  //��һ��const ��c�����к��޵�λ�� �ڶ��� C������ǿת��������ת��
}

void const_test2(int *const a, int *buf)
{
	//a++; 
	*a = 20;
}

void const_test3(const int * const a)
{
	//a++;
	//*a = 20;
}

int main(void)
{
	int a = 10;
	const int b ; //������ֻ�����ԡ�

 //   int *p = &b;

	//*p = 30;

	//printf("%d\n ", b);

	//b = a;
	//a = b;  //const һ�� ��ȫ�Խϸߵ����ԣ� ��ȫ�Խϸߵ� ����һ�� ��ȫ�Ե͵ġ�
	//b = a;

	return 0;
}