#ifndef ROBOTOMATON_H
#define ROBOTOMATON_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "RobotFileObj.h"

using namespace std;

class Robotomaton
{
	vector<long int> stages;
	vector<long int> parts;
private:
	long long int totalSprockets;
public:
	Robotomaton(RobotFileObj rbt, vector<long int> sprockets, vector<long int> stages);
	void BuildRobotomata(RobotFileObj rbf, vector<long int> sprockets, vector<long int> stages);
	long long int getTotalSprockets() { return totalSprockets; };
	void setTotalSprockets(long long int s) { totalSprockets = s; };
};
#endif // !ROBOTOMATON_H 

