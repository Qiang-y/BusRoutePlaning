#include "tcpSocket.h"

bool init_Socket() {
	//parm1:socket�汾 parm2��
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
	//�����յ�Socket
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == INVALID_SOCKET) {
		err("socket");
		return INVALID_SOCKET;
	}

	//����ip �˿�
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);	//��С�����⣬htons���������Ϊ�����ֽ���
	addr.sin_addr.S_un.S_addr = ADDR_ANY; //any-����IP //inet_addr("127.0.0.1");
	//��ip �˿�
	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&addr, sizeof(addr))) {
		err("bind");
		return SOCKET_ERROR;
	}

	listen(fd, 10);	//��������socket��Ϊ�������ܵ�socket
	return fd;		//���ɹ���socket����
}

SOCKET CreateClientSocket(const char* IP)
{
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SOCKET_ERROR == fd) {
		err("socket");
		return SOCKET_ERROR;
	}
	//�ͻ���������һ���� ���Բ��ð�IP������listen
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);	//Ҫ�ͽ���ͨ�ŵĶ˿�һ��
	addr.sin_addr.S_un.S_addr = inet_addr(IP);	//Ŀ��IP	
	//���ӣ���ָ��socket���ӵ�Ŀ���ַ�Ͷ˿ڣ�addr���ã�
	//ǿ��ת��һ�£���ֹ�������
	if (INVALID_SOCKET == connect(fd, (struct sockaddr*)&addr, sizeof(addr))) {
		err("connect");
		return false;
	}

	return fd;	//�����ӳɹ���socket����
}
