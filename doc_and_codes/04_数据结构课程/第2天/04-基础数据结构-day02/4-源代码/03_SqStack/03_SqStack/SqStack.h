#ifndef _SQSTACK_H
#define _SQSTACK_H

#define MAXSIZE 50
typedef struct _SQSTACK
{
	int top;	// 栈顶指针
	unsigned int data[MAXSIZE];
}SqStack;

// 初始化，建立一个空栈S
void InitStack(SqStack *S);

// 将栈清空
void ClearStack(SqStack *S);

// 若栈为空则返回true，否则返回false
int StackEmpty(SqStack S);

// 若栈存在且非空，用e返回S的栈顶元素
void GetTop(SqStack S, void **e);

// 若栈S存在，插入新元素e到栈S中并成为其栈顶元素
void Push(SqStack *S, void *e);

// 删除栈S中的栈顶元素，并用e返回其值
void Pop(SqStack *S, void **e);

// 返回栈S的元素个数
int StackLength(SqStack S);

#endif // _SQSTACK_H
