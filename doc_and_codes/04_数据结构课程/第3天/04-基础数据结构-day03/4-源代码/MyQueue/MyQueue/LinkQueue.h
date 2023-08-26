#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H

typedef struct _NODE
{
	struct _NODE* next;
}Node;

typedef struct
{
	// 长度
	int length;
	// 尾节点指针
	Node *real;
	// 头结点指针
	Node *front;
}LinkQueue;

// 初始化操作，建立一个空队列Q
void InitQueue(LinkQueue *Q);
// 将队列Q清空
void ClearQueue(LinkQueue *Q);
// 若队列为空则返回true，否则返回false
int QueueEmpty(LinkQueue Q);
// 若队列Q存在且非空，用e返回队列Q的队头元素
void GetHead(LinkQueue Q, Node** e);
// 若队列Q存在，插入新元素e到队列Q中并成为队尾元素。
void EnQueue(LinkQueue *Q, Node* e);
// 删除队列Q中的队头元素，并用e返回其值
void DeQueue(LinkQueue *Q, Node** e);
// 返回队列Q的元素个数
int QueueLength(LinkQueue Q);

#endif	//_LINKQUEUE_H