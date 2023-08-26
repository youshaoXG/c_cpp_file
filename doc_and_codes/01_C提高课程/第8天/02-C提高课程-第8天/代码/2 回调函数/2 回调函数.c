#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void funcA(int a, int b) //void ()(int, int)
{
	printf("funcA...\n");
	printf("a = %d, b = %d\n", a, b);
}
//���˵ void ()(int, int) ��һ�ֺ������ͣ� ��ô void (*)(int, int)  ����ִ�д˺����� ָ������
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
void funcD(int c, void(*fp)(int, int)) ////fp = funcA  //��һ������ָ��fp ָ��funcA������ִ�е���ڵ�ַ
{
	int a = 100;

	printf("funcD ...\n");
	printf("c = %d\n", c);

	//��funcD�� ����������һ������  ����˵�������ĺ���������funcD����һ���ص���
	fp(a, c);  //��ӵĵ����� funcA
	//funcA(a, c);

}

//��ҵ���� �����ܹ���
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


typedef void(*FP)(int, int);//FP ��һ��ָ�룬 ����ֵ��void ����2�� �ֱ���int��int �������͵� ָ��
typedef int(*FP2)(int, double);  //FP2 ��һ��ָ�룬����ֵ�� int ����2�� �ֱ��� int�� double

//void business(int a, int b, void(*fp)(int, int))
//1999��
void business(int a, int b, FP fp)
{
	//�̶�ҵ��1
	printf("a = %d\n", a);
	//�̶�ҵ��2
	printf("b = %d\n", b);
	//�̶�ҵ��3 
	//....

	//��ҵ�� (�ɸ����û��Ĳ�ͬ��ʵ�ַſ�����)
	fp(a, b);

	//
}

void business2(int a, double b, FP2 fp)
{
	//�̶�ҵ��1
	printf("a = %d\n", a);
	//�̶�ҵ��2
	printf("b = %lf\n", b);
	//�̶�ҵ��3 
	//....
	fp(a, b);
}

int main(void)
{
	//ָ���������������
	int a = 10;

	int * p = NULL;

	//��������
	p = &a;

	//��Ӹ�ֵ
	*p = 20;  

	//��������ָͨ��ĳ�������������

	//ʲô���ؾ���һ�����������ͣ�
	// 1 . �����ķ���ֵ
	// 2. �����б�(�������βεĸ����� �� �βε����ͣ��������͵�˳��)


	int b = 10;

	funcA(a, b); //�ҵ�funcA ���������ڵ�ַ�� 

	funcB(a, b);

	//����һ�� ָ�룬 ָ�� void ()(int, int)
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