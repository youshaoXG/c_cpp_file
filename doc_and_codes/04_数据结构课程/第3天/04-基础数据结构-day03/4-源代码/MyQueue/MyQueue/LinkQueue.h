#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

typedef struct _NODE
{
	struct _NODE* next;
}Node;

typedef struct
{
	// ����
	int length;
	// β�ڵ�ָ��
	Node *real;
	// ͷ���ָ��
	Node *front;
}LinkQueue;

// ��ʼ������������һ���ն���Q
void InitQueue(LinkQueue *Q);
// ������Q���
void ClearQueue(LinkQueue *Q);
// ������Ϊ���򷵻�true�����򷵻�false
int QueueEmpty(LinkQueue Q);
// ������Q�����ҷǿգ���e���ض���Q�Ķ�ͷԪ��
void GetHead(LinkQueue Q, Node** e);
// ������Q���ڣ�������Ԫ��e������Q�в���Ϊ��βԪ�ء�
void EnQueue(LinkQueue *Q, Node* e);
// ɾ������Q�еĶ�ͷԪ�أ�����e������ֵ
void DeQueue(LinkQueue *Q, Node** e);
// ���ض���Q��Ԫ�ظ���
int QueueLength(LinkQueue Q);

#endif	//_LINKQUEUE_H