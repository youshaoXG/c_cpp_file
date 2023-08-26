#include "LinkStack.h"
#include <stdio.h>

void InitStack(LinkStack *S)
{
	S->length = 0;
	S->top = NULL;
}

void ClearStack(LinkStack *S)
{
	while (S->length)
	{
		Node* p;
		Pop(S, &p);
	}
}

int StackEmpty(LinkStack S)
{
	if (S.length == 0)
	{
		return 1;
	}
	return 0;
}

void GetTop(LinkStack S, Node **e)
{
	// ��ջ
	if (S.length == 0)
	{
		return;
	}
	*e = S.top;
}

// ջ��������ͷ��
void Push(LinkStack *S, Node *e)
{
	// �ڵ�e���뵽�����ͷ��
	e->next = S->top;
	// topָ��ָ���һ���ڵ�
	S->top = e;
	// ����+1
	S->length++;
}

void Pop(LinkStack *S, Node **e)
{
	// ��ջ
	if (S->length == 0)
	{
		return;
	}
	// ɾ����һ���ڵ�
	Node* pDel = S->top;
	// ��ֵ
	*e = pDel;
	// ջ��ָ�����
	S->top = pDel->next;
	// ���ȼ�1
	S->length--;
}

int StackLength(LinkStack S)
{
	return S.length;
}
