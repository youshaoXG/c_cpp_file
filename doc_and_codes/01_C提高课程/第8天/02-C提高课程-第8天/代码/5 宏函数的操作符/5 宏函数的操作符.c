#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#, ##
#define STR(s)   #s    //#s ���ǽ����s�Ĵ��� ������ַ���
//# ������ �ں꺯�����ڣ� �൱�� ����һ���ַ���

//## ����C token��ƴ��
#define A(first, second)   first##second  //���ƴ�Ӳ����ַ�����ƴ�ӣ� ��token��ƴ��

#define ITCAST(a)  itcast##a

#define G(a)  g##a

int G(value) = 10; //g_value = 10;

//...����ɱ���� 
#define showlist(...) \
	printf(#__VA_ARGS__) // __VA_ARGS__ �ͱ�ʾ ...���յ� ���в���

#define compare(test, ...) \
	(test) ? (#test) : printf(#__VA_ARGS__);


int main(void)
{
	printf("%s\n", STR(main()));
	//
	printf("%s\n", "main()");


	printf(" ====== \n");
	A(printf, ("%s\n", "abc"););
	// printf ## ("%s\n", "abc");
	printf("%s\n", "abc");

	int ITCAST(a) = 10;
	//itcast_a = 10;

	showlist(dsadjsadsjksaldsjadlsajsa,dsadsad,dsadasd,dsadsa,dsad);//... = dsadjsadsjksaldsjadlsajsa
	//printf("dsadjsadsjksaldsjadlsajsa");
	printf("\n");

	int a = 10;
	int b = 20;

	compare((a > b),  a is littlen than b);


	return 0;
}