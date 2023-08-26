#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circlelist.h"

/*
	约瑟夫问题-循环链表典型应用
	n 个人围成一个圆圈，首先第 1 个人从 1 开始一个人一个人顺时针报数，
	报到第 m 个人，令其出列。然后再从下一 个人开始从 1 顺时针报数，报
	到第 m 个人，再令其出列，…，如此下去，求出列顺序。

	求解: 假设 m = 3, n = 8 (1 2 3 4 5 6 7 8)
	结果: 3 6 1 5 2 8 4 7
*/


#if 0
//定义结构体,存储数据
typedef struct tag_value
{
	CircleListNode header;
	int v;
}Value;

void joseph_question()
{
	int i;
	//定义结构体数组
	Value val[8];
	//创建循环链表
	CircleList* list = CircleList_Create();
	//判断链表是否创建成功
	if (list == NULL)
	{
		printf("链表创建失败\n");
		return;
	}
	//初始化结构体数组
	for (i = 0; i < sizeof(val) / sizeof(Value); ++i)
	{
		val[i].v = i+1;
		//往循环链表中插入数据
		CircleList_Insert(list, (CircleListNode*)&val[i], i);
	}
	//遍历循环链表
	printf("插入数据:\n");
	for (i = 0; i < CircleList_Length(list); ++i)
	{
		//获取游标指向的元素然后下移
		Value* pVal = (Value*)CircleList_Get(list, i);
		printf("%d\t", pVal->v);
	}

	//重置游标
	CircleList_Reset(list);
	//循环删除指定位置的元素
	printf("\n\n依次删除的节点为:\n");
	while (CircleList_Length(list) > 0)
	{
		//定义结构体指针变量,指向符合条件的元素
		Value* pVal = NULL;
		//根据条件查找指定位置的元素
		for (i = 0; i < 3-1; ++i)	//3为案例中的m
		{
			//向后移动游标
			pVal = (Value*)CircleList_Next(list);
		}
		//保存符合条件的节点
		pVal = (Value*)CircleList_Current(list);
		//打印节点信息
		printf("%d\t", pVal->v);
		//从链表中删除符合条件的节点
		CircleList_DeleteNode(list, (CircleListNode*)pVal);
	}
	printf("\n");
	//销毁循环链表
	CircleList_Destroy(list);
}

#else
// 定义数据结构
// 业务节点的定义
typedef struct _Value
{
	// 内部的链表节点
	CircleListNode node;
	int v;	// 数据
}Value;


void joseph_question()
{
	Value val[8];
	// 创建循环链表
	CircleList *list = CircleList_Create();
	// 初始化数组
	for (int i = 0; i < 8; ++i)
	{
		val[i].v = i + 1;
		// 节点插入到链表
		CircleList_Insert(list, &val[i].node, i);
		//CircleList_Insert(list, (CircleListNode*)&val[i], i);
	}
	// 遍历
	for (int i = 0; i < CircleList_Length(list); ++i)
	{
		Value* p = (Value*)CircleList_Get(list, i);
		printf("%d  ", p->v);
	}
	printf("\n");

	// 出链表操作
	// 游标重置, 指向第一个数据节点
	printf("删除的节点的次序\n");
	CircleList_Reset(list);
	while (CircleList_Length(list))
	{
		// 游标后移的步长
		for (int i = 0; i < 2; ++i)
		{
			// 游标后移
			CircleList_Next(list);
		}
		// 获取当前游标指向的节点
		Value* p = (Value*)CircleList_Current(list);
		// 
		printf("%d  ", p->v);
		// 删除当前节点
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