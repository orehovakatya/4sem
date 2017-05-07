#include "Adge.h"

void set_adge(my_edge& p, int from, int to)
{
	p.from = from;
	p.to = to;
}

errors read_adge(my_edge& p, STREAM* file)
{
	int from, to;
	if (read_adge(&from, &to, file) != 2)
		return ERROR_FILE;
	set_adge(p, from, to);
	return ERROR_NO;
}
errors read_adges(my_edge* adge_aray, int count_adge, STREAM* file)
{
	errors er = ERROR_NO;
	int i = 0;
	while ((er == ERROR_NO) && (i < count_adge))
	{
		er = read_adge(adge_aray[i], file);
		i++;
	}
	return er;
}