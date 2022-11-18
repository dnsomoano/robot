// robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int sprockets = 0;
    ifstream inputRobFile("example-input.txt");
	if (inputRobFile)
	{
		string line;
		while (getline(inputRobFile, line))
		{
			cout << line << endl;
		}
		inputRobFile.close();
	}
	//testing..............
}
