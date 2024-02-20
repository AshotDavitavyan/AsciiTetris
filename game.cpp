#include <string>
#include <unistd.h>
#include "map.hpp"

int main() {
	std::ifstream mapF("map.txt");
	Map map;
	if (!mapF.is_open())
		return (0);
	map.readMap(mapF);
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	timeout(0);

	while (true) {
		if (map.getIsTetrominoActive() == false){
			map.addTet(std::rand() % 7);
			map.getIsTetrominoActive() = true;
		}
		map.move(getch());
		map.printMap();
		refresh();
		if (clock() - map.getStart() >= 1000000){
			map.getStart() = clock();
			map.move('s');
		}
	}
	endwin();
	return 0;
}