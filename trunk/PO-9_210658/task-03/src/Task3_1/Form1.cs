using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace LR_3_1
{
    public partial class Form1 : Form
    {
        private readonly List<int> numbersList;

        public Form1()
        {
            InitializeComponent();
            numbersList = new List<int>();
            FillList();
        }

        private void FillList()
        {
            Random random = new Random();
            for (int i = 0; i < 15; i++)
            {
                int randomValue = random.Next(1, 100);
                numbersList.Add(randomValue);
            }

            textBox1.Text = string.Join(", ", numbersList);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int startPosition = (int)numericStart.Value;
            int endPosition = (int)numericEnd.Value;

            if (startPosition < 1 || endPosition > numbersList.Count || startPosition > endPosition)
            {
                MessageBox.Show("Некорректные позиции для удаления");
                return;
            }

            numbersList.RemoveRange(startPosition - 1, endPosition - startPosition + 1);

            textBox1.Text = string.Join(", ", numbersList);
        }
    }
}