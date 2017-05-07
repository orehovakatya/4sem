using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab3
{
    public partial class Form1 : Form
    {
        Bitmap bmt;
        //Zomer zoom;
        private Bitmap viever;
        BitmapZoomer zoom;
        public Form1()
        {
            InitializeComponent();
            button1.BackColor = Color.White;
            bmt = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            button1.BackColor = Color.Red;
            tabControl1.SelectedIndex = 1;
            //zoom = new Zomer(ref pictureBox1, ref bmt);
            zoom = new BitmapZoomer(pictureBox1.Size, 100, 100);
            pictureBox1.BackColor = Color.White;
            button7.BackColor = Color.White;
            textBox6.Text = "450";
            textBox7.Text = "325";
            textBox8.Text = "10";
            textBox9.Text = "300";
            textBox1.Text = "10";
            textBox2.Text = "10";
            textBox4.Text = "900";
            textBox3.Text = "600";
            textBox5.Text = "1";
        }

        //Выбор цвета
        private void button1_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            button1.BackColor = colorDialog1.Color;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Point start, end;
            //Вкладка с линиями
            if (tabControl1.SelectedIndex == 0)
            {
                try
                {
                    start = new Point(Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox2.Text));
                    end = new Point(Convert.ToInt32(textBox4.Text), Convert.ToInt32(textBox3.Text));
                }
                catch
                {
                    MessageBox.Show("Параметры заданы неверно");
                    return;
                }

                Base B;
                if (radioButton1.Checked)
                    B = new Standart();
                else
                {
                    if (radioButton2.Checked)
                        B = new CDA();
                    else
                    {
                        if (radioButton3.Checked)
                        {
                            B = new Brezenxem_float();
                        }
                        else
                        {
                            if (radioButton4.Checked)
                                B = new Brezenxem_int();
                            else
                                B = new Brez_without_step();
                        }   
                    }
                }


                B.set_color = button1.BackColor;
                B.draw_line(ref bmt, start, end);
                pictureBox1.Image = bmt;
            }
            //Вкладка спектра
            if (tabControl1.SelectedIndex == 1)
            {
                int R;
                float angle;
                try
                {
                    start = new Point(Convert.ToInt32(textBox6.Text), Convert.ToInt32(textBox7.Text));
                    R = Convert.ToInt32(textBox9.Text);
                    angle = Convert.ToInt32(textBox8.Text);
                }
                catch
                {
                    MessageBox.Show("Параметры заданы неверно");
                    return;
                }
                Base B;
                if (radioButton1.Checked)
                    B = new Standart();
                else
                {
                    if (radioButton2.Checked)
                        B = new CDA();
                    else
                    {
                        if (radioButton3.Checked)
                        {
                            B = new Brezenxem_float();
                        }
                        else
                        {
                            if (radioButton4.Checked)
                                B = new Brezenxem_int();
                            else
                                B = new Brez_without_step();
                        }
                    }
                }

                B.set_color = button1.BackColor;

                B.draw_spectr(ref bmt, start, R, angle);//Вызов спектра
                pictureBox1.Image = zoom.zoom(ref bmt);

            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (viever != null)
                viever.Dispose();
            viever = zoom.Up(ref bmt);
            pictureBox1.Image = viever;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (viever != null)
                viever.Dispose();
            viever = zoom.Left(ref bmt);
            pictureBox1.Image = viever;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (viever != null)
                viever.Dispose();
            viever = zoom.Down(ref bmt);
            pictureBox1.Image = viever;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (viever != null)
                viever.Dispose();
            viever = zoom.Right(ref bmt);
            pictureBox1.Image = viever;
        }

        private void textBox5_TextChange(object sender, EventArgs e)
        {
            zoom.setZoomFactor(textBox5.Text);
            if (viever != null)
                viever.Dispose();
            viever = zoom.zoom(ref bmt);
            pictureBox1.Image = viever;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            button1.BackColor = button7.BackColor;
            button2_Click(sender, e);
        }

        /* private void button3_Click(object sender, EventArgs e)
         {
             zoom.setZoomFactor("5");
             if (viever != null)
                 viever.Dispose();
             viever = zoom.zoom(ref bmt);
             pictureBox1.Image = viever;

         }



         private void button3_Click_1(object sender, EventArgs e)
         {
             zoom.setZoomFactor("2");
             if (viever != null)
                 viever.Dispose();
             viever = zoom.zoom(ref bmt);
             pictureBox1.Image = viever;
         }

         private void button4_Click(object sender, EventArgs e)
         {
             if (viever != null)
                 viever.Dispose();
             viever = zoom.Down(ref bmt);
             pictureBox1.Image = viever;
         }

         private void button5_Click(object sender, EventArgs e)
         {

         }*/
    }
}
