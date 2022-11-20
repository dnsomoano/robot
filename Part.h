#pragma once
#include <iostream>
#include <string>

using namespace std;

class Part
{
private:
	string name;
	int partIndex;
	int sprockets;
public:
	Part* left;
	Part* right;
	Part* parent;
	bool isRoot;
	Part();
	Part(int ptidx, int x);
	Part(string n, int ptidx, int x);
	virtual string get_name();
	virtual void set_name(string n);
	virtual int get_part_index();
	virtual void set_part_index(int i);
	virtual int get_sprockets();
	virtual void set_sprockets(int i);
	virtual void insert(string name, int ptIdx, int sp);
};

class RobotTree
{
protected:
  Part* root;
  int size;
public:
  RobotTree() { root = nullptr; size = 0; }
  int getSize() const { return size; }
  virtual void insert(string name, int ptIdx, int x);
  //virtual void remove(int x);
};
