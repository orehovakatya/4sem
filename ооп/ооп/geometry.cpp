#include "geometry.h"

double Max(const points &points, int coord)
{
	double max = point_by_name(point_by_index(points, 0), coord);

	for (int i = 1; i < get_points_count(points); ++i) {
		double temp = point_by_name(point_by_index(points, i), coord);
		if (max < temp) {
			max = temp;
		}
	}
	return max;
}

double Min(const points &points, int coord)
{
	double min = point_by_name(point_by_index(points, 0), coord);

	for (int i = 1; i < get_points_count(points); ++i) {
		double temp = point_by_name(point_by_index(points, i), coord);
		if (min > temp) {
			min = temp;
		}
	}
	return min;
}

my_point get_centre(const points &points)
{
	double X_max = Max(points, X_coord);
	double X_min = Min(points, X_coord);

	double Y_max = Max(points, Y_coord);
	double Y_min = Min(points, Y_coord);

	double Z_max = Max(points, Z_coord);
	double Z_min = Min(points, Z_coord);

	my_point buff_centre;
	set_point(buff_centre, (X_max + X_min) / 2, (Y_max + Y_min) / 2, (Z_max + Z_min) / 2);
	return buff_centre;
}

errors change_points(points &points, action_values values)
{
	if (get_points_count(points) == 0) {
		return ERROR_ZERO;
	}
	my_point centre = get_centre(points);
	calculate_centre(centre, values);
	calculate_all_points(points, centre, values);
	clean_action(values);

	return ERROR_NO;
}

void calculate_all_points(points &points, my_point centre, action_values values)
{
	for (int i = 0; i < get_points_count(points); i++) {
		my_point point = point_by_index(points, i);
		calculate_point(point, centre, values);

		set_point_by_index(points, point, i);
	}
}