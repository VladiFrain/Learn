using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyUtils
{
    public partial class MainForm : Form
    {
        int count = 0;
        Random rnd;
        string pass = "";
        char[] specialChars = new char[] {'%', '*', ')', '?', '#', '$', '^', '&', '~'};
        Dictionary<string, double> metrica;
        public MainForm()
        {
            InitializeComponent();
            rnd = new Random();
            metrica = new Dictionary<string, double>();
            metrica.Add("mm", 1);
            metrica.Add("cm", 10);
            metrica.Add("dm", 100);
            metrica.Add("m", 1000);
            metrica.Add("km", 1000000);
            metrica.Add("mile", 1609344);
        }

        private void tsmiExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void tsmiAbout_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Программа мои утилиты, содержит ряд небольших программ, которые могут пригодиться в жизни." +
                "\nАвтор: Владислав Чистяков", "О программе");
        }

        private void btnPlus_Click(object sender, EventArgs e)
        {
            count++;
            lblCount.Text = count.ToString();
        }

        private void btnMinus_Click(object sender, EventArgs e)
        {
            count--;
            lblCount.Text = count.ToString();
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            count = 0;
            lblCount.Text = count.ToString();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {

        }

        private void btnRandom_Click(object sender, EventArgs e)
        {
            int n = rnd.Next(Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown2.Value) + 1);
            lblRandom.Text = n.ToString();
            if (cbRandom.Checked)
            {
                int i = 0;
                while  (tbRandom.Text.IndexOf(n.ToString()) != -1)
                {
                    n = rnd.Next(Convert.ToInt32(numericUpDown1.Value), Convert.ToInt32(numericUpDown2.Value) + 1);
                    i++;
                    if (i > Convert.ToInt32(numericUpDown2.Value) + 1)
                    {
                        break;
                    }
                }
                if (i <= Convert.ToInt32(numericUpDown2.Value) + 1)
                {
                    tbRandom.AppendText(n + " ");
                    lblRandom.Text = n.ToString();
                }
            }
            else
            {
                tbRandom.AppendText(n + " ");
            }
        }

        private void btnRandomClear_Click(object sender, EventArgs e)
        {
            tbRandom.Clear();
        }

        private void btnRandomCopy_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(tbRandom.Text);
        }

        private void tlsmiInsertDate_Click(object sender, EventArgs e)
        {
            rtbNotepad.AppendText(DateTime.Now.ToShortDateString() + "\n");
        }

        private void tlsmiInsertTime_Click(object sender, EventArgs e)
        {
            rtbNotepad.AppendText(DateTime.Now.ToShortTimeString() + "\n");
        }

        private void tsmiSave_Click(object sender, EventArgs e)
        {
            try
            {
                rtbNotepad.SaveFile("notepad.rtf");
            }
            catch 
            {
                MessageBox.Show("Не удалось сохранить.", "Ошибка");
            }
        }

        private void tsmiLoad_Click(object sender, EventArgs e)
        {
            LoadNotepad();
        }

        void LoadNotepad()
        {
            
            try
            {
                rtbNotepad.LoadFile("notepad.rtf");
            }
            catch
            {
                MessageBox.Show("Файл не найден.", "Ошибка");
            }
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            LoadNotepad();
            clbPass.SetItemChecked(0, true);
            clbPass.SetItemChecked(2, true);
        }

        private void btnCreatePass_Click(object sender, EventArgs e)
        {
            if (clbPass.CheckedItems.Count == 0)
            {
                return;
            }
            pass = "";
            for (int i = 0; i < nudPassLength.Value; i++)
            {
                int n = rnd.Next(0, clbPass.CheckedItems.Count);
                string s = clbPass.CheckedItems[n].ToString();
                switch (s) 
                {
                    case "Цифры": 
                        pass += rnd.Next(10).ToString();
                        break;
                    case "Прописные буквы":
                        pass += Convert.ToChar(rnd.Next(65, 88));
                        break;
                    case "Строчные буквы":
                        pass += Convert.ToChar(rnd.Next(97, 122));
                        break;
                    default:
                        pass += specialChars[rnd.Next(specialChars.Length)];
                        break;        
                }
                tbPass.Text = pass;
            }
        }

        private void btnPassCopy_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(pass);
        }

        private void btnConvert_Click(object sender, EventArgs e)
        {
            double m1 = metrica[cbFrom.Text];
            double m2 = metrica[cbTo.Text];
            double n = Convert.ToDouble(tbFrom.Text);
            tbTo.Text = (n * m1 / m2).ToString();
        }

        private void btnConvertSwap_Click(object sender, EventArgs e)
        {
            string t = cbFrom.Text;
            cbFrom.Text = cbTo.Text;
            cbTo.Text = t;
        }

        private void cbConvertMetric_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (cbConvertMetric.Text)
            {
                case "длинна":
                    metrica.Clear();
                    metrica.Add("mm", 1);
                    metrica.Add("cm", 10);
                    metrica.Add("dm", 100);
                    metrica.Add("m", 1000);
                    metrica.Add("km", 1000000);
                    metrica.Add("mile", 1609344);

                    cbFrom.Items.Clear();
                    cbFrom.Items.Add("mm");
                    cbFrom.Items.Add("cm");
                    cbFrom.Items.Add("dm");
                    cbFrom.Items.Add("m");
                    cbFrom.Items.Add("km");
                    cbFrom.Items.Add("mile");
                    cbFrom.Text = "mm";

                    cbTo.Items.Clear();
                    cbTo.Items.Add("mm");
                    cbTo.Items.Add("cm");
                    cbTo.Items.Add("dm");
                    cbTo.Items.Add("m");
                    cbTo.Items.Add("km");
                    cbTo.Items.Add("mile");
                    cbTo.Text = "cm";
                    break;
                case "вес":
                    metrica.Clear();
                    metrica.Add("g", 1);
                    metrica.Add("kg", 1000);
                    metrica.Add("t", 1000000);
                    metrica.Add("lb", 453.6);
                    metrica.Add("oz", 28.3);

                    cbFrom.Items.Clear();
                    cbFrom.Items.Add("g");
                    cbFrom.Items.Add("kg");
                    cbFrom.Items.Add("t");
                    cbFrom.Items.Add("lb");
                    cbFrom.Items.Add("oz");
                    cbFrom.Text = "g";

                    cbTo.Items.Clear();
                    cbTo.Items.Add("g");
                    cbTo.Items.Add("kg");
                    cbTo.Items.Add("t");
                    cbTo.Items.Add("lb");
                    cbTo.Items.Add("oz");
                    cbTo.Text = "kg";
                    break;
            }
        }
    }
}
