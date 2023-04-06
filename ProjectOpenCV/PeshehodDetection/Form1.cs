using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PeshehodDetection
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }
        
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Controller.Open(openFileDialog1, pictureBox1);
        }

        private void recognizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Controller.Recognize(pictureBox1, pictureBox2, toolStripLabel1);
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            Controller.Pause();
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            Controller.Play(pictureBox1, pictureBox2, toolStripLabel1);
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            Controller.Met(numericUpDown1);
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            Controller.Tem(numericUpDown1);
        }
    }
}