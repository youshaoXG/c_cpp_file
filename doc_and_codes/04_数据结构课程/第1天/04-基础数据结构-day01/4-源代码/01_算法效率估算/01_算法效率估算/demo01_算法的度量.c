#include <stdio.h>
#include <stdlib.h>


/********* 推倒的理论基础 *********

	1. 算法的最终是要编译成具体点计算机指令
	2. 每一个指令在具体的计算机cpu上运行的时间是固定的
	3. 通过具体的步骤多少克推倒出算法的复杂度

********************************/
//时间复杂度: O(n)
//空间复杂度: O(n) 
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

//时间复杂度: O(n) 
//空间复杂度: O(1)
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

//时间复杂度: O(1)
//空间复杂度: O(1)
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
