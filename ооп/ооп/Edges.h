#pragma once
#include "Adge.h"
#include "Memory.h"

struct edges
{
	int count_edges = 0;
	my_edge* edge_array = NULL;
};

void set_count_edge(edges& p, int cout_edges);
void set_edge_array(edges& p, my_edge* edge_array);
void set_edges(edges& p, my_edge* edge_array, int cout_edges);
errors load_edges(edges& p, int cout_points, STREAM* file);
void clear_edges(edges& p);
edges init_edges();
int get_edges_count(const edges& e);
my_edge edges_by_index(const edges& e, int i);