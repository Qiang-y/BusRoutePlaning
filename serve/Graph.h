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
    // �˴�����Dijkstra�㷨
    // vector[0].first:�ܻ���ʱ�� vector[0].second:��ʼվ
    // vector[i].first:�������� vector[i].second:��һվ
    std::vector<std::pair<uint32_t, uint32_t>> minTime(int _start, int _end);
    // �˴�����Dijkstra�㷨
    // vector[0].first:�ܻ��ѳ��� vector[0].second:��ʼվ
    // vector[i].first:�������� vector[i].second:��һվ
    std::vector<std::pair<uint32_t, uint32_t>> minCost(int _start, int _end);
};

#endif // GRAPH_H
