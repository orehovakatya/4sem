#include "Action.h"

action_values modify_act(argument &arg)
{
	return arg.modify_act;
}

char *load_act(argument arg)
{
	return arg.load_act;
}

errors draw_prosessor(model &mod, My_drawing g)
{
	return draw_model(mod, g);
}

errors change_points_prosessor(model &mod, argument arg)
{
	return change_points(mod.p, modify_act(arg));
}

errors load_model_prosessor(model &mod, argument arg)
{
	return load_model(mod, load_act(arg));
}

errors clear_all_prosessor(model &mod)
{
	clear_model(mod);
	return ERROR_NO;
}