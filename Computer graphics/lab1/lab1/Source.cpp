#include "Header.h"
#include<math.h>
#include<algorithm>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void draw_with_per(PointF M, PointF Q, Graphics^ g, float left_x, float left_y, 
	float right_x, float right_y, float kx, float ky)
{
	//MessageBox::Show();
	PointF A;
	PointF B;
	Pen^ pen1 = gcnew Pen(Color::Blue, 1);
	if (Q.X == M.X)
	{
		//MessageBox::Show("Я тут");
		A.X = M.X;
		A.Y = left_y;

		B.X = M.X;
		B.Y = right_y;
	}
	else
	{
		A.X = left_x;
		A.Y = (M.Y*left_x - left_x*Q.Y - Q.X*M.Y + M.X*Q.Y) / (float)(M.X - Q.X);

		B.X = right_x;
		B.Y = (M.Y*right_x - right_x*Q.Y - Q.X*M.Y + M.X*Q.Y) / (float)(M.X - Q.X);
	}
	/*MessageBox::Show(Convert::ToString(A));
	MessageBox::Show(Convert::ToString(B));*/
	A.X = (A.X - left_x)*kx;
	A.Y = 550 - (A.Y - left_y)*ky;

	B.X = (B.X - left_x)*kx;
	B.Y = 550 - (B.Y - left_y)*ky;

	g->DrawLine(pen1, A, B);

}

void draw_median(PointF A, PointF B, PointF C,
	Graphics^ g, float left_x, float left_y, float right_x, float right_y,
	float kx, float ky)
{
	Pen^ penn = gcnew Pen(Color::Red, 1);
	PointF M;
	PointF M_draw;

	M.X = (A.X + C.X) / 2;
	M.Y = (A.Y + C.Y) / 2;

	M_draw.X = (M.X - left_x)*kx;
	M_draw.Y = 550 - (M.Y - left_y)*ky;

	B.X = (B.X - left_x)*kx;
	B.Y = 550 - (B.Y - left_y)*ky;

	g->DrawLine(penn, M_draw, B);
}

void vector_copy(std::vector<PointF*> A, std::vector<PointF*> &B)
{
	PointF point;
	for (int i = 0; i < A.size(); i++)
	{
		B.push_back(new PointF(A[i]->X,A[i]->Y));
	}
}

PointF found_center(std::vector<PointF*> Rectangle1)
{
	PointF center;
	if (Rectangle1[0]->X == Rectangle1[3]->X)
	{
		center.X = (Rectangle1[2]->X + Rectangle1[3]->X) / 2;
		center.Y = (Rectangle1[0]->Y + Rectangle1[3]->Y) / 2;
		return center;
	}

	if (Rectangle1[2]->X == Rectangle1[3]->X)
	{
		center.X = (Rectangle1[0]->X + Rectangle1[3]->X) / 2;
		center.Y = (Rectangle1[2]->Y + Rectangle1[3]->Y) / 2;
	}
	return center;
}

void found_bourder(std::vector<PointF*> Rectangle1, std::vector<PointF*> Points, float *left_x,
	float *left_y, float *right_x, float *right_y)
{
	*left_x = Rectangle1[0]->X;
	*left_y = Rectangle1[0]->Y;
	*right_x = Rectangle1[0]->X;
	*right_y = Rectangle1[0]->Y;

	for (int i = 0; i < Rectangle1.size(); i++)
	{
		if (Rectangle1[i]->X < *left_x)
			*left_x = Rectangle1[i]->X;
		if (Rectangle1[i]->X > *right_x)
			*right_x = Rectangle1[i]->X;
		if (Rectangle1[i]->Y < *left_y)
			*left_y = Rectangle1[i]->Y;
		if (Rectangle1[i]->Y > *right_y)
			*right_y = Rectangle1[i]->Y;
	}
	for (int i = 0; i < Points.size(); i++)
	{
		if (Points[i]->X < *left_x)
			*left_x = Points[i]->X;
		if (Points[i]->X > *right_x)
			*right_x = Points[i]->X;
		if (Points[i]->Y < *left_y)
			*left_y = Points[i]->Y;
		if (Points[i]->Y > *right_y)
			*right_y = Points[i]->Y;
	}
}

int do_triangle(PointF* A, PointF* B, PointF* C)
{
	if ((C->X - A->X)*(B->Y - A->Y) == (B->X - A->X)*(C->Y - A->Y))
		return 0;
	return 1;
}

int found_triangle(std::vector<PointF*> Points, std::vector<std::vector<int>> *Triangle)
{
	//MessageBox::Show("Points.size " + Convert::ToString(Points.size()));
	for (int i = 0; i < Points.size(); i++)
		for (int j = i+1; j < Points.size(); j++)
			for (int k = j + 1; k < Points.size(); k++)
			{
				if (do_triangle(Points[i],Points[j],Points[k]) == 1)
				{
					(*Triangle).push_back({i,j,k});
				}
			}
	return (*Triangle).size();
}

