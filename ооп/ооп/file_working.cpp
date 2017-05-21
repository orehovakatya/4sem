#include "file_working.h"

STREAM* open_file(char* str)
{
	return fopen(str, "r");
}

void close_file(STREAM* file)
{
	fclose(file);
}

int read_edge(int* from, int* to, STREAM* file)
{
	return fscanf(file, "%d-%d\n", from, to);
}

int read_point(double* x, double* y, double* z, STREAM* file)
{
	return fscanf(file, "{%lf;%lf;%lf}\n", x, y, z) == 3;//!!!!!!
}

int read_count(int* n_points, int* n_adges, STREAM* file)
{
	return fscanf(file, "%d %d\n", n_points, n_adges);
}