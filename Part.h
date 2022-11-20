#pragma once
#include <iostream>
#include <string>

using namespace std;

class Part
{
private:
	Part* left;
	Part* right;
	Part* parent;
	string name;
	int sprockets;
public:
	bool isRoot;
	Part();
	virtual string get_name();
	virtual void set_name(string n);
	virtual int get_sprockets();
	virtual void set_sprockets(int i);
};