void min_arc(std::vector<std::vector<int>> Triangle, std::vector<PointF*> Points,
	 PointF Center, Graphics^ g, float left_x, float left_y, float right_x, float right_y,
	 float kx, float ky, bool flag, Graphics^ otv)
{
	System::Drawing::Font^ ft = gcnew System::Drawing::Font("Verdana", 10);
	std::vector<float> Arc;
	std::vector<PointF*> Points_draw;
	PointF M;
	PointF Q;
	for (int i = 0; i < Triangle.size(); i++)
	{
		M.X = (Points[Triangle[i][0]]->X + Points[Triangle[i][2]]->X) / 2.0;
		M.Y = (Points[Triangle[i][0]]->Y + Points[Triangle[i][2]]->Y) / 2.0;

		Q.X = (2.0 / 3.0 * M.X + 1.0 / 3.0 * Points[Triangle[i][1]]->X);
		Q.Y = (2.0 / 3.0 * M.Y + 1.0 / 3.0 * Points[Triangle[i][1]]->Y);

		if (Q.X == Center.X)
			Arc.push_back(0.0);
		else
			Arc.push_back(abs(Q.Y / (sqrt(pow(Q.X, 2) + pow(Q.Y, 2)))));

		/*PointF A;
		A.X = Q.X - Center.X;
		A.Y = Q.Y - Center.Y;
		if ((A.X == 0)&&(A.Y == 0))
			Arc.push_back(0.0);
		else
			Arc.push_back(abs(A.Y / (sqrt(pow(A.X, 2) + pow(A.Y, 2)))));*/
		//Arc.push_back(abs(Q.Y/(sqrt(pow(Q.X,2)+pow(Q.Y,2)))));
	}
	int index = 0;
	for (int i = 0; i < Arc.size()-1; i++)
	{
		if (Arc[index] > Arc[i])
		{
			index = i;
		}
	}
	otv->DrawString("Косинус угла наклона к ОУ = " + Convert::ToString(Arc[index]), ft,
		System::Drawing::Brushes::Black, 1.0, 1.0);
	vector_copy(Points,Points_draw);
	otv->DrawString("Треугольник образован точками: \n" + 
		Convert::ToString(*(Points[Triangle[index][0]])) + " " +
		Convert::ToString(*(Points[Triangle[index][1]])) + " " +
		Convert::ToString(*(Points[Triangle[index][2]])),ft,
		System::Drawing::Brushes::Black, 1.0, 15.0);
	vector_copy(Points, Points_draw);

	for (int i = 0; i < Points_draw.size(); i++)
	{
		Points_draw[i]->X = (Points_draw[i]->X - left_x)*kx;
		Points_draw[i]->Y = 550 - (Points_draw[i]->Y - left_y)*ky;
	}

	M.X = (Points[Triangle[index][0]]->X + Points[Triangle[index][2]]->X) / 2.0;
	M.Y = (Points[Triangle[index][0]]->Y + Points[Triangle[index][2]]->Y) / 2.0;

	Q.X = (2.0 / 3.0 * M.X + 1.0 / 3.0 * ((Points[Triangle[index][1]])->X));
	Q.Y = (2.0 / 3.0 * M.Y + 1.0 / 3.0 * ((Points[Triangle[index][1]])->Y));
	/*MessageBox::Show("MMM = " + Convert::ToString(M));
	MessageBox::Show("QQQ = " + Convert::ToString(Q));*/

	PointF M_draw;
	PointF Q_draw;

	Q_draw.X = (Q.X - left_x)*kx;
	Q_draw.Y = 550 - (Q.Y - left_y)*ky;

	//рисование
	Pen^ pen1 = gcnew Pen(Color::Black, 1);
	Pen^ pen2 = gcnew Pen(Color::SpringGreen, 1);

	

	if (flag)
		g->DrawString(Convert::ToString(Q.X) + ";" +
			Convert::ToString(Q.Y), ft, System::Drawing::Brushes::Blue,
			Q_draw.X, Q_draw.Y);

	g->DrawLine(pen1, *(Points_draw[Triangle[index][0]]), *(Points_draw[Triangle[index][1]]));
	g->DrawLine(pen1, *(Points_draw[Triangle[index][1]]), *(Points_draw[Triangle[index][2]]));
	g->DrawLine(pen1, *(Points_draw[Triangle[index][2]]), *(Points_draw[Triangle[index][0]]));

	//MessageBox::Show("Q = "+Convert::ToString(Q));
	draw_with_per(Q, Center, g, left_x, left_y, right_x, right_y, kx, ky);

	draw_median(*(Points[Triangle[index][0]]), *(Points[Triangle[index][1]]),
		*(Points[Triangle[index][2]]), g, left_x, left_y, right_x, right_y, kx, ky);

	draw_median(*(Points[Triangle[index][1]]), *(Points[Triangle[index][2]]),
		*(Points[Triangle[index][0]]), g, left_x, left_y, right_x, right_y, kx, ky);

	draw_median(*(Points[Triangle[index][2]]), *(Points[Triangle[index][0]]),
		*(Points[Triangle[index][1]]), g, left_x, left_y, right_x, right_y, kx, ky);	
}