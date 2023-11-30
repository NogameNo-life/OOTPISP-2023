using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace OOP_7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            dataGridView1.ScrollBars = ScrollBars.None;
            dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dataGridView1.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;

            dataGridView1.RowHeadersVisible = false;
            dataGridView1.ColumnHeadersVisible = false;

            dataGridView1.ClearSelection();
            Fill();
            toolTip1.SetToolTip(Show2, "Сlick to find numbers that are powers of 2 and 3\nOr use the hotkey (Ctrl + F)");
            toolTip1.SetToolTip(Show3, "Сlick to refill the field\nOr use the hotkey (Ctrl + R)");
        }

        private void Fill()
        {
            int[,] myArray = new int[15, 15];
            Random rnd = new Random();
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    myArray[i, j] = rnd.Next(1, 101);
                }
            }

            for (int col = 0; col < myArray.GetLength(1); col++)
            {
                dataGridView1.Columns.Add($"Column{col}", $"Column{col}");
            }

            for (int row = 0; row < myArray.GetLength(0); row++)
            {
                dataGridView1.Rows.Add();
                for (int col = 0; col < myArray.GetLength(1); col++)
                {
                    dataGridView1.Rows[row].Cells[col].Value = myArray[row, col];
                    dataGridView1.Rows[row].Cells[col].ToolTipText = myArray[row, col].ToString();
                }
            }
        }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            //создано автоматически visual studio
        }
        

        private void Show2_Click(object sender, EventArgs e)
        {
            Find();
        }

        private void Find()
        {
            int count2 = 0; int count3 = 0;
            for (int row = 0; row < dataGridView1.Rows.Count; row++)
            {
                for (int col = 0; col < dataGridView1.Columns.Count; col++)
                {
                    int cellValue = Convert.ToInt32(dataGridView1.Rows[row].Cells[col].Value);
                    double logarithm2check = Math.Log(cellValue, 2);
                    double logarithm3check = Math.Log(cellValue, 3);
                    if (Math.Abs(logarithm2check - Math.Round(logarithm2check)) < 0.000001 && cellValue != 1)
                    {
                        count2++;
                        dataGridView1.Rows[row].Cells[col].Style.BackColor = Color.Blue;
                    }
                    else if (Math.Abs(logarithm3check - Math.Round(logarithm3check)) < 0.000001 && cellValue != 1)
                    {
                        count3++;
                        dataGridView1.Rows[row].Cells[col].Style.BackColor = Color.Red;
                    }
                }
            }
            textBox1.Text = "Powers of two: " + count2 + "\r\nPowers of triple: " + count3;
        }

        private void Show3_Click(object sender, EventArgs e)
        {
            Refill();
        }
        private void Refill()
        {
            int[,] myArray = new int[15, 15];
            Random rnd = new Random();
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    myArray[i, j] = rnd.Next(1, 101);
                }
            }
            for (int row = 0; row < myArray.GetLength(0); row++)
            {
                for (int col = 0; col < myArray.GetLength(1); col++)
                {
                    dataGridView1.Rows[row].Cells[col].Value = myArray[row, col];
                    dataGridView1.Rows[row].Cells[col].ToolTipText = myArray[row, col].ToString();
                }
            }
            for (int row = 0; row < dataGridView1.Rows.Count; row++)
            {
                for (int col = 0; col < dataGridView1.Columns.Count; col++)
                {
                    dataGridView1.Rows[row].Cells[col].Style.BackColor = Color.White;
                }
            }
            textBox1.Text = "\r\n Reloading...";
            dataGridView1.ClearSelection();
        }
        protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
        {
            if (keyData == (Keys.Control | Keys.F))
            {
                Find();
                return true;
            }
            else if(keyData == (Keys.Control | Keys.R))
            {
                Refill();
                return true;
            }
            return base.ProcessCmdKey(ref msg, keyData);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //создано автоматически visual studio
        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {
            //создано автоматически visual studio
        }

        private void toolTip1_Popup(object sender, PopupEventArgs e)
        {
            //создано автоматически visual studio
        }
    }
}
