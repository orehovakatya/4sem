#pragma once
#include "file_working.h"
#include "Error.h"

struct my_edge
{
	int from;
	int to;
};


void set_adge(my_edge& p, int from, int to);

errors read_adge(my_edge& p, STREAM* file);
errors read_adges(my_edge* adge_aray, int count_adge, STREAM* file);

