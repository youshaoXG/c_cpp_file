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

	// ����
	for (int i = 0; i < ListLength(ls); ++i)
	{
		int tmp;
		GetElem(ls, i, &tmp);
		printf("Elem value = %d\n", tmp);
	}

	// ɾ��ȫ��
	while (ListEmpty(ls) != 1)
	{
		int tmp;
		// ���ɾ��
		ListDelete(&ls, 0, &tmp);
		printf("Delete Elem value = %d\n", tmp);
	}

	// ��������
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

	// ����
	for (int i = 0; i < ListLength(ls); ++i)
	{
		char* tmp;
		GetElem(ls, i, (void**)&tmp);
		printf("Elem value = %s\n", tmp);
	}

	// ɾ��ȫ��
	while (ListEmpty(ls) != 1)
	{
		char* tmp;
		// ���ɾ��
		ListDelete(&ls, 0, (void**)&tmp);
		printf("Delete Elem value = %s\n", tmp);
	}

	// ��������
	DestroyList(&ls);

#endif

	system("pause");
}