using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace lab4
{
    class Standart : Base
    {
        public override void draw_circule(ref Bitmap bmt, Point Center, int R)
        {
            Graphics g = Graphics.FromImage(bmt);
            Pen p = new Pen(draw_color, 1);

            g.DrawEllipse(p, new Rectangle(Center.X - R, Center.Y - R, 2 * R, 2 * R));
        }
    }
}
