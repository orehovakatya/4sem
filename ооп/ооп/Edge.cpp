#include "Edge.h"

void set_edge(my_edge& p, int from, int to)
{
	p.from = from;
	p.to = to;
}

errors read_edge(my_edge& p, STREAM* file)
{
	int from, to;
	if (read_edge(&from, &to, file) != 2)
		return ERROR_FILE;
	set_edge(p, from, to);
	return ERROR_NO;
}
errors read_edges(my_edge* edge_aray, int count_edge, STREAM* file)
{
	errors er = ERROR_NO;
	int i = 0;
	while ((er == ERROR_NO) && (i < count_edge))
	{
		er = read_edge(edge_aray[i], file);
		i++;
	}
	return er;
}