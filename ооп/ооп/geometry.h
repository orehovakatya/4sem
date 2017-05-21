#pragma once
#include "Action_geometry.h"
#include "Points.h"

double Max(const points &points, int coord);

double Min(const points &points, int coord);

my_point get_centre(const points &points);

errors change_points(points &points, action_values values);

void calculate_all_points(points &points, my_point centre, action_values values);

