// robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <limits>
#include "Part.h"

using namespace std;

int main()
{
	vector<int> partsLookup;
	vector<RobotTree> robots;
	vector<pair<string, string>> robotsFromFile;
	int numOfRobots = 0;
	int totalParts = 0, totalLayers = 0;
	Part* omnidroid = new Part();
	Part* robotamton = new Part();
    ifstream inputRobFile("example-input.txt");
	if (inputRobFile)
	{
		string line;
		while (getline(inputRobFile, line))
		{
			if (line != "")
			{
				pair<string, string> p;
				stringstream s(line);
				getline(s, p.first, ' ');
				if (s.peek() != EOF)
				{
					s >> p.second;
				}
				robotsFromFile.push_back(p);
			}
			cout << line << endl;
		}
		inputRobFile.close();
	}
	int ifSize = robotsFromFile.size();
	numOfRobots = stoi(robotsFromFile[0].first);
	for (int i = 0; i < numOfRobots; i++)
	{
		RobotTree rbt;
		totalParts = stoi(robotsFromFile[2].first);
		totalLayers = stoi(robotsFromFile[2].second);
		int l = 0;
		for (int k = totalLayers + 3; k < ifSize && l < totalParts; k++, l++)
		{
			partsLookup.push_back(stoi(robotsFromFile[k].first));
		}
		rbt.insert(robotsFromFile[1].first, 6);
		for (int j = 3; j < totalLayers + 3 || isalpha(robotsFromFile[j].first[0]); j++)
		{
			// TODO check for empty string, do not overflow to parts list.
			rbt.insert(robotsFromFile[j].first, partsLookup[stoi(robotsFromFile[j].first)]);
		}
		robots.push_back(rbt);
		cout << "Added one robot" << endl;
		//omnidroid->set_name(robotsFromFile[1].first);
		//omnidroid->set_sprockets(6);
	}
}
//testing git commands
