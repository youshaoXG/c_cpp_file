#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int g_val; //ȫ�ֱ���
int g_val = 10;// ��һ��ȫ�ֱ���

typedef struct teacher
{
	int id;
	char name[64];
}teacher_t;

void f(int i)
{
	printf("i = %d\n", i);
}

g()
{
	return 10;
}

//3 C�����е��߼������ 
void test3()
{
	int flag = 0; // C������ ��ֵ0��ʾΪ��
//	int flag = 1; // C������ ��ֵ��0��ʾ��  C��������ͨ����ֵ�Ƿ�Ϊ0 ���ֱ��߼���ٵġ�
	 
}

//4 ��Ŀ���������ǿ
void test4()
{
	int a = 10;
	int b = 20;

	int min_value = 0;


	//min_value = (a < b ? a : b);  
	//(a < b ? a : b) = 30;//���ص���һ����ֵ�� 10  �� 10 = 30

	*(a < b ? &a : &b) = 30;

	//*(a < b ? &10 : &b) = 30; //10 =30

	
	printf("%d\n", a);
}


//5 c�����е�const 
void test5()
{
	const int a ;
	//int const b; //const int , int const �ǵȼ۵�

	int *p = (int*)&a;
	*p = 20;//C�����п���ͨ��ָ��ļ�Ӹ�ֵ�ı�const���� 

	printf("a = %d\n", a);
}

#define A (3)
#define B (4)

void test6()
{
	int const a = 3;
	int const b = 4; //�ٴ�˵�� c�����е� const ������һ����������һ������ ����ֻ�����ԡ�

	int array[A+ B] = { 0 }; //�������ʹ�С�ǹ̶��� ���������������ȣ��������޷�ȷ������
}

enum season {
	SPR = 0,
	SUM,
	AUT,
	WIN
};

void test7()
{
	enum season s = SPR;

	s = 0;
	s = 1;
	s = 2;  // C���Զ�ö�����͵ĸ�ֵ�� �ǿ���ͨ��ö�ٵ�ֵ��ֱ�Ӹ�ֵ�ġ�
	s = 136; //136  ʲô��˼��

}

//1 ʵ������ǿ
int main(void)
{
	//struct teacher t1; //��C���������ʹ��һ��struct �������ͣ���ô���뽫struct �ؼ���д����
	//teacher_t t2;
	//printf("%d\n", g_val);

	//f(1,2,3);//warning

	//int value = 0;
	//value = g(1, 2, 3, 4, 5);

	//printf("%d\n", value);
	
	//test4();
	//test5();
	test7();
	return 0;
}