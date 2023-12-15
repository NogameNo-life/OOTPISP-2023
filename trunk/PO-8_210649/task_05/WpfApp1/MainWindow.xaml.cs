using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Data.SqlClient;
using MessageBox = System.Windows.Forms.MessageBox;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            ComboBoxTables.ItemsSource = new string[]
            {
                "person",
                "adress",
                "number"
            };
            ComboBoxTables.SelectedIndex = 0;
            _dataTable = new DataTable();
        }
        private DataTable _dataTable;
        private string _connectionString = "Server=YAKOVLAPTOP;Database=lab5;TrustServerCertificate=True; Trusted_Connection=True;";


        private void ButtonSave_OnClick(object sender, RoutedEventArgs e)
        {
            SqlConnection connection = new SqlConnection(_connectionString);
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter($"SELECT * FROM {ComboBoxTables.SelectedItem}",connection);
            new SqlCommandBuilder(sqlDataAdapter);
            sqlDataAdapter.Update(_dataTable);
        }

        private void ButtonFindNumber_OnClick(object sender, RoutedEventArgs e)
        {
            DataGridResult.IsReadOnly = true;
            SqlConnection connection = new SqlConnection(_connectionString);
            SqlCommand command = new SqlCommand($"SELECT number.Number, adress.City, adress.Street, adress.House FROM number, adress, person WHERE person.FirstName = '{TextBoxFirstName.Text}' AND person.SecondName ='{TextBoxSecondName.Text}' AND person.IdNumber = number.Id AND person.IdAdress = adress.Id;;",connection);
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
            _dataTable = new DataTable();
            sqlDataAdapter.Fill(_dataTable);
            DataGridResult.ItemsSource = _dataTable.DefaultView;
        }

        private void ButtonFindFio_OnClick(object sender, RoutedEventArgs e)
        {
            DataGridResult.IsReadOnly = true;
            SqlConnection connection = new SqlConnection(_connectionString);
            SqlCommand command = new SqlCommand($"SELECT person.FirstName, person.SecondName, adress.City, adress.Street, adress.House FROM person, adress, number WHERE number.Number = '{TextBoxNumber.Text}' AND person.IdNumber = number.Id AND person.IdAdress = adress.Id;",connection);
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
            _dataTable = new DataTable();
            sqlDataAdapter.Fill(_dataTable);
            DataGridResult.ItemsSource = _dataTable.DefaultView;
        }

        private void ComboBoxTables_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            DataGridResult.IsReadOnly = false;
            SqlConnection connection = new SqlConnection(_connectionString);
            SqlCommand command = new SqlCommand($"SELECT * FROM {ComboBoxTables.SelectedItem};",connection);
            SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
            _dataTable = new DataTable();
            sqlDataAdapter.Fill(_dataTable);
            DataGridResult.ItemsSource = _dataTable.DefaultView;
            
        }
    }
}