#include "config.h"


int write_config(IN const char *file_name, IN const char *key, IN const char *value, IN const int value_len)
{
	//key = value
	FILE *fp = NULL;
	char file_buf[FILE_MAX_LEN] = { 0 }; //����ļ������е�����
	char line_buf[LINE_MAX_LEN] = { 0 };  //����ļ�ÿ�е�����
	int pos_begin = 0;
	int pos_end = 0;
	int key_exist = 0; //key �Ƿ��Ѿ����� 0 �������� 1 �������


	//��������ļ�����
	fp = fopen(file_name, "r+");
	if (fp == NULL) {
		//1 �������ļ�������
		fp = fopen(file_name, "w+");
		if (fp == NULL) {
			fprintf(stderr, "fopen %s error\n", file_name);
			return -1;
		}
	}

	//���ļ��ڲ���ָ�� һ��ͷ��
	fseek(fp, 0, SEEK_SET);
	pos_begin = ftell(fp);

	//���ļ��ڲ�ָ�� �Ƶ� β��
	fseek(fp, 0, SEEK_END);
	pos_end = ftell(fp);

	fseek(fp, 0, SEEK_SET);

	if ((pos_end - pos_begin) > FILE_MAX_LEN) {
		fprintf(stderr, "�ļ�̫��\n");
		fclose(fp);
		return -1;
	}

	//�ļ��Ϸ�
	while (!feof(fp)) {
		//�ļ�û�ж���
		memset(line_buf, 0, LINE_MAX_LEN);
		if (fgets(line_buf, LINE_MAX_LEN, fp) == NULL) {
			break;
		}
		//��һ�����ݶ���line_buf����
		printf("line_buf =%s\n", line_buf);
		//�ж�һ���������Ƿ���key,����еĻ� �޸�key��valueֵ
		if (strstr(line_buf, key) != NULL) {
			//key ���ļ����Ѿ����� ��Ҫ�޸�key��value
			memset(line_buf, 0, LINE_MAX_LEN);
			sprintf(line_buf, "%s = %s\n", key, value);
			key_exist = 1;
		}
		//key1 = value1

		//name = li4\nid = 10\nkey1 = value1\0  file_buf  -->config.ini
		strcat(file_buf, line_buf);
	}

	if (key_exist == 0) {
		fprintf(fp, "%s = %s\n", key, value);
	}
	else {
		if (fp != NULL) {
			fclose(fp);
			fp = NULL;
		}

		fp = fopen(file_name, "w+");
		if (fp == NULL) {
			fprintf(stderr, "open error\n");
			return -1;
		}
		printf("file_buf:%s\n", file_buf);
		fputs(file_buf, fp);
	}


	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}

	return 0;
}

int read_config(IN const char *file_name, IN const char *key, OUT char *value, OUT int *value_len)
{
	char line_buf[LINE_MAX_LEN] = { 0 };
	int ret = 0;
	FILE *fp = NULL;
	int temp_value_len = 0;
	int key_exist = 0;

	fp = fopen(file_name, "r");
	if (fp == NULL) {
		fprintf(stderr, "fopen %s error\n", file_name);
		return -1;
	}

	while (!feof(fp)) {
		memset(line_buf, 0, LINE_MAX_LEN);
		if (fgets(line_buf, LINE_MAX_LEN, fp) == NULL) {
			break;
		}

		ret = getKeyByValue(line_buf, key, value, &temp_value_len);
		if (ret < 0) {
			continue;
		}
		else {
			key_exist = 1;
			break;
		}
	}

	if (key_exist == 0) {
		printf("%s ������\n", key);
	}
	else {
		*value_len = temp_value_len;
	}

	if (fp != NULL) {
		fclose(fp);
	}

	return 0;
}




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

	strncpy(outbuf, inbuf + i, len);
	outbuf[len] = '\0';

	return 0;
}


/*
2����ֵ�ԣ���key = value�����ַ������ڿ����о���ʹ��.
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ.
Ҫ��2����д����������
Ҫ��3����ֵ���м������n��ո���ȥ���ո�
ע�⣺��ֵ���ַ�����ʽ�������£�
"key1	=	value1"
"key2	=							value2"
"key3		=	hello word      "
"key4								=	value4"
"key5			=			"
"key6			="
int	getKeyByValue(char	*keyvaluebuf,		char	*keybuf,		char	*valuebuf,	int	*
valuebuflen);
int	main(void)
{
//...
getKeyByValude("key1	=	valude1",	"key1",	buf,	&len);
//...
return 0;
}
*/


/*
�˺������� ���� ���������ַ���
"key1	=	value1"
" key2   	=							value2            "
//             ��
"key3		=	hello word      "
"key4								=	value4"
"key5			=			"
"key6			="
ͨ��keyֵ �ҵ�value

keyvaluebuf  in  : ����ԭ�ַ���
keybuf          in  : Ҫ�ҵ���keyֵ
valuebuf      out: �õ�valueֵ
valuebuflen  out: �õ���value����


return   0 �ɹ� -1 ʧ��

*/
int getKeyByValue(char *keyvaluebuf, const char *keybuf, char *valuebuf, int *valuebuflen)
{
	char *p = keyvaluebuf; //ԭ�ַ���
	char *key_p = (char*)keybuf; //key : "key1"
	char *value_p = valuebuf;// �õ��� Ŀ���ڴ��׵�ַ
	int ret = 0;
	int len = 0;

	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL) {
		fprintf(stderr, "[%s:%d]keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL\n",
			__FUNCTION__, __LINE__);
		return -1;
	}

	//����keyvaluebuf �Ƿ��� keybuf  
	p = strstr(p, key_p);
	if (p == NULL) {
		//û�ҵ� key ֵ
		//fprintf(stderr, "δ�ҵ� key %s", key_p);
		return -1;
	}
	p += strlen(key_p);

	//����keyvaluebuf �Ƿ��� =
	p = strstr(p, "=");
	if (p == NULL) {
		//û�ҵ�=
		fprintf(stderr, "δ�ҵ�=\n");
		return -1;
	}
	p += strlen("=");

	//�ҵ�=���ұߵ�value ȥ��value���˵Ŀհ��ַ�
	ret = trimSpace(p, value_p);
	if (ret < 0) {
		fprintf(stderr, "trimSpace err\n");
		return -1;
	}

	len = strlen(value_p);
	*valuebuflen = len;

	return 0;
}
