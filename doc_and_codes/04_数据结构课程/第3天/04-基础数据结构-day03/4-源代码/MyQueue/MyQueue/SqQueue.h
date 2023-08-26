#ifndef _SQQUEUE_H
#define _SQQUEUE_H

#define MAXSIZE 20
typedef struct 
{
	// ��ͷ
	int front;
	// ��β, ָ����������һ��Ԫ��
	int rear;
	// ����
	void* data[MAXSIZE];
}SqQueue;

// ��ʼ������������һ���ն���Q
void InitQueue(SqQueue *Q);
// ������Q���
void ClearQueue(SqQueue *Q);
// ������Ϊ���򷵻�true�����򷵻�false
int QueueEmpty(SqQueue Q);
// ������Q�����ҷǿգ���e���ض���Q�Ķ�ͷԪ��
void GetHead(SqQueue Q, void** e);
// ������Q���ڣ�������Ԫ��e������Q�в���Ϊ��βԪ�ء�
void EnQueue(SqQueue *Q, void* e);
// ɾ������Q�еĶ�ͷԪ�أ�����e������ֵ
void DeQueue(SqQueue *Q, void** e);
// ���ض���Q��Ԫ�ظ���
int QueueLength(SqQueue Q);

#endif	//_SQQUEUE_H