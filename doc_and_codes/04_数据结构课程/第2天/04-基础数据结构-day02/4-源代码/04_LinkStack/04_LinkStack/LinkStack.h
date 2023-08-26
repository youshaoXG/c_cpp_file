#ifndef _LINKSTACK_H
#define _LINKSTACK_H

// ����С����ڵ�
typedef struct NODE
{
	struct NODE* next;
}Node;

// ����ṹ��
typedef struct
{
	// ջ��ָ��
	Node *top;
	// ����
	int length;
}LinkStack;

// ��ʼ��������һ����ջS
void InitStack(LinkStack *S);

// ��ջ���
void ClearStack(LinkStack *S);

// ��ջΪ���򷵻�true�����򷵻�false
int StackEmpty(LinkStack S);

// ��ջ�����ҷǿգ���e����S��ջ��Ԫ��
void GetTop(LinkStack S, Node **e);

// ��ջS���ڣ�������Ԫ��e��ջS�в���Ϊ��ջ��Ԫ��
void Push(LinkStack *S, Node *e);

// ɾ��ջS�е�ջ��Ԫ�أ�����e������ֵ
void Pop(LinkStack *S, Node **e);

// ����ջS��Ԫ�ظ���
int StackLength(LinkStack S);

#endif	// _LINKSTACK_H
