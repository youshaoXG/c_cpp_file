#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//void swap(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}


//�õ�һ���ļ��ĳ���
void get_file_len(int file_len)
{
	file_len = 30;
}


//�����ʹ��ָ�룬��Ҫ���Ӻ����е����ݴ���������ôһ��Ҫ�� ����ֵ�� ����ֵ����
int get_file_len2()
{
	int file_len = 0;

	file_len = 30;

	return file_len;
}

//ͨ��ָ�룬 �ں����ڲ���ӵ��޸ĺ����ⲿ�ı����� �����ָ��ļ�Ӳ���������
int get_file_len3(int *p)
{
	*p = 30;

	return 0;
}

int main(void)
{
	int a = 10;
	int b = 20;

	int file_len = 0;

	//swap(a, b);

	get_file_len(file_len);

	file_len = get_file_len2();


	get_file_len3(&file_len);



	return 0;
}