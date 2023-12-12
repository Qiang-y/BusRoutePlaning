#ifndef _PATH_H_
#define _PATH_H_
#include"Config.h"

class Path {
public:
	//记录花费最少时间/金钱及其公交编号
	uint32_t time;
	uint32_t timeBus;
	uint32_t cost;
	uint32_t costBus;
public:
	Path();
	void compare(uint32_t _busIndex, uint32_t _time, uint32_t _cost);
	//返回：first:时间最少的公交 second:最短时间
	std::pair<uint32_t, uint32_t> minTime();
	//返回：first:车费最少的公交 second:最少车费
	std::pair<uint32_t, uint32_t> minCost();
	~Path();
};

#endif // !_PATH_H_
