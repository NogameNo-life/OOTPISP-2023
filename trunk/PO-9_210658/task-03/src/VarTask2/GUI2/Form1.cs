namespace GUIvarTask2
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
        }
        private void Fill()
        {
            dataGridView1.Rows.Clear();
            dataGridView1.Columns.Clear();
            int x = (int)num1.Value;
            int y = (int)num2.Value;
            int[,] myArray = new int[x, y];
            Random rnd = new Random();
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
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
                    dataGridView1.Rows[row].Cells[col].ToolTipText = FindAmount(myArray, row, y);
                }
            }
        }
        private string FindAmount(int[,] array, int row, int numberofcols)
        {
            int amount = 0;
            int avg = 0, suminrow = 0;
            string output = "";

            for (int i = 0; i < numberofcols; ++i)
            {
                suminrow += array[row, i];
            }
            avg = suminrow / numberofcols;
            for (int i = 0; i < numberofcols; ++i)
            {
                if(array[row, i] > avg)
                {
                    ++amount;
                }
            }
            output = "Avg: " + avg + "/Amount: " + amount;
            return output;
        }
        private int Average()
        {
            return 0;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Fill();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            //автоматически создано visual studio
        }

        private void num1_ValueChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                num2.Value = num1.Value;
            }
        }

        private void num2_ValueChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                num1.Value = num2.Value;
            }
        }
    }
}