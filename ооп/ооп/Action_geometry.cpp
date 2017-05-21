#include "Action_geometry.h"

void calculate_point(my_point &point, my_point centre, action_values values)
{
	double value = 0;

	if ((value = get_action_value(moveOX, values)) != 0) {
		Move_OX(point, value);
	}

	else if ((value = get_action_value(moveOY, values)) != 0) {
		Move_OY(point, value);
	}
	else if ((value = get_action_value(moveOZ, values)) != 0) {
		Move_OZ(point, value);
	}

	else if ((value = get_action_value(angleOX, values)) != 0) {
		Rotate_X(point, value, centre);
	}

	else if ((value = get_action_value(angleOY, values)) != 0) {
		Rotate_Y(point, value, centre);
	}

	if ((value = get_action_value(angleOZ, values)) != 0) {
		Rotate_Z(point, value, centre);
	}

	if ((value = get_action_value(scale, values)) != 1) {
		Scale(&point, value, centre);
	}
}

void clean_action(action_values &values)
{
	set_action(values, angleOX, 0);
	set_action(values, angleOY, 0);
	set_action(values, angleOZ, 0);
	set_action(values, moveOX, 0);
	set_action(values, moveOY, 0);
	set_action(values, moveOZ, 0);
	set_action(values, scale, 1);
}

void set_action(action_values &values, actions action, double value)
{
	switch (action) {

	case moveOX:
		values.moveOX = value;
		break;

	case moveOY:
		values.moveOY = value;
		break;

	case moveOZ:
		values.moveOZ = value;
		break;

	case angleOX:
		values.angleOX = value;
		break;

	case angleOY:
		values.angleOY = value;
		break;

	case angleOZ:
		values.angleOZ = value;
		break;

	case scale:
		values.scale = value;
		break;

	default:
		break;
	}
}

double get_action_value(actions action, action_values values)
{
	switch (action) {
	case moveOX:
		return values.moveOX;

	case moveOY:
		return values.moveOY;

	case moveOZ:
		return values.moveOZ;

	case scale:
		return values.scale;

	case angleOX:
		return values.angleOX;

	case angleOY:
		return values.angleOY;

	case angleOZ:
		return values.angleOZ;

	default:
		return NULL;
	}
}

void calculate_centre(my_point &point, action_values values)
{
	double value = 0;

	if ((value = get_action_value(moveOX, values)) != 0) {
		Move_OX(point, value);
	}

	if ((value = get_action_value(moveOY, values)) != 0) {
		Move_OY(point, value);
	}
	if ((value = get_action_value(moveOZ, values)) != 0) {
		Move_OZ(point, value);
	}
}