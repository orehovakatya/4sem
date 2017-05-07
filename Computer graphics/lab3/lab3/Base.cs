using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace lab3
{
    class Base
    {
        protected Color draw_color;

        public Color set_color
        {
            set
            {
                draw_color = value;
            }
        }

        public virtual void draw_line(ref Bitmap bmt, Point start, Point end) { }

        protected void Add_pixel(ref Bitmap bmt, Point p, Color col)
        {
            if (((p.X >= 0)&&(p.X < bmt.Width))&& ((p.Y >= 0) && (p.Y < bmt.Height)))
            {
                bmt.SetPixel(p.X, p.Y, col);
            }
        }
        protected int round(double x)
        {
            return (int)Math.Round(x);
        }
        public void draw_spectr(ref Bitmap bmt, Point start, int R, float angle)
        {
            angle = (float)Math.PI * angle / 180;
            float t = 0;
            PointF end = new PointF(start.X + R, start.Y);

            //draw_line(ref bmt, start, new Point(round(end.X), round(end.Y)));
            while (t <= 2*Math.PI)
            {
                end.X = R * (float)Math.Cos(t) + start.X;
                end.Y = R * (float)Math.Sin(t) + start.Y;

                draw_line(ref bmt, start, new Point(round(end.X), round(end.Y)));

                t += angle;
            }
        }
    }
}
