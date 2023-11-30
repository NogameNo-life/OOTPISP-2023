using System.Diagnostics;

namespace Task6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();

            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string inputFile = openFileDialog.FileName;
                string outputFile = "g.txt";

                int[] numbers = File.ReadAllText(inputFile)
                    .Split(',')
                    .Select(int.Parse)
                    .ToArray();

                int[] evenNumbers = numbers.Where(n => n % 2 == 0).ToArray();
                int[] divisibleBy3NotBy7 = numbers.Where(n => n % 3 == 0 && n % 7 != 0).ToArray();
                int[] perfectSquares = numbers.Where(n => IsPerfectSquare(n)).ToArray();

                File.WriteAllText(outputFile, "а)" + string.Join(", ", evenNumbers) + Environment.NewLine);
                File.AppendAllText(outputFile, "б)" + string.Join(", ", divisibleBy3NotBy7) + Environment.NewLine);
                File.AppendAllText(outputFile, "в)" + string.Join(", ", perfectSquares));

                textBox1.Text = "а)" + string.Join(", ", evenNumbers) + Environment.NewLine;
                textBox1.AppendText("б)" + string.Join(", ", divisibleBy3NotBy7) + Environment.NewLine);
                textBox1.AppendText("в)" + string.Join(", ", perfectSquares));

                MessageBox.Show("Результаты записаны в файл g.txt и выведены в TextBox.");
            }

        }
        private bool IsPerfectSquare(int number)
        {
            double squareRoot = Math.Sqrt(number);
            int roundedSquareRoot = (int)squareRoot;
            return roundedSquareRoot * roundedSquareRoot == number;
        }
    }
}