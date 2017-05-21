#include "Point.h"

void set_point(my_point& p, double x, double y, double z)
{
	p.x = x;
	p.y = y;
	p.z = z;
}

errors read_point(my_point& p, STREAM* file)
{
	double x, y, z;
	if (read_point(&x, &y, &z, file) != 3)
		return ERROR_FILE;
	set_point(p, x, y, z);
	return ERROR_NO;
}
errors read_points(my_point* points_aray, int count_points, STREAM* file)
{
	errors er = ERROR_NO;
	for (int i = 0; er == ERROR_NO && i < count_points; i++)
	{
		er = read_point(points_aray[i], file);
	}
	return er;
}

void set_point_by_name(my_point &point, int i, double value)
{
	switch (i) {

	case X_coord:
		point.x = value;
		break;

	case Y_coord:
		point.y = value;
		break;

	case Z_coord:
		point.z = value;
		break;

	default:
		break;
	}
}

double point_by_name(const my_point point, int i) {
	switch (i) {

	case X_coord:
		return point.x;

	case Y_coord:
		return point.y;

	case Z_coord:
		return point.z;

	default:
		return 0;
	}
}