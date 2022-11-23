#include "Omnidroid.h"

Omnidroid::Omnidroid(vector<pair<string, string>> strToks, int p, int d)
{
	totalParts = p;
	totalDependencies = d;
	buildPartsMap(strToks, totalParts, totalDependencies);
}

void Omnidroid::buildPartsMap(vector<pair<string, string>> rfStrToks, int parts, int deps)
{
	vector<int> listOfPartsById;
	bool isOmni = false;
	vector<int> sprockets;
	vector<int> use;
	unordered_map<int, vector<int>> req;
	int totalBldSteps = deps + 3;
	int ifSize = rfStrToks.size();
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
				int jUp = j - 1;
				int jCol = j + 2;
				int numOfConsec = 2;
				while (stoi(rfStrToks[jUp].first) == iVal)
				{
					numOfConsec++;
					jUp--;
				}
				while (stoi(rfStrToks[jCol].first) == iVal)
				{
					numOfConsec++;
					jCol++;
				}
				// TODO change to power of 2 instead of 4.
				for (int b = 0; b < numOfConsec; b++)
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
	for (int k = deps + 3; k < ifSize && l < totalParts; k++, l++)
	{
		sprockets.push_back(stoi(rfStrToks[k].first));
	}
	for (int i = 0; i < totalParts; i++)
	{
		listOfPartsById.push_back(0);
	}
	unordered_map<int, vector<int>>::iterator itr;
    for(itr = req.begin(); itr != req.end(); itr++){
        //cout << itr->first << ": ";
		int sum = 0;
        for(auto v : itr->second){
			listOfPartsById[v] = listOfPartsById[v] + 1;
        }
        cout << '\n';
    }
	listOfPartsById[totalParts - 1] = 1;
	vector<int> totalSprockets;
	//totalSprockets = totalSprocketWrapper(listOfPartsById, sprockets, totalParts);
	//int sprTot = naiveRb(listOfPartsById, sprockets, totalParts - 1);
	int sprTot = totalSprocketWrapper(listOfPartsById, sprockets, totalParts - 1);
	cout << "Added one robot" << endl;
}

int Omnidroid::totalSprocketWrapper(std::vector<int> listOfPartsById, vector<int> sprockets, int totalParts)
{
	// * Initialize array with sentinel value
	vector<int> sprocketsLookup;
	for (int i = 0; i < totalParts + 1; i++)
	{
		sprocketsLookup.push_back(-1);
	}
	return memoizedSprockets(listOfPartsById, sprockets, sprocketsLookup, totalParts);
}

int Omnidroid::memoizedSprockets(vector<int> listOfPartsById, vector<int> sprockets, vector<int>& sprocketsLookup, int totalPts)
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
