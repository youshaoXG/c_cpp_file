#include "LinkQueue.h"
#include <stdio.h>

void InitQueue(LinkQueue *Q)
{
	Q->length = 0;
	Q->real = NULL;
	Q->front = NULL;
}

void ClearQueue(LinkQueue *Q)
{
	while (Q->length)
	{
		Node* p;
		DeQueue(Q, &p);
	}
}

int QueueEmpty(LinkQueue Q)
{
	if (Q.length == 0)
	{
		return 1;
	}
	return 0;
}

// 链表的头部为队头, 尾部为队尾
void GetHead(LinkQueue Q, Node** e)
{
	// 错误处理
	if (Q.length == 0)
	{
		return;
	}
	*e = Q.front;
}

void EnQueue(LinkQueue *Q, Node* e)
{
	if (Q->length == 0)
	{
		// 空链表
		Q->real = Q->front = e;
	}
	else
	{
		// 新节点放到队尾
		Q->real->next = e;
		// rear指向最后一个节点
		Q->real = e;
	}
	// 长度
	Q->length++;
}

void DeQueue(LinkQueue *Q, Node** e)
{
	if (Q->length == 0)
	{
		// 空链表
		return;
	}
	// 赋值
	*e = Q->front;
	// front指针后移
	Q->front = Q->front->next;
	// 长度
	Q->length--;

	if (Q->length == 0)
	{
		// 删除最后一个节点的时候, 尾指针需要指向NULL
		Q->real = NULL;
	}
}

int QueueLength(LinkQueue Q)
{
	return Q.length;
}
