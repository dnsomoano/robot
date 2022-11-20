// robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <limits>
#include <ctype.h>
#include "Part.h"

using namespace std;

int main()
{
	bool isOmni = false;
	vector<int> sprockets;
	vector<int> use;
	vector<vector<int>> req;
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
	int ifSize = robotsFromFile.size();
	numOfRobots = stoi(robotsFromFile[0].first);
	for (int i = 0; i < numOfRobots; i++)
	{
		RobotTree rbt;
		totalParts = stoi(robotsFromFile[2].first);
		totalLayers = stoi(robotsFromFile[2].second);
		// * Generating sprockets lookup for parts.
		int l = 0;
		for (int k = totalLayers + 3; k < ifSize && l < totalParts; k++, l++)
		{
			sprockets.push_back(stoi(robotsFromFile[k].first));
		}
		// *
		//rbt.insert(robotsFromFile[1].first, sprockets[totalParts - 1], 6);
		for (int j = 3; j < totalLayers + 3 || isalpha(robotsFromFile[j].first[0]); j++)
		{
			int currentBasicPt = stoi(robotsFromFile[j].first);
			int nextBasicPt = stoi(robotsFromFile[j + 1].first);
			int prevBasicPt = stoi(robotsFromFile[j - 1].first);

			int currentIntermPt = stoi(robotsFromFile[j].second);
			int nextIntermPt = stoi(robotsFromFile[j + 1].second);
			int prevIntermPt = stoi(robotsFromFile[j - 1].second);
			vector<int> children;
			bool hasTwoArtJoints = currentBasicPt == nextBasicPt;
			bool hasTwoArmsOrLegs = currentIntermPt == nextIntermPt;
			// TODO check for empty string, do not overflow to parts list.
			if (hasTwoArtJoints && hasTwoArmsOrLegs)
			{
				children.push_back(stoi(robotsFromFile[j].first));
				children.push_back(stoi(robotsFromFile[j+1].first));
				req.push_back(children);
				//req.push_back(children);
				use.push_back(stoi(robotsFromFile[j].second));
				use.push_back(stoi(robotsFromFile[j+1].second));
				children.clear();
				//j = j + 1;
			}
			else if(hasTwoArtJoints && !hasTwoArtJoints)
			{

				if (use[currentIntermPt])
				{
					req[use[currentIntermPt]].push_back(currentBasicPt);
				}

			//}
			rbt.insert("", stoi(robotsFromFile[j].first), sprockets[stoi(robotsFromFile[j].first)]);
		}
		robots.push_back(rbt);
		cout << "Added one robot" << endl;
		//omnidroid->set_name(robotsFromFile[1].first);
		//omnidroid->set_sprockets(6);
	}
}

//testing
