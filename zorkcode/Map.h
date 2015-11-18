#pragma once
#include <string>
#include "Item.h"
#include "Enemy.h"

using namespace std;
class Map
{
private:
	Map* way;
	Map* map;

	Map* north;
	Map* south;
	Map* west;
	Map* east;

	bool wrongWay;
	bool start;
	bool end;

	string name;
	string description;

	Item item;

	Enemy monster;
public:
	Map();
	virtual ~Map();

	void AddStartRoom();

	void AddRoom1();
	void AddRoom2();
	void AddRoom3();
	void AddRoom4();
	void AddRoom5();
	void AddRoom6();

	void AddEndRoom();

	void AddItem();
	void AddEnemy();
	void deleterooms();

	Map* getposition();
	Map* playerGoEast(Map *);
	Map* playerGoWest(Map *);
	Map* playerGoNorth(Map *);
	Map* playerGoSouth(Map *);
	Map* startAgain(Map*);
	Map* Again(Map*);

	bool noway();
	bool restart(Map*);
	
	string watch(Map*);
	string RoomDescription(Map* m);
	string takeItem();

	void next();
	void bossnoexist(Map*);
	void changedescription(Map*);
	
	bool bossexist(Map*);
	bool finalroom(Map*);		

};

