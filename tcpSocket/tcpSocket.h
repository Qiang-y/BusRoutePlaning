#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include"../serve/Config.h"
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")	//���������
#define PORT 8888
//��ʼ�������
bool init_Socket();
//�ر������
bool close_Socket();
//���������socket
SOCKET CreateServeSocket();
//�����ͻ���socket
SOCKET CreateClientSocket(const char* IP);
//��������

#endif // !_TCPSOCKET_H_
