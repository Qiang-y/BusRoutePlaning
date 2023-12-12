#include"Path.h"

Path::Path() : time(INT_MAX), timeBus(0), cost(INT_MAX), costBus(0) {}

void Path::compare(uint32_t _busIndex, uint32_t _time, uint32_t _cost)
{
	if (_time < time) {
		time = _time;
		timeBus = _busIndex;
	}
	if (_cost < cost) {
		cost = _cost;
		costBus = _busIndex;
	}
}

std::pair<uint32_t, uint32_t> Path::minTime()
{
	std::pair<uint32_t, uint32_t> temp(timeBus, time);
	return temp;
}

std::pair<uint32_t, uint32_t> Path::minCost()
{
	std::pair<uint32_t, uint32_t> temp(costBus, cost);
	return temp;
}

Path::~Path() = default;
