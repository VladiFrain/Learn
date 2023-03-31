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
        private Image<Bgr, byte> inputImage = null;
        public Form1()
        {
            InitializeComponent();
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult res = openFileDialog1.ShowDialog();

            if (res == DialogResult.OK)
            {
                inputImage = new Image<Bgr, byte>(openFileDialog1.FileName);

                pictureBox1.Image = inputImage.AsBitmap();
            }
            else
            {
                MessageBox.Show("Изображение не выбрано", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void findShapesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Image<Gray, byte> grayImage = inputImage.SmoothGaussian(5).Convert<Gray, byte>().ThresholdBinaryInv(new Gray(230), new Gray(255));

            VectorOfVectorOfPoint contours = new VectorOfVectorOfPoint();

            Mat hierarchy = new Mat();

            CvInvoke.FindContours(grayImage, contours, hierarchy, Emgu.CV.CvEnum.RetrType.External, Emgu.CV.CvEnum.ChainApproxMethod.ChainApproxSimple);

            for (int i = 0; i < contours.Size; i++)
            {
                double perimeter = CvInvoke.ArcLength(contours[i], true);

                VectorOfPoint approximation = new VectorOfPoint();

                CvInvoke.ApproxPolyDP(contours[i], approximation, 0.04 * perimeter, true);

                CvInvoke.DrawContours(inputImage, contours, i, new MCvScalar(0, 0, 255), 2);

                Moments moments = CvInvoke.Moments(contours[i]);

                int x = (int)(moments.M10 / moments.M00);

                int y = (int)(moments.M01 / moments.M00);

                if (approximation.Size == 3)
                {
                    CvInvoke.PutText(inputImage, "Triangle", new Point(x, y), 
                        Emgu.CV.CvEnum.FontFace.HersheyPlain, 2, new MCvScalar(0, 0, 0), 1);
                }

                if (approximation.Size == 4)
                {
                    Rectangle rect = CvInvoke.BoundingRectangle(contours[i]);

                    double aspectRatio = (double)rect.Width / (double)rect.Height;

                    if (aspectRatio >= 0.95 && aspectRatio <= 1.05)
                    {
                        CvInvoke.PutText(inputImage, "Square", new Point(x, y), 
                            Emgu.CV.CvEnum.FontFace.HersheyPlain, 2, new MCvScalar(0, 0, 0), 1);
                    }
                    else
                    {
                        CvInvoke.PutText(inputImage, "Rectangle", new Point(x, y), 
                            Emgu.CV.CvEnum.FontFace.HersheyPlain, 2, new MCvScalar(0, 0, 0), 1);
                    }
                }

                if (approximation.Size == 5)
                {
                    CvInvoke.PutText(inputImage, "Pentagon", new Point(x, y), 
                        Emgu.CV.CvEnum.FontFace.HersheyPlain, 2, new MCvScalar(0, 0, 0), 1);
                }

                if (approximation.Size == 6)
                {
                    CvInvoke.PutText(inputImage, "Hexagon", new Point(x, y), 
                        Emgu.CV.CvEnum.FontFace.HersheyPlain, 2, new MCvScalar(0, 0, 0), 1);
                }

                if (approximation.Size > 6)
                {
                    CvInvoke.PutText(inputImage, "Circle", new Point(x, y), 
                        Emgu.CV.CvEnum.FontFace.HersheyPlain, 2, new MCvScalar(0, 0, 0), 1);
                }

                pictureBox2.Image = inputImage.AsBitmap();
            }
        }
    }
}
