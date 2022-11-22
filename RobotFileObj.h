#ifndef ROBOTFILEOBJ_H
#define ROBOTFILEOBJ_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RobotFileObj
{
	string type = "";
	int totalParts = 0;
	int totalDeps = 0;
public:
	vector<int> partVals;
	vector<pair<int, int>> deps;
	RobotFileObj();
	void setType(string s) { type = s; }
	void setTotalParts(int i) { totalParts = i; }
	void setTotalDeps(int i) { totalDeps = i; }
	void addPartId(int i) { partVals.push_back(i); }
	void addDepend(pair<int, int> d) { deps.push_back(d); }

	string getType() { return type; }
	int getTotalParts() { return totalParts; }
	int getTotalDeps() { return totalDeps; }
	vector<int> getCostByPartId() { return partVals; }
	vector<pair<int, int>> getDeps() { return deps; }
};
#endif // !ROBOTIOBJ_H
