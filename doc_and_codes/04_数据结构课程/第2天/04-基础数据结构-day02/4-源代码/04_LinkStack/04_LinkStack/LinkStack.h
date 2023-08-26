#ifndef _LINKSTACK_H
#define _LINKSTACK_H

// 定义小链表节点
typedef struct NODE
{
	struct NODE* next;
}Node;

// 链表结构体
typedef struct
{
	// 栈顶指针
	Node *top;
	// 长度
	int length;
}LinkStack;

// 初始化，建立一个空栈S
void InitStack(LinkStack *S);

// 将栈清空
void ClearStack(LinkStack *S);

// 若栈为空则返回true，否则返回false
int StackEmpty(LinkStack S);

// 若栈存在且非空，用e返回S的栈顶元素
void GetTop(LinkStack S, Node **e);

// 若栈S存在，插入新元素e到栈S中并成为其栈顶元素
void Push(LinkStack *S, Node *e);

// 删除栈S中的栈顶元素，并用e返回其值
void Pop(LinkStack *S, Node **e);

// 返回栈S的元素个数
int StackLength(LinkStack S);

#endif	// _LINKSTACK_H
