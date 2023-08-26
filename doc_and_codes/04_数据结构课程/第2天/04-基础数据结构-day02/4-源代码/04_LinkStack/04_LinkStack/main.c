#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

// 业务节点
typedef struct stu
{
	// 包含链表节点
	Node node;
	int id;
	int age;
}Student;

void main()
{
	Student stu[10];
	// 链表结构变量
	LinkStack st;
	// 初始化栈
	InitStack(&st);
	// 初始化数组
	for (int i = 0; i < sizeof(stu) / sizeof(Student); ++i)
	{
		stu[i].id = i;
		stu[i].age = i + 20;
		// 数据添加链表中
		Push(&st, &stu[i].node);
	

	printf("stack size = %d\n", StackLength(st));

	while (StackEmpty(st) != 1)
	{
		Node* p;
		// 获取栈顶元素
		GetTop(st, &p);
		Student* pp = (Student*)p;
		printf("elem id = %d, age=%d\n", pp->id, pp->age);

		// 删除
		Pop(&st, &p);
		pp = (Student*)p;
		printf("Delete elem id = %d, age=%d\n", pp->id, pp->age);
	}
}
