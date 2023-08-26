#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#, ##
#define STR(s)   #s    //#s 就是将这个s的代码 都编程字符串
//# 操作符 在宏函数体内， 相当于 创建一个字符串

//## 代表C token的拼接
#define A(first, second)   first##second  //这个拼接不是字符串的拼接， 是token的拼接

#define ITCAST(a)  itcast##a

#define G(a)  g##a

int G(value) = 10; //g_value = 10;

//...代表可变参数 
#define showlist(...) \
	printf(#__VA_ARGS__) // __VA_ARGS__ 就表示 ...接收的 所有参数

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