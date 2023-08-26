#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

void main()
{
#if 0
	int array[10];
	// �������б���
	SqQueue q;
	// ��ʼ������
	InitQueue(&q);
	// 
	for (int i = 0; i < 10; ++i)
	{
		array[i] = i + 10;
		// �����
		EnQueue(&q, (void*)&array[i]);
	}

	printf("Queeu size = %d\n", QueueLength(q));

	// ȫ����������
	while (QueueEmpty(q) != 1)
	{
		int* tmp;
		GetHead(q, (void**)&tmp);
		printf("Queue head value = %d\n", *tmp);
		// ������
		DeQueue(&q, (void**)&tmp);
		printf("Delete elem value = %d\n", *tmp);
	}
#else

	// ҵ��ڵ�
	typedef struct _tag_value
	{
		// ����һ������ڵ�
		Node node;
		// ����
		int v;
	}Value;

	Value val[5];
	// ���б���
	LinkQueue q;
	// init
	InitQueue(&q);
	//
	for (int i = 0; i < 5; ++i)
	{
		val[i].v = i + 20;
		// �����
		EnQueue(&q, &val[i].node);
	}

	printf("Queue size = %d\n", QueueLength(q));

	// ɾ��ȫ���ڵ�
	while (QueueEmpty(q) != 1)
	{
		// ȡ����ͷԪ��
		Node* p;
		GetHead(q, &p);
		Value* pp = (Value*)p;
		printf("Queue head value = %d\n", pp->v);
		// ������
		DeQueue(&q, &p);
		pp = (Value*)p;
		printf("Delete Queue head value = %d\n", pp->v);
	}
#endif

	system("pause");
}