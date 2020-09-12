#include "sphere.h"
#include <string>

#define PI_NUMBER 3.14

using namespace std;

Sphere::Sphere(int _x,int _y,int _z,int _radius)
	: Shape(_x, _y, _z)
{
   	if (_radius <= 0)
    	throw IllegalArgumentException();
   	radius = _radius;
}

void Sphere::scale (int factor)
{
	radius *= factor;
}

int Sphere::volume () const
{
	return pow(radius,3)*(3.14)*4/3; 
}

string Sphere::get_type () const {return "Sphere";}