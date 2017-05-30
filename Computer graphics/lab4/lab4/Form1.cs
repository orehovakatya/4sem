using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Bitmap bmt = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Standart b = new Standart();
            b.set_color = Color.Black;
            b.draw_circule(ref bmt, new Point(30, 30), 20);

            pictureBox1.Image = bmt;
        }
    }
}
