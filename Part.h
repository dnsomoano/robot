#pragma once
#include <iostream>
#include <string>

using namespace std;

class Part
{
private:
	string name;
	int sprockets;
public:
	Part* left;
	Part* right;
	Part* parent;
	bool isRoot;
	Part();
	Part(int x);
	Part(string n, int x);
	virtual string get_name();
	virtual void set_name(string n);
	virtual int get_sprockets();
	virtual void set_sprockets(int i);
	virtual void insert(string name, int sp);
};

class RobotTree
{
protected:
  Part* root;
  int size;
public:
  RobotTree() { root = nullptr; size = 0; }
  int getSize() const { return size; }
  virtual void insert(string name, int x);
  //virtual void remove(int x);
};
