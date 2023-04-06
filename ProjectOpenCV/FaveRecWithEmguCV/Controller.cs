using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Emgu.CV;
using Emgu.CV.Structure;

namespace FaveRecWithEmguCV
{
    internal class Controller
    {
        private static CascadeClassifier classifier = new CascadeClassifier("./haarcascade_frontalface_alt_tree.xml");

        internal static void Run(OpenFileDialog openFileDialog1, PictureBox pictureBox1)
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
