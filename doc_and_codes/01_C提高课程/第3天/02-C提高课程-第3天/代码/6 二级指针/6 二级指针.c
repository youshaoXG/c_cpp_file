#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;
	int *p = &a;
	int **pp = &p;

	printf("&a : %p\n", &a);
	printf("p : %p\n", p);
	printf("&p: %p\n", &p);
	printf("pp: %p\n", pp);
	printf("&pp: %p\n", &pp);
	printf("*p: %d\n", *p);
	printf("*pp:%p\n", *pp);
	printf("**pp:%d\n", **pp);

	return 0;
}