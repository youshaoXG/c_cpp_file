#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


//������Ϊ���������� ��һ���˻�������
//int printArray(int array[7], int len)
int printArray(int array[], int len) //
//int printArray(int *array, int len)
{
	int i = 0;

	// 7 �� Ӳ����
	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("---- Сtest ---\n");
	printf("len = %d\n", len);
	int size = sizeof(array) / sizeof(array[0]);//sizeof��һ���������͵Ĵ�С
	printf("size = %d\n", size);
	printf("---- Сtest ---\n");

	return 0;
}

int sortArray(int array[], int len)
{
	int i = 0; //���
	int j = 0;//�ڲ�
	int temp = 0;

	//��i = 0ʱ�� ��j �� 0 ��n ���б����� �ҵ�һ����Сֵ
	//�� i =1 ʱ�� ��j��1 ��n ���б����� �ҵ�һ����Сֵ
	//��סi���ţ� j ͨ���ڲ��𼶱���
	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			if (array[j] > array[i]) {
				//��Ҫ����
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	return 0;//��C���� 0 ����ִ�гɹ�  < 0 �Ǵ��� >1��һЩ����ֵ����
}

int main(void)
{
	int array[] = { 3, 5, 4, 11, 13, 9, 18 , 123, 143};

	int len = sizeof(array) / sizeof(array[0]);

	printf("����֮ǰ:\n");
	printArray(array, len);

	//��������
	sortArray(array, len);

	printf("����֮ǰ:\n");
	printArray(array, len);


	return 0;
}