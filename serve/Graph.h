#ifndef _GRAPH_H_
#define _GRAPH_H_
#include"Place.h"
#include"Path.h"
#include"Config.h"
class Graph{
public:
    int len;
    std::vector<Places*> places;
    std::vector<std::vector<Path>> graph;
public:
    Graph();
    Graph(int _len, std::vector<Places*> _places);
    void addPlaces(std::string _name, std::string _info);
    void addPath(uint32_t _busIndex
                , uint32_t _start
                , uint32_t _end
                , uint32_t _time
                , uint32_t _cost);
    void printPlaces();
    void PrintPath();
    // 此处采用Dijkstra算法
    // vector[0].first:总花费时间 vector[0].second:起始站
    // vector[i].first:乘坐公交 vector[i].second:下一站
    std::vector<std::pair<uint32_t, uint32_t>> minTime(int _start, int _end);
    // 此处采用Dijkstra算法
    // vector[0].first:总花费车费 vector[0].second:起始站
    // vector[i].first:乘坐公交 vector[i].second:下一站
    std::vector<std::pair<uint32_t, uint32_t>> minCost(int _start, int _end);
};

#endif // GRAPH_H
