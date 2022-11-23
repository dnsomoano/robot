#include "Omnidroid.h"

Omnidroid::Omnidroid(RobotFileObj strToks, long int p, long int d)
{
	totalParts = p;
	totalDependencies = d;
	buildPartsMap(strToks, totalParts, totalDependencies);
}

void Omnidroid::buildPartsMap(RobotFileObj rbf, long int parts, long int deps)
{
	vector<long int> listOfPartsById;
	vector<long int> sprockets = rbf.getCostByPartId();
	vector<long int> use;
	unordered_map<long int, vector<long int>> req;
	long long int sprocketsTotal = 0;
	vector<pair<long int, long int>> depsList = rbf.getDeps();
	//int ifSize = rfStrToks.size();
	for (long int j = 0; j < deps; j++)
	{
		long int iVal = depsList[j].first;
		long int iPlusOneVal = -1;
		if ((j + 1) < deps)
		{
			iPlusOneVal = depsList[j+1].first;
		}
		long int jVal = depsList[j].second;
		int jPlusOneVal = -1;
		if ((j + 1) < deps)
		{
			jPlusOneVal = depsList[j + 1].second;
		}

		bool isIValsEq = iVal == iPlusOneVal;
		bool isJValsEq = jVal == jPlusOneVal;
		bool isIValIntermPart = find(use.begin(), use.end(), iVal) != use.end();
		bool isJValIntermPart = find(use.begin(), use.end(), jVal) != use.end();
		// * If i int is eq to i + 1 int and j is eq to j + 1 int.
		// * Add i and i + 1 and entries into req, plus add an entry each for j and j + 1 to use(interm array).
		if (isIValsEq && isJValsEq)
		{
			int jUp = 0;
			int numOfConsec = 2;
			jUp = j - 1;
			if (jUp > -1)
			{
				while (jUp > -1 && depsList[jUp].first == iVal)
				{
					numOfConsec++;
					jUp--;
				}
			}
			if (j + 2 < deps)
			{
				int jCol = j + 2;
				while (depsList[jCol].first == iVal)
				{
					numOfConsec++;
					jCol++;
				}
			}
			if (!isIValIntermPart)
			{
				for (int b = 0; b < numOfConsec; b++)
					req[jVal].push_back(iVal);
				use.push_back(jVal);
			}
			else
			{
				for (int b = 0; b < numOfConsec; b++)
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
	//// * Generating sprockets for parts id by value.
	// * Flatten map to a 1-d array, so that each index is a total count of that part.
	for (int i = 0; i < parts; i++)
	{
		listOfPartsById.push_back(0);
	}
	unordered_map<long int, vector<long int>>::iterator itr;
    for(itr = req.begin(); itr != req.end(); itr++){
        //cout << itr->first << ": ";
		int sum = 0;
        for(auto v : itr->second){
			listOfPartsById[v] = listOfPartsById[v] + 1;
        }
    }
	// * Append the last part, which will not appear as a basic part in the map.
	listOfPartsById[parts - 1] = 1;
	// Recursively iterate through 1-d array with part counts, using memoized algorithm.
	sprocketsTotal = totalSprocketHelper(listOfPartsById, sprockets, parts - 1);
	setTotalSprockets(sprocketsTotal);
}

long long int Omnidroid::totalSprocketHelper(std::vector<long int> listOfPartsById, vector<long int> sprockets, long int totalParts)
{
	// * Initialize array with sentinel value
	vector<long long int> sprocketsLookup;
	for (int i = 0; i < totalParts + 1; i++)
	{
		sprocketsLookup.push_back(-1);
	}
	return memoizedSprockets(listOfPartsById, sprockets, sprocketsLookup, totalParts);
}

long long int Omnidroid::memoizedSprockets(vector<long int> listOfPartsById, vector<long int> sprockets, vector<long long int>& sprocketsLookup, long int totalPts)
{
	if (totalPts < 0)
	{
		return 0;
	}
	if (sprocketsLookup[totalPts] == -1)
	{
		if (totalPts < 0)
		{
			return sprocketsLookup[totalPts];
		}
		else
		{
			sprocketsLookup[totalPts] = sprockets[totalPts] * listOfPartsById[totalPts] + (memoizedSprockets(listOfPartsById, sprockets, sprocketsLookup, totalPts - 1));
		}
	}
	return sprocketsLookup[totalPts];
}
