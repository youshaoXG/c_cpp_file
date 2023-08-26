#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void funcA(int a, int b) //void ()(int, int)
{
	printf("funcA...\n");
	printf("a = %d, b = %d\n", a, b);
}
//如果说 void ()(int, int) 是一种函数类型， 那么 void (*)(int, int)  就是执行此函数的 指针类型
void funcB(int a, int b)//void ()(int, int)
{
	printf("funcB...\n");
	printf("a + b = %d\n", a + b);
}

void funcC(int a, double d) //void ()(int  , double )
{
	printf("a = %d\n", a);
}


// int c  
// void(*fp)(int, int), fp-->void (*)(int, int)
void funcD(int c, void(*fp)(int, int)) ////fp = funcA  //让一个函数指针fp 指向funcA函数的执行的入口地址
{
	int a = 100;

	printf("funcD ...\n");
	printf("c = %d\n", c);

	//在funcD种 调用了另外一个函数  ，就说传进来的函数，就是funcD函数一个回调。
	fp(a, c);  //间接的调用了 funcA
	//funcA(a, c);

}

//主业务函数 （主架构）
//1999
void addFunc(int a, int b)
{
	printf("a +b : %d\n", a + b);
}
//1999
void subFunc(int a, int b)
{
	printf("a - b : %d\n", a - b);
}

//2001 
void addFunc2(int a, int b)
{
	printf("a + a +b: %d\n", a + a + b);
}

int addFunc1(int a, double b)
{
	return a + b;
}


typedef void(*FP)(int, int);//FP 是一种指针， 返回值是void 参数2个 分别是int，int 函数类型的 指针
typedef int(*FP2)(int, double);  //FP2 是一种指针，返回值是 int 参数2个 分别是 int， double

//void business(int a, int b, void(*fp)(int, int))
//1999年
void business(int a, int b, FP fp)
{
	//固定业务1
	printf("a = %d\n", a);
	//固定业务2
	printf("b = %d\n", b);
	//固定业务3 
	//....

	//子业务 (可根据用户的不同的实现放可配置)
	fp(a, b);

	//
}

void business2(int a, double b, FP2 fp)
{
	//固定业务1
	printf("a = %d\n", a);
	//固定业务2
	printf("b = %lf\n", b);
	//固定业务3 
	//....
	fp(a, b);
}

int main(void)
{
	//指针成立的三个条件
	int a = 10;

	int * p = NULL;

	//建立关联
	p = &a;

	//间接赋值
	*p = 20;  

	//以上是普通指针的成立的三个条件

	//什么因素决定一个函数的类型？
	// 1 . 函数的返回值
	// 2. 参数列表(包括，形参的个数， 和 形参的类型（包括类型的顺序）)


	int b = 10;

	funcA(a, b); //找到funcA 这个函数入口地址， 

	funcB(a, b);

	//定义一个 指针， 指向 void ()(int, int)
	void(*fp)(int, int) = funcA; //fp --> funcA

	
	(*fp)(a, b); // funcA(a, b)
	//fp(a, b);


	fp = funcB;
	(*fp)(a, b);

	printf(" ============== \n");

	funcD(300, funcB); //fp = funcA



	printf(" ============== \n");

	int num1 = 10;
	int num2 = 20;
	double num3 = 30.0;



	business(num1, num2, addFunc2);

	business(num1, num2, subFunc);

	business2(num1, num3, addFunc1);


	return 0;
}