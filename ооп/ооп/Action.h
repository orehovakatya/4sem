#pragma once
#include "Model.h"
#include "geometry.h"
#include "drawing.h"

enum action {
	LOAD,
	CHANGE,
	DRAW,
	CLEAR
};

typedef union {
	char *load_act;
	action_values modify_act;
} argument;

action_values modify_act(argument &arg);

char *load_act(argument arg);

errors draw_prosessor(model &mod, My_drawing g);

errors change_points_prosessor(model &mod, argument arg);

errors load_model_prosessor(model &mod, argument arg);

errors clear_all_prosessor(model &mod);
