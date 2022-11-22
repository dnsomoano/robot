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
	//static TaskList load_tasks();
	//static void save_tasks(TaskList& tasks);
	void set_filename(string fname_param);
	string get_filename();
};
#endif // !ROBOTIO_H
