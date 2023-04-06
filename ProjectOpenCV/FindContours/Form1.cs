using System;
using System.Windows.Forms;

namespace FindContours
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Controller.Open(openFileDialog1, pictureBox1);
        }

        private void findContoursToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Controller.Find(pictureBox2, checkBox1);
        }
    }
}
