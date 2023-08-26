#include <stdio.h>
#include <stdlib.h>

/***************************** 练习 *****************************

	在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
	设计一个算法，找出出现次数最多的数字。

	int array[] = { 1, 1, 3, 4, 5, 6, 6, 6, 2, 3 };

	出现次数最多的数字: 6

***************************************************************/

//查找
//时间复杂度: O(n)
void search(int a[], int len)
{
	int sp[1000] = { 0 };	
	int i = 0;
	int max = 0;

	// 计算数组中个元素值出现的次数
	for (i = 0; i<len; i++)	//n
	{
		// 获取数组中 i 位置元素的值
		int index = a[i];
		// 计算数index出现的次数
		// 出现一次就在新的数组中 index 的位置加1
		sp[index]++;
	}

	//寻找sp数组中的最大数
	for (i = 0; i<1000; i++)	//n
	{
		if (max < sp[i])
		{
			//保存最大值
			max = sp[i];
		}
	}

	//根据位置寻找最大值对应的元素
	for (i = 0; i<1000; i++)	//n
	{
		if (max == sp[i])
		{
			printf("出现次数最多的数字: %d\n", i);
		}
	}
}

#if 1
int main()
{
	int array[] = { 1, 1, 3, 4, 5, 6, 6, 6, 2, 3 };

	search(array, sizeof(array) / sizeof(*array));

	system("pause");
	return 0;
}
#endif


#if 0
#include <map>
#include <iostream>
using namespace std;

//STL 实现
void search(int* array, int len)
{
	map<int, int> M;
	for (int i = 0; i < len; i++)
	{
		//将数组中的元素
		pair<map<int, int>::iterator, bool> pairIt = M.insert(pair<int, int>(array[i], 1));
		if (pairIt.second != true)
		{
			//如果插入失败,则说明插入的数已存在,将其value做加1运算,计算出现的次数
			M[array[i]]++;
		}
	}

	int max = 0;//存储频率
	int data = 0;//a[i]
	for (int i = 0; i < len; i++)
	{
		if (M[array[i]] > max)
		{
			n = i;
			// 存储出现次数最多的元素
			data = array[i];
			// 存储出现最多的次数
			max = M[array[i]];
		}
	}
	cout<< "出现次数最多的元素为:" << data << endl;
	cout<< "出现的次数为: " << max <<endl;
}
#endif
