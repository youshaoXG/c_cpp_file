#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

void main()
{
#if 0
	// ���Գ���
	SqList list;
	// ��ʼ��
	InitList(&list);

	// �������
	for (int i = 0; i < 10; ++i)
	{
		ListInsert(&list, i, i + 10);
	}

	// ����
	for (int i = 0; i < ListLength(list); ++i)
	{
		int tmp;
		GetElem(list, i, &tmp);
		printf("Elem value = %d\n", tmp);
	}

	// ɾ�� - ȫ��
	while (ListEmpty(list) != 1)
	{
		int tmp;
		ListDelete(&list, 0, &tmp);
		printf("Delete Elem value = %d\n", tmp);
	}
#else

	// ���Գ���
	SqList list;

	char* array[] =
	{
		"aaaaa",
		"bbbbb",
		"ccccc",
		"ddddd"
	};
 	// ��ʼ��
	InitList(&list);

	int aa;
	// �������
	for (int i = 0; i < 4; ++i)
	{
		ListInsert(&list, i, (void*)&i);
	}

	// ����
	for (int i = 0; i < ListLength(list); ++i)
	{
		int *tmp;
		GetElem(list, i, (void**)&tmp);
		printf("Elem value = %d\n", *tmp);
	}

	// 

	// ɾ�� - ȫ��
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


