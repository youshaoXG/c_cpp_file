#include "SqQueue.h"
#include <string.h>

void InitQueue(SqQueue *Q)
{
	// �ն���
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

// �����ͷ��Ϊ��ͷ, β��Ϊ��β
void GetHead(SqQueue Q, void** e)
{
	// ������
	if (Q.front == -1)
	{
		// �ն���
		return;
	}
	*e = Q.data[Q.front];
}

void EnQueue(SqQueue *Q, void* e)
{
	if (Q->rear == MAXSIZE - 1)
	{
		// ��������
		return;
	}
	// ��ӵ�һ����ʱ��
	if (Q->front == -1)
	{
		Q->front = 0;
	}
	// β��+1
	Q->rear++;
	Q->data[Q->rear] = e;
}

void DeQueue(SqQueue *Q, void** e)
{
	if (Q->front == -1)
	{
		return;
	}
	// �����ͷԪ��
	*e = Q->data[Q->front];
	// ��1���������ǰ��
	for (int i = 1; i <= Q->rear; ++i)
	{
		Q->data[i - 1] = Q->data[i];
	}
	// ��βǰ��
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
