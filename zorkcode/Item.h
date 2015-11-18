#pragma once
#include <map>
#include<string>

using namespace std;

class Item
{
private:
	string item;
	string name;

public:
	Item();
	virtual ~Item();

	void addItem(string,string);
	void deleteItem();
	string getItem();
	string getName();
};

