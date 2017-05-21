#include "Points.h"

void set_points_count(points& p, int cout_points)
{
	p.count_points = cout_points;
}
void set_points_array(points& p, my_point* points_array)
{
	p.points_array = points_array;
}
void set_points(points& p, my_point* points_array, int cout_points)
{
	set_points_count(p, cout_points);
	set_points_array(p, points_array);
}
errors load_points(points& p, int cout_points, STREAM* file)
{
	my_point* ptr = NULL;
	ptr = (my_point*)alloc_memory(cout_points, sizeof(my_point));
	if (ptr == NULL)
		return ERROR_MEMORY;
	errors er = ERROR_NO;
	er = read_points(ptr, cout_points, file);
	if (er != ERROR_NO)
	{
		clear_memory(ptr);
		return er;
	}
	set_points(p, ptr, cout_points);
	return er;
}
void clear_points(points& p)
{
	clear_memory(p.points_array);
	set_points(p, NULL, 0);
}
points init_points()
{
	points p;
	p.count_points = 0;
	p.points_array = NULL;
	return p;
}
int get_points_count(const points& p)
{
	return p.count_points;
}
my_point point_by_index(const points& p, int i)
{
	return p.points_array[i];
}
void set_point_by_index(points &points, const my_point &point, int index)
{
	points.points_array[index].x = point.x;
	points.points_array[index].y = point.y;
	points.points_array[index].z = point.z;
}