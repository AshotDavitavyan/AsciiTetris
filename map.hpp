#include <vector>
#include <ncurses.h>
#include <iostream>
#include <fstream>

class blocks{
private:
	int x;
	int y;
public:
	void setXY(int x, int y){this->x = x; this->y = y;}
	int &getX(){return (x);}
	int &getY(){return (y);}
};

class Map{
private:
	clock_t start;
	std::vector<std::string> mapArr;
	bool isTetrominoActive;
public:
	blocks currentBlocks[4];
	Map(){start = clock();}
	std::vector<std::string> &getMapArr();
	bool &getIsTetrominoActive();
	clock_t &getStart();
	void printMap();
	void readMap(std::ifstream &mapF);
	void addTet(int tet);
	void putOnMap();
	void move(int ch);
	void changeMap(int x, int y);
};