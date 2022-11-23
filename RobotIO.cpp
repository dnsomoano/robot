#include "RobotIO.h"

RobotIO::RobotIO(string filename)
{
	set_filename(filename);
}

RobotList RobotIO::loadRobots()
{
	vector<pair<string, string>> rfStrToks;
	int totalRobots = 0;
	RobotList robots;
    ifstream inputRobFile("custom-example.txt");
	if (inputRobFile)
	{
		string line;
		while (getline(inputRobFile, line))
		{
			if (line != "")
			{
				totalRobots = stol(line);
				getline(inputRobFile, line, '\n');
					for (int i = 0; i < totalRobots; i++)
					{
						if (line == "")
						{
							getline(inputRobFile, line, '\n');
						}
						RobotFileObj newRobot;
						newRobot.setType(line);
						if (newRobot.getType() == "omnidroid")
						{
							newRobot.isOmnidroid = true;
						}
						else
						{
							newRobot.isRobotomaton = true;
						}
						if (newRobot.isOmnidroid)
						{
							getline(inputRobFile, line, ' ');
							newRobot.setTotalParts(stol(line));
							getline(inputRobFile, line, '\n');
							newRobot.setTotalDeps(stol(line));
						}
						else {
							getline(inputRobFile, line, '\n');
							newRobot.setTotalParts(stol(line));
						}
						int depCount = 0;
						if (newRobot.isOmnidroid)
						{
							while (depCount < newRobot.getTotalDeps())
							{
								pair<int, int> p;
								int lineSize = 0;
								getline(inputRobFile, line, '\n');
								lineSize = line.length();
								int spPost = line.find(" ");
								p.first = stol(line.substr(0, spPost));
								p.second = stol(line.substr(spPost, lineSize));
								newRobot.addDepend(p);
								depCount++;
							}
						}
						int partCount = 0;
						while (partCount < newRobot.getTotalParts())
						{
							getline(inputRobFile, line, '\n');
							if (newRobot.isOmnidroid)
								newRobot.addPartId(stol(line));
							else
							{
								int spPost = line.find(" ");
								int lineSize = line.length();
								newRobot.addPartId(stol(line.substr(0, spPost)));
								newRobot.addStage(stol(line.substr(spPost, lineSize)));
							}
							partCount++;
							//
						}
						getline(inputRobFile, line, '\n');
						robots += newRobot;
					}
			}
		}
		inputRobFile.close();
	}
	return robots;
}

void RobotIO::saveSprockets(vector<long long int> sprocketTotals, long int size)
{
	ofstream sprocketOutputFile("output.txt");
	for (int i = 0; i < size; i++)
	{
		sprocketOutputFile << sprocketTotals[i] << endl;
	}
	sprocketOutputFile.close();
}

void RobotIO::set_filename(string fname_param)
{
	filename = fname_param;
}

string RobotIO::get_filename()
{
	return filename;
}
