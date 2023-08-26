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
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
	char *p = keyvaluebuf; //ԭ�ַ���
	char *key_p = keybuf; //key : "key1"
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
		fprintf(stderr, "δ�ҵ� key%s", key_p);
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


int main(void)
{
	char *str = " key2   	=";
	int retn = 0;
	char value[64] = { 0 };
	int value_len = 0;
	char *key = "key2";

	retn = getKeyByValue(str, key, value, &value_len);
	if (retn < 0) {
		fprintf(stderr, "getKeyByValue err\n");
		return -1;
	}

	printf("key:%s  --> value:%s[%d]\n", key, value, value_len);


	return 0;
}