#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
#if 0
	// 测试程序
	SqList list;
	// 初始化
	InitList(&list);

	// 插入操作
	for (int i = 0; i < 10; ++i)
	{
		ListInsert(&list, i, i + 10);
	}

	// 遍历
	for (int i = 0; i < ListLength(list); ++i)
	{
		int tmp;
		GetElem(list, i, &tmp);
		printf("Elem value = %d\n", tmp);
	}

	// 删除 - 全部
	while (ListEmpty(list) != 1)
	{
		int tmp;
		ListDelete(&list, 0, &tmp);
		printf("Delete Elem value = %d\n", tmp);
	}
#else

	// 测试程序
	SqList list;

	char* array[] =
	{
		"aaaaa",
		"bbbbb",
		"ccccc",
		"ddddd"
	};
 	// 初始化
	InitList(&list);

	int aa;
	// 插入操作
	for (int i = 0; i < 4; ++i)
	{
		ListInsert(&list, i, (void*)&i);
	}

	// 遍历
	for (int i = 0; i < ListLength(list); ++i)
	{
		int *tmp;
		GetElem(list, i, (void**)&tmp);
		printf("Elem value = %d\n", *tmp);
	}

	// 

	// 删除 - 全部
	while (ListEmpty(list) != 1)
	{
		int *tmp;
		ListDelete(&list, 0, (void**)&tmp);
		printf("Delete Elem value = %d\n", *tmp);
	}

#endif

	system("pause");

// 	char* p;
// 	mallocppp(p);

}

// void* mallocppp(char** p)
// {
// 	*p = (char*)malloc(100);
// }


