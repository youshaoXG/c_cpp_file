#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

void main()
{
#if 0
	LinkList ls;
	// init
	InitList(&ls);
	// insert data
	for (int i = 0; i < 10; ++i)
	{
		ListInsert(&ls, i, i + 5);
	}

	// 遍历
	for (int i = 0; i < ListLength(ls); ++i)
	{
		int tmp;
		GetElem(ls, i, &tmp);
		printf("Elem value = %d\n", tmp);
	}

	// 删除全部
	while (ListEmpty(ls) != 1)
	{
		int tmp;
		// 逐个删除
		ListDelete(&ls, 0, &tmp);
		printf("Delete Elem value = %d\n", tmp);
	}

	// 销毁链表
	DestroyList(&ls);

#else

	char* array[] =
	{
		"aaa",
		"bbb",
		"ccc",
		"ddd"
	};
	LinkList ls;
	// init
	InitList(&ls);
	// insert data
	for (int i = 0; i < 4; ++i)
	{
		ListInsert(&ls, i, (void*)array[i]);
	}

	// 遍历
	for (int i = 0; i < ListLength(ls); ++i)
	{
		char* tmp;
		GetElem(ls, i, (void**)&tmp);
		printf("Elem value = %s\n", tmp);
	}

	// 删除全部
	while (ListEmpty(ls) != 1)
	{
		char* tmp;
		// 逐个删除
		ListDelete(&ls, 0, (void**)&tmp);
		printf("Delete Elem value = %s\n", tmp);
	}

	// 销毁链表
	DestroyList(&ls);

#endif

	system("pause");
}