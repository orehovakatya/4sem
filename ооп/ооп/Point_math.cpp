#include "Point_math.h"


void Rotate_X(my_point &point, double alpha, my_point centre)
{
	alpha *= M_PI / 180;
	my_point buff = point;
	set_point_by_name(point, X_coord, buff.x);
	set_point_by_name(point, Y_coord, centre.y + (buff.y - centre.y) * cos(alpha) + (buff.z - centre.z) * sin(alpha));
	set_point_by_name(point, Z_coord, centre.z + (buff.y - centre.y) * sin(-alpha) + (buff.z - centre.z) * cos(alpha));
}

void Rotate_Y(my_point &point, double alpha, my_point centre)
{
	alpha *= M_PI / 180;
	my_point buff = point;
	set_point_by_name(point, X_coord, centre.x + (buff.x - centre.x) * cos(alpha) + (buff.z - centre.z) * sin(alpha));
	set_point_by_name(point, Y_coord, buff.y);
	set_point_by_name(point, Z_coord, centre.z + (buff.x - centre.x) * sin(-alpha) + (buff.z - centre.z) * cos(alpha));
}

void Rotate_Z(my_point &point, double alpha, my_point centre)
{
	alpha *= M_PI / 180;
	my_point buff = point;
	set_point_by_name(point, X_coord, centre.x + (buff.x - centre.x) * cos(alpha) + (buff.y - centre.y) * sin(-alpha));
	set_point_by_name(point, Y_coord, centre.y + (buff.x - centre.x) * sin(alpha) + (buff.y - centre.y) * cos(alpha));
	set_point_by_name(point, Z_coord, centre.z + (buff.z - centre.z));
}

void Move_OX(my_point &point, double Move)
{
	double X = point_by_name(point, X_coord);
	X += Move;
	set_point_by_name(point, X_coord, X);
}
void Move_OY(my_point &point, double Move)
{
	double Y = point_by_name(point, Y_coord);
	Y += Move;
	set_point_by_name(point, Y_coord, Y);
}
void Move_OZ(my_point &point, double Move)
{
	double Z = point_by_name(point, Z_coord);
	Z += Move;
	set_point_by_name(point, Z_coord, Z);
}
void Scale(my_point *point, double Scale, my_point centre)
{
	set_point(*point, centre.x + (point->x - centre.x) * Scale,
		centre.y + (point->y - centre.y) * Scale,
		centre.z + (point->z - centre.z) * Scale);
}