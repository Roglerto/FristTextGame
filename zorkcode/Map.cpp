#include "stdafx.h"
#include "Map.h"
#include <iostream>


Map::Map()
{
	map = NULL;

	north = NULL;
	south = NULL;
	west = NULL;
	east = NULL;

	description="";
	name="";

	Item item();
	Enemy monster();

	start = false;
	end = false;
	wrongWay = false;

}


Map::~Map()
{/*
	delete map->north->north;
	delete map->north;
	delete map->east->north;
	delete map->east->east;
	delete map->east->south;
	delete map->south;
	delete map;

	map = NULL;
	north = NULL;
	south = NULL;
	west = NULL;
	east = NULL;
	*/
	map = NULL;
	way = NULL;
	wrongWay = false;
	start = false;
}

void Map::deleterooms() {
	delete map->north->north;
	delete map->north;
	delete map->east->north;
	delete map->east->east;
	delete map->east->south;
	delete map->south;
	delete map;

}

void Map::AddStartRoom() {

	map= new Map();
	map->description = "Seems like you are in the middle of your Bedroom. The last thing that you remember was that your parents were to have a romantic dinner, and the leave you with the babysiter.";
	way = map;
	
}

void Map::AddRoom1() {

	map->east = new Map();
	map->east->description = "You are in the bathroom ";

	map->east->west = map;


}

void Map::AddRoom2() {

	map->north = new Map();
	map->north->description = "You are in the Living Room, there is a babysiter, so you can't go further unless you drop de correct item ";
	map->north->south = map;
	map->north->east = NULL;

	map->north->monster.setdescription("rer") ;
	map->north->monster.setstate(true);

}

void Map::AddEndRoom() {

	map->north->north = new Map();
	map->north->north->description = "You are in the enter of the house you can see the movile charger so now if you have the note with the telephone number of your parents and the movil you can charge it and then call to your parents";
	map->north->north->south= map->north;

	map->north->north->end = true;
}

void Map::AddRoom3() {

	map->east->north = new Map();
	map->east->north->description = "You are in the garage, but you make too much noise opening the door, the babysitter catch you, and take you to your bedroom. \n \n -> Seems like you are in the middle of your Bedroom. The last thing that you remember was that your parents were to have a romantic dinner, and the leave you with the babysiter. ";
	map->east->north->south = map->east;
	map->east->north->west = map->north;
	map->north->east= map->east->north;

	map->east->north->start = true;
}

void Map::AddRoom4() {

	map->east->east = new Map();
	map->east->east->description = "You are in the kitchen, you fell bad";
	map->east->east->west = map->east;

	map->east->east->item.addItem(" -movile phone- ", "You can see a movile phone on the table but doesn't have battery");
	
}

void Map::AddRoom5() {

	map->south = new Map();
	map->south->description = "You are in the Toys room";
	map->south->north = map;

	map->south->item.addItem(" -telephone number- ","You can see a piece of paper there are some telephone numers include the telephone number of your parents");

}

void Map::AddRoom6() {

	map->east->south = new Map();
	map->east->south->description = "You are in your Paretns room";
	map->east->south->north = map->east;

	map->east->south->item.addItem(" -magazine- ", "You can see a magazine lie on the bed");

}

void Map::AddItem() {

}

void Map::AddEnemy() {

}

Map* Map::getposition() {

	return map;
}

string Map::RoomDescription(Map *m) {

	return m->description;
}

Map* Map::playerGoEast(Map *player) {

	if (player->east != NULL) {

		return player->east;
		
	}
	else wrongWay = true;

	return player;

}
Map* Map::playerGoWest(Map *player) {

	if (player->west != NULL) {
		
		return player->west;
		
	}
	else wrongWay = true;

	return player;

}
Map* Map::playerGoNorth(Map *player) {

	if (player->north != NULL) {
		
		return player->north;
		
	}
	else wrongWay = true;

	return player;


}
Map* Map::playerGoSouth(Map *player) {

	if (player->south != NULL) {
		
		return player->south;
		
	}
	else wrongWay = true;

	return player;

}
bool Map::noway() {

	return wrongWay;
}

string Map::watch(Map* pla) {
	
	return pla->item.getItem();
}

string Map::takeItem() {
	string objet = item.getName();
	item.deleteItem();
	return objet;
}

bool Map::restart(Map* p) {

	return p->start;
}
Map* Map::startAgain(Map* p) {

	return  p->south->west;
	
}

bool Map::bossexist(Map* player) {

	return player->monster.getstate();
}

Map* Map::Again(Map *p) {

	return p->south;
}

void Map::changedescription(Map*p) {
	p->description = "You are in the Living Room, the babysiter is reading a magazine on the corner";
}

void Map::bossnoexist(Map* p) {
	p->monster.setstate(false);
}

bool Map::finalroom(Map* p) {
	return p->end;
}