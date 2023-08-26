#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkList.h"



//��������
DLinkList* DLinkList_Create()
{
	//����ṹ������ָ�����,�������ڴ�ռ�
	TDLinkList* dlist = (TDLinkList*)malloc(sizeof(TDLinkList));
	//��������ڴ�ɹ�,���ʼ������
	if (dlist != NULL)
	{
		dlist->head.next = NULL;
		dlist->slider = NULL;
		dlist->length = 0;
		return (DLinkList*)dlist;
	}
	//ʧ�ܷ��ؿ�
	printf("�����ڴ�ʧ��\n");
	return NULL;
}

//��������
void DLinkList_Destroy(DLinkList* list)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//�ͷ��ڴ�ռ�
		free(list);
	}
}

//�������
void DLinkList_Clear(DLinkList* list)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		//��������
		dlist->length = 0;
		dlist->head.next = NULL;
		dlist->slider = NULL;
	}
}

//��ȡ������
int DLinkList_Length(DLinkList* list)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		return dlist->length;
	}
	printf("DLinkList_Length error: list ָ����Ч\n");
	return -1;
}

//��ȡ��pos��Ԫ�ز���
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		//���帨��ָ�����, ����ʼ��,ָ��ͷ�ڵ�
		DLinkListNode* currNode = &dlist->head;
		//ѭ������posλ��Ԫ��
		for (int i = 0; i <= pos; ++i)
		{
			currNode = currNode->next;
		}
		return currNode;
	}

	printf("DLinkList_Get error: list ָ����Ч\n");
	return NULL;
}

//����Ԫ�ص�λ��pos
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		//���帨��ָ�����, ����ʼ��,ָ��ͷ�ڵ�
		DLinkListNode* currNode = &dlist->head;
		//���帨��ָ�����
		DLinkListNode* posNode = NULL;
		//ѭ������pos-1λ��Ԫ��
		for (int i = 0; i < pos; ++i)
		{
			//�ж��Ƿ��к�̽ڵ�
			if (currNode->next != NULL)
			{
				//ָ�����
				currNode = currNode->next;
			}
			else
			{
				//û�к�̽ڵ�,����ѭ��
				break;
			}
		}
		//��ֵ,����ָ�����ָ��posλ�ýڵ�
		posNode = currNode->next;

		//��ʼ����Ԫ��
		//step1: ���½ڵ��next��ָ��ָ��posλ�ýڵ�ĵ�ַ
		node->next = posNode;
		//step2: ����ǰ�ڵ��next��ָ��ָ���²���ڵ�ĵ�ַ
		currNode->next = node;
		//step3: ��posλ�õĽڵ��prev��ָ��ָ���²���ڵ�ĵ�ַ
		//********** ���⴦�� **********
		if (posNode != NULL)	//����������һ��Ԫ����Ҫ���⴦��
		{
			posNode->prev = node;
		}
		//step4: ���²���ڵ�ĵ�ַָ��ǰ�ڵ�ĵ�ַ
		node->prev = currNode;
		//********** ���⴦�� **********
		if (currNode == &dlist->head)	//�������Ϊ��
		{
			//����һ���ڵ��ǰ���ڵ���Ϊ��
			node->prev = NULL;
			//�α�ָ���һ���ڵ�
			dlist->slider = node;
		}
		//step4: �����ȼ�1
		dlist->length++;

		return 0;
	}

	printf("DLinkList_Insert error: list ָ����Ч\n");
	return -1;
}

//ɾ��λ��pos����Ԫ��
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL && pos >= 0)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		//���帨��ָ�����, ����ʼ��,ָ��ͷ�ڵ�
		DLinkListNode* currNode = &dlist->head;
		//���帨��ָ�����
		DLinkListNode* delNode = NULL;
		DLinkListNode* nextNode = NULL;
		//ѭ������pos-1λ��Ԫ��
		for (int i = 0; i < pos; ++i)
		{
			currNode = currNode->next;
		}
		//��ֵ
		delNode = currNode->next;
		nextNode = delNode->next;

		//��ʼɾ��Ԫ��
		//step1: ����ǰ�ڵ��next��ָ��ָ��ɾ���ڵ�ĺ�̽ڵ�
		currNode->next = nextNode;
		//****** ��Ҫ���⴦�� ******
		if (nextNode != NULL)
		{
			//step2: nextNode�ڵ��prev��ָ��ָ��ǰ�ڵ�ĵ�ַ
			nextNode->prev = currNode;
			//****** ��Ҫ���⴦�� ******
			if (currNode == &dlist->head)	//�����ǰ�ڵ�Ϊͷ���
			{
				//��nextNode�ڵ�ָ���
				nextNode->prev = NULL;
			}
		}
		//step 3: �����ȼ�1
		dlist->length--;

		//�ж�ɾ����Ԫ���ǲ��ǵ�ǰ�α�ָ���λ��
		if (dlist->slider == delNode)
		{
			//�����,�α����
			dlist->slider = nextNode;
		}

		return delNode;
	}

	printf("DLinkList_Delete error: listָ�� �� posλ����Ч\n");
	return NULL;
}

//��ȡ��ǰ�α�ָ�������Ԫ��
DLinkListNode* DLinkList_Current(DLinkList* list)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		return dlist->slider;
	}

	printf("DLinkList_Current error: list ָ����Ч\n");
	return NULL;
}

//���α�����ָ�������еĵ�һ������Ԫ��
DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		dlist->slider = dlist->head.next;
		return dlist->slider;
	}

	printf("DLinkList_Reset error: list ָ����Ч\n");
	return NULL;
}

//���α��ƶ�ָ�������е���һ������Ԫ��
DLinkListNode* DLinkList_Next(DLinkList* list)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		//��������ڵ�ָ�뱣�浱ǰ�α��ַ
		DLinkListNode* currSlider = dlist->slider;
		//�α����
		if (dlist->slider->next != NULL)
		{
			dlist->slider = dlist->slider->next;
			return currSlider;
		}
		else
		{
			return NULL;
		}
	}

	printf("DLinkList_Next error: list ָ����Ч\n");
	return NULL;
}

//���α��ƶ�ָ�������е���һ������Ԫ��
DLinkListNode* DLinkList_Prev(DLinkList* list)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		//��������ڵ�ָ�뱣�浱ǰ�α��ַ
		DLinkListNode* currSlider = dlist->slider;
		//�α�ǰ��
		dlist->slider = dlist->slider->prev;
		return currSlider;
	}

	printf("DLinkList_Prev error: list ָ����Ч\n");
	return NULL;
}

//ֱ��ָ��ɾ�������е�ĳ������Ԫ��
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list != NULL)
	{
		int nPos = 0;
		//����ṹ������ָ��,�����丳ֵ
		TDLinkList* dlist = (TDLinkList*)list;
		//������node�ڵ���ȵĽڵ�
		for (int i = 0; i < dlist->length; ++i)
		{
			if (node == DLinkList_Get(list, i))
			{
				//����λ��
				nPos = i;
				//����ѭ��
				break;
			}
		}
		//ɾ��ָ��nPosλ�ýڵ�
		DLinkListNode* delNode = DLinkList_Delete(list, nPos);
		return delNode;
	}

	printf("DLinkList_DeleteNode error: list or node ָ����Ч\n");
	return NULL;
}

