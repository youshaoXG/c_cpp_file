#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//
//int g_a = 100;

int main(void)
{
	int a = 10; 


	int *p = &a;

	*p = 20;	
	//ͨ������޸� a�ڴ���ֵ

	int addr = 0;

	addr = (int)&a;

	*((int*)addr) = 200;

	printf("a = %d\n", a);

	//a �ĵ�ַ �� 7339396 

	*((int*)(73339396)) = 400; //��ӵ��޸���a�ı���

	printf("&a = %d\n", &a);
	


	return 0;
}