#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void test()
{
	//int//0ά����  һ��ָ��
	//int[10]//һά���飬 ����ָ��
	//int[10][20]//��ά���飬 ����ָ��

	int a[3][4];
	//  a ��һ�� ָ�룬  ָ��  �˶�ά������Ԫ�أ�int[4]���ĵ�ַ�� int (*)[4]   ==>����ָ�� ָ��һά����
	// &a Ҳ��һ��ָ�룬 ָ�� �˶�ά����(int[3][4])�ĵ�ַ,   int(*p)[3][4]  ---> ����ָ��  ָ��һ����ά����

	//һ������ָ�룬 ����Ǽ���ָ�룬 ���� ָ�������һ��ά�ȵ����顣


}


int main(void)
{
	//����һ��ָ������
	//char *pointer_array[4] = { NULL, NULL, NULL, NULL };//��ջ��
	char *pointer_array[4] = { 0}; 
	int i = 0;
	for (i = 0; i < 4; i++) {
		pointer_array[i] = malloc(100);
	}
	
	//����һ������ָ��
	//����һ
	//ֱ�Ӷ���һ����������
	typedef int(ARRAY_CHAR_4)[4];  
	ARRAY_CHAR_4 array = { 0 };  //(int[4]) array ��������Ԫ�صĵ�ַ  
	ARRAY_CHAR_4 *p = NULL;   //����ĵ�ַ   (int[4]) * p = NULL;

	p = &array;  //  array  int*   &array --> (int[4])*

	for (i = 0; i < 4; i++) {
		(*p)[i] = i;  // array[i] = i;
		// char[4]    *(p +  i) === p[i]
	}

	for (i = 0; i < 4; i++) {
		printf("%d\n", array[i]);
	}
	int size = 0;
	size = sizeof(ARRAY_CHAR_4);
	printf("ARRAY_CHAR_4 = %d\n ", size);  // 16

	/*
	int *p = NULL;
	typedef int* POINT;
	POINT p;
	*/


	//������
	typedef int(*ARRAY_CHAR_4_POINTER)[4];  //p  ----> int[10]
	typedef int(*ARRAY_CHAR_10_POINTER)[10]; //int[10]

	ARRAY_CHAR_4_POINTER  array_pointer = &array;

	size = sizeof(ARRAY_CHAR_4_POINTER);
	printf("ARRAY_CHAR_4_POINTER = %d\n ", size); //4


	for (i = 0; i < 4; i++) {
		(*array_pointer)[i] = 10 - i;
	}

	printf("\n");

	for (i = 0; i < 4; i++) {
		printf("%d\n", array[i]);
	}


	//������
	int(*array_p)[4] = NULL; //ֱ�Ӷ���һ������ָ��

	array_p = &array;

	for (i = 0; i < 4; i++) {
		(*array_p)[i] = 20 - i;
	}

	printf("\n");

	for (i = 0; i < 4; i++) {
		printf("%d\n", array[i]);
	}






	return 0;
}