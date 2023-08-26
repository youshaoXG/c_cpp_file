#ifndef _SQQUEUE_H
#define _SQQUEUE_H

#define MAXSIZE 20
typedef struct 
{
	// 队头
	int front;
	// 队尾, 指向数组的最后一个元素
	int rear;
	// 数据
	void* data[MAXSIZE];
}SqQueue;

// 初始化操作，建立一个空队列Q
void InitQueue(SqQueue *Q);
// 将队列Q清空
void ClearQueue(SqQueue *Q);
// 若队列为空则返回true，否则返回false
int QueueEmpty(SqQueue Q);
// 若队列Q存在且非空，用e返回队列Q的队头元素
void GetHead(SqQueue Q, void** e);
// 若队列Q存在，插入新元素e到队列Q中并成为队尾元素。
void EnQueue(SqQueue *Q, void* e);
// 删除队列Q中的队头元素，并用e返回其值
void DeQueue(SqQueue *Q, void** e);
// 返回队列Q的元素个数
int QueueLength(SqQueue Q);

#endif	//_SQQUEUE_H