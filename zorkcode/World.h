#include <string>
#include "Player.h"
#include "Map.h"
#pragma once


//using namespace std;

class World
{
private:
	Map map;
	Player player;
	//string n;
	bool restart;
public:
	World(Map m);
	virtual ~World();

	string position();	
	string watch();	
	string playerInventory();
	
	void goback();
	void babysitermove();
	void take();
	void go(string s);

	bool playermagazine();
	bool bossfight();
	bool endgame();
	bool playerallitem();

};

