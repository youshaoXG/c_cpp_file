#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "c:/test/test3.txt"

//�ַ���д����
int test_write_char()
{
	char *buf = "abcdefghij";
	int i = 0;

	FILE *fp = fopen(FILE_NAME, "w+");
	if (fp == NULL) {
		fprintf(stderr, "open %s error\n", FILE_NAME);
		return -1;
	}



	for (i = 0; i < (int)strlen(buf); i++) {
		if (fputc(buf[i], fp) == EOF) {
			fprintf(stderr, "fput %c error\n", buf[i]);
			break;
		}
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_read_char()
{
	FILE *fp = NULL;
	char buf[128] = { 0 };
	char ch = 0;
	int i = 0;

	fp = fopen(FILE_NAME, "r+");
	if (fp == NULL) {
		fprintf(stderr, "fopen %s error\n", FILE_NAME);
		return -1;
	}

	while (  (   (ch = fgetc(fp)) != EOF) ) {
		buf[i] = ch;
		i++;
	}

	printf("buf: %s\n", buf);

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_append_char()
{
	FILE *fp = NULL;
	char *buf = "123456";
	int i = 0;


	fp = fopen(FILE_NAME, "a+"); //���û���ļ� Ҳ�ᴴ��
	if (fp == NULL) {
		fprintf(stderr, "open %s  error\n", FILE_NAME);
		return -1;
	}

	int len = strlen(buf);

	for (i = 0; i < len; i++) {
		if(fputc(buf[i], fp) == EOF)
		{
			fprintf(stderr, "fputc %c error\n", buf[i]);
			break;
		}
	}

	if (fp != NULL) {
		fclose(fp);
	}
	
	return 0;
}

int test_write_line()
{
	FILE *fp = fopen(FILE_NAME, "w+");
	char *buf = "abcdefg\n";
	int line_num = 10; //10��
	int i = 0;

	if (fp == NULL) {
		printf("open errorn\n");
		return  -1;
	}

	for (i = 0; i < line_num; i++) {
		// 1 fputs ������ַ�����'\0'д��ȥ 
		// 2 ��Ȼ˵fputs ��дһ�� ʵ����s �� string����˼�� �������ַ�����β����һ��\n  (��һ���ַ���д���ļ��У�������\0)
		if (fputs(buf, fp) == EOF) {
			fprintf(stderr, "fputs %s error\n", buf);
			break;
		}
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_read_line()
{
	FILE *fp = NULL;
	char buf[1024] = { 0 };
	char *p = NULL;
	int i = 0;
	int len = 0;
	fp = fopen(FILE_NAME, "r+");
	if (fp == NULL) {
		fprintf(stderr, "open %s error\n", FILE_NAME);
		return -1;
	}

	//һ��Ҫ���ȿ��ٺ� buf �Ŀռ�
	while ((fgets(buf, 1024, fp) != NULL)) {
		//1 fgets ���Ǹ���\0�����ļ�����һ�� ���� ͨ��\n ���һ��\n������  //��һ�е��ڴ��� \n
		len = strlen(buf);
		buf[len - 1] = '\0';
		printf("�� %d��������:%s\n", i, buf);
		i++;
		memset(buf, 0, 1024);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

struct student
{
	int age;
	char name[64];
	int id;
};

struct teacher
{
	int age;
	int id;
	char *name;   //malloc  "zhang3"
	int name_len;
};

int test_bin_write()
{
	struct student s_array[3] = { 0 };
	int i = 0;
	int num = 3;
	FILE *fp = NULL;
	int write_ret = 0;

	for (i = 0; i < num; i++) {
		s_array[i].id = i;
		s_array[i].age = i + 20;
		sprintf(s_array[i].name, "��%d", i + 1);
	}

	
	fp = fopen(FILE_NAME, "wb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen %s error\n", FILE_NAME);
		return -1;
	}

	int a = 10;

	//fwrite(&a, sizeof(int), 1, fp);

	//write_ret = fwrite(&s_array[0], sizeof(struct student), 3, fp);
	//printf("write_ret = %d\n", write_ret);


	for (i = 0; i < num; i++) {
		write_ret = fwrite(&s_array[i], sizeof(struct student), 1, fp);
		if (write_ret < 0) {
			fprintf(stderr, "write error\n");
			break;
		}
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int test_bin_read()
{
	FILE *fp = NULL;
	struct student *s_array = NULL;
	int num = 3;
	int i = 0;
	int read_ret = 0;

	s_array = (struct student *)malloc(sizeof(struct student) * num);
	if (s_array == NULL) {
		return -1;
	}
	memset(s_array, 0, sizeof(struct student) *num);

	fp = fopen(FILE_NAME, "rb+");
	if (fp == NULL) {
		fprintf(stderr, "fopen error\n");
		return -1;
	}

	for (i = 0; i < num; i++) {
		read_ret = fread(&s_array[i], sizeof(struct student), 1, fp);
		if (read_ret < 0) {
			fprintf(stderr, "read err\n");
			break;
		}
	}

	for (i = 0; i < num; i++) {
		printf("age : %d, name :%s, id :%d\n", s_array[i].age, s_array[i].name, s_array[i].id);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}

int main(void)
{
	char buf[1024] = { 0 };
	int len = 0;

	//test_write_char();
	//test_read_char();
	//test_append_char();
	//test_write_line();
	//test_read_line();

	/*
	if (fgets(buf, 1024, stdin) != NULL) {
		len = strlen(buf);
		buf[len - 1] = '\0';
		printf("buf: %s\n", buf);
	}
	*/

	//test_bin_write();
	test_bin_read();



	return 0;
}