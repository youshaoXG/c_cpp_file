#include <stdio.h> 
#include <stdlib.h>
//�ڱ���������� ��Ҫ�����еĴ�����һ��Ԥ����Ĺ���
//#, include , <, stdio.h, >, 

#define STR "hello, "\
	"world\n"

//#define STR "hello, world"

//#, define, STR, "hello, ", \, \t, \t, "world", 
//1�� Ԥ���� ��һ���ڵ���� �����д��� ��ֳ�һ��һ��  �������ܹ�ʶ�����С��Ԫ�� �ͽ�һ��token
//2 ,  �����еĺ�չ���� �����е����з� ȥ�� �� ע��ȥ��
//#, define, STR, "hello, ", \t, \t, "world", 

#define MAX_LEN		(138)

#define MAX(a, b)     \
	(a)> (b) ? (a) : (b)  \
//����Ԥ������ �Դ���Ĳ�֣� û���﷨У��


//���ɱ��������õģ� �������ͺ��﷨���м���

int max1(int a, int b)
{
	return (a > b ? a : b);
}




#define FREE(p) \
do {						 \
	free(p);			\
	p = NULL;		\
} while(0)

int main(void)
{
	printf(
		STR);
	//printf, (,\n, \t, \t, STR, ), ;,
	//2 ,  �����еĺ�չ���� �����е����з� ȥ�� �� ע��ȥ��
	// printf, (, \n, \t, \t, "hello", \t, \t, "world", ), ;,
	//3 , �ϲ����е� ��ͬ�Ŀհ��ַ�, �ϲ����е��ַ���
	// printf, (,\n, \t, "hello", \t, "world", ), ;
	//4 ȥ�����еĿհ��ַ�
	// printf, (,"hello world", ), ;
	//Ԥ������Ϊֹ���Ͳ����ڽ��жԴ���Ĳ�֣� ����Ϊֹ����ͨ��Ԥ������֮��ʣ�µ�  �������ܹ�
	//ʶ�����С��Ԫ ���ǳ����� ��һ�� C token

	int ret = 0;
	int a = 10;
	int b = 20;

	MAX(a + b, a - b); //	a> b ? a : b  
	(a+b)>(a-b)?(a+b):(a-b)


	//ret = MAX(10, 20); 
	//ret = 10 > 20 ? 10 : 20;
	//ret = MAX("dsadsa", "dasdsads");
	// ret = "dsadsa" > "dasdsads" ?  "dsadsa" : "dasdsads"

	//ret = max("dsadsa", "dsadsa");
	//ret = MAX(-a, -b);
	//ret = (-a) > (-b) ? (-a) : (-b)
	//ret = MAX(a++, b++);
	//ret = max(a++, b++);
	//ret = MAX(a++, b++);
	// ret = (a++) > (b++)? (a++): (b++)
	//�꺯�� �����������εĲ������� ���յġ�
	//printf("ret = %d\n", ret);
	printf("a = %d, b = %d\n", a, b);

	printf(" ========= \n");
#if 1
	char *p = NULL;

	p = (char*)malloc(100);
	
	//ʹ��p 


		

	if (p != NULL) 
		//free(p);
		FREE(p);// free(p), p = NULL;
		/*
	do {
		free(p);
		p = NULL;
	} while (0);
	*/
	else {
		printf(" p == NULL\n");
	}

#endif

	return 0;
}