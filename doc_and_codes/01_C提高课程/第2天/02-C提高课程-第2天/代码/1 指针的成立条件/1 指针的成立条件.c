#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int change_value(int *p)
{
	*p = 30; //  ������ ��  �ں������ڲ��ı� ����
}

//����1 2 д��һ�� ������ д����һ��������
//����1 д��һ�������� ��23 д��һ�� //����
int main(void)
{
	int  a = 10;  

	change_value(&a); // int *p = &a; //  ����һ �� ������ ��һ�������У� main������


	return 0;
}

/*
//����123 д��һ��������
int main(void)
{
	int a = 10; //һ������

	int *p = NULL; //��һ������     ����һ:Ҫ����������������������һ����ָ�����ͣ�

	p = &a; // ��������  ��������  

	*p = 30; //������ ��ͨ��ָ�� ��ӵĲ�������

	return 0;
}
*/