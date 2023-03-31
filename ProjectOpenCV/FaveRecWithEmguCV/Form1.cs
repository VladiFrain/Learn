using Emgu.CV;
using Emgu.CV.Structure;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FaveRecWithEmguCV
{
    public partial class Form1 : Form
    {
        private static CascadeClassifier classifier = new CascadeClassifier("C:\\Users\\lixac\\source\\repos\\ProjectOpenCV\\FaveRecWithEmguCV\\haarcascade_frontalface_alt_tree.xml");
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                DialogResult res = openFileDialog1.ShowDialog();

                if (res == DialogResult.OK)
                {
                    string path = openFileDialog1.FileName;

                    pictureBox1.Image = Image.FromFile(path);

                    Bitmap bitmap = new Bitmap(pictureBox1.Image);

                    Image<Bgr, byte> grayImage = bitmap.ToImage<Bgr, byte>();

                    Rectangle[] faces = classifier.DetectMultiScale(grayImage, 1.4, 0);

                    foreach (var face in faces)
                    {
                        using (Graphics graphics = Graphics.FromImage(bitmap))
                        {
                            using (var pen = new Pen(Color.Yellow, 3))
                            {
                                graphics.DrawRectangle(pen, face);
                            }
                        }
                    }

                    pictureBox1.Image = bitmap;
                }
                else
                {
                    MessageBox.Show("Изображение не выбрано!", "Ошибка!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
