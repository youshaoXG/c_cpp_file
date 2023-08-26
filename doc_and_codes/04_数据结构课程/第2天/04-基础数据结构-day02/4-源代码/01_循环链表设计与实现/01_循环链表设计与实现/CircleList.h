#ifndef _CIRCLE_LIST_H
#define _CIRCLE_LIST_H

//自定义循环链表数据类型
typedef void CircleList;
//自定义循环链表节点数据类型
typedef struct tag_CirclListNode
{
	struct tag_CirclListNode *next;
}CircleListNode;

//创建结构体管理链表
typedef struct tag_CircleList
{
	//循环链表头结点
	CircleListNode	header;
	//循环链表游标
	CircleListNode	*slider;
	//循环链表长度
	int				length;
}TCircleList;


//创建循环链表
CircleList* CircleList_Create();

//销毁循环链表
void CircleList_Destroy(CircleList* list);

//清空循环链表
void CircleList_Clear(CircleList* list);

//获取循环链表长度
int CircleList_Length(CircleList* list);

//在循环链表中插入新节点
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

//获取循环链表中的指定位置的节点
CircleListNode* CircleList_Get(CircleList* list, int pos);

//删除循环链表中的指定位置的节点
CircleListNode* CircleList_Delete(CircleList* list, int pos);

//------------------ new add ------------------

//直接指定删除链表中的某个数据元素
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

//将游标重置指向链表中的第一个数据元素
CircleListNode* CircleList_Reset(CircleList* list);

//获取当前游标指向的数据元素
CircleListNode* CircleList_Current(CircleList* list);

//将游标移动指向到链表中的下一个数据元素
CircleListNode* CircleList_Next(CircleList* list);

#endif //_CIRCLE_LIST_H