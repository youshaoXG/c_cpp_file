﻿#include <stdio.h>
#include <stdlib.h>

/********************* 排序规则 *********************

冒泡排序算法的运作如下：（从后往前）
	1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。
	2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
	3. 针对所有的元素重复以上的步骤，除了最后一个。
	4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

稳定性:冒泡排序是一种稳定排序算法

***************************************************/

//冒泡排序(升序)
void bubbleSort(int *array, int len)	//O(n²)
{
#if 0
	// 外层
	for (int i= 0; i < len; ++i)
	{
		for (int j = 1; j < len - i; j++)
		{
			// 交换
			if (array[j] < array[j - 1])
			{
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
#endif
	// 0: 没有排好, 1: 已经排好
	int flag = 0;
	for (int i = len - 1; i > 0 && flag==0; --i)
	{
		flag = 1;	// 默认已经排好
		for (int j = 0; j < i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = 0;	// 没有排好
			}
		}
	}
}

#if 0
void main()
{
	int i;
	//定义整型数组
	int array[] = { 11, 8, 7, 6, 3 };
	//计算数组长度
	int len = sizeof(array) / sizeof(int);
	//遍历数组
	printf("待排序数组序列: ");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	//排序
	bubbleSort(array, len);

	//遍历
	printf("冒泡排序之后的序列:	");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	system("pause");
}
#endif

