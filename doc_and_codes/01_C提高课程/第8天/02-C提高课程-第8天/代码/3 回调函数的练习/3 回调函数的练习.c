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
	//(*(void(*)())0)();		//<C 陷阱与缺陷>
	//(*（void(*)())0 )()

	int f;
	double b;


	int a;
	int *b;
	int *c[10];
	int(*c)[10];
	void(*fp)();
	int aa[10][30];
	//有一种通用方法 ， 判断一个变量的数据类型， 和如何将这个类型传参
	//去掉变量名， 剩下的就是 他的数据类型，参数就可以直接写过去


	return 0;
}