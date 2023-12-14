#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include"../serve/Config.h"
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")	//链接网络库
#define PORT 8888
//初始化网络库
bool init_Socket();
//关闭网络库
bool close_Socket();
//创建服务端socket
SOCKET CreateServeSocket();
//创建客户端socket
SOCKET CreateClientSocket(const char* IP);
//发送数据

#endif // !_TCPSOCKET_H_
