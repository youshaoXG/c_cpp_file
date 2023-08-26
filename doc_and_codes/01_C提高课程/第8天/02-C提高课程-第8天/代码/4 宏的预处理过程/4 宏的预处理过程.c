#include <stdio.h> 
#include <stdlib.h>
//在编译器编译的 需要对所有的代码有一个预处理的过程
//#, include , <, stdio.h, >, 

#define STR "hello, "\
	"world\n"

//#define STR "hello, world"

//#, define, STR, "hello, ", \, \t, \t, "world", 
//1， 预处理 第一个节点就是 将所有代码 拆分成一个一个  编译器能够识别的最小单元， 就叫一个token
//2 ,  将所有的宏展开， 将所有的续行符 去掉 和 注释去掉
//#, define, STR, "hello, ", \t, \t, "world", 

#define MAX_LEN		(138)

#define MAX(a, b)     \
	(a)> (b) ? (a) : (b)  \
//是由预处理器 对代码的拆分， 没有语法校验


//是由编译器调用的， 他会类型和语法进行检验

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
	//2 ,  将所有的宏展开， 将所有的续行符 去掉 和 注释去掉
	// printf, (, \n, \t, \t, "hello", \t, \t, "world", ), ;,
	//3 , 合并所有的 相同的空白字符, 合并所有的字符串
	// printf, (,\n, \t, "hello", \t, "world", ), ;
	//4 去掉所有的空白字符
	// printf, (,"hello world", ), ;
	//预处理到此为止，就不会在进行对代码的拆分， 到此为止最终通过预处理处理之后剩下的  编译器能够
	//识别的最小单元 我们称他们 是一个 C token

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
	//宏函数 对于自增传参的操作是由 风险的。
	//printf("ret = %d\n", ret);
	printf("a = %d, b = %d\n", a, b);

	printf(" ========= \n");
#if 1
	char *p = NULL;

	p = (char*)malloc(100);
	
	//使用p 


		

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