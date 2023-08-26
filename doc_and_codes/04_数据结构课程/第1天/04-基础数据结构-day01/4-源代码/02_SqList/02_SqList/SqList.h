#ifndef _SQLIST_H
#define _SQLIST_H

#define MAXSIZE 50	// �������
typedef unsigned int ElemType;	// ��������
// �������Ա�ṹ��
typedef struct SQLIST
{
    ElemType data[MAXSIZE];	// ����
	//void* data[MAXSIZE];
	int length;	//���鳤�� -- �Ž�ȥ�˶��ٸ�
}SqList;

#if 0
// ��ʼ��������һ���յ����Ա�L��
void InitList(SqList *L);
// �����Ա�Ϊ�գ�����true�����򷵻�false
int ListEmpty(SqList L);
// �����Ա����
void ClearList(SqList *L);
// �����Ա�L�еĵ�pos��λ�õ�Ԫ�ط��ظ�e
void GetElem(SqList L, int pos, ElemType *e);
// �����Ա�L�еĵ�pos��λ�ò�����Ԫ��e
void ListInsert(SqList *L, int pos, ElemType e);
// ɾ�����Ա�L�еĵ�pos��λ��Ԫ�أ�����e������ֵ
void ListDelete(SqList *L, int pos, ElemType *e);
// �������Ա�L��Ԫ�ظ���
int ListLength(SqList L);


#else
// ָ����unsigned int ����
// ��ʼ��������һ���յ����Ա�L��
void InitList(SqList *L);
// �����Ա�Ϊ�գ�����true�����򷵻�false
int ListEmpty(SqList L);
// �����Ա����
void ClearList(SqList *L);
// �����Ա�L�еĵ�pos��λ�õ�Ԫ�ط��ظ�e
void GetElem(SqList L, int pos, void** e);
// �����Ա�L�еĵ�pos��λ�ò�����Ԫ��e
void ListInsert(SqList *L, int pos, void* e);
// ɾ�����Ա�L�еĵ�pos��λ��Ԫ�أ�����e������ֵ
void ListDelete(SqList *L, int pos, void **e);
// �������Ա�L��Ԫ�ظ���
int ListLength(SqList L);

#endif


#endif // _SQLIST_H
