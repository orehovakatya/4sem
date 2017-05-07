using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace lab3
{
    class Standart : Base //Наследование
    {
        public override void draw_line(ref Bitmap bmt, Point start, Point end)
        {
            Graphics g = Graphics.FromImage(bmt);
            Pen p = new Pen(draw_color, 1);

            g.DrawLine(p, start, end);
        }
    }
}
