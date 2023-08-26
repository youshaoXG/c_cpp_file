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

	// ∂®“Â’ª±‰¡ø
	SqStack st;
	// ≥ı ºªØ’ª
	InitStack(&st);
	// —π’ª
	for (int i = 0; i < 10; ++i)
	{
		stu[i].id = i;
		stu[i].age = i + 20;
		// —π’ª
		Push(&st, (void*)&stu[i]);
	}

	printf("stack size = %d\n", StackLength(st));

	// ≥ˆ’ª
	while (StackEmpty(st) != 1)
	{
		Student* p;
		// »°’ª∂•‘™Àÿ
		GetTop(st, (void**)&p);
		printf("stack top elem id = %d, age=%d\n", p->id, p->age);

		// …æ≥˝’ª∂•‘™Àÿ
		Pop(&st, (void*)&p);
		printf("Delete stack elem id = %d, age=%d\n", p->id, p->age);
	}
	system("pause");
}