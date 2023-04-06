using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Emgu;
using Emgu.CV;
using Emgu.Util;
using Emgu.CV.Util;
using Emgu.CV.Structure;

namespace ShapeRecognision
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

        private void findShapesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Controller.Find(pictureBox2);
        }
    }
}