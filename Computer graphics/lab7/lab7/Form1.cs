using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab7
{
    public partial class Form1 : Form
    {
        Bitmap bmap;
        Graphics g;
        List<Point> polygon;
        List<List<Point>> lines;
        
        int f = 0;
        Pen polygon_pen = new Pen(Color.Black, 1);
        Pen line_pen = new Pen(Color.Black, 1);
        Pen new_line_pen = new Pen(Color.Red, 3);
        public Form1()
        {
            polygon = new List<Point>();
            lines = new List<List<Point>>();
            InitializeComponent();
            g = pictureBox1.CreateGraphics();
            bmap = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            textBox1.Text = "100";
            textBox2.Text = "100";
            textBox3.Text = "250";
            textBox4.Text = "600";

        }

        private void InitPolygon()
        {
            int x, y;
            int width, height;
            x = Convert.ToInt32(textBox1.Text);
            y = Convert.ToInt32(textBox2.Text);
            width = Convert.ToInt32(textBox4.Text);
            height = Convert.ToInt32(textBox3.Text);
            polygon.Add(new Point(x, y));
            polygon.Add(new Point(x + width, y));
            polygon.Add(new Point(x + width, y + height));
            polygon.Add(new Point(x, y + height));
        }

        private void DrawPolygon()
        {
            bmap = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            g = Graphics.FromImage(bmap);
            for (int i = 0; i < polygon.Count - 1; i++)
                g.DrawLine(polygon_pen, polygon[i], polygon[i + 1]);
            g.DrawLine(polygon_pen, polygon[0], polygon[3]);
            pictureBox1.Image = bmap;
        }

        private void ZapolnenieMassiva(Point P, ref int[] mas)
        {
            if (P.X < polygon[0].X)
                mas[0] = 1;
            else
                mas[0] = 0;

            if (P.X > polygon[1].X)
                mas[1] = 1;
            else
                mas[1] = 0;

            if (P.Y < polygon[1].Y)
                mas[2] = 1;
            else
                mas[2] = 0;

            if (P.Y > polygon[2].Y)
                mas[3] = 1;
            else
                mas[3] = 0;
        }

        private int SumEnd(int[] mas)
        {
            int s = 0;
            for (int i = 0; i < mas.Length; i++)
            {
                s += mas[i];
            }
            return s;
        }

        private int MultBit(int[] mas1, int[] mas2)
        {
            for (int i = 0; i < 4; i++)
                if (mas1[i] * mas2[i] == 1)
                    return 1;
            return 0;
        }

        private void MyFunc84(Point P1, Point P2, Point R, int[] T1, int[] T2, int i)
        {
            if ((Math.Abs(P1.X - P2.X) <= 1)&&(Math.Abs(P1.Y - P2.Y) <= 1))
            {
                P1 = P2;
                P2 = R;
                i++;
                MyFunc(P1, P2, T1, T2, i);
                return;
            }
            Point Pcr = new Point((int)Math.Round((P1.X+P2.X)/2.0), (int)Math.Round((P1.Y + P2.Y) / 2.0));
            Point Pm = P1;
            P1 = Pcr;
            ZapolnenieMassiva(P1,ref T1);
            if (MultBit(T1, T2) == 0)
            {
                MyFunc84(P1, P2, R, T1, T2, i);
                return;
            }
            P1 = Pm;
            P2 = Pcr;
            MyFunc84(P1, P2, R, T1, T2, i);
            return;
        }

        private void MyFunc(Point P1, Point P2, int[] T1, int[] T2, int i)
        {
            ZapolnenieMassiva(P1, ref T1);
            ZapolnenieMassiva(P2, ref T2);
            int S1 = SumEnd(T1);
            int S2 = SumEnd(T2);
            if ((S1 != 0)||(S2 != 0))
            {
                if (MultBit(T1, T2) != 0)
                    return;
                Point R = P1;
                if (i > 2)
                {
                    if (MultBit(T1, T2) == 0)
                    {
                        g = Graphics.FromImage(bmap);
                        /*P1.X += 1;
                        P2.X += 1;
                        P1.Y += 1;
                        P2.Y += 1;*/
                        g.DrawLine(new_line_pen, P1, P2);
                        pictureBox1.Image = bmap;
                        return;
                    }
                    else
                        return;
                }
                else
                {
                    if (S2 == 0)
                    {
                        P1 = P2;
                        P2 = R;
                        i++;
                        MyFunc(P1, P2, T1, T2, i);
                        return;//nen
                    }
                    else
                    {
                        MyFunc84(P1, P2, R, T1, T2, i);
                        return;//nen
                    }

                }

            }
            else
            {
                g = Graphics.FromImage(bmap);
                /*P1.X += 1;
                P2.X += 1;
                P1.Y += 1;
                P2.Y += 1;*/
                g.DrawLine(new_line_pen, P1, P2);
                pictureBox1.Image = bmap;
                return;
            }
        }

        private void foma(Point P1, Point P2)
        {
            int i = 1;
            int[] T1 = new int[4];
            int[] T2 = new int[4];
            g = Graphics.FromImage(bmap);
            MyFunc(P1, P2, T1, T2, i);
        }

        private void Otsechenie()
        {
            for (int i = 0; i < lines.Count; i++)
                foma(lines[i][0],lines[i][1]);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            polygon.Clear();
            lines.Clear();
            g.Clear(Color.White);
            InitPolygon();
            DrawPolygon();
            


            //polygon.Clear();
        }

        private void DrawLastLine()
        {
            //bmap = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            g = Graphics.FromImage(bmap);
            g.DrawLine(line_pen, lines[lines.Count-1][0], lines[lines.Count -1][1]);
            pictureBox1.Image = bmap;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (f == 0)
            {
                lines.Add(new List<Point>());
                lines[lines.Count - 1].Add(((MouseEventArgs)e).Location);
                f = 1;
            }
            else if (f == 1)
            {
                lines[lines.Count - 1].Add(((MouseEventArgs)e).Location);
                f = 0;
                DrawLastLine();
            }
        }

        private void DrawLineToMouse(EventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;
            Point coordinates = me.Location;
            g.DrawLine(line_pen, lines[lines.Count - 1][0], coordinates);
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            pictureBox1.Refresh();
            //bmap = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            //g = Graphics.FromImage(bmap);
            g = pictureBox1.CreateGraphics();
            if (f == 1)
                DrawLineToMouse(e);

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Otsechenie();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            polygon.Clear();
            lines.Clear();
            bmap = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            g = Graphics.FromImage(bmap);
            g.Clear(Color.White);
            pictureBox1.Image = bmap;
        }
    }
}
