#include"Graph.h"

Graph::Graph() : len(0){}

Graph::Graph(int _len, std::vector<Places*> _places) : len(_len)
{
	places = _places;
	std::vector<std::vector<Path>> tem(len, std::vector<Path>(len));
	graph = tem;
}

void Graph::addPlaces(std::string _name, std::string _info)
{
	len++;
	Places* temp = new Places(_name, _info);
	places.push_back(temp);
	for (int i = 0; i < graph.size(); i++) {
		graph[i].resize(len);
	}
	graph.push_back(std::vector<Path>(len));
}

void Graph::addPlaces(json Json)
{
}

void Graph::addPath(uint32_t _busIndex, uint32_t _start, uint32_t _end, uint32_t _time, uint32_t _cost)
{
	if (_start >= len || _end >= len) {
		err("addPath");
		return;
	}
	graph[_start][_end].compare(_busIndex, _time, _cost);
}

void Graph::addPath(json Josn)
{
}

void Graph::printPlaces()
{
	std::cout << "Places: ";
	for (auto i : places) {
		std::cout << i->name << "," << i->info << " ; ";
	}
	std::cout << std::endl;
}

void Graph::PrintPath()
{
	std::cout << "Path:" << std::endl;
	for (auto i : graph) {
		for (auto j : i) {
			if (j.time == INT_MAX)	std::cout << -1 << " ";
			else std::cout << j.minTime().first << " ";
		}
		std::cout << std::endl;
	}
}

// vector[0].first:�ܻ���ʱ�� vector[0].second:��ʼվ
// vector[i].first:�������� vector[i].second:��һվ
std::vector<std::pair<uint32_t, uint32_t>> Graph::minTime(int _start, int _end)
{
	std::vector<int> lowCost(len, INT_MAX);	//��¼��̻���ʱ��
	std::vector<bool> isJoin(len, false);	//��¼�Ƿ����������
	std::vector<int> pastPlace(len, -1);	//��¼��һλ��
	lowCost[_start] = 0;
	isJoin[_start] = true;
	for (int i = 0; i < len; i++) {
		if (graph[_start][i].time == INT_MAX)	continue;
		lowCost[i] = graph[_start][i].time;
		pastPlace[i] = _start;
	}
	for (int i = 1; i < len; i++) {
		int minTime = INT_MAX, minIndex = -1;
		//�ҵ�Ŀǰ��_start����Ľڵ�
		for (int j = 0; j < len; j++) {
			if (lowCost[j] >= minTime || isJoin[j] == true)	continue;
			minIndex = j;
		}
		//�ж��Ƿ���δ��ͨ
		if (minIndex == -1) {
			err("minTime��Ŀ�ĵ�δ��ͨ");
			return std::vector<std::pair<uint32_t, uint32_t>>(NULL);
		}
		if (minIndex == _end)	break;	//�ҵ�Ŀ���յ�
		isJoin[minIndex] = true;	//���Ϊ���ҹ�
		for (int j = 0; j < len; j++) {
			if (graph[minIndex][j].time == INT_MAX
				|| isJoin[j] == true
				|| lowCost[j] <= lowCost[minIndex] + graph[minIndex][j].time) 
				continue; 
			lowCost[j] = lowCost[minIndex] + graph[minIndex][j].time;
			pastPlace[j] = minIndex;
		}
	}

	//��¼·��
	std::stack<std::pair<uint32_t, uint32_t>> Stack;
	int temp = _end;
	while (pastPlace[temp] != -1) {
		int prePlace = pastPlace[temp];
		std::pair<uint32_t, uint32_t> t(graph[prePlace][temp].timeBus, temp);
		Stack.push(t);
	}
	std::vector<std::pair<uint32_t, uint32_t>> result;
	result.push_back(std::pair<uint32_t, uint32_t>(lowCost[_end], _start));
	while (Stack.empty() == 0) {
		result.push_back(Stack.top());
		Stack.pop();
	}
	return result;
}

std::vector<std::pair<uint32_t, uint32_t>> Graph::minCost(int _start, int _end)
{
	return std::vector<std::pair<uint32_t, uint32_t>>();
}
