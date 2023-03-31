using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MedicalSystem
{
    public partial class EnterData : Form
    {
        private List<TextBox> Inputs = new List<TextBox>();
        public EnterData()
        {
            InitializeComponent();

            var propInfo = typeof(Patient).GetProperties();
            for (int i = 0; i < propInfo.Length; i++)
            {
                var property = propInfo[i];
                var textBox = CreateTextBox(i, property);
                Controls.Add(textBox);
                Inputs.Add(textBox);
            }
        }

        public bool? ShowForm()
        {
            var form = new EnterData();
            if (form.ShowDialog() == DialogResult.OK)
            {
                var patient = new Patient();

                foreach (var textBox in form.Inputs)
                {
                    patient.GetType().InvokeMember(textBox.Tag.ToString(),
                        BindingFlags.Instance | BindingFlags.Public | BindingFlags.SetProperty, Type.DefaultBinder,
                        patient,
                        new object[] { textBox.Text });
                }

                var result = Program.Controller.DataNetwork.Predict()?.Output;

                return result == 1.0;
            }
            return null;
        }

        private TextBox CreateTextBox(int number, PropertyInfo property)
        {
            var y = number * 25 + 13;
            var textBox = new TextBox
            {
                Anchor = (AnchorStyles)(AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right),
                Location = new Point(13, y),
                Name = "textBox" + number,
                Size = new Size(322, 22),
                TabIndex = number,
                Text = property.Name,
                Tag = property.Name,
                Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Italic, GraphicsUnit.Point, 204),
                ForeColor = Color.Gray
            };

            textBox.GotFocus += TextBox_GotFocus;
            textBox.LostFocus += TextBox_LostFocus;

            return textBox;
        }

        private void TextBox_LostFocus(object sender, EventArgs e)
        {
            var textBox = sender as TextBox;
            if (textBox.Text == string.Empty)
            {
                textBox.Text = textBox.Tag.ToString();
                textBox.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Italic, GraphicsUnit.Point, 204);
                textBox.ForeColor = Color.Gray;
            }
        }

        private void TextBox_GotFocus(object sender, EventArgs e)
        {
            var textBox = sender as TextBox;
            if (textBox.Text == textBox.Tag.ToString())
            {
                textBox.Text = string.Empty;
                textBox.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 204);
                textBox.ForeColor = Color.Black;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult =  DialogResult.OK;
            Close();
        }
    }
}
