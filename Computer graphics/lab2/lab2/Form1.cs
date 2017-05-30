using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab2
{
    public partial class Form1 : Form
    {
        Picture P;
        Stack<Picture> St;

        public Form1()
        {
            InitializeComponent();
            P = new Picture(250f, new PointF(450, 300), new SizeF(250, 250));
            St = new Stack<Picture>();
            pictureBox1.Image = P.Draw_Picture(pictureBox1.Size);
        }


        //Откатить назад
        private void button4_Click(object sender, EventArgs e)
        {
            if (St.Count != 0)
                P = St.Pop();
            else
                MessageBox.Show("Нет объектов");
            pictureBox1.Image = P.Draw_Picture(pictureBox1.Size);
        }

        //Перенос
        private void button1_Click(object sender, EventArgs e)
        {
            St.Push(P);
            float dx = 0f, dy = 0f;
            try
            {
                dx = (float)(Convert.ToDouble(textBox1.Text.Replace(".", ",")));
                dy = (float)(Convert.ToDouble(textBox2.Text.Replace(".", ",")));
            }
            catch
            {
                MessageBox.Show("Ошибка ввода: недопустимые символы");
            }
            P = P.Replase(new PointF(dx, dy));
            pictureBox1.Image = P.Draw_Picture(pictureBox1.Size);
        }

        //Масштабирование
        private void button2_Click(object sender, EventArgs e)
        {
            St.Push(P);
            float x = 0f, y = 0f;
            float k = 0f;
            try
            {
                x = (float)(Convert.ToDouble(textBox7.Text.Replace(".", ",")));
                y = (float)(Convert.ToDouble(textBox8.Text.Replace(".", ",")));
                k = (float)(Convert.ToDouble(textBox4.Text.Replace(".", ",")));
            }
            catch
            {
                MessageBox.Show("Ошибка ввода: недопустимые символы");
            }
            P = P.Change_Scale(x, y, k);
            Bitmap bmt = P.Draw_Picture(pictureBox1.Size);
            Graphics g = Graphics.FromImage(bmt);
            g.DrawLine(new Pen(Color.Red, 3), x, y, x+1, y+1);
            pictureBox1.Image = bmt;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            St.Push(P);
            float angle = 0f, x = 0f, y=0f;
            try
            {
                angle = (float)(Convert.ToDouble(textBox3.Text.Replace(".", ",")));
                x = (float)(Convert.ToDouble(textBox5.Text.Replace(".", ",")));
                y = (float)(Convert.ToDouble(textBox6.Text.Replace(".", ",")));
            }
            catch
            {
                MessageBox.Show("Ошибка ввода: недопустимые символы");
            }
            PointF Center = new PointF(x,y);
            angle = angle * (float)Math.PI / 180;
            P = P.Rotate(Center, angle);
            Bitmap bmt = P.Draw_Picture(pictureBox1.Size);
            Graphics g = Graphics.FromImage(bmt);
            g.DrawLine(new Pen(Color.Red, 3), Center, new PointF(Center.X + 1, Center.Y + 1));
            //pictureBox1.Image = P.Draw_Picture(pictureBox1.Size);
            pictureBox1.Image = bmt;
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            textBox7.Text = MousePosition.X.ToString();
            textBox8.Text = MousePosition.Y.ToString();

            textBox5.Text = MousePosition.X.ToString();
            textBox6.Text = MousePosition.Y.ToString();

        }
    }
}
