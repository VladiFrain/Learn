using Emgu.CV.Structure;
using Emgu.CV;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Emgu.CV.Util;
using System.Drawing;

namespace ShapeRecognision
{
    internal class Controller
    {
        private static Image<Bgr, byte> inputImage = null;

        internal static void Open(OpenFileDialog openFileDialog, PictureBox pictureBox)
        {
            DialogResult res = openFileDialog.ShowDialog();

            if (res == DialogResult.OK)
            {
                inputImage = new Image<Bgr, byte>(openFileDialog.FileName);

                pictureBox.Image = inputImage.AsBitmap();
            }
            else
            {
                MessageBox.Show("Изображение не выбрано", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        internal static void Find(PictureBox pictureBox)
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

                pictureBox.Image = inputImage.AsBitmap();
            }
        }
    }
}
