#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void change_pointer(int **p)  //�������� int**p = &main::p;
{
	*p = (int*)0x00000000;
}

int main(void)
{
	int * p = NULL;

	change_pointer(&p);// change_pointer::p = &  main::p

	return 0;
}

#if 0
//123 д��һ��
int main(void)
{
	int *p = NULL;

	//ָ���ֱ�Ӹ�ֵ
	p = (int*)0x12345678;

	int **pp = NULL;   //����һ��  ���������� ��������һ����ָ��

	//2 ��������
	pp = &p;


	*pp = (int*)0x00000000;  //������ �� ��Ӳ���

	return 0;
}
#endif