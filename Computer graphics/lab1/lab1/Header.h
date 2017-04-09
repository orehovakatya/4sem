#pragma once
using namespace System::Drawing;
#include <vector>

PointF found_center(std::vector<PointF*> Rectangle1);//Нахождние центра прямоугольника
void found_bourder(std::vector<PointF*> Rectangle1, std::vector<PointF*> Points, float *left_x,
float *left_y, float *right_x, float *right_y);//Нахождение координа границ для 
int found_triangle(std::vector<PointF*> Points, std::vector<std::vector<int>> *Triangle);
int do_triangle(PointF* A, PointF* B, PointF* C);
void min_arc(std::vector<std::vector<int>> Triangle, std::vector<PointF*> Points,
	PointF Center, Graphics^ g, float left_x, float left_y, float right_x, float right_y,
	float kx, float ky, bool flag, Graphics^ otv);
void vector_copy(std::vector<PointF*> A, std::vector<PointF*> &B);
void draw_median(PointF A, PointF B, PointF C,
	Graphics^ g, float left_x, float left_y, float right_x, float right_y,
	float kx, float ky);
void draw_with_per(PointF M, PointF Q, Graphics^ g, float left_x, float left_y,
	float right_x, float right_y, float kx, float ky);