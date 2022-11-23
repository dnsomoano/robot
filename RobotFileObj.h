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
	long int totalParts = 0;
	long int totalDeps = 0;
	vector<long int> partVals;
	vector<pair<long int, long int>> deps;
	vector<long int> stages;
public:
	bool isOmnidroid = false;
	bool isRobotomaton = false;
	RobotFileObj();
	void setType(string s) { type = s; }
	void setTotalParts(long int i) { totalParts = i; }
	void setTotalDeps(long int i) { totalDeps = i; }
	void addPartId(long int i) { partVals.push_back(i); }
	void addDepend(pair<long int, long int> d) { deps.push_back(d); }
	void addStage(long int i) { stages.push_back(i); };

	string getType() { return type; }
	long int getTotalParts() { return totalParts; }
	long int getTotalDeps() { return totalDeps; }
	vector<long int> getCostByPartId() { return partVals; }
	vector<pair<long int, long int>> getDeps() { return deps; }
	vector<long int> getStages() { return stages; }
};
#endif // !ROBOTIOBJ_H
