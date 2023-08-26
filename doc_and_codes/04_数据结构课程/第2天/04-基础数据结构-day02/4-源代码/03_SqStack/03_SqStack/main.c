#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"


typedef struct stu
{
	int id;
	int age;
}Student;

void main()
{
	Student stu[10];

	// ����ջ����
	SqStack st;
	// ��ʼ��ջ
	InitStack(&st);
	// ѹջ
	for (int i = 0; i < 10; ++i)
	{
		stu[i].id = i;
		stu[i].age = i + 20;
		// ѹջ
		Push(&st, (void*)&stu[i]);
	}

	printf("stack size = %d\n", StackLength(st));

	// ��ջ
	while (StackEmpty(st) != 1)
	{
		Student* p;
		// ȡջ��Ԫ��
		GetTop(st, (void**)&p);
		printf("stack top elem id = %d, age=%d\n", p->id, p->age);

		// ɾ��ջ��Ԫ��
		Pop(&st, (void*)&p);
		printf("Delete stack elem id = %d, age=%d\n", p->id, p->age);
	}
	system("pause");
}