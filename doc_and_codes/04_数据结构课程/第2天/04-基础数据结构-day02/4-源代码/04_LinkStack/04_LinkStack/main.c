#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

// ҵ��ڵ�
typedef struct stu
{
	// ��������ڵ�
	Node node;
	int id;
	int age;
}Student;

void main()
{
	Student stu[10];
	// ����ṹ����
	LinkStack st;
	// ��ʼ��ջ
	InitStack(&st);
	// ��ʼ������
	for (int i = 0; i < sizeof(stu) / sizeof(Student); ++i)
	{
		stu[i].id = i;
		stu[i].age = i + 20;
		// �������������
		Push(&st, &stu[i].node);
	

	printf("stack size = %d\n", StackLength(st));

	while (StackEmpty(st) != 1)
	{
		Node* p;
		// ��ȡջ��Ԫ��
		GetTop(st, &p);
		Student* pp = (Student*)p;
		printf("elem id = %d, age=%d\n", pp->id, pp->age);

		// ɾ��
		Pop(&st, &p);
		pp = (Student*)p;
		printf("Delete elem id = %d, age=%d\n", pp->id, pp->age);
	}
}
