using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Emgu;
using Emgu.Util;
using Emgu.CV;
using Emgu.CV.Util;
using Emgu.CV.Structure;

namespace PeshehodDetection
{
    internal static class Controller
    {
        private static VideoCapture capture = null;

        private static double frames;

        private static double framesCounter;

        private static double fps;

        private static bool play = false;

        private static Image<Bgr, byte> Find(Image<Bgr, byte> image)
        {
            MCvObjectDetection[] regions;

            using (HOGDescriptor descriptor = new HOGDescriptor())
            {
                descriptor.SetSVMDetector(HOGDescriptor.GetDefaultPeopleDetector());

                regions = descriptor.DetectMultiScale(image);
            }

            foreach (var pesh in regions)
            {
                image.Draw(pesh.Rect, new Bgr(Color.Red), 3);

                CvInvoke.PutText(image, "Peshehod", new Point(pesh.Rect.X, pesh.Rect.Y),
                    Emgu.CV.CvEnum.FontFace.HersheyPlain, 1, new MCvScalar(255, 255, 255), 2);
            }

            return image;
        }

        internal static async void ReadFrames(PictureBox pictureBox1, PictureBox pictureBox2, ToolStripLabel toolStripLabel1)
        {
            Mat m = new Mat();

            while (play && framesCounter < frames)
            {
                framesCounter += 1;

                capture.Set(Emgu.CV.CvEnum.CapProp.PosFrames, framesCounter);
                capture.Read(m);
                pictureBox1.Image = m.ToBitmap();

                pictureBox2.Image = Find(m.ToImage<Bgr, byte>()).ToBitmap();

                toolStripLabel1.Text = $"{framesCounter} / {frames}";

                await Task.Delay(1000 / Convert.ToInt16(fps));
            }
        }

        internal static void Open(OpenFileDialog openFileDialog1 ,PictureBox pictureBox1)
        {
            try
            {
                DialogResult result = openFileDialog1.ShowDialog();

                if (result == DialogResult.OK)
                {
                    capture = new VideoCapture(openFileDialog1.FileName);

                    Mat m = new Mat();
                    capture.Read(m);

                    pictureBox1.Image = m.ToBitmap();

                    fps = capture.Get(Emgu.CV.CvEnum.CapProp.Fps);

                    frames = capture.Get(Emgu.CV.CvEnum.CapProp.FrameCount);

                    framesCounter = 1;
                }
                else
                {
                    MessageBox.Show("Видео не выбрано", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        internal static void Recognize(PictureBox pictureBox1, PictureBox pictureBox2, ToolStripLabel toolStripLabel1)
        {
            try
            {
                if (capture == null)
                {
                    throw new Exception("Видео не выбрано!");
                }

                play = true;

                ReadFrames(pictureBox1, pictureBox2, toolStripLabel1);

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        internal static void Pause()
        {
            play = false;
        }

        internal static void Play(PictureBox pictureBox1, PictureBox pictureBox2, ToolStripLabel toolStripLabel1)
        {
            try
            {
                if (capture == null)
                {
                    throw new Exception("Видео не выбрано!");
                }

                play = true;

                ReadFrames(pictureBox1, pictureBox2, toolStripLabel1);

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        internal static void Met(NumericUpDown numericUpDown1)
        {
            try
            {
                framesCounter -= Convert.ToDouble(numericUpDown1.Value);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        internal static void Tem(NumericUpDown numericUpDown1)
        {
            try
            {
                framesCounter += Convert.ToDouble(numericUpDown1.Value);

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
