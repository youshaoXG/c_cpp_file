#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


typedef struct student  //��һ���������� �����
{
	char name[64];
	int age;
} student_t;

//int g_a = 10;


typedef  unsigned int u32;
typedef unsigned long u64;


int main(void)
{
	int a = 10; //int ���Ǹ��߱����� ���ٹ̶���С4���ֽڵ��ڴ��
	double b = 1.30;//���Ǹ��߱����� ���ٹ̶���С8���ֽڵ��ڴ��
	char c = 'c';
	//�������͵����ı�����  �̶���С�ڴ濴�ı���

	a = 30;

	int * p = &a;  //p��һ��ָ�룬 ָ��a�ĵ�ַ�� 
	char *pp = &c;

	int b_array[10] = { 0 }; //����һ������  

	printf("sizeof(p) :%d\n", sizeof(p));   //�� int* �������͵Ĵ�С  4
	printf("sizeof(pp) :%d\n", sizeof(pp));//��char*�������͵Ĵ�С 4
	printf("sizeof(*p):%d\n", sizeof(*p)); // ��int�������͵Ĵ�С 4
	printf("sizeof(*pp):%d\n", sizeof(*pp));//�� char�������͵Ĵ�С 1
	
	printf("p : %p, p+1: %p\n", p, p + 1);     //ָ����������� ����ָ��Ŀ����������
	printf("pp : %p, pp+1: %p\n", pp, pp + 1);
	 
	//int---4
	//double --8
	//int * ---4;
	//int[10]  ----40
	//���������͵Ĵ�С sizeof
	printf("sizeof(b_array) :  %d\n", sizeof(b_array));  //�� int b_array[10]���ݵĴ�С
	printf("sizeof(b_array[0]): %d\n", sizeof(b_array[0])); //��int�����������͵Ĵ�С

	printf("&b_array:%p, b_array:%p, &b_array+1: %p, b_array+1: %p", &b_array, b_array, &b_array + 1, b_array + 1);
	
	//b_array ����������Ԫ�صĵ�ַ����Ԫ����int���� b_array���������� int*
	//&b_array ��������(int[10])�ĵ�ַ, ����������� int[10]  ,, &b_array->  (int[10]) *

	student_t s1; //���� 68 ���ֽ��ڴ��
	student_t *sp = &s1; 
	//g_a = 30;
	u32 aa;

	printf("sizeof(student_t) : %d\n", sizeof(s1));
	//sp + 1; sp

//	void a;
	void * //��һ����������  * ��־����ָ�룬 void  ����


	return 0;
}


