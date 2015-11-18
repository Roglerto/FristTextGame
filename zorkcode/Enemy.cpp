#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	description = "";
	exist = false;
}


Enemy::~Enemy()
{
}

void Enemy::setdescription(string des) {

	description = des;
}

bool Enemy::getstate() {
	return exist;
}

void Enemy::setstate(bool state) {
	exist = state;
}