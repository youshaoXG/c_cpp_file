#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//1
struct teacher
{
	int id;
	char name[64];
};

struct teacher t5 = { 5, "laoshi5" };

//2
struct {
	int id;
	char name[64];
} t3, t4;//�����Ľṹ������  ����ֻ�ܶ���һ�Σ� ����ͨ����������


//3
typedef struct  _teacher
{
	int id;
	char name[64];
} teacher_t;  //��õ�д��

/*
struct _teacher
{
	int id;
	char name[64];
};

typedef struct _teacher teacher_t;
*/




void print_teacher(struct teacher* p1)
{
	printf("id = %d\n", p1->id);
	printf("name = %s\n", p1->name);
}

void print_teacher2(struct teacher t) //t = t1     int a = b; struct teacher t1 = t2
{
	printf("===== print_teacher2===\n");
	printf("id = %d\n", t.id);
	printf("name = %d\n", t.name);
}

void copy(struct teacher to, struct teacher from)
{
	to = from;
}

void copy2(struct teacher *to, struct teacher *from)
{
	*to = *from;
}

/*
void print_teacher2(struct {
	int id;
	char name[64];
})
*/
 
int main(void)
{
	struct teacher  t1;
	struct teacher  t8;
	teacher_t t6 = {6, "laoshi6"};
	//teacher t7;  // C������  ����һ���ṹ�� �������struct �ؼ���  C++���ü�

	t1.id = 10;
	strcpy(t1.name, "laoshi1");

	print_teacher(&t1);
	print_teacher(&t5);

	print_teacher2(t1);  //

	printf("=====\n");
	copy2(&t8, &t1);
	print_teacher(&t8);

	struct teacher t9 = t1; //int a = b;


	return 0;
}