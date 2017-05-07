#pragma once
#include "Model.h"

typedef System::Drawing::Graphics^ My_drawing;
typedef System::Drawing::Color col;

struct  Drawing_action
{
	int width;
	int height;
};
void draw_line(My_drawing g, my_point start, my_point end);
void draw_edge(My_drawing g, my_edge e, points p);
void clean_display(My_drawing g, Drawing_action& act);

errors draw_model(const model& mod, My_drawing g, Drawing_action& act);



