#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_LEN  64

struct teacher
{
	int id;
	char *name;
};


//����ṹ������ָ�� �ڶ��Ͽ��ٵĿռ�
//����������������� ����ǳ����
//�ṹ�����ͨ������ֱ�Ӹ�ֵ�� ����Ҫʹ�����ַ����� 
//Ҫ���ṹ���еĳ�Ա һ��һ������
void copy_teacher(struct teacher *to, struct teacher *from)
{
	*to = *from;
}

void copy_teacher_deep(struct teacher *to, struct teacher *from)
{
	to->name = (char*)malloc(NAME_LEN);
	memset(to->name, 0, NAME_LEN);
	strcpy(to->name, from->name);

	to->id = from->id;
}


void print_teacher(struct teacher *tp)
{
	printf("id : %d, name : %s\n", tp->id, tp->name);
}

int main(void)
{
	struct teacher tp1 = {0}; //��ջ�Ͽ��ٵ�һ��teacher�ṹ��
	struct teacher tp2 = {0};

	tp1.id = 1;
	tp1.name = (char*)malloc(NAME_LEN);
	memset(tp1.name, 0, NAME_LEN);
	strcpy(tp1.name, "zhang3");

	//copy_teacher(&tp2, &tp1);
	copy_teacher_deep(&tp2, &tp1);

	print_teacher(&tp1);
	print_teacher(&tp2);

	if (tp1.name != NULL) {
		free(tp1.name);
		tp1.name = NULL;
	}

	if (tp2.name != NULL) {
		free(tp2.name);
		tp2.name = NULL;
	}



	return 0;
}