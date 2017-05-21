#pragma once
#include <stdio.h>

#define STREAM FILE

STREAM* open_file(char*);
void close_file(STREAM*);
int read_edge(int* from, int* to, STREAM*);

/*int main()
{
	int a, b;
	scanf("%d %d", &a, &b)
}*/

int read_point(double* x, double* y, double* z, STREAM*);
int read_count(int* n_points, int* n_adges, STREAM*);