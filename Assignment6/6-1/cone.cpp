#include "cone.h"
#include <string>

#define PI_NUMBER 3.14

using namespace std;

Cone::Cone(int _x,int _y,int _z,int _radius,int _height)
	:Shape (_x,_y,_z)
{
	if (_radius <= 0 || _height<=0)
    	throw IllegalArgumentException();
	radius = _radius;
	height = _height;
}

void Cone::scale(int factor)
{
	radius *= factor;
	height *= factor;
}

int Cone::volume() const
{
	return pow(radius,2)*height*3.14/3;
}

string Cone::get_type() const {return "Cone";}