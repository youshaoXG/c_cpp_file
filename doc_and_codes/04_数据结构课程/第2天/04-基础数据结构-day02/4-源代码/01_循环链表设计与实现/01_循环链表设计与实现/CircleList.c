#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"


//创建循环链表
CircleList* CircleList_Create()
{
	//定义TCircleList指针变量,并分配内存空间
	TCircleList* tlist = (TCircleList*)malloc(sizeof(TCircleList));
	if (tlist == NULL)
	{
		printf("error: TCircleList* tlist = (TCircleList*)malloc(sizeof(TCircleList)) \n");
		return NULL;
	}
	//数据初始化
	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;

	return (CircleList*)tlist;
}

//销毁循环链表
void CircleList_Destroy(CircleList* list)
{
	//定义TCircleList指针变量
	TCircleList *tlist = NULL;
	//判断list是否为有效指针
	if (list == NULL)
	{
		printf("Destory error: list 为无效指针\n");
		return;
	}
	free(list);
}


//清空循环链表
void CircleList_Clear(CircleList* list)
{
	//定义TCircleList指针变量
	TCircleList *tlist = NULL;
	//判断list是否为有效指针
	if (list == NULL)
	{
		printf("Clear error: list 为无效指针\n");
		return;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;
	//将长度重置为0
	tlist->length = 0;
	//头结点指针域指向空
	tlist->header.next = NULL;
	//游标指向空
	tlist->slider = NULL;
}


//获取循环链表长度
int CircleList_Length(CircleList* list)
{
	//定义TCircleList指针变量
	TCircleList *tlist = NULL;
	//判断list是否为有效指针
	if (list == NULL)
	{
		printf("Length error: list 为无效指针\n");
		return -1;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;

	return tlist->length;
}


//在循环链表中插入新节点
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	int i;
	//定义TCircleList指针变量
	TCircleList		*tlist = NULL;
	//定义辅助指针变量
	CircleListNode	*currentNode = NULL;
	//判断list是否为有效指针
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("Insert error: if (list == NULL || node == NULL || pos < 0)\n");
		return -1;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;

	//元素插入
	//step 1: 使用辅助指针变量,指向头结点
	currentNode = &tlist->header;
	//step 2: 找到pos-1位置节点
	for (i = 0; i < pos; ++i)
	{
		//判断是否有后继节点
		if (currentNode->next != NULL)
		{
			//指针后移
			currentNode = currentNode->next;
		}
		else
		{
			//没有后继节点跳出循环
			break;
		}
	}
	//step 3: 将node节点的指针指向当前节点(pos-1)的后继节点(pos)
	node->next = currentNode->next;
	//step 4: 当前节点的指针指向node节点的地址
	currentNode->next = node;
	//step 5: 如果是第一次插入节点
	if (tlist->length == 0)
	{
		//将游标指向新插入节点
		tlist->slider = node;
	}
	//step 6: 链表长度加1
	tlist->length++;
	//step 7:若头插法 currentNode仍然指向头部
	//原因: 跳0步, 没有跳走
	if (currentNode == &tlist->header)
	{
		CircleListNode* lastNode = CircleList_Get(list, tlist->length - 1);
		//最后一个节点的指针,指向第一个数据节点
		lastNode->next = currentNode->next;
	}
	return 0;
}


//获取循环链表中的指定位置的节点
CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	int				i;
	//定义TCircleList指针变量
	TCircleList		*tlist = NULL;
	//定义辅助指针变量
	CircleListNode	*currentNode = NULL;
	//判断list是否为有效指针
	if (list == NULL || pos < 0)
	{
		printf("CircleList_Get error: if (list == NULL || pos < 0)\n");
		return NULL;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;

	//step 1: 使用辅助指针变量,指向头结点
	currentNode = &tlist->header;
	//step 2: 找到pos位置节点
	for (i = 0; i <= pos; ++i)
	{
		//判断是否有后继节点
		if (currentNode->next != NULL)
		{
			//指针后移
			currentNode = currentNode->next;
		}
		else
		{
			//没有后继节点跳出循环
			printf("error: 没找到指定位置的元素\n");
			return NULL;
		}
	}

	return currentNode;
}


//删除循环链表中的指定位置的节点
//-------------------------------
CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	int				i;
	//定义TCircleList指针变量
	TCircleList		*tlist = NULL;
	//定义链表节点指针,保存要删除的节点地址
	CircleListNode	*deleteNode = NULL;
	//定义链表节点指针,保存最后一个节点
	CircleListNode  *lastNode = NULL;
	//定义辅助指针变量
	CircleListNode  *currentNode = NULL;


	//判断list是否为有效指针
	if (list == NULL || pos < 0)
	{
		printf("CircleList_Delete error: if (list == NULL || pos < 0)\n");
		return NULL;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;
	//判断链表中是否有节点
	if (tlist->length <= 0)
	{
		printf("error: 链表为空,不能删除\n");
		return NULL;
	}

	//元素删除
	//step 1: 辅助指针变量,指向头结点
	currentNode = &tlist->header;
	//step 2: 找到pos-1位置节点
	for (i = 0; i < pos; ++i)
	{
		//指针后移
		currentNode = currentNode->next;
	}
	//step 3: 保存要删除的节点的地址
	deleteNode = currentNode->next;
	//step 4-1: 判断删除的元素是否为第一个元素
	if (currentNode == &tlist->header)
	{
		//step 4-2: 找到最后一个节点
		lastNode = CircleList_Get(list, tlist->length - 1);
	}
	//step 4-3: 判断lastNode是否为空
	if (lastNode != NULL)
	{
		//step 4-4: 将最后一个节点的地址指向要删除节点的后继节点
		lastNode->next = deleteNode->next;
	}
	//step 4-5: 将头结点的指针指向要删除节点的后继节点
	currentNode->next = deleteNode->next;
	//step 5: 链表长度减1
	tlist->length--;
	//step 6-1: 判断删除的元素是否为游标指向的元素
	if (tlist->slider == deleteNode)
	{
		//step 6-2: 游标后移
		tlist->slider = deleteNode->next;
	}
	//step 7-1: 判断删除元素后,链表长度是否为零
	if (tlist->length == 0)
	{
		//step 7-2: 链表头结点指针域指向空
		tlist->header.next = NULL;
		//step 7-3: 链表游标指向空
		tlist->slider = NULL;
	}

	return deleteNode;
}


//------------------ new add ------------------

//直接指定删除链表中的某个数据元素
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	int			i;
	int			nPos = 0;
	//定义TCircleList指针变量
	TCircleList *tlist = NULL;
	//判断list是否为有效指针
	if (list == NULL || node == NULL)
	{
		printf("CircleList_DeleteNode error: if (list == NULL || node == NULL)\n");
		return NULL;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;

	//定义辅助指针变量,指向头结点
	CircleListNode* currentNode = &tlist->header;
	//定义辅助指针变量,用来保存要删除的节点地址
	CircleListNode* delNode = NULL;
	//查找node节点在循环链表中的位置
	for (i = 0; i < tlist->length; ++i)
	{
		//从第一个数据节点开始判断,查找等于node的节点
		if (currentNode->next == node)
		{
			//保存与node节点相等的节点的位置
			nPos = i;
			//保存要删除的节点地址
			delNode = currentNode->next;
			//跳出循环
			break;
		}
		//当前节点指针后移
		currentNode = currentNode->next;
	}
	//如果找到delNode,根据nPos删除该节点
	if (delNode != NULL)
	{
		//删除指定位置的元素
		CircleList_Delete(list, nPos);
	}

	return delNode;
}


//将游标重置指向链表中的第一个数据元素
CircleListNode* CircleList_Reset(CircleList* list)
{
	//定义TCircleList指针变量
	TCircleList *tlist = NULL;
	//判断list是否为有效指针
	if (list == NULL)
	{
		printf("CircleList_Reset error: if (list == NULL)\n");
		return NULL;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;
	//重置游标位置
	tlist->slider = tlist->header.next;

	return tlist->slider;
}


//获取当前游标指向的数据元素
CircleListNode* CircleList_Current(CircleList* list)
{
	//定义TCircleList指针变量
	TCircleList *tlist = NULL;
	//判断list是否为有效指针
	if (list == NULL)
	{
		printf("CircleList_Current error: if (list == NULL)\n");
		return NULL;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;

	return tlist->slider;
}


//将游标移动指向到链表中的下一个数据元素
CircleListNode* CircleList_Next(CircleList* list)
{
	//定义链表节点指针变量
	CircleListNode	*currNode = NULL;
	//定义TCircleList指针变量
	TCircleList		*tlist = NULL;
	//判断list是否为有效指针
	if (list == NULL)
	{
		printf("CircleList_Next error: if (list == NULL)\n");
		return NULL;
	}
	//类型转换并赋值
	tlist = (TCircleList*)list;
	//存储当前游标位置
	currNode = tlist->slider;

	//判断当前游标是否指向空
	if (tlist->slider != NULL)
	{
		//游标后移
		tlist->slider = currNode->next;
	}

	return currNode;
}

