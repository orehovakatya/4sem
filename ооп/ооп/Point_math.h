#pragma once
#include "Point.h"
#define _USE_MATH_DEFINES // for C++  
#include <cmath> 

void Rotate_X(my_point &point, double Alpha, my_point centre);
void Rotate_Y(my_point &point, double Alpha, my_point centre);
void Rotate_Z(my_point &point, double Alpha, my_point centre);

void Move_OX(my_point &point, double Move);
void Move_OY(my_point &point, double Move);
void Move_OZ(my_point &point, double Move);

void Scale(my_point *point, double Scale, my_point centre);