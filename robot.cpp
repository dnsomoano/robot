// robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <limits>
#include <ctype.h>
#include "RobotIO.h"
#include "Omnidroid.h"
#include "Robotomaton.h"

using namespace std;

int main()
{
	vector<pair<string, string>> rfStrToks;
	long int numOfRobots = 0, totalParts = 0, totalLayers = 0;
	vector<long long int> sprocketTotals;
	RobotIO robotIO("example-input.txt");
	RobotList robotList = robotIO.loadRobots();
	numOfRobots = robotList.length;
	for (int i = 0; i < robotList.length; i++)
	{
		if (robotList[i].isOmnidroid)
		{
			Omnidroid newOmni = Omnidroid(robotList[i], robotList[i].getTotalParts(), robotList[i].getTotalDeps());
			sprocketTotals.push_back(newOmni.getTotalSprockets());
		}
		else
		{
			Robotomaton newRoboto = Robotomaton(robotList[i], robotList[i].getCostByPartId(), robotList[i].getStages());
			sprocketTotals.push_back(newRoboto.getTotalSprockets());

		}
	}
	//
	for (int i = 0; i < numOfRobots; i++)
	{
		cout << sprocketTotals[i] << endl;
	}
	robotIO.saveSprockets(sprocketTotals, numOfRobots);
}
