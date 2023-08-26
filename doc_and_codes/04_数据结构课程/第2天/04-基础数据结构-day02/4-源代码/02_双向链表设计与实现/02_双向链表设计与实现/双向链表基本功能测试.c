#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkList.h"

//�������ݽṹ��
typedef struct tag_value
{
	//����˫�������һ���ڵ�
	DLinkListNode head;
	int value;
}Value;

//˫��������Գ���
void dLinkListTest()
{
	int i;
	//����ṹ������
	Value val[10];
	//����˫������
	DLinkList *dlist = DLinkList_Create();
	//�ж��Ƿ񴴽��ɹ�
	if (dlist == NULL)
	{
		printf("˫��������ʧ��\n");
		return;
	}
	//��ʼ�����������в�������
	for (i = 0; i < sizeof(val) / sizeof(Value); ++i)
	{
		val[i].value = i + 10;
		//��β������Ԫ��
		DLinkList_Insert(dlist, (DLinkListNode*)&val[i], i);
	}
	//����˫������
	printf("����˫������\n");
	for (int i = 0; i < DLinkList_Length(dlist); ++i)
	{
		//��ȡָ��λ��Ԫ��
		Value* val = (Value*)DLinkList_Get(dlist, i);
		printf("%d\t", val->value);
	}
	printf("\n");

	//ɾ�����һ���ڵ�
	DLinkList_Delete(dlist, DLinkList_Length(dlist) - 1);
	//ɾ����һ�ڵ�
	DLinkList_Delete(dlist, 0);
	//�ٴα�������
	printf("�ٴα���˫������\n");
	for (int i = 0; i < DLinkList_Length(dlist); ++i)
	{
		//��ȡָ��λ��Ԫ��
		Value* val = (Value*)DLinkList_Get(dlist, i);
		printf("%d\t", val->value);
	}
	printf("\n");

	//�����α�
	DLinkList_Reset(dlist);
	//�α����
	DLinkList_Next(dlist);
	//��ȡ��ǰ�α�ָ��Ľڵ�
	Value* pVal = (Value*)DLinkList_Current(dlist);
	//��ӡ��ǰ�ڵ��valueֵ
	printf("DLinkList_Next --- ��ӡ��ǰ�ڵ��valueֵ: value = %d\n", pVal->value);
	//ɾ���α�ָ��ĵ�ǰ�ڵ�
	DLinkList_DeleteNode(dlist, (DLinkListNode*)pVal);
	//�ٴλ�ȡ��ǰ�α�ָ��Ľڵ�
	pVal = (Value*)DLinkList_Current(dlist);
	//�ٴδ�ӡ��ǰ�ڵ��valueֵ
	printf("DLinklist_DeleteNode --- �ٴδ�ӡ��ǰ�ڵ��valueֵ: value = %d\n", pVal->value);

	//��ǰ�ƶ��α�
	DLinkList_Prev(dlist);
	//�����λ�ȡ��ǰ�α�ָ��Ľڵ�
	pVal = (Value*)DLinkList_Current(dlist);
	//�����δ�ӡ��ǰ�ڵ��valueֵ
	printf("DLinkList_Prev --- �ٴδ�ӡ��ǰ�ڵ��valueֵ: value = %d\n", pVal->value);

	//��ӡ����ĳ���
	printf("��ӡ����ĳ���, Length = %d\n", DLinkList_Length(dlist));

	//����˫������
	DLinkList_Destroy(dlist);
}

void main()
{
	dLinkListTest();
	system("pause");
}