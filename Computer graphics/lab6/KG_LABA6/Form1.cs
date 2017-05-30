using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace KG_LABA6
{
    public partial class Form1 : Form
    {
        /// <summary>
        /// Многоугольники
        /// </summary>
        private List<List<Point>> Polygons;
        /// <summary>
        /// отклонение мыши по оси X
        /// </summary>
        private const  int MouseErrorX = 20;
        /// <summary>
        /// отклонение мыши по оси Y
        /// </summary>
        private const int MouseErrorY = 50;

        bool InputEnded = false;
        /// <summary>
        /// Точка затравки
        /// </summary>
        private Point StPoint;

        /// <summary>
        /// расовалка на битмапе
        /// </summary>
        private Graphics g;
        
        private Pen pen;

        /// <summary>
        /// Битмап на котором мы все рисуем.
        /// </summary>
        private Bitmap bitmap;

        /// <summary>
        /// флаг блокировки событий textbox2 и 3 для того чтобы не глючил мышиный ввод
        /// </summary>
        private bool flag = false;

        private List<Point> ellipse;
        public Form1()
        {
            InitializeComponent();

            //Список нужен ли?
            Polygons = new List<List<Point>> {new List<Point>()};
            ellipse = new List<Point>();
           
            //Цвет граней
            button4.BackColor = Color.Black;
            //Цвет заливки
            button5.BackColor = Color.Red;

            bitmap = new Bitmap(pictureBox1.Size.Width, pictureBox1.Size.Height);
            //g = Graphics.FromImage(bitmap);
            g = pictureBox1.CreateGraphics();
            pen = new Pen(button4.BackColor, 1);
            //точка затравки по-умолчанию
            textBox1.Text = "5";
           
            //точка затравки по-умолчанию
            textBox2.Text = "1";
            textBox3.Text = "1";
            StPoint = new Point(1, 1);

            richTextBox1.Enabled = false;
            richTextBox1.Text = @"Ввод затравочной точки - shift
Ввод прямых паралельно осям - control
Установка точки - левая кнопка мыши
Замыкание многоугольника - правая кнопка мыши";
        }

        /// <summary>
        /// Сохранение точки в список
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;
            Point coordinates = me.Location;
            if ((MouseButtons.Middle == ((MouseEventArgs)e).Button) || (ModifierKeys == Keys.Shift))
            {

                StPoint.X = coordinates.X;
                StPoint.Y = coordinates.Y;

                //блокировка событий
                flag = true;
                textBox2.Text = StPoint.X.ToString();
                textBox3.Text = StPoint.Y.ToString();
                flag = false;
                return;
            }

            if (MouseButtons.Left == ((MouseEventArgs)e).Button)
            {
                if (ModifierKeys == Keys.Control)
                {
                    if (Polygons[Polygons.Count - 1].Count == 0)
                        return;
                    Polygons[Polygons.Count - 1].Add(ControlKeyLine(Polygons[Polygons.Count - 1][Polygons[Polygons.Count - 1].Count - 1],e));
                }
                else
                {
                    Polygons[Polygons.Count - 1].Add(coordinates);
                }

            }


            if (((MouseEventArgs)e).Button == MouseButtons.Right)
            {
                Polygons.Add(new List<Point>());
            }

            DrawAllLines();

            RecreteDataGridView1();
        }

        private int check(Point p1, Point p2, Point p3)
        {
            return (p2.X - p1.X) * (p3.Y - p1.Y) - (p3.X - p1.X) * (p2.Y - p1.Y);

        }



        private bool IsRight(List<Point> list)
        {
            int minindex = 0;
            for (int i = 0; i < list.Count(); i++)
            {
                if (list[i].X < list[minindex].X)
                    minindex = i;
            }

            if (list.Count() == 0)
                return true;
            if (check(list[minindex], list[(list.Count() + minindex - 1) % list.Count()], list[(minindex + 1) % list.Count()]) > 0)
                return true;
            else
                return false;
        }


        private void UsePointsFromDataGridView1()
        {
            List<List<Point>> newpoints = new List<List<Point>>();

            int listcount = 0;
            for (int i = 0; i < dataGridView1.RowCount - 1; i++)
            {


                if (dataGridView1.Rows[i].Cells[2].Value.ToString() != (listcount).ToString())
                {
                    newpoints.Add(new List<Point>());
                    listcount = Convert.ToInt32(dataGridView1.Rows[i].Cells[2].Value.ToString());
                }

                int X = Convert.ToInt32(dataGridView1.Rows[i].Cells[0].Value);
                int Y = Convert.ToInt32(dataGridView1.Rows[i].Cells[1].Value);
                newpoints[newpoints.Count - 1].Add(new Point(X, Y));

            }
            newpoints.Add(new List<Point>());

            Polygons = newpoints;
            //отчистка экрана
            pictureBox1.Refresh();

            //рисуем все уже сохраненные точки
            DrawAllLines();

        }

        private void RecreteDataGridView1()
        {
            int count = 0;
            dataGridView1.Rows.Clear();

            //Этот цикл нельзя оьъединять со следущим так как добавлениее строки очищает таблицу
            for (int i = 0; i < Polygons.Count; i++)
            {
                for (int j = 0; j < Polygons[i].Count; j++)
                    dataGridView1.Rows.Add();
            }

            for (int i = 0; i < Polygons.Count; i++)
            {
                List<Point> temp = Polygons[i];
                for (int j = 0; j < temp.Count; j++)
                {
                    dataGridView1.Rows[count].Cells[0].Value = temp[j].X;
                    dataGridView1.Rows[count].Cells[1].Value = temp[j].Y;
                    dataGridView1.Rows[count].Cells[2].Value = i + 1;
                    count++;
                }

            }
        }
        /// <summary>
        /// При нажатой клавише ctrl, возвряшает кординаты токни на оси ох или oy
        /// </summary>
        /// <param name="lastpoint">Последняя введенная пользователем точка</param>
        /// <returns></returns>
        private Point ControlKeyLine(Point lastpoint, EventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;
            Point coordinates = me.Location;
            Point p = new Point();
            /*int deltaX = lastpoint.X - MousePosition.X + MouseErrorX;
            int deltaY = lastpoint.Y - MousePosition.Y + MouseErrorY;*/
            int deltaX = lastpoint.X - coordinates.X;
            int deltaY = lastpoint.Y - coordinates.Y;
            if (deltaX != 0)
            {
                double tang = deltaY / deltaX;
                if (Math.Abs(tang) < 1)
                {
                    p = new Point(coordinates.X, lastpoint.Y);
                }
                else
                {
                    p = new Point(lastpoint.X, coordinates.Y);
                }
            }
            else
            {
                p = new Point(lastpoint.X, MousePosition.Y - MouseErrorY);
            }
            return p;
        }

        /// <summary>
        /// Рисует линии к мыши из последней и первой точке
        /// </summary>
        /// <param name="list"></param>
        private void DrawLinesToMouse(List<Point> list, EventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;
            Point coordinates = me.Location;
            if (list.Count > 0)
            {
                if (ModifierKeys == Keys.Control)
                {
                    g.DrawLine(pen, list[list.Count - 1], ControlKeyLine(list[list.Count - 1], e));
                    g.DrawLine(pen, ControlKeyLine(list[list.Count - 1], e), list[0]);
                }
                else
                {
                    //g.DrawLine(pen, list[list.Count - 1], new Point(MousePosition.X - MouseErrorX, MousePosition.Y - MouseErrorY));
                    //g.DrawLine(pen, new Point(MousePosition.X - MouseErrorX, MousePosition.Y - MouseErrorY), list[0]);
                    g.DrawLine(pen, list[list.Count - 1], coordinates);
                    g.DrawLine(pen, coordinates, list[0]);
                }
            }
        }

        /// <summary>
        /// Отрисовка всех сохраненных линий
        /// </summary>
        private void DrawAllLines()
        {
            Bitmap bmt = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics g = Graphics.FromImage(bmt);
            pictureBox1.Refresh();
            int i;
            for (i = 0; i < Polygons.Count() - 1; i++)
            {
                if (Polygons[i].Count > 1)
                {
                    g.DrawLines(pen, Polygons[i].ToArray());
                    g.DrawLine(pen, Polygons[i][0], Polygons[i][Polygons[i].Count - 1]);
                }

            }
            //последний многоуголиник
            if (Polygons[i].Count > 1)
            {
                g.DrawLines(pen, Polygons[i].ToArray());
                if (InputEnded == true)
                    g.DrawLine(pen, Polygons[i][0], Polygons[i][Polygons[i].Count - 1]);
            }
            pictureBox1.Image = bmt;


        }

        /// <summary>
        /// Создание линий при движении мыши
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            //отчистка экрана
            pictureBox1.Refresh();

            //рисуем все уже сохраненные точки
            //DrawAllLines();

            //Рисует линии к мыши из последней и первой точке
            if (Polygons.Count >= 1)
                DrawLinesToMouse(Polygons[Polygons.Count() - 1], e);


        }

        private void panel1_Paint(object sender, PaintEventArgs e){}

        private void Form1_KeyDown(object sender, KeyEventArgs e){}


        private void button1_Click(object sender, EventArgs e)
        {
            GC.Collect();
            int interval = 0;
            
            try
            {
                interval = Convert.ToInt32(textBox1.Text);
            }
            catch
            {
                MessageBox.Show("Плохая задержка");
                return;
            }

            FillPoligons pol = new FillPoligons(ref pictureBox1,StPoint,interval,button5.BackColor, button4.BackColor);
            bitmap.Dispose();
            g.Dispose();
            bitmap = pol.GetBitmap;
            pictureBox1.Image = bitmap;
            g = Graphics.FromImage(bitmap);
          
        }

        private void button2_Click(object sender, EventArgs e)
        {
            UsePointsFromDataGridView1();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            List<List<Point>> newpoints = new List<List<Point>>();
            newpoints.Add(new List<Point>());


            Polygons = newpoints;
            //отчистка экрана

            
            Brush br = new SolidBrush(Color.White);
            g.FillRectangle(br, 0, 0, pictureBox1.Width, pictureBox1.Height);
            pictureBox1.Refresh();
            pictureBox1.Image = bitmap;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            button4.BackColor = colorDialog1.Color;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            button5.BackColor = colorDialog1.Color;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (flag == true)
            {

                return;
            }
            try
            {
                int x = Convert.ToInt32(textBox2.Text);
                int y = Convert.ToInt32(textBox3.Text);
                StPoint = new Point(x, y);
            }
            catch { }
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            if (flag == true)
            {
               
                return;
            }
                try
            {
                int x = Convert.ToInt32(textBox2.Text);
                int y = Convert.ToInt32(textBox3.Text);
                StPoint = new Point(x, y);
            }
            catch
            {
            }
        }
    }
}

