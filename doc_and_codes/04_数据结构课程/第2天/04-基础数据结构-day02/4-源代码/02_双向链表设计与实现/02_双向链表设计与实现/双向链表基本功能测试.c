#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkList.h"

//定义数据结构体
typedef struct tag_value
{
	//包含双向链表的一个节点
	DLinkListNode head;
	int value;
}Value;

//双向链表测试程序
void dLinkListTest()
{
	int i;
	//定义结构体数组
	Value val[10];
	//创建双向链表
	DLinkList *dlist = DLinkList_Create();
	//判断是否创建成功
	if (dlist == NULL)
	{
		printf("双向链表创建失败\n");
		return;
	}
	//初始化并向链表中插入数据
	for (i = 0; i < sizeof(val) / sizeof(Value); ++i)
	{
		val[i].value = i + 10;
		//向尾部插入元素
		DLinkList_Insert(dlist, (DLinkListNode*)&val[i], i);
	}
	//遍历双向链表
	printf("遍历双向链表\n");
	for (int i = 0; i < DLinkList_Length(dlist); ++i)
	{
		//获取指定位置元素
		Value* val = (Value*)DLinkList_Get(dlist, i);
		printf("%d\t", val->value);
	}
	printf("\n");

	//删除最后一个节点
	DLinkList_Delete(dlist, DLinkList_Length(dlist) - 1);
	//删除第一节点
	DLinkList_Delete(dlist, 0);
	//再次遍历链表
	printf("再次遍历双向链表\n");
	for (int i = 0; i < DLinkList_Length(dlist); ++i)
	{
		//获取指定位置元素
		Value* val = (Value*)DLinkList_Get(dlist, i);
		printf("%d\t", val->value);
	}
	printf("\n");

	//重置游标
	DLinkList_Reset(dlist);
	//游标后移
	DLinkList_Next(dlist);
	//获取当前游标指向的节点
	Value* pVal = (Value*)DLinkList_Current(dlist);
	//打印当前节点的value值
	printf("DLinkList_Next --- 打印当前节点的value值: value = %d\n", pVal->value);
	//删除游标指向的当前节点
	DLinkList_DeleteNode(dlist, (DLinkListNode*)pVal);
	//再次获取当前游标指向的节点
	pVal = (Value*)DLinkList_Current(dlist);
	//再次打印当前节点的value值
	printf("DLinklist_DeleteNode --- 再次打印当前节点的value值: value = %d\n", pVal->value);

	//向前移动游标
	DLinkList_Prev(dlist);
	//第三次获取当前游标指向的节点
	pVal = (Value*)DLinkList_Current(dlist);
	//第三次打印当前节点的value值
	printf("DLinkList_Prev --- 再次打印当前节点的value值: value = %d\n", pVal->value);

	//打印链表的长度
	printf("打印链表的长度, Length = %d\n", DLinkList_Length(dlist));

	//销毁双向链表
	DLinkList_Destroy(dlist);
}

void main()
{
	dLinkListTest();
	system("pause");
}