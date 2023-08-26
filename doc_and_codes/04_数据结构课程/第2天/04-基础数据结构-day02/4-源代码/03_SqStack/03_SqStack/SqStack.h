#ifndef _SQSTACK_H
#define _SQSTACK_H

#define MAXSIZE 50
typedef struct _SQSTACK
{
	int top;	// ջ��ָ��
	unsigned int data[MAXSIZE];
}SqStack;

// ��ʼ��������һ����ջS
void InitStack(SqStack *S);

// ��ջ���
void ClearStack(SqStack *S);

// ��ջΪ���򷵻�true�����򷵻�false
int StackEmpty(SqStack S);

// ��ջ�����ҷǿգ���e����S��ջ��Ԫ��
void GetTop(SqStack S, void **e);

// ��ջS���ڣ�������Ԫ��e��ջS�в���Ϊ��ջ��Ԫ��
void Push(SqStack *S, void *e);

// ɾ��ջS�е�ջ��Ԫ�أ�����e������ֵ
void Pop(SqStack *S, void **e);

// ����ջS��Ԫ�ظ���
int StackLength(SqStack S);

#endif // _SQSTACK_H
