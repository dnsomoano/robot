#ifndef OMNIDROID_H
#define ROBOTOMATON_H
#pragma once
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

using namespace std;

class Omnidroid
{
	int totalDependencies;
	int totalParts;
public:
	Omnidroid(vector<pair<string, string>> strToks, int p, int d);
	void buildPartsMap(vector<pair<string, string>> strToks, int parts, int deps);
	int memoizedSprockets(vector<int> listOfPartsById, vector<int> sprockets, vector<int>& sumArr, int totalPts);
	int totalSprocketWrapper(vector<int> listOfPartsById, vector<int> sprockets, int totalParts);
};
#endif // !OMNIDROID_H 
