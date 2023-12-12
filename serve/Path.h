#ifndef _PATH_H_
#define _PATH_H_
#include"Config.h"

class Path {
public:
	//��¼��������ʱ��/��Ǯ���乫�����
	uint32_t time;
	uint32_t timeBus;
	uint32_t cost;
	uint32_t costBus;
public:
	Path();
	void compare(uint32_t _busIndex, uint32_t _time, uint32_t _cost);
	//���أ�first:ʱ�����ٵĹ��� second:���ʱ��
	std::pair<uint32_t, uint32_t> minTime();
	//���أ�first:�������ٵĹ��� second:���ٳ���
	std::pair<uint32_t, uint32_t> minCost();
	~Path();
};

#endif // !_PATH_H_
