#include <stdio.h>
#include <stdlib.h>


/********* �Ƶ������ۻ��� *********

	1. �㷨��������Ҫ����ɾ��������ָ��
	2. ÿһ��ָ���ھ���ļ����cpu�����е�ʱ���ǹ̶���
	3. ͨ������Ĳ�����ٿ��Ƶ����㷨�ĸ��Ӷ�

********************************/
//ʱ�临�Ӷ�: O(n)
//�ռ临�Ӷ�: O(n) 
long sum1(int n)
{
	long ret = 0;	// 1 4
	int* array = (int*)malloc(n * sizeof(int));	// 1 4n 
	int i = 0;	// 1 4

	for (i = 0; i<n; i++)	// n
	{
		array[i] = i + 1;
	}

	for (i = 0; i<n; i++)	// n
	{
		ret += array[i];
	}

	free(array);	// 1

	return ret;	// 1
}

//ʱ�临�Ӷ�: O(n) 
//�ռ临�Ӷ�: O(1)
long sum2(int n)
{
	long ret = 0;	// 1 4
	int i = 0;	//1 4

	for (i = 1; i <= n; i++)	//n
	{
		ret += i;
		for (int j = 0; j < 2; ++j) // n
		{

		}
	}

	return ret;	//1
}

//ʱ�临�Ӷ�: O(1)
//�ռ临�Ӷ�: O(1)
long sum3(int n)
{
	long ret = 0;	// 1 4

	if (n > 0)	// 1
	{
		ret = (1 + n) * n / 2;	// 1
	}

	return ret;	//1
}

#if 0
int main()
{
	printf("%d\n", sum1(100));
	printf("%d\n", sum2(100));
	printf("%d\n", sum3(100));

	system("pause");
	return 0;
}
#endif
