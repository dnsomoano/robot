#ifndef ROBOTOMATON_H
#define ROBOTOMATON_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Robotomaton
{
public:
	Robotomaton(vector<pair<string, string>> strToks, int sprockets[], int stages[]);
	void BuildRobotomata(vector<pair<string, string>> strToks, int sprockets[], int stages[]);
};
#endif // !ROBOTOMATON_H 
