#include "tcpSocket.h"

bool init_Socket() {
	//parm1:socket版本 parm2：
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) {
		err("start");
		return false;
	}
	return true;
}
bool close_Socket() {
	if (0 != WSACleanup()) {
		err("close");
		return false;
	}
	return true;
}

SOCKET CreateServeSocket()
{
	//创建空的Socket
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET) {
		err("socket");
		return INVALID_SOCKET;
	}

	//设置ip 端口
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);	//大小端问题，htons将主机序变为网络字节序
	addr.sin_addr.S_un.S_addr = ADDR_ANY; //any-任意IP //inet_addr("127.0.0.1");
	//绑定ip 端口
	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&addr, sizeof(addr))) {
		err("bind");
		return SOCKET_ERROR;
	}

	listen(fd, 10);	//将主动的socket变为被动接受的socket
	return fd;		//将成功的socket返回
}

SOCKET CreateClientSocket(const char* IP)
{
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SOCKET_ERROR == fd) {
		err("socket");
		return SOCKET_ERROR;
	}
	//客户端是主动一方， 所以不用绑定IP和设置listen
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);	//要和进行通信的端口一样
	addr.sin_addr.S_un.S_addr = inet_addr(IP);	//目标IP	
	//链接，将指定socket连接到目标地址和端口（addr设置）
	//强制转化一下，防止编译错误
	if (INVALID_SOCKET == connect(fd, (struct sockaddr*)&addr, sizeof(addr))) {
		err("connect");
		return false;
	}

	return fd;	//将链接成功的socket返回
}
