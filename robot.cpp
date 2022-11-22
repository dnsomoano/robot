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
	int numOfRobots = 0, totalParts = 0, totalLayers = 0;
	// * Read input file.
    ifstream inputRobFile("small-omni-input.txt");
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
				rfStrToks.push_back(p);
			}
		}
		//while (getline(inputRobFile, line))
		//getline(inputRobFile, line, '\n');
		//numOfRobots = stoi(line);
		//getline(inputRobFile, line, '\n');
		//getline(inputRobFile, line, '\n');
		//if (line.compare("omnidroid") == 0)
		//{
		//	isOmni = true;
		//	getline(inputRobFile, line, ' ');
		//	totalParts = stoi(line);
		//	getline(inputRobFile, line, ' ');
		//	totalLayers = stoi(line);
		//	getline(inputRobFile, line, '\n');
		//	cout << line << endl;
		//	while (getline(inputRobFile, line, '\n'))
		//	{
		//			// * Omnidroid
		//		//pair<string, string> p;
		//		//stringstream s(line);
		//		//getline(s, p.first, ' ');
		//		//if (s.peek() != EOF)
		//		//{
		//		//	s >> p.second;
		//		//}
		//		//robotsFromFile.push_back(p);
		//	}
		//	cout << line << endl;
		inputRobFile.close();
	}
	numOfRobots = stoi(rfStrToks[0].first);
	totalParts = stoi(rfStrToks[2].first);
	totalLayers = stoi(rfStrToks[2].second);
	Omnidroid newOmni = Omnidroid(rfStrToks, totalParts, totalLayers);
}
