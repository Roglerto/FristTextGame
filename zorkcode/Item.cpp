#include "stdafx.h"
#include "Item.h"
#include <iostream>

Item::Item()
{
	item = "There is nothing";
	name = "";
}


Item::~Item()
{
}

void Item::addItem( string n,string des) {

	name = n;
	item = des;
	
}

string Item::getItem() {

	return item;
}

string Item::getName() {
	return name;
}

void Item::deleteItem() {
	item = "There is nothing";
	name = "";
}