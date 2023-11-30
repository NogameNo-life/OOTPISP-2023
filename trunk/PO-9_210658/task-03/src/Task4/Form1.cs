namespace LR4_1
{
    public partial class Form1 : Form
    {
        private Stack<int> numberStack;
        private Queue<int> numberQueue;
        public Form1()
        {
            InitializeComponent();
            numberStack = new Stack<int>();
            numberQueue = new Queue<int>();
            FillQueue();
        }
        void FillQueue()
        {
            Random random = new Random();
            numberQueue.Clear();
            for (int i = 0; i < 8; i++)
            {
                int randomNumber = random.Next(-20, 51); 
                numberQueue.Enqueue(randomNumber);
            }

            textBox1.Text = string.Join(", ", numberQueue);
        }
        private void button1_Click(object sender, EventArgs e)
        {

            numberStack.Clear();
            numberStack.Push((int)numeric8.Value);
            numberStack.Push((int)numeric7.Value);
            numberStack.Push((int)numeric6.Value);
            numberStack.Push((int)numeric5.Value);
            numberStack.Push((int)numeric4.Value);
            numberStack.Push((int)numeric3.Value);
            numberStack.Push((int)numeric2.Value);
            numberStack.Push((int)numeric1.Value);

            int stackSize = numberStack.Count;
            int[] stackArray = numberStack.ToArray();

            for (int i = 0; i < stackSize / 2; i++)
            {
                int product = stackArray[i] * stackArray[stackSize - 1 - i];
                stackArray[i] = product;
                stackArray[stackSize - 1 - i] = product;
            }
            numberStack = new Stack<int>(stackArray);

            numeric1.Value = numberStack.Pop();
            numeric2.Value = numberStack.Pop();
            numeric3.Value = numberStack.Pop();
            numeric4.Value = numberStack.Pop();
            numeric5.Value = numberStack.Pop();
            numeric6.Value = numberStack.Pop();
            numeric7.Value = numberStack.Pop();
            numeric8.Value = numberStack.Pop();
        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {
            //автоматически создано visual studio
        }

        private void numericUpDown6_ValueChanged(object sender, EventArgs e)
        {
            //автоматически создано visual studio
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Queue<int> resultQueue = new Queue<int>();
            while (numberQueue.Count >= 2)
            {
                int firstNumber = numberQueue.Dequeue();
                int secondNumber = numberQueue.Peek();
                int average = (firstNumber + secondNumber) / 2;
                resultQueue.Enqueue(average);
            }
            textBox1.Text = string.Join(", ", resultQueue);
            numberQueue = resultQueue; 
        }
    }
}