#include "SqStack.h"
#include <string.h>

void InitStack(SqStack *S)
{
	// ¿ÕÕ»
	S->top = -1;
	memset(S->data, 0, sizeof(S->data));
}

void ClearStack(SqStack *S)
{
	S->top = -1;
}

int StackEmpty(SqStack S)
{
	if (S.top == -1)
	{
		return 1;
	}
	return 0;
}

void GetTop(SqStack S, void **e)
{
	// Õ»Îª¿Õ
	if (S.top == -1)
	{
		return;
	}
	*e = (void*)S.data[S.top];
}

void Push(SqStack *S, void *e)
{
	// Õ»ÒÑ¾­ÂúÁË
	if (S->top == MAXSIZE - 1)
	{
		return;
	}
	// Õ»¶¥ÉÏÒÆ
	S->top++;
	// ¸³Öµ
	S->data[S->top] = (unsigned int)e;
}

void Pop(SqStack *S, void **e)
{
	// Õ»Îª¿Õ
	if (S->top == -1)
	{
		return;
	}
	// ¸³Öµ
	*e = S->data[S->top];
	// Õ»¶¥Ö¸ÕëÏÂÒÆ
	S->top--;
}

int StackLength(SqStack S)
{
	return S.top + 1;
}
