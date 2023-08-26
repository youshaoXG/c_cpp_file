#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeee,ssss,����
д��������(API)��������½��
��һ��API
1)�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
2)�Ѷ�ά��������������Ҳ����
�ڶ���API
1)�Զ��ŷָ��ַ������γ�һ������ָ�롣
2)��һ����ֶ������ַ�����������
Ҫ��
1, ����ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�
2, ��ȷʵ�ֽӿں͹���.
3, ��д��ȷ�Ĳ�������.
*/

int spitString(char *str, char ch, char array[][30], int *count)
{
	char *p = str;
	char *q = p;
	int temp_count = 0;
	int len = 0;

	if (str == NULL || array == NULL || count == NULL) {
		fprintf(stderr, "str == NULL || array == NULL || count == NULL\n");
		return -1;
	}

	//��һ���ַ����� �ҵ�һ���ַ�  �ҵ��� ���ص�һ���ַ��ĵ�ַ�� ʧ�ܷ���NULL
	//strchr(ĸ���� �ַ�)
	while ((p = strchr(p, ch)) != NULL) {
		//�ҵ���
		strncpy(array[temp_count], q, p - q);
		array[temp_count][p - q] = '\0';

		temp_count++;
		p++;
		q = p;
		if (*p == '\0') {
			break;
		}
	}

	if (*q != '\0') {
		len = (str + strlen(str)) - q;
		strncpy(array[temp_count], q, len);
		array[temp_count][len] = '\0';
		temp_count++;
	}

	*count = temp_count;

	return 0;
}

int main(void)
{
	char *str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char array[10][30];
	int count = 0;
	int retn = 0;
	int i = 0;

	retn = spitString(str, ',', array, &count);
	if (retn < 0) {
		fprintf(stderr, "spitString er\n");
		return -1;
	}


	for (i = 0; i < count; i++) {
		printf("array[%d]:%s\n", i, array[i]);
	}




	return 0;
}