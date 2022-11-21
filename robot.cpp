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
#include "Part.h"

using namespace std;

int rec_omnidroid(vector<int>& sprockets, unordered_map<int, vector<int> >& prev, unordered_map<int, int>& step_map, int current);
// int rec_robotomaton();

int main()
{
	bool isOmni = false;
	vector<int> sprockets;
	vector<int> use;
	unordered_map<int, vector<int>> req;
	vector<pair<string, string>> rfStrToks;
	int numOfRobots = 0, totalParts = 0, totalLayers = 0;
	Part* omnidroid = new Part();
	Part* robotamton = new Part();
	// * Read input file.
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
				rfStrToks.push_back(p);
			}
			//cout << line << endl;
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
	int ifSize = rfStrToks.size();
	numOfRobots = stoi(rfStrToks[0].first);
	totalParts = stoi(rfStrToks[2].first);
	//cout << totalParts << endl;
	totalLayers = stoi(rfStrToks[2].second);
	//cout << totalLayers << endl;
	int totalBldSteps = totalLayers + 3;
	for (int j = 3; j < totalBldSteps || isalpha(rfStrToks[j].first[0]); j++)
	{
		int iVal = stoi(rfStrToks[j].first);
		int iPlusOneVal = stoi(rfStrToks[j+1].first);

		int jVal = stoi(rfStrToks[j].second);
		int jPlusOneVal = 0;
		if ((j + 1) < totalBldSteps)
		{
			jPlusOneVal = stoi(rfStrToks[j + 1].second);
		}

		bool isIValsEq = iVal == iPlusOneVal;
		bool isJValsEq = jVal == jPlusOneVal;
		bool isIValIntermPart = find(use.begin(), use.end(), iVal) != use.end();
		bool isJValIntermPart = find(use.begin(), use.end(), jVal) != use.end();
		// * If i int is eq to i + 1 int and j is eq to j + 1 int.
		// * Add i and i + 1 and entries into req, plus add an entry each for j and j + 1 to use(interm array).
		if (isIValsEq && isJValsEq)
		{
			if (!isIValIntermPart)
			{
				// TODO change to power of 2 instead of 4.
				for (int b = 0; b < 4; b++)
				{
					req[jVal].push_back(iVal);
				}
				use.push_back(jVal);
			}
			else
			{
				// TODO change to power of 2 instead of 4.
				for (int b = 0; b < 2; b++)
					req[jVal].push_back(iVal);
			}
			j = j + 1;
		}
		// * If i int is NOT eq to i + 1 int and j is eq to j + 1 int.
		// * Add i and i + 1 and entries into req, and add ONLY one entry for j and j + 1 to use(interm array).
		else if (!isIValsEq && isJValsEq)
		{
			req[jVal].push_back(iVal);
			req[jVal].push_back(iPlusOneVal);
			use.push_back(jVal);
			j = j + 1;
		}
		// * If i int is NOT eq to i + 1 int and j is NOT eq to j + 1 int.
		// * Add i and i + 1 as SEPARATE entries into req, plus add an entry each for j, corresp with i, and j + 1, corresp with i + 1, to use(interm array).
		else if (!isIValsEq && !isJValsEq)
		{
			req[jVal].push_back(iVal);
			if (!isJValIntermPart)
				use.push_back(jVal);
		}
	}
	// * Generating sprockets lookup for parts.
	int l = 0;
	for (int k = totalLayers + 3; k < ifSize && l < totalParts; k++, l++)
	{
		sprockets.push_back(stoi(rfStrToks[k].first));
	}
	cout << "Added one robot" << endl;

	// TODO must iterate over map using memoized algorithm to generate total sprockets for each robot.
}//end main