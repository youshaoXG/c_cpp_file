#include "SqList.h"
#include <string.h>

#if 0
void InitList(SqList *L)
{
	// 初始化
	L->length = 0;
	// 可要可不要
	memset(L->data, 0, sizeof(L->data));
}

int ListEmpty(SqList L)
{
	if (L.length == 0)
	{
		return 1;
	}
	return 0;
}

void ClearList(SqList *L)
{
	InitList(L);
}

void GetElem(SqList L, int pos, ElemType *e)
{
	// pos值是否合法
	if (pos < 0 || pos >= L.length)
	{
		return;
	}
	// 如果为空
	if (L.length == 0)
	{
		return;
	}
	// 赋值
	*e = L.data[pos];
}

void ListInsert(SqList *L, int pos, ElemType e)
{
	// 错误处理
	if (pos < 0 || pos > L->length)
	{
		return;
	}
	if (L->length >= MAXSIZE)
	{
		// 已满
		return;
	}
	// 移动
	// 从length-1 到 pos 依次后移
	for (int i = L->length - 1; i >= pos; --i)
	{
		L->data[i + 1] = L->data[i];
	}
	// 赋值 -- 数据的拷贝
	L->data[pos] = e;
	// 
	L->length++;
}

void ListDelete(SqList *L, int pos, ElemType *e)
{
	// 错误处理
	if (pos < 0 || pos >= L->length)
	{
		return;
	}
	if (L->length == 0)
	{
		// 空表
		return;
	}

	// 保存要删除的位置的值
	*e = L->data[pos];
	// pos+1 --> length-1 
	for (int i = pos + 1; i < L->length; ++i)
	{
		// 前移操作
		L->data[i - 1] = L->data[i];
	}
	// 长度
	L->length--;
}

int ListLength(SqList L)
{
	return L.length;
}

#else

void InitList(SqList *L)
{
	// 初始化
	L->length = 0;
	// 可要可不要
	memset(L->data, 0, sizeof(L->data));
}

int ListEmpty(SqList L)
{
	if (L.length == 0)
	{
		return 1;
	}
	return 0;
}

void ClearList(SqList *L)
{
	InitList(L);
}

void GetElem(SqList L, int pos, void **e)
{
	// pos值是否合法
	if (pos < 0 || pos >= L.length)
	{
		return;
	}
	// 如果为空
	if (L.length == 0)
	{
		return;
	}
	// 赋值
	*e = L.data[pos];
}

void ListInsert(SqList *L, int pos, void* e)
{
	// 错误处理
	if (pos < 0 || pos > L->length)
	{
		return;
	}
	if (L->length >= MAXSIZE)
	{
		// 已满
		return;
	}
	// 移动
	// 从length-1 到 pos 依次后移
	for (int i = L->length - 1; i >= pos; --i)
	{
		L->data[i + 1] = L->data[i];
	}
	// 赋值 -- 数据的拷贝
	L->data[pos] = (unsigned int)e;
	// 
	L->length++;
}

void ListDelete(SqList *L, int pos, void** e)
{
	// 错误处理
	if (pos < 0 || pos >= L->length)
	{
		return;
	}
	if (L->length == 0)
	{
		// 空表
		return;
	}

	// 保存要删除的位置的值
	*e = (void*)L->data[pos];
	// pos+1 --> length-1 
	for (int i = pos + 1; i < L->length; ++i)
	{
		// 前移操作
		L->data[i - 1] = L->data[i];
	}
	// 长度
	L->length--;
}

int ListLength(SqList L)
{
	return L.length;
}

#endif

