#pragma once

#include <string>

using namespace std;

class Enemy 
{
private:
	string description;
	bool exist;
public:
	Enemy();
	virtual ~Enemy();

	void setdescription(string);
	bool getstate();
	void setstate(bool);
};

