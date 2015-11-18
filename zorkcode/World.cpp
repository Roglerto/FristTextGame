#include "stdafx.h"
#include "World.h"
#include <iostream>


World::World(Map m)
{
	map = m;

	map.AddStartRoom();

	map.AddRoom1();
	map.AddRoom2();
	map.AddRoom3();
	map.AddRoom4();
	map.AddRoom5();
	map.AddRoom6();

	map.AddEndRoom();

	player.position(map.getposition());


}


World::~World()
{
	map.deleterooms();

}

string World::position() {
	string aux;
	return player.whereIam();

}

void World::go(string s) {

	player.walking(s);
	

}

string World::watch() {

	return map.watch(player.walk());
}

void World::take() {

	player.take();
}

string World::playerInventory() {

	return player.inventory();
}
bool World::bossfight() {

	if (player.boss()==true) {
		return true;
	}
	else return false;
}

void World::goback() {
	
	player.playergoback();
}

bool World::playermagazine() {

	return player.playerhasmagazine();
}

void World::babysitermove() {

	player.dropmagazine();
}

bool World::endgame() {
	return player.ending();
}

bool World::playerallitem() {
	
	return player.allitems();
}