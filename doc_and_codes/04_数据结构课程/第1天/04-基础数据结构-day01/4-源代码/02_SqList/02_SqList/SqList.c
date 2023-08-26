#include "SqList.h"
#include <string.h>

#if 0
void InitList(SqList *L)
{
	// ��ʼ��
	L->length = 0;
	// ��Ҫ�ɲ�Ҫ
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
	// posֵ�Ƿ�Ϸ�
	if (pos < 0 || pos >= L.length)
	{
		return;
	}
	// ���Ϊ��
	if (L.length == 0)
	{
		return;
	}
	// ��ֵ
	*e = L.data[pos];
}

void ListInsert(SqList *L, int pos, ElemType e)
{
	// ������
	if (pos < 0 || pos > L->length)
	{
		return;
	}
	if (L->length >= MAXSIZE)
	{
		// ����
		return;
	}
	// �ƶ�
	// ��length-1 �� pos ���κ���
	for (int i = L->length - 1; i >= pos; --i)
	{
		L->data[i + 1] = L->data[i];
	}
	// ��ֵ -- ���ݵĿ���
	L->data[pos] = e;
	// 
	L->length++;
}

void ListDelete(SqList *L, int pos, ElemType *e)
{
	// ������
	if (pos < 0 || pos >= L->length)
	{
		return;
	}
	if (L->length == 0)
	{
		// �ձ�
		return;
	}

	// ����Ҫɾ����λ�õ�ֵ
	*e = L->data[pos];
	// pos+1 --> length-1 
	for (int i = pos + 1; i < L->length; ++i)
	{
		// ǰ�Ʋ���
		L->data[i - 1] = L->data[i];
	}
	// ����
	L->length--;
}

int ListLength(SqList L)
{
	return L.length;
}

#else

void InitList(SqList *L)
{
	// ��ʼ��
	L->length = 0;
	// ��Ҫ�ɲ�Ҫ
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
	// posֵ�Ƿ�Ϸ�
	if (pos < 0 || pos >= L.length)
	{
		return;
	}
	// ���Ϊ��
	if (L.length == 0)
	{
		return;
	}
	// ��ֵ
	*e = L.data[pos];
}

void ListInsert(SqList *L, int pos, void* e)
{
	// ������
	if (pos < 0 || pos > L->length)
	{
		return;
	}
	if (L->length >= MAXSIZE)
	{
		// ����
		return;
	}
	// �ƶ�
	// ��length-1 �� pos ���κ���
	for (int i = L->length - 1; i >= pos; --i)
	{
		L->data[i + 1] = L->data[i];
	}
	// ��ֵ -- ���ݵĿ���
	L->data[pos] = (unsigned int)e;
	// 
	L->length++;
}

void ListDelete(SqList *L, int pos, void** e)
{
	// ������
	if (pos < 0 || pos >= L->length)
	{
		return;
	}
	if (L->length == 0)
	{
		// �ձ�
		return;
	}

	// ����Ҫɾ����λ�õ�ֵ
	*e = (void*)L->data[pos];
	// pos+1 --> length-1 
	for (int i = pos + 1; i < L->length; ++i)
	{
		// ǰ�Ʋ���
		L->data[i - 1] = L->data[i];
	}
	// ����
	L->length--;
}

int ListLength(SqList L)
{
	return L.length;
}

#endif

