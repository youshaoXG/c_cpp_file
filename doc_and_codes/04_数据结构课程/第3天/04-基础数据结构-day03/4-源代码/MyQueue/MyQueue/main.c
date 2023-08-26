#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

void main()
{
#if 0
	int array[10];
	// 创建队列变量
	SqQueue q;
	// 初始化队列
	InitQueue(&q);
	// 
	for (int i = 0; i < 10; ++i)
	{
		array[i] = i + 10;
		// 入队列
		EnQueue(&q, (void*)&array[i]);
	}

	printf("Queeu size = %d\n", QueueLength(q));

	// 全部都出队列
	while (QueueEmpty(q) != 1)
	{
		int* tmp;
		GetHead(q, (void**)&tmp);
		printf("Queue head value = %d\n", *tmp);
		// 出队列
		DeQueue(&q, (void**)&tmp);
		printf("Delete elem value = %d\n", *tmp);
	}
#else

	// 业务节点
	typedef struct _tag_value
	{
		// 包含一个链表节点
		Node node;
		// 数据
		int v;
	}Value;

	Value val[5];
	// 队列变量
	LinkQueue q;
	// init
	InitQueue(&q);
	//
	for (int i = 0; i < 5; ++i)
	{
		val[i].v = i + 20;
		// 入队列
		EnQueue(&q, &val[i].node);
	}

	printf("Queue size = %d\n", QueueLength(q));

	// 删除全部节点
	while (QueueEmpty(q) != 1)
	{
		// 取出队头元素
		Node* p;
		GetHead(q, &p);
		Value* pp = (Value*)p;
		printf("Queue head value = %d\n", pp->v);
		// 出队列
		DeQueue(&q, &p);
		pp = (Value*)p;
		printf("Delete Queue head value = %d\n", pp->v);
	}
#endif

	system("pause");
}