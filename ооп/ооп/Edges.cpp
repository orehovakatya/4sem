#include "Edges.h"

void set_count_edge(edges& p, int cout_edges)
{
	p.count_edges = cout_edges;
}
void set_edge_array(edges& p, my_edge* edge_array)
{
	p.edge_array = edge_array;
}
void set_edges(edges& p, my_edge* edge_array, int cout_edges)
{
	set_count_edge(p, cout_edges);
	set_edge_array(p, edge_array);
}
errors load_edges(edges& p, int cout_edges, STREAM* file)
{
	errors er = ERROR_NO;
	my_edge* ptr = NULL;
	ptr = (my_edge*)alloc_memory(cout_edges, sizeof(my_edge));
	if (ptr == NULL)
		return ERROR_MEMORY;
	er = read_adges(ptr, cout_edges, file);
	if (er != ERROR_NO)
	{
		clear_memory(ptr);
		return er;
	}
	//p.edge_array = ptr;
	set_edges(p, ptr, cout_edges);
	return er;
}
void clear_edges(edges& p)
{
	clear_memory(p.edge_array);
	set_edges(p, NULL, 0);
}
edges init_edges()
{
	edges p;
	p.count_edges = 0;
	p.edge_array = NULL;
	return p;
}
int get_edges_count(const edges& e)
{
	return e.count_edges;
}
my_edge edges_by_index(const edges& e, int i)
{
	return e.edge_array[i];
}