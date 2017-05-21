#pragma once
#include "file_working.h"
#include "Error.h"

struct my_edge
{
	int from;
	int to;
};


void set_edge(my_edge& p, int from, int to);

errors read_edge(my_edge& p, STREAM* file);
errors read_edges(my_edge* adge_aray, int count_adge, STREAM* file);

