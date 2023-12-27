using Microsoft.Data.Sqlite;
using System.Data;
using System.Diagnostics;

namespace LR5
{
    public partial class Form1 : Form
    {
        readonly string connectionString = "Data Source=C:/Users/Dmitriy/Documents/OOTPISP-Kukharev/trunk/PO-9_210658/task_05/src/lr5database.sqlite";
        int userId;

        public Form1()
        {
            InitializeComponent();

            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "SQLite Database File|*.sqlite";
                openFileDialog.Title = "Выберите файл базы данных (!В ПАПКЕ SRC!)";
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    connectionString = $"Data Source={openFileDialog.FileName}";
                    connectionString = connectionString.Replace("\\", "/");
                }
                else
                {
                    MessageBox.Show("Не выбран файл базы данных. Программа будет закрыта.");
                    Close();
                    return;
                }
            }

            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string selectQuery = "SELECT name FROM hosts";
                using (var command = new SqliteCommand(selectQuery, connection))
                {
                    using (var reader = command.ExecuteReader())
                    {
                        comboBox1.Items.Clear();

                        while (reader.Read())
                        {
                            string name = reader.GetString(0);
                            comboBox1.Items.Add(name);
                        }
                    }
                }
            }
        }

        private void OpenFileExplorerInCurrentDirectory()
        {
            string currentDirectory = Directory.GetCurrentDirectory();
            Process.Start("explorer.exe", currentDirectory);
        }

        private void AddPCUser(string name, string PCname)
        {
            
            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string query = "SELECT id FROM hosts WHERE name = @PCname";
                using (var command = new SqliteCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@PCname", PCname);
                    using (var reader = command.ExecuteReader())
                    {
                        if (!reader.Read())
                        {
                            MessageBox.Show("ID не найден", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            return;
                        }
                        
                    }
                }

                query = "SELECT id FROM users WHERE user = @name";
                using (var command = new SqliteCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@name", name);
                    using (var reader = command.ExecuteReader())
                    {
                        if (!reader.Read())
                        {
                            MessageBox.Show("ID не найден", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        }
                    }
                }

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            string PCname = comboBox1.Text;
            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                if (textBox1.Text == "")
                {
                    MessageBox.Show("Имя обязательно для ввода", "Внимание!");
                    return;
                }

                string findPC = $"SELECT id FROM hosts WHERE name = @name";
                using (var command = new SqliteCommand(findPC, connection))
                {
                    command.Parameters.AddWithValue("@name", PCname);
                    var result = command.ExecuteScalar();
                    if (result == null)
                    {
                        MessageBox.Show("Такого компьютера нет!", "Внимание!");
                        return;
                    }
                }

                string selectQuery = $"SELECT id FROM users WHERE user = '{name}'";
                using (var command = new SqliteCommand(selectQuery, connection))
                {
                    using (var reader = command.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            reader.Close(); 
                        }
                        else
                        {
                            reader.Close();
                            string insertQuery = $"INSERT INTO users (user, hour) VALUES ('{name}', '00:00:00'); SELECT last_insert_rowid();";

                            command.CommandText = insertQuery;
                            userId = Convert.ToInt32(command.ExecuteScalar());
                        }
                    }
                }
            }
            if(name == "admin")
            {
                Form3 form3 = new Form3(this, connectionString);
                form3.Show();
                this.Hide();
            }
            else
            {
                AddPCUser(name, PCname);

                Form2 form2 = new Form2(name, comboBox1.Text , this, connectionString);
                form2.Show();
                this.Hide();
            }

        }
    }
}