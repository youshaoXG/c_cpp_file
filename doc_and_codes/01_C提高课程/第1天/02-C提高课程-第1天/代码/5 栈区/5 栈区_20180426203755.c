#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>


//ջ
void test()
{
	int a = 10; //�ֲ����� ��ջ�Ͽ����ڴ�  ���ɲ���ϵͳ�Զ���ջ�Ͽ��ٵ�
	int b = 20;
	int array[10]; 

	{
		int c;
		int d;

	}

}

//ȫ�������� ��̬����ȫ�ֱ����� ��̬�ľֲ�����ȫ�������� �ͳ�����
int g_a; 


//��
void test2()
{
	char * p = NULL; // ��ջ�Ͽ���4���ֽڡ�
	char *str = "1234567";


	//�ڶ��Ͽ��ٿռ�
	p = (char*)malloc(100);
	if (p == NULL) {
		fprintf(stderr, "malloc error\n");
		return;
	}
	static int b = 20;

	//�ͷŶѵĿռ�
	if (p != NULL) {
		free(p);
		p = NULL;
	}

}

int main(void)
{

	return 0;
}