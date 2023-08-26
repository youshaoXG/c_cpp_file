#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct _Test
{
	int value;
	char name[32];
}Test;

typedef struct Value
{
	Test d;
	int a;
	short b;
	char c[24];
}Value;

void main()
{
	Value v;
	// ¸³Öµ
	v.a = 10;
	v.b = 2;
	strcpy(v.c, "aaaaa");
	v.d.value = 30;
	strcpy(v.d.name, "bbbbb");

	// È¡Öµ
	// Test
	Test *test = (Test*)&v;
	printf("Test value = %d, name = %s\n", test->value, test->name);

	// v.a
	int a = *(int *)((char*)&v + sizeof(Test));
	printf("v.a = %d\n", a);

	// v.b
	short b = *(short*)((char*)&v + sizeof(Test)+sizeof(int));
	printf("v.b = %d\n", b);

	// v.c
	char* c = ((char*)&v + sizeof(Test)+sizeof(int)+sizeof(short));
	printf("v.c = %s\n", c);
}