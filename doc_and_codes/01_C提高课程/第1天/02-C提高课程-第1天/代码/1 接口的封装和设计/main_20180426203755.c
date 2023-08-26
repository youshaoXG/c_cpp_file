#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include "socket.h"

struct A{
	int info;
	int a;
	int b; 
};

int main(void)
{
	struct A *a;

	char buf[128] = "12312321321321";
	int ret = 0;

	ret = socket_client_init(&a);
	if (ret != 0) {
		fprintf(stderr, "socket_client_init err\n");
		return -1;
	}

	ret = socket_client_send(a,buf, strlen(buf));
	if (ret != 0) {
		fprintf(stderr, "socket_client_send err\n");
		return -1;
	}

	



	return 0;
}