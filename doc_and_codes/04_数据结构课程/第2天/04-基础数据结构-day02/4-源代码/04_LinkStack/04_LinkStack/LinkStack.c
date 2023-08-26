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
	// 空栈
	if (S.length == 0)
	{
		return;
	}
	*e = S.top;
}

// 栈顶是链表头部
void Push(LinkStack *S, Node *e)
{
	// 节点e插入到链表的头部
	e->next = S->top;
	// top指针指向第一个节点
	S->top = e;
	// 长度+1
	S->length++;
}

void Pop(LinkStack *S, Node **e)
{
	// 空栈
	if (S->length == 0)
	{
		return;
	}
	// 删除第一个节点
	Node* pDel = S->top;
	// 赋值
	*e = pDel;
	// 栈顶指针后移
	S->top = pDel->next;
	// 长度减1
	S->length--;
}

int StackLength(LinkStack S)
{
	return S.length;
}
