#include "SqQueue.h"
#include <string.h>

void InitQueue(SqQueue *Q)
{
	// 空队列
	Q->front = -1;
	Q->rear = -1;
	memset(Q->data, 0, sizeof(Q->data));
}

void ClearQueue(SqQueue *Q)
{
	Q->front = -1;
	Q->rear = -1;
}

int QueueEmpty(SqQueue Q)
{
	if (Q.front == -1)
	{
		return 1;
	}
	return 0;
}

// 数组的头部为队头, 尾部为队尾
void GetHead(SqQueue Q, void** e)
{
	// 错误处理
	if (Q.front == -1)
	{
		// 空队列
		return;
	}
	*e = Q.data[Q.front];
}

void EnQueue(SqQueue *Q, void* e)
{
	if (Q->rear == MAXSIZE - 1)
	{
		// 队列已满
		return;
	}
	// 添加第一个的时候
	if (Q->front == -1)
	{
		Q->front = 0;
	}
	// 尾部+1
	Q->rear++;
	Q->data[Q->rear] = e;
}

void DeQueue(SqQueue *Q, void** e)
{
	if (Q->front == -1)
	{
		return;
	}
	// 保存队头元素
	*e = Q->data[Q->front];
	// 从1到最后依次前移
	for (int i = 1; i <= Q->rear; ++i)
	{
		Q->data[i - 1] = Q->data[i];
	}
	// 队尾前移
	Q->rear--;
	if (Q->rear == -1)
	{
		Q->front = -1;
	}
}

int QueueLength(SqQueue Q)
{
	return Q.rear+1;
}
