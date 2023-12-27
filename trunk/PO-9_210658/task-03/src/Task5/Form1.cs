using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Task5
{
    public partial class Form1 : Form
    {

        private readonly Dictionary<string, List<string>> carImports; 

        public Form1()
        {
            InitializeComponent();
            carImports = new Dictionary<string, List<string>>();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // создано Visual Studio
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string selectedValue = comboBox.Text.Trim();

            if (!string.IsNullOrEmpty(selectedValue))
            {
                comboBox.Items.Add(selectedValue);
                comboBox.Text = ""; 
                MessageBox.Show("Значение сохранено и добавлено в список");
            }
            else
            {
                MessageBox.Show("Пожалуйста, выберите или введите значение");
            }
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Random random = new Random();


            carImports.Clear();


            string[] carBrands = new string[6];
            carBrands[0] = textBox1.Text;
            carBrands[1] = textBox2.Text;
            carBrands[2] = textBox3.Text;
            carBrands[3] = textBox4.Text;
            carBrands[4] = textBox5.Text;
            carBrands[5] = textBox6.Text;

            foreach (string carBrand in carBrands)
            {
                string[] countries = comboBox.Items.Cast<string>().ToArray();
                List<string> importedCountries = new List<string>();


                foreach (string country in countries)
                {
                    bool isImported = random.Next(2) == 1; 

                    if (isImported){
                        importedCountries.Add(country);
                    }
                        
                }

                if (importedCountries.Count > 0){
                    carImports.Add(carBrand, importedCountries);
                }
                    
            }

            SetTooltips();

        }

        private void SetTooltips()
        {
            foreach (Control control in Controls)
            {
                if (control is TextBox textBox)
                {
                    string carBrand = textBox.Text;
                    string tooltipText = GetTooltipText(carBrand);
                    toolTip1.SetToolTip(textBox, tooltipText);
                }
            }
        }

        private string GetTooltipText(string carBrand)
        {
            if (carImports.ContainsKey(carBrand))
            {
                List<string> importedCountries = carImports[carBrand];

                if (importedCountries.Count == comboBox.Items.Count){
                    return "Машина импортирована во все страны";
                }
                    
                else if (importedCountries.Count > 0)
                {
                    string countriesList = string.Join(", ", importedCountries);
                    return $"Машина импортирована в некоторые страны: {countriesList}";
                }
                else{
                    return "Машина не импортирована ни в одну страну";
                }
                    
            }

            return string.Empty;
        }

        private void ClearTextBoxes()
        {
            foreach (Control control in Controls)
            {
                if (control is TextBox textBox)
                {
                    textBox.Clear();
                }
            }
        }
    }
}