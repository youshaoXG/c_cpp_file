#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"

typedef struct tag_value
{
	CircleListNode circleNode;
	int v;
}Value;

#if 0
int main()
{
	int i;
	//定义Value结构体数组
	Value val[10];	//创建循环链表
	CircleList* list = CircleList_Create();

	//循环初始化数组
	for (i = 0; i < sizeof(val) / sizeof(Value); ++i)
	{
		val[i].v = i + 20;
		//往循环链表中插入数据
		CircleList_Insert(list, (CircleListNode*)&val[i], i);
	}
	//遍历循环链表
	//************* 怎么证明是循环链表? *************
	for (i = 0; i < CircleList_Length(list) * 2; ++i)	//打印两遍
	{
		Value *pVal = (Value*)CircleList_Get(list, i);
		printf("Value %d = %d\n", i, pVal->v);
	}
	//删除节点
	while (CircleList_Length(list) > 0)
	{
		Value *pVal = (Value*)CircleList_Delete(list, 0);
		printf("Delete Value: val = %d\n", pVal->v);
	}
	//销毁循环链表
	CircleList_Destroy(list);

	return 0;
}
#endif