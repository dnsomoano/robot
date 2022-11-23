#ifndef OMNIDROID_H
#define OMNIDROID_H
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
#include "RobotFileObj.h"

using namespace std;

class Omnidroid
{
	long int totalDependencies;
	long int totalParts;
private:
	long long int totalSprockets;
	void buildPartsMap(RobotFileObj rbf, long int parts, long int deps);
	long long int memoizedSprockets(vector<long int> listOfPartsById, vector<long int> sprockets, vector<long long int>& sumArr, long int totalPts);
	long long int totalSprocketHelper(vector<long int> listOfPartsById, vector<long int> sprockets, long int totalParts);
public:
	Omnidroid(RobotFileObj rbf, long int p, long int d);
	long long int getTotalSprockets() { return totalSprockets; };
	void setTotalSprockets(long long int s) { totalSprockets = s; };
};
#endif // !OMNIDROID_H 
