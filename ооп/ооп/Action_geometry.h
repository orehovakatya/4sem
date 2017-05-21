#pragma once
#include "Point_math.h"

typedef struct {
	double moveOX;
	double moveOY;
	double moveOZ;
	double scale;
	double angleOX;
	double angleOY;
	double angleOZ;
} action_values;

enum actions {
	moveOX, moveOY, moveOZ, scale, angleOX, angleOY, angleOZ
};

void calculate_point(my_point &point, my_point centre, action_values values);

void clean_action(action_values &values);

void set_action(action_values &values, actions action, double value);

double get_action_value(actions action, action_values values);

void calculate_centre(my_point &point, action_values values);

