#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkList.h"



//创建链表
DLinkList* DLinkList_Create()
{
	//定义结构体类型指针变量,并分配内存空间
	TDLinkList* dlist = (TDLinkList*)malloc(sizeof(TDLinkList));
	//如果分配内存成功,则初始化变量
	if (dlist != NULL)
	{
		dlist->head.next = NULL;
		dlist->slider = NULL;
		dlist->length = 0;
		return (DLinkList*)dlist;
	}
	//失败返回空
	printf("分配内存失败\n");
	return NULL;
}

//销毁链表
void DLinkList_Destroy(DLinkList* list)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//释放内存空间
		free(list);
	}
}

//清空链表
void DLinkList_Clear(DLinkList* list)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		//数据重置
		dlist->length = 0;
		dlist->head.next = NULL;
		dlist->slider = NULL;
	}
}

//获取链表长度
int DLinkList_Length(DLinkList* list)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		return dlist->length;
	}
	printf("DLinkList_Length error: list 指针无效\n");
	return -1;
}

//获取第pos个元素操作
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		//定义辅助指针变量, 并初始化,指向头节点
		DLinkListNode* currNode = &dlist->head;
		//循环查找pos位置元素
		for (int i = 0; i <= pos; ++i)
		{
			currNode = currNode->next;
		}
		return currNode;
	}

	printf("DLinkList_Get error: list 指针无效\n");
	return NULL;
}

//插入元素到位置pos
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		//定义辅助指针变量, 并初始化,指向头节点
		DLinkListNode* currNode = &dlist->head;
		//定义辅助指针变量
		DLinkListNode* posNode = NULL;
		//循环查找pos-1位置元素
		for (int i = 0; i < pos; ++i)
		{
			//判断是否有后继节点
			if (currNode->next != NULL)
			{
				//指针后移
				currNode = currNode->next;
			}
			else
			{
				//没有后继节点,结束循环
				break;
			}
		}
		//赋值,辅助指针变量指向pos位置节点
		posNode = currNode->next;

		//开始插入元素
		//step1: 将新节点的next域指针指向pos位置节点的地址
		node->next = posNode;
		//step2: 将当前节点的next域指针指向新插入节点的地址
		currNode->next = node;
		//step3: 将pos位置的节点的prev域指针指向新插入节点的地址
		//********** 特殊处理 **********
		if (posNode != NULL)	//当链表插入第一个元素需要特殊处理
		{
			posNode->prev = node;
		}
		//step4: 将新插入节点的地址指向当前节点的地址
		node->prev = currNode;
		//********** 特殊处理 **********
		if (currNode == &dlist->head)	//如果链表为空
		{
			//将第一个节点的前驱节点设为空
			node->prev = NULL;
			//游标指向第一个节点
			dlist->slider = node;
		}
		//step4: 链表长度加1
		dlist->length++;

		return 0;
	}

	printf("DLinkList_Insert error: list 指针无效\n");
	return -1;
}

//删除位置pos处的元素
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	//判断list是否为有效指针
	if (list != NULL && pos >= 0)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		//定义辅助指针变量, 并初始化,指向头节点
		DLinkListNode* currNode = &dlist->head;
		//定义辅助指针变量
		DLinkListNode* delNode = NULL;
		DLinkListNode* nextNode = NULL;
		//循环查找pos-1位置元素
		for (int i = 0; i < pos; ++i)
		{
			currNode = currNode->next;
		}
		//赋值
		delNode = currNode->next;
		nextNode = delNode->next;

		//开始删除元素
		//step1: 将当前节点的next域指针指向被删除节点的后继节点
		currNode->next = nextNode;
		//****** 需要特殊处理 ******
		if (nextNode != NULL)
		{
			//step2: nextNode节点的prev域指针指向当前节点的地址
			nextNode->prev = currNode;
			//****** 需要特殊处理 ******
			if (currNode == &dlist->head)	//如果当前节点为头结点
			{
				//将nextNode节点指向空
				nextNode->prev = NULL;
			}
		}
		//step 3: 链表长度减1
		dlist->length--;

		//判断删除的元素是不是当前游标指向的位置
		if (dlist->slider == delNode)
		{
			//如果是,游标后移
			dlist->slider = nextNode;
		}

		return delNode;
	}

	printf("DLinkList_Delete error: list指针 或 pos位置无效\n");
	return NULL;
}

//获取当前游标指向的数据元素
DLinkListNode* DLinkList_Current(DLinkList* list)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		return dlist->slider;
	}

	printf("DLinkList_Current error: list 指针无效\n");
	return NULL;
}

//将游标重置指向链表中的第一个数据元素
DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		dlist->slider = dlist->head.next;
		return dlist->slider;
	}

	printf("DLinkList_Reset error: list 指针无效\n");
	return NULL;
}

//将游标移动指向到链表中的下一个数据元素
DLinkListNode* DLinkList_Next(DLinkList* list)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		//定义链表节点指针保存当前游标地址
		DLinkListNode* currSlider = dlist->slider;
		//游标后移
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

	printf("DLinkList_Next error: list 指针无效\n");
	return NULL;
}

//将游标移动指向到链表中的上一个数据元素
DLinkListNode* DLinkList_Prev(DLinkList* list)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		//定义链表节点指针保存当前游标地址
		DLinkListNode* currSlider = dlist->slider;
		//游标前移
		dlist->slider = dlist->slider->prev;
		return currSlider;
	}

	printf("DLinkList_Prev error: list 指针无效\n");
	return NULL;
}

//直接指定删除链表中的某个数据元素
DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	//判断list是否为有效指针
	if (list != NULL)
	{
		int nPos = 0;
		//定义结构体类型指针,并给其赋值
		TDLinkList* dlist = (TDLinkList*)list;
		//查找与node节点相等的节点
		for (int i = 0; i < dlist->length; ++i)
		{
			if (node == DLinkList_Get(list, i))
			{
				//保存位置
				nPos = i;
				//跳出循环
				break;
			}
		}
		//删除指定nPos位置节点
		DLinkListNode* delNode = DLinkList_Delete(list, nPos);
		return delNode;
	}

	printf("DLinkList_DeleteNode error: list or node 指针无效\n");
	return NULL;
}

