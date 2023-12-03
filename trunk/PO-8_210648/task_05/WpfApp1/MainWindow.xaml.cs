using System.Data;
using System.Text;
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

namespace WpfApp1;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
        ComboBox.ItemsSource = new string[]
        {
            "zakaz",
            "tema"
        };
        
        //ComboBox.SelectedIndex = 0;
        _dataTable = new DataTable();
    }

    private DataTable _dataTable;
    private string _connectionString = "Server=YAKOVLAPTOP;Database=dblab5;TrustServerCertificate=True; Trusted_Connection=True;";
    private string _connectionString1 = "Server=YAKOVLAPTOP;Database=master; TrustServerCertificate=True; Trusted_Connection=True;";

    private void ButtonCreateDb_OnClick(object sender, RoutedEventArgs e)
    {
        using (SqlConnection connection = new SqlConnection(_connectionString1))
        {
            connection.Open();
            SqlCommand command = new SqlCommand("CREATE DATABASE dblab5;",connection);

            command.ExecuteNonQuery();
            using (SqlConnection connection1 = new SqlConnection(_connectionString))
            {
                connection1.Open();
                SqlCommand sqlCommand = new SqlCommand(
                    "CREATE TABLE zakaz (id INT NOT NULL IDENTITY, day INT NOT NULL, month INT NOT NULL, year INT NOT NULL, vip INT NOT NULL, PRIMARY KEY (id));" +
                    "CREATE TABLE tema (id INT NOT NULL IDENTITY, id_zakaza INT, tema VARCHAR(20) NOT NULL, text VARCHAR(200) NOT NULL , PRIMARY KEY (id), FOREIGN KEY (id_zakaza) REFERENCES zakaz(id) ON DELETE SET NULL );",connection1);
                sqlCommand.ExecuteNonQuery();
            }
        }
    }

    private void ButtonTask1_OnClick(object sender, RoutedEventArgs e)
    {
        DataGrid.IsReadOnly = true;
        SqlConnection connection = new SqlConnection(_connectionString);
        SqlCommand command = new SqlCommand($"SELECT zakaz.id, zakaz.day, zakaz.month, zakaz.year, zakaz.vip, tema.tema, tema.text FROM zakaz, tema WHERE zakaz.id = tema.id_zakaza; ",connection);
        SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
        _dataTable = new DataTable();
        sqlDataAdapter.Fill(_dataTable);
        DataGrid.ItemsSource = _dataTable.DefaultView;
    }

 
    private void ComboBox_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
    {
        DataGrid.IsReadOnly = false;
        SqlConnection connection = new SqlConnection(_connectionString);
        SqlCommand command = new SqlCommand($"SELECT * FROM {ComboBox.SelectedItem};",connection);
        SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
        _dataTable = new DataTable();
        sqlDataAdapter.Fill(_dataTable);
        DataGrid.ItemsSource = _dataTable.DefaultView;
    }

    private void SaveButton_OnClick(object sender, RoutedEventArgs e)
    {
        SqlConnection connection = new SqlConnection(_connectionString);
        SqlDataAdapter sqlDataAdapter = new SqlDataAdapter($"SELECT * FROM {ComboBox.SelectedItem}",connection);
        new SqlCommandBuilder(sqlDataAdapter);
        sqlDataAdapter.Update(_dataTable);
    }

    private void ButtonTask2_OnClick(object sender, RoutedEventArgs e)
    {
        DataGrid.IsReadOnly = true;
        SqlConnection connection = new SqlConnection(_connectionString);
        SqlCommand command = new SqlCommand($"SELECT zakaz.id, zakaz.day, zakaz.month, zakaz.year, zakaz.vip, tema.tema, tema.text FROM zakaz, tema WHERE zakaz.id = tema.id_zakaza AND zakaz.id = {Box.Text}; ",connection);
        SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(command);
        _dataTable = new DataTable();
        sqlDataAdapter.Fill(_dataTable);
        DataGrid.ItemsSource = _dataTable.DefaultView;
    }
}