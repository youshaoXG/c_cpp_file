#ifndef _LINKLIST_H
#define _LINKLIST_H

#if 0
typedef int ElemType;
typedef struct NODE
{
	ElemType data;	// ����
	struct NODE *next;	// ָ���̽ڵ��ָ��
}Node;

typedef struct LINKLIST
{
	int length;
	Node header;
}LinkList;



// ��ʼ��������һ���յ����Ա�L��
void InitList(LinkList *L);
// �����Ա�Ϊ�գ�����true�����򷵻�false
int ListEmpty(LinkList L);
// �����Ա����
void ClearList(LinkList *L);
// �����Ա�L�еĵ�pos��λ�õ�Ԫ�ط��ظ�e
void GetElem(LinkList L, int pos, int *e);
// �����Ա�L�еĵ�pos��λ�ò�����Ԫ��e
void ListInsert(LinkList *L, int pos, int e);
// ɾ�����Ա�L�еĵ�pos��λ��Ԫ�أ�����e������ֵ
void ListDelete(LinkList *L, int pos, int *e);
// �������Ա�L��Ԫ�ظ���
int ListLength(LinkList L);
// �������Ա�
void DestroyList(LinkList *L);

#else

typedef int ElemType;
// С����ڵ�
typedef struct NODE
{
	struct NODE *next;	// ָ���̽ڵ��ָ��
}Node;

// ҵ��ڵ�(����һ��С����ڵ�)
typedef struct _LISTNODE
{
	Node node;	// С����ڵ�
	void *data;	// ָ�����ݵ�ַ��ָ��
}ListNode;

// ����ҵ��ڵ�Ľṹ
typedef struct LINKLIST
{
	int length;
	ListNode header;
}LinkList;


// ��ʼ��������һ���յ����Ա�L��
void InitList(LinkList *L);
// �����Ա�Ϊ�գ�����true�����򷵻�false
int ListEmpty(LinkList L);
// �����Ա����
void ClearList(LinkList *L);
// �����Ա�L�еĵ�pos��λ�õ�Ԫ�ط��ظ�e
void GetElem(LinkList L, int pos, void **e);
// �����Ա�L�еĵ�pos��λ�ò�����Ԫ��e
void ListInsert(LinkList *L, int pos, void* e);
// ɾ�����Ա�L�еĵ�pos��λ��Ԫ�أ�����e������ֵ
void ListDelete(LinkList *L, int pos, void **e);
// �������Ա�L��Ԫ�ظ���
int ListLength(LinkList L);
// �������Ա�
void DestroyList(LinkList *L);

#endif

#endif	// _LINKLIST_H