#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <iostream>
#include <string>

class IllegalArgumentException {};

class Shape
{
public:
	Shape(int _x, int _y, int _z): z(_z), x(_x), y(_y) {}
	void move(int dx, int dy, int dz);
	/*int get_x() const { return x; }
    int get_y() const { return y; }
    int get_z() const { return z; }*/
	virtual void scale(int factor) = 0;
	virtual int volume() const = 0;
	virtual std::string get_type () const = 0;
	friend std::ostream& operator<<(std::ostream& out, const Shape* shape);
protected:
	int x;
	int y;
	int z;
};

#endif

