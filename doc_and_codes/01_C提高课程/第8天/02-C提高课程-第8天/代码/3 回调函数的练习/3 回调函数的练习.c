#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void funcAA(int a)
{

}

void funcBB(int * b)
{

}

void funcCC(int *c[10]  )
{

}

void funcDD(int(*c)[10])
{

}

void funcEE(void(*fp)())
{

}
void funcFF(int  pp[10][30])
{

}

int main(void)
{
	//(*(void(*)())0)();		//<C ������ȱ��>
	//(*��void(*)())0 )()

	int f;
	double b;


	int a;
	int *b;
	int *c[10];
	int(*c)[10];
	void(*fp)();
	int aa[10][30];
	//��һ��ͨ�÷��� �� �ж�һ���������������ͣ� ����ν�������ʹ���
	//ȥ���������� ʣ�µľ��� �����������ͣ������Ϳ���ֱ��д��ȥ


	return 0;
}