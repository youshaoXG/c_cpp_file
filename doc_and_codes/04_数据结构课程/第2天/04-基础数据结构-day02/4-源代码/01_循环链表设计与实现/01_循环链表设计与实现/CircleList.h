#ifndef _CIRCLE_LIST_H
#define _CIRCLE_LIST_H

//�Զ���ѭ��������������
typedef void CircleList;
//�Զ���ѭ������ڵ���������
typedef struct tag_CirclListNode
{
	struct tag_CirclListNode *next;
}CircleListNode;

//�����ṹ���������
typedef struct tag_CircleList
{
	//ѭ������ͷ���
	CircleListNode	header;
	//ѭ�������α�
	CircleListNode	*slider;
	//ѭ��������
	int				length;
}TCircleList;


//����ѭ������
CircleList* CircleList_Create();

//����ѭ������
void CircleList_Destroy(CircleList* list);

//���ѭ������
void CircleList_Clear(CircleList* list);

//��ȡѭ��������
int CircleList_Length(CircleList* list);

//��ѭ�������в����½ڵ�
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

//��ȡѭ�������е�ָ��λ�õĽڵ�
CircleListNode* CircleList_Get(CircleList* list, int pos);

//ɾ��ѭ�������е�ָ��λ�õĽڵ�
CircleListNode* CircleList_Delete(CircleList* list, int pos);

//------------------ new add ------------------

//ֱ��ָ��ɾ�������е�ĳ������Ԫ��
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

//���α�����ָ�������еĵ�һ������Ԫ��
CircleListNode* CircleList_Reset(CircleList* list);

//��ȡ��ǰ�α�ָ�������Ԫ��
CircleListNode* CircleList_Current(CircleList* list);

//���α��ƶ�ָ�������е���һ������Ԫ��
CircleListNode* CircleList_Next(CircleList* list);

#endif //_CIRCLE_LIST_H