using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace lab4
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

        public virtual void draw_circule(ref Bitmap bmt, Point Center, int R) { }

        protected void Add_pixel(ref Bitmap bmt, Point p, Color col)
        {
            if (((p.X >= 0) && (p.X < bmt.Width)) && ((p.Y >= 0) && (p.Y < bmt.Height)))
            {
                bmt.SetPixel(p.X, p.Y, col);
            }
        }

    }
}
