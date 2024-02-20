#include "map.hpp"

std::vector<std::string> &Map::getMapArr(){
	return (mapArr);
}

bool &Map::getIsTetrominoActive(){
	return (isTetrominoActive);
}

clock_t &Map::getStart(){
	return (start);
}

void Map::printMap(){
	clear();
	std::string block = "██";
	for (size_t i = 0; i < mapArr.size(); i++){
		for (size_t j = 0; j < mapArr[i].size(); j++){
			switch (mapArr[i][j]){
				case '1':
				printw("%s", block.c_str());
				break;
				case '0':
				printw("  ");
				break;
			}
		}
		printw("\n");
	}
}

void Map::readMap(std::ifstream &mapF){
	std::string line;

	while (getline(mapF, line))
		mapArr.push_back(line);
}

void Map::putOnMap(){
	for (size_t i = 0; i < 4; i++)
		mapArr[currentBlocks[i].getX()][currentBlocks[i].getY()] = '1';
}

void Map::addTet(int tet){
	switch (tet){
		case 0: //cube
			currentBlocks[0].setXY(0, 5);
			currentBlocks[1].setXY(0, 6);
			currentBlocks[2].setXY(1, 5);
			currentBlocks[3].setXY(1, 6);
			break ;
	}
	putOnMap();
}

void Map::changeMap(int x, int y){
	for (size_t i = 0; i < 4; i++)
		mapArr[currentBlocks[i].getX()][currentBlocks[i].getY()] = '0';
	for (size_t i = 0; i < 4; i++){
		currentBlocks[i].getX() += x;
		currentBlocks[i].getY() += y;
	}
	putOnMap();
}

void Map::move(int ch){
	switch(ch){
		case 'a':
		changeMap(0, -1);
		break ;
		case 'd':
		changeMap(0, 1);
		break ;
		case 's':
		changeMap(1, 0);
		break ;
		default:
		return;
	}
}