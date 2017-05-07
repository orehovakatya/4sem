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
	int i = 0;
	while ((er == ERROR_NO)&&(i < count_points))
	{
		er = read_point(points_aray[i], file);
		i++;
	}
	return er;
}