#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a[10] = { 0 };
	int i = 0;
	int j = 0;

	// a ��������  a++,,,, a = a +��; a[1];  *(a+1)��//��������һ�������� ��һ����ָ�룬���ܹ����޸�  ,ָ����Ԫ��
	/*
		a + 1   a�� int *const a;  a +1   4 ���ֽڵ�ƫ��
		&a +1  &a  int[10] * a     &a+1  4 *10 = 40 ���ֽڵ�ƫ��
	*/



	int aa[3][4] = { 
		{ 3, 5, 4, 3 },
		{2,3,4,5}
	};

	// aa ,int[4]���͵ĵ�ַ

	//��ʼ��һ�����飬�����Ǽ�ά�ģ� �����ʼ������ȫ�� ʣ�µľ�ȫ�����0

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", aa[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int size = sizeof(aa); //����һ����ά����� �������ʹ�С  int   [3][4][5]
	printf("size = %d\n", size);

	// �ȽϺ����ķ��� (int   [3][4])  * p = NULL;
	int(*p)[3][4] = NULL;//ָ���ά���� int[3][4]��ָ��

	printf("p : 0x%p, p + 1 : 0x%p\n", p, p + 1);
	printf("p : %d, p + 1 : %d\n", p, p + 1);


	//����Ҳ�����������͵�

	return 0;
}