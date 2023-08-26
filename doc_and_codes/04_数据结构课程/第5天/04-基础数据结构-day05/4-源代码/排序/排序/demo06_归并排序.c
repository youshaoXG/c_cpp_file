#include <stdio.h>
#include <stdlib.h>

//将两个有序数列a[first...mid]和a[mid+1...last]合并。
void mergeArray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;	// 第一个有序序列的开始下标
	int j = mid + 1;	// 第2个有序序列的开始下标

	int length = 0;
	// 合并两个有序序列
	while (i<=mid && j<=last)
	{
		// 找二者中比较小的数
		if (a[i] < a[j])
		{
			temp[length] = a[i];
			i++;
		}
		else
		{
			temp[length] = a[j];
			j++;
		}
		length++;
	}
	// 还剩下一个有序序列中有数据
	while (i <= mid)
	{
		temp[length] = a[i];
		i++;
		length++;
	}
	while (j <= last)
	{
		temp[length++] = a[j++];
	}

	// 覆盖原来位置的无序序列
	for (int i = 0; i < length; ++i)
	{
		// 找到原来 的第一个有序序列的开始位置 - 开始覆盖
		a[first + i] = temp[i];
	}
}

//归并排序
void mergeSort(int a[], int first, int last, int temp[])
{
	// 递归结束的条件
	if (first == last)
	{
		return;
	}
	// 从中间位置拆分
	int mid = (first + last) / 2;
	// 拆分
	// 左半边
	mergeSort(a, first, mid, temp);
	// 右半边
	mergeSort(a, mid + 1, last, temp);
	// 合并两个有序序列
	mergeArray(a, first, mid, last, temp);
}


#if 1
void main()
{
	int i;
	//定义整型数组
	int array[] = { 12, 5, 33, 6, 10 };
	//计算数组长度
	int len = sizeof(array) / sizeof(int);
	//遍历数组
	printf("待排序数组序列: ");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	//创建合适大小的临时数组
	int *p = (int*)malloc(sizeof(int) * len);
	if (p == NULL)
	{
		return;
	}
	mergeSort(array, 0, len - 1, p);
	free(p);

	//遍历
	printf("归并排序之后的序列:	");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	system("pause");
}
#endif