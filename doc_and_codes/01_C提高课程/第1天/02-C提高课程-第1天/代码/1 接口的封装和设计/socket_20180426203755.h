#ifndef _SOCKET_CLIENT_H
#define _SOCKET_CLIENT_H


//A ��װһ��socket�����̵� �ӿ�


//��ʼ��socket'����Ľӿ�
int  socket_client_init(void **handle);

//����socket���籨��
int socket_client_send(void *handle, unsigned char *buf, int buf_len);


//����socket���籨��
int socket_client_recv(void *handle, unsigned char *buf, int *buf_len);

//�ͷ�socket�����Դ
int destory_socket(void *handle);




#endif