#include "shape.h"
#include <string>

using namespace std;

void Shape::move(int dx, int dy, int dz)
{
	x += dx;
	y += dy;
	z += dz;
}

ostream& operator<<(ostream& out, const Shape* shape)
{
	out << "type: " << shape->get_type() << ", " << "center: " << "(" << shape->x 
	    << ", " << shape->y <<", "<< shape->z << ")" << ", " << "volume: " << shape->volume();
	return out;
}
