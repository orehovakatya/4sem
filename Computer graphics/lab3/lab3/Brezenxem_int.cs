using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace lab3
{
    class Brezenxem_int : Base
    {
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
            float m = dy / (float)dx;
            int fl = 0;

            //Анализ m
            if (m > 1)
            {
                int w = dx;
                dx = dy;
                dy = w;
                m = 1 / m;
                fl = 1;
            }
            if (m < 0)
                fl = 0;

            int f = 2*dy - dx;//Инициализация начального значения ошибки

            //Инициализания координат текущего пиксела
            int x = start.X;
            int y = start.Y;

            for (int i = 0; i < dx + 1; i++)
            {
                Add_pixel(ref bmt, new Point(x, y), draw_color);
                if (f > 0)
                {
                    if (fl == 1)
                        x += sx;
                    else
                        y += sy;
                    f -= 2*dx;
                }
                if (f < 0)
                {
                    if (fl == 1)
                        y += sy;
                    else
                        x += sx;
                    
                }
                f += 2 * dy;
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
