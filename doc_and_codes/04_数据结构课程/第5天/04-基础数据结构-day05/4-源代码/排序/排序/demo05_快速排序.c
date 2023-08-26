#include <stdio.h>
#include <stdlib.h>

//快速排序
void quickSort(int s[], int l, int r)
{
	// 递归结束的条件
	if (l >= r)
	{
		return;
	}
	int i = l;	// 开始位置
	int j = r;	// 最后一个元素的位置
	// 基准数
	int tmp = s[l];	// 取第一个元素作为基准数 -- i的位置是坑

	// 循环判断
	while (i < j)
	{
		// j位置的元素, 大于等于基准数
		while (i<j && s[j] >= tmp)
		{
			// 前移
			j--;
		}
		// 找到了填坑的数
		if (i < j)
		{
			// 填坑
			s[i] = s[j];	// j变成坑
			// i后移
			i++;
		}
		// 移动i, 坑不移动
		// i位置的元素 小于基准数
		while (i < j && s[i] < tmp)
		{
			i++;
		}
		// 找到了大于等于基准数的元素
		if (i < j)
		{
			// 填后边的坑
			s[j] = s[i];
			// j前移
			j--;
		}
	}
	// i j 相遇 i==j
	// 填坑
	s[i] = tmp;
	// 拆分左半部分
	quickSort(s, l, i - 1);
	// 右
	quickSort(s, i + 1, r);
}

#if 0
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

	//排序
	quickSort(array, 0, len-1);

	//遍历
	printf("快速排序之后的序列:	");
	for (i = 0; i < len; ++i)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	system("pause");
}
#endif


#if 0

#define SWAP(x,y){int z;z=x;x=y;y=z;}
//快速排序
#pragma region 第三种快排
int partition(int number[], int left, int right)
{
	int i, j, s;
	s = number[right];
	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (number[j] <= s)
		{
			i++;
			SWAP(number[i], number[j]);
		}
	}
	SWAP(number[i + 1], number[right]);
	return i + 1;
}

void quickSort(int s[], int left, int right)
{
	int q;
	if (left < right)
	{
		q = partition(s, left, right);
		quickSort(s, left, q - 1);
		quickSort(s, q + 1, right);
	}
}
#endif