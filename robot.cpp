// robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include "Part.h"

using namespace std;

struct RobotStruct {
	string joints = "";
	string partNum = "";
};

int main()
{
	vector<RobotStruct> robotsFromFile;
	int numOfRobots = 0;
	int totalParts = 0, totalLayers = 0;
	Part* omnidroid = new Part();
	Part* robotamton = new Part();
    ifstream inputRobFile("example-input.txt");
	if (inputRobFile)
	{
		string line;
		//while (getline(inputRobFile, line))
		while (getline(inputRobFile, line))
		{
			if (line != "")
			{
				RobotStruct rb;
				stringstream s(line);
				getline(s, rb.joints, ' ');
				if (s.peek() != EOF)
				{
					s >> rb.partNum;
				}
				robotsFromFile.push_back(rb);
			}
			cout << line << endl;
		}
		inputRobFile.close();
	}
	numOfRobots = stoi(robotsFromFile[0].joints);
	for (int i = 0; i < numOfRobots; i++)
	{
		omnidroid->set_name(robotsFromFile[1].joints);
		totalParts = stoi(robotsFromFile[2].joints);
		totalLayers = stoi(robotsFromFile[2].partNum);
	}
}
//testing git commands
