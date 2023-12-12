#include"Graph.h"

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
	return 0;
}
