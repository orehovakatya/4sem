#include "Model.h"

void set_model_points(model& mod, points p)
{
	mod.p = p;
}
void set_model_edges(model& mod, edges e)
{
	mod.e = e;
}
void set_model(model& mod, points p, edges e)
{
	set_model_edges(mod, e);
	set_model_points(mod, p);
}
void clear_model(model& mod)
{
	clear_points(mod.p);
	clear_edges(mod.e);
}
model init_model()
{
	model mod;
	mod.e = init_edges();
	mod.p = init_points();
	return mod;
}
errors load_model(model& mod, char* file_name)
{
	STREAM* file = open_file(file_name);
	if (!file)
		return ERROR_FILE;
	model tmp;
	errors er = ERROR_NO;
	er = load_model_stream(tmp, file);
	fclose(file);
	if (er != ERROR_NO)
		return er;
	clear_model(mod);
	mod = tmp;
	return er;
}
errors load_model_stream(model& mod, STREAM* file)
{
	errors er = ERROR_NO;
	points p;
	edges e;
	int count_points;
	int count_edges;
	if ((er = get_counts(count_points, count_edges, file)) != ERROR_NO)
		return er;
	if ((er = load_points(p, count_points, file)) != ERROR_NO)
		return er;
	if ((er = load_edges(e, count_edges, file)) != ERROR_NO)
	{
		clear_points(p);
		return er;
	}
	set_model(mod, p, e);
	return er;
}
errors get_counts(int& points_count, int& point_edges, STREAM* file)
{
	if (read_count(&points_count, &point_edges, file) != 2)
		return ERROR_FILE;
	return ERROR_NO;
}