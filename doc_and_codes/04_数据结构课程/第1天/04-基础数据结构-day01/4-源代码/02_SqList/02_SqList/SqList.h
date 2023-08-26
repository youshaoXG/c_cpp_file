#ifndef _SQLIST_H
#define _SQLIST_H

#define MAXSIZE 50	// 最大容量
typedef unsigned int ElemType;	// 数据类型
// 定义线性表结构体
typedef struct SQLIST
{
    ElemType data[MAXSIZE];	// 数组
	//void* data[MAXSIZE];
	int length;	//数组长度 -- 放进去了多少个
}SqList;

#if 0
// 初始化，建立一个空的线性表L。
void InitList(SqList *L);
// 若线性表为空，返回true，否则返回false
int ListEmpty(SqList L);
// 将线性表清空
void ClearList(SqList *L);
// 将线性表L中的第pos个位置的元素返回给e
void GetElem(SqList L, int pos, ElemType *e);
// 在线性表L中的第pos个位置插入新元素e
void ListInsert(SqList *L, int pos, ElemType e);
// 删除线性表L中的第pos个位置元素，并用e返回其值
void ListDelete(SqList *L, int pos, ElemType *e);
// 返回线性表L的元素个数
int ListLength(SqList L);


#else
// 指针是unsigned int 类型
// 初始化，建立一个空的线性表L。
void InitList(SqList *L);
// 若线性表为空，返回true，否则返回false
int ListEmpty(SqList L);
// 将线性表清空
void ClearList(SqList *L);
// 将线性表L中的第pos个位置的元素返回给e
void GetElem(SqList L, int pos, void** e);
// 在线性表L中的第pos个位置插入新元素e
void ListInsert(SqList *L, int pos, void* e);
// 删除线性表L中的第pos个位置元素，并用e返回其值
void ListDelete(SqList *L, int pos, void **e);
// 返回线性表L的元素个数
int ListLength(SqList L);

#endif


#endif // _SQLIST_H
