#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//int * p = NULL;
	//int **pp = NULL;
	//int ***ppp = NULL;


	//int ***************pppp = NULL;// ����ռ��4���ֽڡ�
	//pp = &p;

	//char *p = "1234567"; //ֻ������
	char *p = NULL;
	//char p_array[] = "1234567";
	//                ��
	//*(p_array + 1) = 'x'; //*ָ�� ��=��ߵ� һ����֤ ָ����ָ����ڴ�ռ� ���Ա��޸�


	char ch; 


	ch = *p; //��*p ��=���ұߵ�ʱ�� Ҫ��֤ ָ����ָ��Ŀռ� �ɶ�

	printf("ch = %c\n", ch);

	//printf("%s\n", p_array);

	char buf[4] = { 0 };
	int i = 0;
	for (i = 0; i < 4; i++) {
		p = &buf[i];
	}


	int *p2 = NULL;
	int a = 10;

	p2 = &a;

	p2++; // p2 = (unsigned int)p2 + sizeof(int)

	char *p3 = NULL;

	strcpy(p3, "1234567");

	return 0;
}