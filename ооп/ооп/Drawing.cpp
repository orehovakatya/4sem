#include "Drawing.h"

void draw_line(My_drawing g, my_point start, my_point end)
{
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Black, 1.0f);
	g->DrawLine(pen, (float)start.x, (float)start.y, (float)end.x, (float)end.y);
}

void draw_edge(My_drawing g, my_edge e, points p)
{
	my_point start = point_by_index(p, e.from);
	my_point end = point_by_index(p, e.to);
	draw_line(g, start, end);
}


void clean_display(My_drawing g, Drawing_action& act)
{
	System::Drawing::SolidBrush^ br = gcnew System::Drawing::SolidBrush(col::White);
	g->FillRectangle(br, 0, 0, act.width, act.height);
}

errors draw_model(const model& mod, My_drawing g, Drawing_action& act)
{
	if ((get_points_count(mod.p) <= 0) || (get_edges_count(mod.e) <= 0))
		return ERROR_ZERO;
	clean_display(g, act);//!
	for (int i = 0; i < get_edges_count(mod.e); i++)
	{
		draw_edge(g, edges_by_index(mod.e, i), mod.p);
	}
}