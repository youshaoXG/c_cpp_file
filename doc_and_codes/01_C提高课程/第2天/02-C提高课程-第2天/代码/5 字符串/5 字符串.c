#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//C��������û���ַ������� ���������ַ����� �����һ�� '\0'

int main(void)
{
	//char str1[] = "abcd"; //5
	//char str1[] = {'a', 'b', 'c', 'd', '\0'};
	char str1[] = {'a', 'b', 'c', 'd','\0'};
	char str3[128] = { 'x', 'y', 'z' };		 //Ĭ�����0 //char[128]

	char *str2 = "abcd"; //4


	printf("str1: %s\n", str1);

	printf("str3 : %s\n", str3);

	int i = 0;
	for (i = 0; i < 128; i++) {
		printf("%d ", str3[i]);
	}
	printf("\n");

	
	printf("------------------\n");

	printf("strlen(str2): %d\n", strlen(str2)); //strlen ���ַ������� ������'\0'
	printf("strlen(str3): %d\n", strlen(str3));
	printf("sizeof(str2): %d\n", sizeof(str2));  //4 
	printf("sizeof(str3): %d\n", sizeof(str3)); //128
	printf("sizeof(str3): %d\n", sizeof(str1)); 


	//ȡ�ַ����е�Ԫ��
	int len = strlen(str1);
	
	for (i = 0; i < len; i++) {
		printf("%c\n", str1[i]); //ͨ�������±�  [] ֱ������
	}

	char *p = NULL;
	p = str1;
	for (i = 0; i < len; i++, p++) {
		printf("%c\n", *p);
	}

	p = str1;
	for (i = 0; i < len; i++)
	{
		printf("%c\n", *(p + 1));
	}

	// p[i]  ==> p[0 + i ]  == > *(p +i )

	//p[i][j]  ==> p[i][0 +j ] ==>*(p[i] + j) ==> *(p[0 + i ] + j) ==>*(*(p + i ) + j) 

	//ָ�� �� ������ ����
	//str1++; //str1 = str1 +1


	return 0;
}