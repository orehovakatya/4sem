using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace lab3
{
    class CDA : Base
    {
        public override void draw_line(ref Bitmap bmt, Point start, Point end)
        {
            float dx = end.X - start.X,
                dy = end.Y - start.Y;
            float lx = Math.Abs(dx),
                ly = Math.Abs(dy);

            float l;
            if (lx > ly)
                l = lx;
            else
                l = ly;

            dx /= l;
            dy /= l;

            PointF calculated = new PointF(start.X, start.Y);
            for (int i = 1; i < l+1; i++)
            {
                Add_pixel(ref bmt, new Point(round(calculated.X), round(calculated.Y)), draw_color);
                calculated.X += dx;
                calculated.Y += dy;
            }
            Add_pixel(ref bmt, new Point(round(calculated.X), round(calculated.Y)), draw_color);
        }
    }
}
