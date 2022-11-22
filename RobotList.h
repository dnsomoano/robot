#ifndef ROBOTLIST_H
#define ROBOTLIST_H
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "RobotFileObj.h"

using namespace std;

class RobotList
{
	vector<RobotFileObj> robotInpObjs;
public:
	int length = 0;
	void operator+= (RobotFileObj& robotInp);
	RobotFileObj& operator[](int index);
};

#endif // !ROBOTLIST_H!
