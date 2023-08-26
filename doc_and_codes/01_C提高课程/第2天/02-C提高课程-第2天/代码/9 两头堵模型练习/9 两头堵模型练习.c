#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
��һ���ַ�����ͷ���β����n���ո�
���� abcdefgdddd ������
��ȥ��ǰ��ո񣬷���һ�����ַ�����
Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ�
�ܣ�
Ҫ��2����д����������
int trimSpace(char *inbuf, char *outbuf);
*/

int trimSpace(char *inbuf, char *outbuf)
{
	int i = 0;
	int j = 0;
	int len = 0;

	if (inbuf == NULL || outbuf == NULL) {
		fprintf(stderr, " (inbuf == NULL || outbuf == NULL)\n  ");
		return -1;
	}

	j = strlen(inbuf) - 1;

	//��߿�ʼ����
	while (isspace(inbuf[i]) && inbuf[i] != '\0') {
		i++;
	}

	//�ұ�
	while (isspace(inbuf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(outbuf, inbuf + i,len);
	outbuf[len] = '\0';

	return 0;
}


int main(void)
{
	char *str = "   abcdefgdddd   ";
	char buf[128] = { 0 };

	if (trimSpace(str, buf) < 0) {
		fprintf(stderr, " trimSpace err\n ");
		return -1;
	}

	printf("buf: [%s]\n", buf);

	return 0;
}