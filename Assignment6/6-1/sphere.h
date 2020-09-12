#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "shape.h"
#include <iostream>
#include <cmath>
#include <string>

class Sphere : public Shape
{
public:
	Sphere(int _x,int _y,int _z,int _radius);
	virtual void scale(int factor);
	virtual int volume() const;
	virtual std::string get_type () const;
private:
	int x;
	int y;
	int z;
	int radius;
};

#endif