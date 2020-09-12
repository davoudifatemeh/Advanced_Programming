#ifndef __CUBOID_H__
#define __CUBOID_H__

#include "shape.h"
#include <iostream>
#include <string>

class Cuboid : public Shape
{
public:
	Cuboid(int _x,int _y,int _z,int _width,int _height,int _depth);
	virtual void scale(int factor);
	virtual int volume() const;
	virtual std::string get_type () const;
private:
	int x;
	int y;
	int z;
	int width;
	int height;
	int depth;
};

#endif