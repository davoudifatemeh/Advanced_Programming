#include "cuboid.h"
#include <string>

using namespace std;

Cuboid::Cuboid(int _x,int _y,int _z,int _width,int _height,int _depth)
	: Shape (_x,_y,_z)
{
	if (_width <= 0 || _height<=0 || _depth<=0)
    	throw IllegalArgumentException();
	width = _width;
	height = _height;
	depth = _depth;
}

void Cuboid::scale(int factor)
{
	width *= factor;
	height *= factor;
	depth *= factor;	
}

int Cuboid::volume() const
{
	return width*height*depth; 
}

string Cuboid::get_type () const {return "Cuboid";}