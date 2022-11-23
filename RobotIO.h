#ifndef ROBOTIO_H
#define ROBOTIO_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "RobotList.h"

using namespace std;

class RobotIO
{
private:
	string filename;
public:
	RobotIO(string filename = "");
	static RobotList loadRobots();
	void saveSprockets(vector<long long int> sprocketTotals, long int size);
	void set_filename(string fname_param);
	string get_filename();
};
#endif // !ROBOTIO_H
