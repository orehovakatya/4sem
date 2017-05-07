using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace lab2
{
    class Picture
    {
        List<PointF> Rect, Astr, Hatch;
        //List<List<PointF>> Hatch;

        public Picture()
        {

            //Hatch = new List<List<PointF>>();
            Hatch = new List<PointF>();
            Rect = new List<PointF>();
            Astr = new List<PointF>();
        }

        /*int katya;
        public int ages
        {
            get
            {
                return katya;
            }
            set
            {
                katya = value;
            }
        }*/

        public Picture(float b, PointF Center, SizeF size)
        {
            if ((size.Height == 0) || (size.Width == 0))
            {
                MessageBox.Show("Невозможно отобразить рисунок");
                return;
            }

            Rect = new List<PointF>();
            Astr = new List<PointF>();
            Hatch = new List<PointF>();
            //Hatch = new List<List<PointF>>();

            Rect.Add(new PointF(Center.X + size.Width, Center.Y));
            Rect.Add(new PointF(Center.X, Center.Y + size.Height));
            Rect.Add(new PointF(Center.X - size.Width, Center.Y));
            Rect.Add(new PointF(Center.X, Center.Y - size.Height));


            float t = 0f;
            float step = 1/size.Height;
            while (t < 2 * Math.PI)
            {
                Astr.Add(new PointF(b * (float)(Math.Pow(Math.Sin(t), 3)) + Center.X, b * (float)(Math.Pow(Math.Cos(t), 3)) + Center.Y));
                t += step;
            }

            step = 2 * size.Width / 50;
            t = Center.Y - size.Height + step;
            float x1_rec, x2_rec, x1_astr, x2_astr;
            while (t < Center.Y + size.Height)
            {
                if (t > Center.Y)
                {
                    x1_astr = b * (float)(Math.Pow(Math.Sin(Math.Acos(Math.Pow((t-Center.Y)/ b, 1.0 / 3))), 3))+Center.X;
                    x1_rec = (t- Center.Y - size.Height) / (-size.Height / size.Width)+Center.X;

                    x2_astr = Center.X-(x1_astr-Center.X);
                    x2_rec = (t - Center.Y- size.Height) / (-size.Height / -size.Width)+Center.X;

                    Hatch.Add(new PointF(x1_astr, t));
                    Hatch.Add(new PointF(x1_rec, t));

                    Hatch.Add(new PointF(x2_astr, t));
                    Hatch.Add(new PointF(x2_rec, t));
                }
                if (t < Center.Y)
                {
                    x1_astr = b * (float)(Math.Pow(Math.Sin(Math.Acos(Math.Pow((Center.Y - t) / b, 1.0 / 3))), 3)) + Center.X;
                    x1_rec = (t - Center.Y + size.Height) / (size.Height / size.Width)+Center.X;

                    x2_astr = Center.X - (x1_astr - Center.X);
                    x2_rec = (t - Center.Y + size.Height) / (size.Height / -size.Width)+Center.X;

                    Hatch.Add(new PointF(x1_astr, t));
                    Hatch.Add(new PointF(x1_rec, t));

                    Hatch.Add(new PointF(x2_astr, t));
                    Hatch.Add(new PointF(x2_rec, t));
                }
                t += step;
            }
        }

        public Bitmap Draw_Picture(Size screen_size)
        {
            Bitmap bmt = new Bitmap(screen_size.Width, screen_size.Height);

            Graphics g = Graphics.FromImage(bmt);

            Pen p = new Pen(Color.Black, 1);
            Pen q = new Pen(Color.Red, 2);

            //SolidBrush drawBrush = new SolidBrush(Color.Green);
            Font drawFont = new Font("Arial", 9);


            string st1, st2;
            for (int i = 0; i < Rect.Count() - 1; i++)
            {
                g.DrawLine(p, Rect[i], Rect[i + 1]);
                st1 = String.Format("{0:F0}",Rect[i].X);
                st2 = String.Format("{0:F0}", Rect[i].Y);
                g.DrawString(st1 + ";" + st2, drawFont, Brushes.DarkBlue, Rect[i]);
            }
            g.DrawLine(p, Rect[0], Rect[Rect.Count() - 1]);
            st1 = String.Format("{0:F0}", Rect[Rect.Count()-1].X);
            st2 = String.Format("{0:F0}", Rect[Rect.Count()-1].Y);
            g.DrawString(st1 + ";" + st2, drawFont, Brushes.DarkBlue, Rect[Rect.Count()-1]);

            for (int i = 0; i < Astr.Count() - 1; i++)
            {
                g.DrawLine(p, Astr[i], Astr[i + 1]);
            }
            g.DrawLine(p, Astr[0], Astr[Astr.Count() - 1]);

            for (int i = 0; i < Hatch.Count(); i += 2)
            {
                g.DrawLine(p, Hatch[i], Hatch[i+1]);
            }

            return bmt;
        }

        //Перенос
        public Picture Replase(PointF delta)
        {
            Picture new_object = new Picture();

            for (int i = 0; i < Rect.Count(); i++)
            {
                new_object.Rect.Add(new PointF(Rect[i].X + delta.X, Rect[i].Y + delta.Y));
            }

            for (int i = 0; i < Astr.Count(); i++)
            {
                new_object.Astr.Add(new PointF(Astr[i].X + delta.X, Astr[i].Y + delta.Y));
            }

            for (int i = 0; i < Hatch.Count(); i++)
            {
                new_object.Hatch.Add(new PointF(Hatch[i].X + delta.X, Hatch[i].Y + delta.Y));
            }
            return new_object;
        }

        //Масштабирование
        public Picture Change_Scale(float x, float y, float scale)
        {
            Picture new_object = new Picture();
            if (scale == 0)
            {
                new_object.Rect = Rect;
                new_object.Astr = Astr;
                new_object.Hatch = Hatch;
                MessageBox.Show("Масштаб задан неверно.");
                return new_object;
            }
            /*if (((Rect[0].X - Rect[1].X) *scale) < 0.5)
            {
                new_object.Rect = Rect;
                new_object.Astr = Astr;
                new_object.Hatch = Hatch;
                MessageBox.Show("Неверно задан масштаб, изображение превращается в точку.");
                return new_object;
            }*/
            for (int i = 0; i < Rect.Count(); i++)
                new_object.Rect.Add(new PointF(Rect[i].X - x, Rect[i].Y - y));
            for (int i = 0; i < Astr.Count(); i++)
                new_object.Astr.Add(new PointF(Astr[i].X - x, Astr[i].Y - y));
            for (int i = 0; i < Hatch.Count(); i++)
                new_object.Hatch.Add(new PointF(Hatch[i].X - x, Hatch[i].Y - y));

            for (int i = 0; i < Rect.Count(); i++)
                new_object.Rect[i] = new PointF(new_object.Rect[i].X*scale, new_object.Rect[i].Y*scale);
            for (int i = 0; i < Astr.Count(); i++)
                new_object.Astr[i] = new PointF(new_object.Astr[i].X*scale, new_object.Astr[i].Y*scale);
            for (int i = 0; i < Hatch.Count(); i++)
                new_object.Hatch[i] = new PointF(new_object.Hatch[i].X*scale, new_object.Hatch[i].Y*scale);

            for (int i = 0; i < Rect.Count(); i++)
                new_object.Rect[i] = new PointF(new_object.Rect[i].X + x, new_object.Rect[i].Y + y);
            for (int i = 0; i < Astr.Count(); i++)
                new_object.Astr[i] = new PointF(new_object.Astr[i].X + x, new_object.Astr[i].Y + y);
            for (int i = 0; i < Hatch.Count(); i++)
                new_object.Hatch[i] = new PointF(new_object.Hatch[i].X + x, new_object.Hatch[i].Y + y);

            return new_object;
        }

        //Поворот
        public Picture Rotate(PointF Center, float angle)
        {
            Picture new_object = new Picture();

            //Преобразование к новой СК
            for (int i = 0; i < Rect.Count(); i++)
                new_object.Rect.Add(new PointF(Rect[i].X-Center.X, Rect[i].Y-Center.Y));
            for (int i = 0; i < Astr.Count(); i++)
                new_object.Astr.Add(new PointF(Astr[i].X-Center.X, Astr[i].Y-Center.Y));
            for (int i = 0; i < Hatch.Count(); i++)
                new_object.Hatch.Add(new PointF(Hatch[i].X-Center.X, Hatch[i].Y-Center.Y));

            //Поворот в новой СК
            for (int i = 0; i < Rect.Count(); i++)
                new_object.Rect[i] = new PointF(
                    new_object.Rect[i].X*(float)Math.Cos(angle) + new_object.Rect[i].Y *(float)Math.Sin(angle),
                    -new_object.Rect[i].X *(float)Math.Sin(angle) + new_object.Rect[i].Y *(float)Math.Cos(angle));
            for (int i = 0; i < Astr.Count(); i++)
                new_object.Astr[i] = new PointF(
                    new_object.Astr[i].X * (float)Math.Cos(angle) + new_object.Astr[i].Y * (float)Math.Sin(angle),
                    -new_object.Astr[i].X * (float)Math.Sin(angle) + new_object.Astr[i].Y * (float)Math.Cos(angle));
            for (int i = 0; i < Hatch.Count(); i++)
                new_object.Hatch[i] = new PointF(
                    new_object.Hatch[i].X * (float)Math.Cos(angle) + new_object.Hatch[i].Y * (float)Math.Sin(angle),
                    -new_object.Hatch[i].X * (float)Math.Sin(angle) + new_object.Hatch[i].Y * (float)Math.Cos(angle));

            //Возвращение к старой СК
            for (int i = 0; i < Rect.Count(); i++)
                new_object.Rect[i] = new PointF(new_object.Rect[i].X + Center.X, new_object.Rect[i].Y + Center.Y);
            for (int i = 0; i < Astr.Count(); i++)
                new_object.Astr[i] = new PointF(new_object.Astr[i].X + Center.X, new_object.Astr[i].Y + Center.Y);
            for (int i = 0; i < Hatch.Count(); i++)
                new_object.Hatch[i] = new PointF(new_object.Hatch[i].X + Center.X, new_object.Hatch[i].Y + Center.Y);

            return new_object;
        }
    }
}