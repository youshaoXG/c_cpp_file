#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"


//����ѭ������
CircleList* CircleList_Create()
{
	//����TCircleListָ�����,�������ڴ�ռ�
	TCircleList* tlist = (TCircleList*)malloc(sizeof(TCircleList));
	if (tlist == NULL)
	{
		printf("error: TCircleList* tlist = (TCircleList*)malloc(sizeof(TCircleList)) \n");
		return NULL;
	}
	//���ݳ�ʼ��
	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;

	return (CircleList*)tlist;
}

//����ѭ������
void CircleList_Destroy(CircleList* list)
{
	//����TCircleListָ�����
	TCircleList *tlist = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL)
	{
		printf("Destory error: list Ϊ��Чָ��\n");
		return;
	}
	free(list);
}


//���ѭ������
void CircleList_Clear(CircleList* list)
{
	//����TCircleListָ�����
	TCircleList *tlist = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL)
	{
		printf("Clear error: list Ϊ��Чָ��\n");
		return;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;
	//����������Ϊ0
	tlist->length = 0;
	//ͷ���ָ����ָ���
	tlist->header.next = NULL;
	//�α�ָ���
	tlist->slider = NULL;
}


//��ȡѭ��������
int CircleList_Length(CircleList* list)
{
	//����TCircleListָ�����
	TCircleList *tlist = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL)
	{
		printf("Length error: list Ϊ��Чָ��\n");
		return -1;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;

	return tlist->length;
}


//��ѭ�������в����½ڵ�
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	int i;
	//����TCircleListָ�����
	TCircleList		*tlist = NULL;
	//���帨��ָ�����
	CircleListNode	*currentNode = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("Insert error: if (list == NULL || node == NULL || pos < 0)\n");
		return -1;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;

	//Ԫ�ز���
	//step 1: ʹ�ø���ָ�����,ָ��ͷ���
	currentNode = &tlist->header;
	//step 2: �ҵ�pos-1λ�ýڵ�
	for (i = 0; i < pos; ++i)
	{
		//�ж��Ƿ��к�̽ڵ�
		if (currentNode->next != NULL)
		{
			//ָ�����
			currentNode = currentNode->next;
		}
		else
		{
			//û�к�̽ڵ�����ѭ��
			break;
		}
	}
	//step 3: ��node�ڵ��ָ��ָ��ǰ�ڵ�(pos-1)�ĺ�̽ڵ�(pos)
	node->next = currentNode->next;
	//step 4: ��ǰ�ڵ��ָ��ָ��node�ڵ�ĵ�ַ
	currentNode->next = node;
	//step 5: ����ǵ�һ�β���ڵ�
	if (tlist->length == 0)
	{
		//���α�ָ���²���ڵ�
		tlist->slider = node;
	}
	//step 6: �����ȼ�1
	tlist->length++;
	//step 7:��ͷ�巨 currentNode��Ȼָ��ͷ��
	//ԭ��: ��0��, û������
	if (currentNode == &tlist->header)
	{
		CircleListNode* lastNode = CircleList_Get(list, tlist->length - 1);
		//���һ���ڵ��ָ��,ָ���һ�����ݽڵ�
		lastNode->next = currentNode->next;
	}
	return 0;
}


//��ȡѭ�������е�ָ��λ�õĽڵ�
CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	int				i;
	//����TCircleListָ�����
	TCircleList		*tlist = NULL;
	//���帨��ָ�����
	CircleListNode	*currentNode = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL || pos < 0)
	{
		printf("CircleList_Get error: if (list == NULL || pos < 0)\n");
		return NULL;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;

	//step 1: ʹ�ø���ָ�����,ָ��ͷ���
	currentNode = &tlist->header;
	//step 2: �ҵ�posλ�ýڵ�
	for (i = 0; i <= pos; ++i)
	{
		//�ж��Ƿ��к�̽ڵ�
		if (currentNode->next != NULL)
		{
			//ָ�����
			currentNode = currentNode->next;
		}
		else
		{
			//û�к�̽ڵ�����ѭ��
			printf("error: û�ҵ�ָ��λ�õ�Ԫ��\n");
			return NULL;
		}
	}

	return currentNode;
}


