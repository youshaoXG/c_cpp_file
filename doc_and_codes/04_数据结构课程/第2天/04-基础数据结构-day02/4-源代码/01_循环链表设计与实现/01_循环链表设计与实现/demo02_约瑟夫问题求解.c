#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circlelist.h"

/*
	Լɪ������-ѭ���������Ӧ��
	n ����Χ��һ��ԲȦ�����ȵ� 1 ���˴� 1 ��ʼһ����һ����˳ʱ�뱨����
	������ m ���ˣ�������С�Ȼ���ٴ���һ ���˿�ʼ�� 1 ˳ʱ�뱨������
	���� m ���ˣ���������У����������ȥ�������˳��

	���: ���� m = 3, n = 8 (1 2 3 4 5 6 7 8)
	���: 3 6 1 5 2 8 4 7
*/


#if 0
//����ṹ��,�洢����
typedef struct tag_value
{
	CircleListNode header;
	int v;
}Value;

void joseph_question()
{
	int i;
	//����ṹ������
	Value val[8];
	//����ѭ������
	CircleList* list = CircleList_Create();
	//�ж������Ƿ񴴽��ɹ�
	if (list == NULL)
	{
		printf("������ʧ��\n");
		return;
	}
	//��ʼ���ṹ������
	for (i = 0; i < sizeof(val) / sizeof(Value); ++i)
	{
		val[i].v = i+1;
		//��ѭ�������в�������
		CircleList_Insert(list, (CircleListNode*)&val[i], i);
	}
	//����ѭ������
	printf("��������:\n");
	for (i = 0; i < CircleList_Length(list); ++i)
	{
		//��ȡ�α�ָ���Ԫ��Ȼ������
		Value* pVal = (Value*)CircleList_Get(list, i);
		printf("%d\t", pVal->v);
	}

	//�����α�
	CircleList_Reset(list);
	//ѭ��ɾ��ָ��λ�õ�Ԫ��
	printf("\n\n����ɾ���Ľڵ�Ϊ:\n");
	while (CircleList_Length(list) > 0)
	{
		//����ṹ��ָ�����,ָ�����������Ԫ��
		Value* pVal = NULL;
		//������������ָ��λ�õ�Ԫ��
		for (i = 0; i < 3-1; ++i)	//3Ϊ�����е�m
		{
			//����ƶ��α�
			pVal = (Value*)CircleList_Next(list);
		}
		//������������Ľڵ�
		pVal = (Value*)CircleList_Current(list);
		//��ӡ�ڵ���Ϣ
		printf("%d\t", pVal->v);
		//��������ɾ�����������Ľڵ�
		CircleList_DeleteNode(list, (CircleListNode*)pVal);
	}
	printf("\n");
	//����ѭ������
	CircleList_Destroy(list);
}

#else
// �������ݽṹ
// ҵ��ڵ�Ķ���
typedef struct _Value
{
	// �ڲ�������ڵ�
	CircleListNode node;
	int v;	// ����
}Value;


void joseph_question()
{
	Value val[8];
	// ����ѭ������
	CircleList *list = CircleList_Create();
	// ��ʼ������
	for (int i = 0; i < 8; ++i)
	{
		val[i].v = i + 1;
		// �ڵ���뵽����
		CircleList_Insert(list, &val[i].node, i);
		//CircleList_Insert(list, (CircleListNode*)&val[i], i);
	}
	// ����
	for (int i = 0; i < CircleList_Length(list); ++i)
	{
		Value* p = (Value*)CircleList_Get(list, i);
		printf("%d  ", p->v);
	}
	printf("\n");

	// ���������
	// �α�����, ָ���һ�����ݽڵ�
	printf("ɾ���Ľڵ�Ĵ���\n");
	CircleList_Reset(list);
	while (CircleList_Length(list))
	{
		// �α���ƵĲ���
		for (int i = 0; i < 2; ++i)
		{
			// �α����
			CircleList_Next(list);
		}
		// ��ȡ��ǰ�α�ָ��Ľڵ�
		Value* p = (Value*)CircleList_Current(list);
		// 
		printf("%d  ", p->v);
		// ɾ����ǰ�ڵ�
		CircleList_DeleteNode(list, (CircleListNode*)p);
	}
	CircleList_Destroy(list);

}

#endif

#if 1
void main()
{
	joseph_question();
	system("pause");
}
#endif