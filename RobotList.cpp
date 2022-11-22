#include "RobotList.h"

void RobotList::operator+=(RobotFileObj& robotInp)
{
	robotInpObjs.push_back(robotInp);
	length++;
}

RobotFileObj& RobotList::operator[](int index)
{
	return robotInpObjs[index];
}
