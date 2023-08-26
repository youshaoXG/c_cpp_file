#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�ڶ��� ���������ڴ棬 ��main����ʹ��

#define OUT
#define IN

/*
��Ҫ�ⲿ�ͷ� �ڴ�  pp1 �� pp2
*/
/*
   �����ļ�飺 ���������ڴ�

   pp1  out  ����һ�����ڴ� 
   pp2  out  

   len_p_1 out ��һ���ڴ���Ч���ݵĴ�С
   len_p_2 out 
   len1     in   ��Ҫ����1 �ڴ�Ĵ�С
   len2     in   ��Ҫ����2 �ڴ�Ĵ�С

   return -1 ʧ��
             0  �ɹ�
*/
int get_mem(OUT char **pp1, OUT char **pp2, OUT  int *len_p_1, OUT int *len_p_2, IN  int len1, IN int len2)//�ӿڣ�API
{
	char *p1 = NULL;
	char *p2 = NULL;
	int temp_len1 = 0;
	int temp_len2 = 0;


	p1 = (char*)malloc(len1);//p1
	if (p1 == NULL) {
		fprintf(stderr, "malloc p1 err\n");
		return -1;
	}
	memset(p1, 0, len1);


	p2 = malloc(len2);
	if (p2 == NULL) {
		fprintf(stderr, "malloc p2 err\n");
		return -1;
	}
	memset(p2, 0, len2);

	
	strcpy(p1, "1234567890");
	temp_len1 = strlen(p1);

	strcpy(p2, "abcdefghijk");
	temp_len2 = strlen(p2);
	


	//����  ����˵������û������
	*pp1 = p1;
	*pp2 = p2;
	*len_p_1 = temp_len1;
	*len_p_2 = temp_len2;  //��Ӳ���


	return 0;
}

//�����ṩһ�� �ͷ��ڴ�Ľӿ�
void free_mem(char *p1, char *p2)
{
	if (p1 != NULL) {
		free(p1);
		//p1 = NULL;
	}
	if (p2 != NULL) {
		free(p2);
	}
}

void free_mem2(char **pp1, char **pp2)
{
	char *p1 = NULL;
	char *p2 = NULL;

	p1 = *pp1;
	p2 = *pp2;

	if (p1 != NULL) {
		free(p1);
	}
	if (p2 != NULL) {
		free(p2);
	}

	*pp1 = NULL;
	*pp2 = NULL;

}

int main(void)
{
	char *p1 = NULL;  //��һ���ڴ���׵�ַ
	char *p2 = NULL;

	int len1 = 0; //��һ���ڴ�ĳ���
	int len2 = 0;

	int ret = 0;

	ret = get_mem(&p1, &p2, &len1, &len2, 200, 300);
	if (ret != 0) {
		fprintf(stderr, "get mem error: %d\n", ret);
		return -1;
	}


	//���ڴ�Ĳ���
	printf("p1 : %s[%d], p2 : %s[%d]\n", p1, len1, p2, len2);



	//if (p1 != NULL) {
	//	free(p1);
	//	p1 = NULL;
	//}

	//if (p2 != NULL) {
	//	free(p2);
	//	p2 = NULL;
	//}
	//free_mem(p1, p2);
	//p1 = NULL;
	//p2 = NULL;
	free_mem2(&p1, &p2);

	return 0;
}