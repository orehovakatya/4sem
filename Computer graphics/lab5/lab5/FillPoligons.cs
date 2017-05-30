using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Threading;

namespace lab5
{
    class FillPoligons
    {
        private Bitmap bitmap;
        private Color drawcolor;
        private Color foncolor;

        public void AddPoint(int x, int y, Color col)
        {
            bitmap.SetPixel(x, y, col);
        }

        public void DrawLine1(Point pointfrom, Point pointto, Color col)
        {
            int dx = (int)(Math.Abs(pointto.X - pointfrom.X));
            int dy = (int)(Math.Abs(pointto.Y - pointfrom.Y));
            int stepx = Math.Sign(pointto.X - pointfrom.X);
            int stepy = Math.Sign(pointto.Y - pointfrom.Y);

            int flag;
            if (dy > dx)
            {
                int tmp = dx;
                dx = dy;
                dy = tmp;
                flag = 1;
            }
            else
                flag = 0;
            int f1 = 2 * dy - dx;
            int x = pointfrom.X;
            int y = pointfrom.Y;
            int old_y = -1;
            for (int i = 0; i < dx; i++)
            {
                AddPoint(x, y, col);
                if (f1 >= 0)
                {
                    if (flag == 1)
                        x += stepx;
                    else
                        y += stepy;
                    f1 -= 2 * dx;
                }
                if (flag == 1)
                    y += stepy;
                else
                    x += stepx;
                f1 += 2 * dy;
            }
            AddPoint(x, y, col);
        }

        public void DrawLine(Point pointfrom, Point pointto, Color col)
        {
           int dx = (int)(Math.Abs(pointto.X - pointfrom.X));
           int dy = (int)(Math.Abs(pointto.Y - pointfrom.Y));
           int stepx = Math.Sign(pointto.X - pointfrom.X);
           int stepy = Math.Sign(pointto.Y - pointfrom.Y);

            int flag;
            if (dy > dx)
            {
                int tmp = dx;
                dx = dy;
                dy = tmp;
                flag = 1;
            }
            else
                flag = 0;
            int f1 = 2 * dy - dx;
            int x = pointfrom.X;
            int y = pointfrom.Y;
            int old_y = -1;
            for (int i = 0; i < dx; i++)
            {
                if (f1 >= 0)
                {
                    if (flag == 1)
                        x += stepx;
                    else
                        y += stepy;
                    f1 -= 2 * dx;
                }
                if (flag == 1)
                    y += stepy;
                else
                    x += stepx;
                f1 += 2 * dy;
                if (old_y != y)
                    AddPoint(x, y, col);
                old_y = y;
            }
        }

        public void FillLine(Point pointfrom)
        {
            Color col = bitmap.GetPixel(pointfrom.X, pointfrom.Y);
            Color draw = drawcolor;
            if (col.Name == "0")
            {
                bitmap.SetPixel(pointfrom.X, pointfrom.Y, drawcolor);
                pointfrom.X = pointfrom.X + 1;
            }
            else if (col.ToArgb() == foncolor.ToArgb())
            {
                bitmap.SetPixel(pointfrom.X, pointfrom.Y, drawcolor);
                pointfrom.X = pointfrom.X + 1;
            }
            else if (col.ToArgb() == drawcolor.ToArgb())
            {
                bitmap.SetPixel(pointfrom.X, pointfrom.Y, foncolor);
                pointfrom.X = pointfrom.X + 1;
            }
            for (int i = pointfrom.X; i < bitmap.Size.Width; i++)
            {
                col = bitmap.GetPixel(i, pointfrom.Y);
                if (col.Name == "0")
                    bitmap.SetPixel(i, pointfrom.Y, drawcolor);
                else if (col.ToArgb() == foncolor.ToArgb())
                    bitmap.SetPixel(i, pointfrom.Y, drawcolor);
                else if (col.ToArgb() == drawcolor.ToArgb())
                    bitmap.SetPixel(i, pointfrom.Y, foncolor);
            }
        }

        public void FillSide(Point pointfrom, Point pointto, ref System.Windows.Forms.PictureBox pb, int time)
        {
            int dx = (int)(Math.Abs(pointto.X - pointfrom.X));
            int dy = (int)(Math.Abs(pointto.Y - pointfrom.Y));
            int stepx = Math.Sign(pointto.X - pointfrom.X);
            int stepy = Math.Sign(pointto.Y - pointfrom.Y);

            int flag;
            if (dy > dx)
            {
                int tmp = dx;
                dx = dy;
                dy = tmp;
                flag = 1;
            }
            else
                flag = 0;
            int f1 = 2 * dy - dx;
            int x = pointfrom.X;
            int y = pointfrom.Y;
            int old_y = y;
            for (int i = 0; i < dx; i++)
            {
                if (f1 >= 0)
                {
                    if (flag == 1)
                        x += stepx;
                    else
                        y += stepy;
                    f1 -= 2 * dx;
                }
                if (flag == 1)
                    y += stepy;
                else
                    x += stepx;
                f1 += 2 * dy;

                if (old_y != y)
                {
                    FillLine(new Point(x, y));
                    if (time != 0)
                    {
                        pb.CancelAsync();
                        pb.Refresh();
                        System.Threading.Thread.Sleep(time);
                    }
                }
                old_y = y;
            }
            if (old_y != y)
            {
                FillLine(new Point(x, y));
                if (time != 0)
                {
                    pb.CancelAsync();
                    pb.Refresh();
                    System.Threading.Thread.Sleep(time);
                }
            }
        }

        public FillPoligons(Size bit_size, Color color, Color col)
        {
            bitmap = new Bitmap(bit_size.Width, bit_size.Height);
            drawcolor = color;
            foncolor = col;
        }

        public Bitmap DrawPoligons(List<List<Point>> Polygons, Color col, Size bit_size)
        {
            bitmap = new Bitmap(bit_size.Width, bit_size.Height);
            for (int i = 0; i < Polygons.Count-1; i++)
            {
                for (int j = 0; j < Polygons[i].Count-1; j++)
                {
                    DrawLine1(Polygons[i][j], Polygons[i][j+1],col);
                }
                DrawLine1(Polygons[i][0], Polygons[i][Polygons[i].Count-1], col);
            }
            return bitmap;
        }

        public void FillPoligon(ref System.Windows.Forms.PictureBox pb, List<List<Point>> Polygons, int delay)
        {
            pb.Image = bitmap;
            for (int i =0; i < Polygons.Count-1; i++)
            {
                for (int j = 0; j < Polygons[i].Count-1; j++)
                {
                    if (Polygons[i][j].Y <= Polygons[i][j+1].Y)
                        FillSide(Polygons[i][j], Polygons[i][j + 1], ref pb,delay);
                    else
                        FillSide(Polygons[i][j+1], Polygons[i][j], ref pb, delay);
                }
                if (Polygons[i][0].Y <= Polygons[i][Polygons[i].Count-1].Y)
                    FillSide(Polygons[i][0], Polygons[i][Polygons[i].Count -1], ref pb, delay);
                else
                    FillSide(Polygons[i][Polygons[i].Count - 1], Polygons[i][0], ref pb,delay);
            }
            pb.Image = bitmap;
        }
    }
}
