#pragma once
#include "Point.h"
#include "Memory.h"

struct points
{
	int count_points = 0;
	my_point* points_array = NULL;
};

void set_points_count(points& p, int cout_points);
void set_points_array(points& p, my_point* points_array);
void set_points(points& p, my_point* points_array, int cout_points);
errors load_points(points& p, int cout_points, STREAM* file);
void clear_points(points& p);
points init_points();
int get_points_count(const points& p);
my_point point_by_index(const points& p, int i);
void set_point_by_index(points &points, const my_point &point, int index);