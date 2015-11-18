#pragma once
#include "Map.h"

#include "Item.h"
#include <vector>

class Player 
{
private:
	Map* progress;
	string way;
	vector<string> ite;

public:
	Player();
	virtual ~Player();

	Map* walk();	

	string inventory();
	string whereIam();

	void position(Map* m);
	void dropmagazine();
	void playergoback();
	void walking(string);
	void take();

	bool playerhasmagazine();
	bool boss();
	bool ending();
	bool allitems();
};

