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
using Emgu.Util;
using Emgu.CV;
using Emgu.CV.Util;
using Emgu.CV.Structure;

namespace PeshehodDetection
{
    public partial class Form1 : Form
    {
        private VideoCapture capture = null;

        private double frames;

        private double framesCounter;

        private double fps;

        private bool play = false;
        public Form1()
        {
            InitializeComponent();
        }

        private Image<Bgr, byte> Find(Image<Bgr, byte> image)
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

        private async void ReadFrames()
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

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
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

        private void recognizeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (capture == null)
                {
                    throw new Exception("Видео не выбрано!");
                }

                play = true;

                ReadFrames();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            play = false;
        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            try
            {
                if (capture == null)
                {
                    throw new Exception("Видео не выбрано!");
                }

                play = true;

                ReadFrames();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
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

        private void toolStripButton4_Click(object sender, EventArgs e)
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
