using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace lab3
{
    class Brez_without_step : Base
    {
        private int I = 255;

        public override void draw_line(ref Bitmap bmt, Point start, Point end)
        {
            //Проверка вырожденности
            if ((start.X == end.X) && (start.Y == end.Y))
            {
                Add_pixel(ref bmt, start, draw_color);
                return;
            }

            //Вычисление приращений
            int dx = end.X - start.X;
            int dy = end.Y - start.Y;

            //Вычисление шага изменения каждой координаты пиксела
            int sx = sign(dx);
            int sy = sign(dy);

            //Вычисление модуля приращения кординат
            dx = Math.Abs(dx);
            dy = Math.Abs(dy);

            //Вычисление модуля тангенса угла наклона отрезка
            //float m = (dy / (float)dx) * I;
            float m = dy / (float)dx;
            int ob = 0;

            //Анализ m
            if (dy > dx)
            {
                int a = dx;
                dx = dy;
                dy = a;
                ob = 1;
                m = 1 / m;
            }
            else
                ob = 0;

            float f = I / 2.0f;//Инициализация начального значения ошибки
            m *= I;
            float w = I - m;

            //Инициализания координат текущего пиксела
            int x = start.X;
            int y = start.Y;

            Color color = Color.FromArgb((int)(f / I * 255), draw_color.R, draw_color.G, draw_color.B);
            Add_pixel(ref bmt, new Point(x, y), color);

            for (int i = 0; i < dx; i++)
            {
                if (f <= w)
                {
                    if (ob == 0)
                        x += sx;
                    else
                        y += sy;
                    f += m;
                }
                else
                {
                    x += sx;
                    y += sy;
                    f -= w;
                }

                double C = 1 - f / I;
                color = Color.FromArgb((int)(C * 255), draw_color.R, draw_color.G, draw_color.B);
                Add_pixel(ref bmt, new Point(x,y), color);
            }
        }
        private int sign(int x)
        {
            if (x > 0)
                return 1;
            if (x == 0)
                return 0;
            else
                return -1;
        }

    }
}
