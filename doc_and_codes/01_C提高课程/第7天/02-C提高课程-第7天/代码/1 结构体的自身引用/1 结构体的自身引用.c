#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
struct teacher {
	int id;
	
	struct teacher t1;   //ѭ������   ����������ȷ������ structteacher ����ռ�ö��ٸ��ֽ�
};
*/

//�̶� �ڴ��С�ı���


struct teacher {
	int id;
	struct teacher *tp;
};

int main(void)
{
	struct teacher t2;
	t2.id = 10;
	struct teacher t1;
	t1.id = 20;

	t2.tp = &t1;   //  t2->tp = &t1

	printf("%d\n", t2.tp->id);
	printf("%d\n",t1.id);


	return 0;
}