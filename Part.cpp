#include "Part.h"

Part::Part() 
{
	name = "";
	sprockets = 0;
}
string Part::get_name()
{
	return name;
}
void Part::set_name(string n)
{
	name = n;
}
int Part::get_sprockets()
{
	return sprockets;
}
void Part::set_sprockets(int i)
{
	sprockets = i;
}
