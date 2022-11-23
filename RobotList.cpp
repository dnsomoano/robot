#include "RobotList.h"

void RobotList::operator+=(RobotFileObj& robotInp)
{
	robotInpObjs.push_back(robotInp);
	length++;
}

RobotFileObj& RobotList::operator[](long int index)
{
	return robotInpObjs[index];
}
