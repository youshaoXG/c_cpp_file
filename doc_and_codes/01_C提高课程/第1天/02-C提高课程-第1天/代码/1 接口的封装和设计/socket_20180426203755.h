#ifndef _SOCKET_CLIENT_H
#define _SOCKET_CLIENT_H


//A 封装一套socket网络编程的 接口


//初始化socket'句柄的接口
int  socket_client_init(void **handle);

//发送socket网络报文
int socket_client_send(void *handle, unsigned char *buf, int buf_len);


//接收socket网络报文
int socket_client_recv(void *handle, unsigned char *buf, int *buf_len);

//释放socket句柄资源
int destory_socket(void *handle);




#endif