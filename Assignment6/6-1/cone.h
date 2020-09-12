#include "shape.h"
#include <iostream>
#include <cmath>
#include <string>

class Cone : public Shape
{
public:
	Cone (int _x,int _y,int _z,int _radius,int _height);
	virtual void scale(int factor);
	virtual int volume() const;
	virtual std::string get_type() const;
private:
	int x;
	int y;
	int z;
	int radius;
	int height;
};