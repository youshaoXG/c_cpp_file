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

// �����ͷ��Ϊ��ͷ, β��Ϊ��β
void GetHead(LinkQueue Q, Node** e)
{
	// ������
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
		// ������
		Q->real = Q->front = e;
	}
	else
	{
		// �½ڵ�ŵ���β
		Q->real->next = e;
		// rearָ�����һ���ڵ�
		Q->real = e;
	}
	// ����
	Q->length++;
}

void DeQueue(LinkQueue *Q, Node** e)
{
	if (Q->length == 0)
	{
		// ������
		return;
	}
	// ��ֵ
	*e = Q->front;
	// frontָ�����
	Q->front = Q->front->next;
	// ����
	Q->length--;

	if (Q->length == 0)
	{
		// ɾ�����һ���ڵ��ʱ��, βָ����Ҫָ��NULL
		Q->real = NULL;
	}
}

int QueueLength(LinkQueue Q)
{
	return Q.length;
}
