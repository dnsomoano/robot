// robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <ctype.h>
#include "Part.h"

using namespace std;

int main()
{
	bool isOmni = false;
	vector<int> sprockets;
	unordered_map<int, vector<int>> use;
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
		//while (getline(inputRobFile, line))
		getline(inputRobFile, line, '\n');
		numOfRobots = stoi(line);
		getline(inputRobFile, line, '\n');
		getline(inputRobFile, line, '\n');
		if (line.compare("omnidroid") == 0)
		{
			isOmni = true;
			getline(inputRobFile, line, ' ');
			totalParts = stoi(line);
			getline(inputRobFile, line, ' ');
			totalLayers = stoi(line);
			getline(inputRobFile, line, '\n');
			cout << line << endl;
			while (getline(inputRobFile, line, '\n'))
			{
					// * Omnidroid
				//pair<string, string> p;
				//stringstream s(line);
				//getline(s, p.first, ' ');
				//if (s.peek() != EOF)
				//{
				//	s >> p.second;
				//}
				//robotsFromFile.push_back(p);
			}
			cout << line << endl;
		}
		inputRobFile.close();
	}
	//int ifSize = robotsFromFile.size();
	//numOfRobots = stoi(robotsFromFile[0].first);
	//for (int i = 0; i < numOfRobots; i++)
	//{
	//	RobotTree rbt;
	//	totalParts = stoi(robotsFromFile[2].first);
	//	totalLayers = stoi(robotsFromFile[2].second);
	//	int l = 0;
	//	for (int k = totalLayers + 3; k < ifSize && l < totalParts; k++, l++)
	//	{
	//		sprockets.push_back(stoi(robotsFromFile[k].first));
	//	}
	//	rbt.insert(robotsFromFile[1].first, sprockets[totalParts - 1], 6);
	//	for (int j = 3; j < totalLayers + 3 || isalpha(robotsFromFile[j].first[0]); j++)
	//	{
	//		// TODO check for empty string, do not overflow to parts list.
	//		rbt.insert("", sprockets[stoi(robotsFromFile[j].first)], stoi(robotsFromFile[j].first));
	//	}
	//	robots.push_back(rbt);
	//	cout << "Added one robot" << endl;
	//	//omnidroid->set_name(robotsFromFile[1].first);
	//	//omnidroid->set_sprockets(6);
	//}
}

//testing
