#ifndef _DLINK_LIST_H
#define _DLINK_LIST_H

//�Զ���˫��������������
typedef void DLinkList;
//�Զ���˫������ڵ���������
typedef struct tag_dLinkListNode
{
	struct tag_dLinkListNode *prev;
	struct tag_dLinkListNode *next;
}DLinkListNode;

//�������˫������Ľṹ��
typedef struct _tag_dlinklist
{
	DLinkListNode head;
	DLinkListNode *slider;
	int length;
}TDLinkList;
 
//��������
DLinkList* DLinkList_Create();

//��������
void DLinkList_Destroy(DLinkList* list);

//�������
void DLinkList_Clear(DLinkList* list);

//��ȡ������
int DLinkList_Length(DLinkList* list);

//��ȡ��pos��Ԫ�ز���
DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

//����Ԫ�ص�λ��pos
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

//ɾ��λ��pos����Ԫ��
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);

//��ȡ��ǰ�α�ָ�������Ԫ��
DLinkListNode* DLinkList_Current(DLinkList* list);

//���α�����ָ�������еĵ�һ������Ԫ��
DLinkListNode* DLinkList_Reset(DLinkList* list);

//���α��ƶ�ָ�������е���һ������Ԫ��
DLinkListNode* DLinkList_Next(DLinkList* list);

//���α��ƶ�ָ�������е���һ������Ԫ��
DLinkListNode* DLinkList_Prev(DLinkList* list);

//ֱ��ָ��ɾ�������е�ĳ������Ԫ��
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);

#endif //_DLINK_LIST_H