//ɾ��ѭ�������е�ָ��λ�õĽڵ�
//-------------------------------
CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	int				i;
	//����TCircleListָ�����
	TCircleList		*tlist = NULL;
	//��������ڵ�ָ��,����Ҫɾ���Ľڵ��ַ
	CircleListNode	*deleteNode = NULL;
	//��������ڵ�ָ��,�������һ���ڵ�
	CircleListNode  *lastNode = NULL;
	//���帨��ָ�����
	CircleListNode  *currentNode = NULL;


	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL || pos < 0)
	{
		printf("CircleList_Delete error: if (list == NULL || pos < 0)\n");
		return NULL;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;
	//�ж��������Ƿ��нڵ�
	if (tlist->length <= 0)
	{
		printf("error: ����Ϊ��,����ɾ��\n");
		return NULL;
	}

	//Ԫ��ɾ��
	//step 1: ����ָ�����,ָ��ͷ���
	currentNode = &tlist->header;
	//step 2: �ҵ�pos-1λ�ýڵ�
	for (i = 0; i < pos; ++i)
	{
		//ָ�����
		currentNode = currentNode->next;
	}
	//step 3: ����Ҫɾ���Ľڵ�ĵ�ַ
	deleteNode = currentNode->next;
	//step 4-1: �ж�ɾ����Ԫ���Ƿ�Ϊ��һ��Ԫ��
	if (currentNode == &tlist->header)
	{
		//step 4-2: �ҵ����һ���ڵ�
		lastNode = CircleList_Get(list, tlist->length - 1);
	}
	//step 4-3: �ж�lastNode�Ƿ�Ϊ��
	if (lastNode != NULL)
	{
		//step 4-4: �����һ���ڵ�ĵ�ַָ��Ҫɾ���ڵ�ĺ�̽ڵ�
		lastNode->next = deleteNode->next;
	}
	//step 4-5: ��ͷ����ָ��ָ��Ҫɾ���ڵ�ĺ�̽ڵ�
	currentNode->next = deleteNode->next;
	//step 5: �����ȼ�1
	tlist->length--;
	//step 6-1: �ж�ɾ����Ԫ���Ƿ�Ϊ�α�ָ���Ԫ��
	if (tlist->slider == deleteNode)
	{
		//step 6-2: �α����
		tlist->slider = deleteNode->next;
	}
	//step 7-1: �ж�ɾ��Ԫ�غ�,�������Ƿ�Ϊ��
	if (tlist->length == 0)
	{
		//step 7-2: ����ͷ���ָ����ָ���
		tlist->header.next = NULL;
		//step 7-3: �����α�ָ���
		tlist->slider = NULL;
	}

	return deleteNode;
}


//------------------ new add ------------------

//ֱ��ָ��ɾ�������е�ĳ������Ԫ��
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	int			i;
	int			nPos = 0;
	//����TCircleListָ�����
	TCircleList *tlist = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL || node == NULL)
	{
		printf("CircleList_DeleteNode error: if (list == NULL || node == NULL)\n");
		return NULL;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;

	//���帨��ָ�����,ָ��ͷ���
	CircleListNode* currentNode = &tlist->header;
	//���帨��ָ�����,��������Ҫɾ���Ľڵ��ַ
	CircleListNode* delNode = NULL;
	//����node�ڵ���ѭ�������е�λ��
	for (i = 0; i < tlist->length; ++i)
	{
		//�ӵ�һ�����ݽڵ㿪ʼ�ж�,���ҵ���node�Ľڵ�
		if (currentNode->next == node)
		{
			//������node�ڵ���ȵĽڵ��λ��
			nPos = i;
			//����Ҫɾ���Ľڵ��ַ
			delNode = currentNode->next;
			//����ѭ��
			break;
		}
		//��ǰ�ڵ�ָ�����
		currentNode = currentNode->next;
	}
	//����ҵ�delNode,����nPosɾ���ýڵ�
	if (delNode != NULL)
	{
		//ɾ��ָ��λ�õ�Ԫ��
		CircleList_Delete(list, nPos);
	}

	return delNode;
}


//���α�����ָ�������еĵ�һ������Ԫ��
CircleListNode* CircleList_Reset(CircleList* list)
{
	//����TCircleListָ�����
	TCircleList *tlist = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL)
	{
		printf("CircleList_Reset error: if (list == NULL)\n");
		return NULL;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;
	//�����α�λ��
	tlist->slider = tlist->header.next;

	return tlist->slider;
}


//��ȡ��ǰ�α�ָ�������Ԫ��
CircleListNode* CircleList_Current(CircleList* list)
{
	//����TCircleListָ�����
	TCircleList *tlist = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL)
	{
		printf("CircleList_Current error: if (list == NULL)\n");
		return NULL;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;

	return tlist->slider;
}


//���α��ƶ�ָ�������е���һ������Ԫ��
CircleListNode* CircleList_Next(CircleList* list)
{
	//��������ڵ�ָ�����
	CircleListNode	*currNode = NULL;
	//����TCircleListָ�����
	TCircleList		*tlist = NULL;
	//�ж�list�Ƿ�Ϊ��Чָ��
	if (list == NULL)
	{
		printf("CircleList_Next error: if (list == NULL)\n");
		return NULL;
	}
	//����ת������ֵ
	tlist = (TCircleList*)list;
	//�洢��ǰ�α�λ��
	currNode = tlist->slider;

	//�жϵ�ǰ�α��Ƿ�ָ���
	if (tlist->slider != NULL)
	{
		//�α����
		tlist->slider = currNode->next;
	}

	return currNode;
}

