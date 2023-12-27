namespace ThirdLab1
{
    public partial class Form1 : Form
    {
        bool isFirst = true;
        public Form1()
        {
            InitializeComponent();
            textBox.Text = "X = ; Y = ;";
            textBox.SelectionStart = textBox.TextLength;
        }
        bool Foo()
        {
            if (isFirst == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //автоматически создано visual studio 
        }
        private void ProcessText()
        {
            int x = 0, y = 0;
            bool isNum = false;
            string str = textBox.Text;
            isFirst = true;
            for (int i = 0; i < str.Length; i++) 
            {
                if (Char.IsDigit(str[i]))
                {
                    isNum = true;

                    if (Foo()) 
                    {
                        x = x * 10 + (str[i] - '0'); 
                    }
                    else
                    {
                        y = y * 10 + (str[i] - '0'); 
                    }
                }
                else
                {
                    if (isNum == true)
                    {
                        isNum = false;
                        isFirst = false; 
                    }
                }
            }
            textBox.Text = string.Format("X = {0}; Y = {1};", Math.Min(x, y), Math.Max(x, y));
        }
        protected override bool ProcessCmdKey(ref Message msg, Keys keyData)
        {
            if (keyData == (Keys.Enter))
            {
                ProcessText();
                return true;
            }
            return base.ProcessCmdKey(ref msg, keyData);
        }
    }
}