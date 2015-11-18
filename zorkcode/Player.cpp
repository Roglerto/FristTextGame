#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <vector>

Player::Player()
{
	progress = NULL;
}


Player::~Player()
{
	progress = NULL;
	way = "";
}

void Player::position(Map* m) {

	progress = m;

}

string Player::whereIam() {
	Map* aux;
	if (progress->noway()) {
		return "You can't go in that direction";
	}
	if (progress->restart(progress) == true){
		aux = progress;
		progress=progress->startAgain(progress);
		return aux->RoomDescription(aux);
	}else return progress->RoomDescription(progress);
}

Map* Player::walk() {

	return progress;
}

void Player::walking(string direction) {

	if (direction == "east") {
		progress=progress->playerGoEast(progress);
	}else if (direction == "west") {
		progress = progress->playerGoWest(progress);
	}else if (direction == "north") {
		progress = progress->playerGoNorth(progress);
	}else if (direction == "south") {
		progress = progress->playerGoSouth(progress);
	}		
}

void Player::take() {

	ite.push_back(progress->takeItem());

}

string Player::inventory() {
	string listitem;
	for (int i = 0;i < ite.size();i++)
		listitem += ite[i];

	return listitem;
}

bool Player::boss() {

	if (progress->bossexist(progress) == true) {
		return true;
	}
	else return false;

}

void Player::playergoback() {
	
	progress = progress->Again(progress);
}

bool Player::playerhasmagazine() {
	for (int i = 0;i < ite.size();i++) {
		if (ite[i] == " -magazine- ")
			return true;
	}
	return false;		
}

void Player::dropmagazine() {
	vector<string>::iterator it = ite.begin();

	if (ite.size()==1) {
		it = ite.erase(it);
		progress->changedescription(progress);
		progress->bossnoexist(progress);
	}
	else {
		for ( it = ite.begin(); it != ite.end(); ++it) {
			if (*it == " -magazine- ") {
				it = ite.erase(it);
				it = ite.begin();
			}
		}
		progress->changedescription(progress);
		progress->bossnoexist(progress);
	}
}

bool Player::ending() {
	return progress->finalroom(progress);
}

bool Player::allitems() {
	if (ite.size() == 2) {
		return true;
	}
	else return false;
}