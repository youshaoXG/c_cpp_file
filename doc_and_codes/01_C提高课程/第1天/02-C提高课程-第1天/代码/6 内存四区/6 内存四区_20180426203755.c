#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//ջ
void test1()
{
	int a = 10; //�������� �� ������һ��
}

//��
//�ڶ��Ͽ���һЩ�ڴ�
char* get_mem(int size)
{
	char *p = NULL; //

	p =(char*) malloc(size);
	if (p == NULL) {
		fprintf(stderr, "malloc %d err\n", size);
		return NULL;
	}

	memset(p, 0, size);

	return p;
}


//ͨ��ջ �ڴ洫��ȥ
char* get_mem2(int size)
{
	char buf[128] = { 0 };

	strcpy(buf, "123456");

	return buf;
}


char *get_addr()
{
	char *p = "12345678";

	return p;
}

char *get_addr2()
{
	char *p = "12345678";

	return p;
}



int main(void)
{
#if 0
	
	//char buf[10] = { 0 };
	char *main_p = NULL;
	main_p = get_mem(100);
	//main_p = get_mem2(100);


	if (main_p == NULL) {
		fprintf(stderr, "get_mem err\n");
		return -1;
	}

	strcpy(main_p, "123456");
	
#endif

	char *main_p1 = NULL;
	char *main_p2 = NULL;

	main_p1 = get_addr();
	main_p2 = get_addr2();

	if (main_p1 == main_p2) {
		printf("main_p1 ��main_p2 ָ��ͬһ����ַ\n");
	}
	else {
		printf("main_p1 ��main_p2����  ͬһ����ַ\n");

	}
	
	return 0;
}