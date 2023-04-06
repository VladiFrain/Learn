using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Emgu.CV;
using Emgu.CV.Util;
using Emgu.CV.Structure;

namespace FindContours
{
    internal class Controller
    {
        private static Image<Bgr, byte> inputImage = null;

        internal static void Open(OpenFileDialog openFileDialog1, PictureBox pictureBox1)
        {
            try
            {
                DialogResult res = openFileDialog1.ShowDialog();

                if (res == DialogResult.OK)
                {
                    inputImage = new Image<Bgr, byte>(openFileDialog1.FileName);

                    pictureBox1.Image = inputImage.AsBitmap();
                }
                else
                {
                    MessageBox.Show("Файл не выбран!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        internal static void Find(PictureBox pictureBox2, CheckBox checkBox1)
        {
            try
            {
                Image<Gray, byte> outputeImage = inputImage.Convert<Gray, byte>().ThresholdBinary(new Gray(100), new Gray(255));

                VectorOfVectorOfPoint contours = new VectorOfVectorOfPoint();

                Mat hierarchy = new Mat();

                CvInvoke.FindContours(outputeImage, contours, hierarchy, Emgu.CV.CvEnum.RetrType.Tree, Emgu.CV.CvEnum.ChainApproxMethod.ChainApproxSimple);

                if (checkBox1.Checked)
                {
                    Image<Gray, Byte> blackBackground = new Image<Gray, byte>(inputImage.Width, inputImage.Height, new Gray(0));

                    CvInvoke.DrawContours(blackBackground, contours, -1, new MCvScalar(255, 0, 0), 3);

                    pictureBox2.Image = blackBackground.AsBitmap();
                }
                else
                {
                    CvInvoke.DrawContours(inputImage, contours, -1, new MCvScalar(255, 0, 0), 3);

                    pictureBox2.Image = inputImage.AsBitmap();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
