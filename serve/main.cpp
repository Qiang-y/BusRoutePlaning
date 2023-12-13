#include"Graph.h"
#include"../tcpSocket/tcpSocket.h"
int main()
{
	Graph map;
	map.addPlaces("1", "test1");
	map.addPlaces("2", "test2");
	map.addPlaces("3", "test3");
	map.addPath(1, 0, 1, 10, 2);
	map.addPath(1, 1, 3, 20, 3);
	map.addPath(1, 1, 2, 20, 3);

	map.printPlaces();
	map.PrintPath();

	//�������
	init_Socket();
	SOCKET serfd = CreateServeSocket();
	//����пͻ�������, �����͵���Ϣ����
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (SOCKET_ERROR == clifd) {
		err("accept");
	}

	//���ӳɹ����ɽ���ͨѶ
	//�ȶ�����Ϣ������
	//char buf[BUFSIZ] = { 0 };	//BUFSIZ = 512
	std::vector<char> buf;
	while (true) {
		//recv��ָ����socket������Ϣ
		uint32_t len;
		char len_ch;
		//�Ƚ������ݴ�С
		if (0 == recv(clifd, &len_ch, sizeof(len_ch), 0))
			err("recv");
		len = len_ch - '0';
		buf.resize(len);
		//�ٽ�������
		if (0 < recv(clifd, buf.data(), len * sizeof(buf[0]), 0)) {
			//std::cout << buf << std::endl;
			//memset(buf, 0, BUFSIZ);
			//buf.push_back('/0');
			std::cout << "resive" << std::endl;
			for (auto i : buf)
				std::cout << i;
			std::cout << std::endl;
			buf.clear();
		}

		//��ͻ��˷�����Ϣ
		std::cout << "send>";
		//std::cin >> buf;
		std::string str;
		std::cin >> str;
		buf.assign(str.begin(), str.end());
		//buf.push_back('/0');
		//�������ݴ�С
		len = buf.size();
		len_ch = len + '0';
		if (SOCKET_ERROR == send(clifd, &len_ch, sizeof(len_ch), 0)) {
			err("send");
		}
		//��������
		if (SOCKET_ERROR == send(clifd, buf.data(), buf.size() * sizeof(buf[0]), 0)) {
			err("send");
		}
	}
	//�ر�
	closesocket(serfd);
	closesocket(clifd);

	close_Socket();


	return 0;
}
