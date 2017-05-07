#pragma once
#include "file_working.h"
#include "Error.h"

struct my_point
{
	double x = 0;
	double y = 0;
	double z = 0;
};

void set_point(my_point& p, double x, double y, double z);

errors read_point(my_point& p, STREAM* file);
errors read_points(my_point* points_aray, int count_points, STREAM* file);