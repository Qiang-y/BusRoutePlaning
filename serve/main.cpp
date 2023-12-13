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

	//网络测试
	init_Socket();
	SOCKET serfd = CreateServeSocket();
	//如果有客户端链接, 将发送的信息接收
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (SOCKET_ERROR == clifd) {
		err("accept");
	}

	//链接成功，可进行通讯
	//先定义消息缓冲区
	//char buf[BUFSIZ] = { 0 };	//BUFSIZ = 512
	std::vector<char> buf;
	while (true) {
		//recv从指定的socket接受信息
		uint32_t len;
		char len_ch;
		//先接收数据大小
		if (0 == recv(clifd, &len_ch, sizeof(len_ch), 0))
			err("recv");
		len = len_ch - '0';
		buf.resize(len);
		//再接受数据
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

		//向客户端发送消息
		std::cout << "send>";
		//std::cin >> buf;
		std::string str;
		std::cin >> str;
		buf.assign(str.begin(), str.end());
		//buf.push_back('/0');
		//发送数据大小
		len = buf.size();
		len_ch = len + '0';
		if (SOCKET_ERROR == send(clifd, &len_ch, sizeof(len_ch), 0)) {
			err("send");
		}
		//发送数据
		if (SOCKET_ERROR == send(clifd, buf.data(), buf.size() * sizeof(buf[0]), 0)) {
			err("send");
		}
	}
	//关闭
	closesocket(serfd);
	closesocket(clifd);

	close_Socket();


	return 0;
}
