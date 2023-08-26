#ifndef _DLINK_LIST_H
#define _DLINK_LIST_H

//自定义双向链表数据类型
typedef void DLinkList;
//自定义双向链表节点数据类型
typedef struct tag_dLinkListNode
{
	struct tag_dLinkListNode *prev;
	struct tag_dLinkListNode *next;
}DLinkListNode;

//定义管理双向链表的结构体
typedef struct _tag_dlinklist
{
	DLinkListNode head;
	DLinkListNode *slider;
	int length;
}TDLinkList;
 
//创建链表
DLinkList* DLinkList_Create();

//销毁链表
void DLinkList_Destroy(DLinkList* list);

//清空链表
void DLinkList_Clear(DLinkList* list);

//获取链表长度
int DLinkList_Length(DLinkList* list);

//获取第pos个元素操作
DLinkListNode* DLinkList_Get(DLinkList* list, int pos);

//插入元素到位置pos
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);

//删除位置pos处的元素
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);

//获取当前游标指向的数据元素
DLinkListNode* DLinkList_Current(DLinkList* list);

//将游标重置指向链表中的第一个数据元素
DLinkListNode* DLinkList_Reset(DLinkList* list);

//将游标移动指向到链表中的下一个数据元素
DLinkListNode* DLinkList_Next(DLinkList* list);

//将游标移动指向到链表中的上一个数据元素
DLinkListNode* DLinkList_Prev(DLinkList* list);

//直接指定删除链表中的某个数据元素
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node);

#endif //_DLINK_LIST_H