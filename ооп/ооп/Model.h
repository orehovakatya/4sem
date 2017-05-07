#pragma once
#include "Points.h"
#include "Edges.h"
#include "file_working.h"

struct model
{
	points p;
	edges e;
	//center
};

void set_model_points(model& mod, points p);
void set_model_edges(model& mod, edges e);
void set_model(model& mod, points p, edges e);
void clear_model(model& mod);
model init_model();
errors load_model(model& mod, char* file_name);
errors load_model_stream(model& mod, STREAM* file);
errors get_counts(int& points_count, int& point_edges, STREAM* file);