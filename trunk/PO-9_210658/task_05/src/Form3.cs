using Microsoft.Data.Sqlite;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace LR5
{
    public partial class Form3 : Form
    {
        private readonly Form1 previousForm;
        readonly string connectionString;
        public Form3(Form1 previous, string connectionString)
        {
            connectionString = connectionString;
            previousForm = previous;
            InitializeComponent();
            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string selectQuery = "SELECT name FROM hosts";
                using (var command = new SqliteCommand(selectQuery, connection))
                {
                    using (var reader = command.ExecuteReader())
                    {
                        comboBox4.Items.Clear();
                        comboBox2.Items.Clear();
                        comboBox1.Items.Clear();

                        while (reader.Read())
                        {
                            string name = reader.GetString(0);
                            comboBox4.Items.Add(name);
                            comboBox2.Items.Add(name);
                            comboBox1.Items.Add(name);
                        }
                    }
                }
            }

            ToolTip toolTip1 = new ToolTip();
            toolTip1.SetToolTip(button2, "Время работы компьютера за день");
            toolTip1.SetToolTip(button4, "Вывести список пользователей для заданного компьютера");
            toolTip1.SetToolTip(button5, "Вывести пользователя, работавшего за компьютером в указанное время");
            toolTip1.SetToolTip(hours, "Часы");
            toolTip1.SetToolTip(minutes, "Минуты");
            toolTip1.SetToolTip(seconds, "Секунды");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            previousForm.Show();
            this.Close();
        }

        private void label4_Click(object sender, EventArgs e)
        {
            //автоматически создано visual studio
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "" || textBox2.Text == "")
            {
                MessageBox.Show("Все поля обязательны для заполнения!", "Внимание!");
                return;
            }
            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string name = textBox1.Text;
                string host = textBox2.Text;

                string insertQuery = $"INSERT INTO hosts (name, host) VALUES ('{name}', '{host}')";

                using (var command = new SqliteCommand(insertQuery, connection))
                {
                    command.ExecuteNonQuery();
                }

                MessageBox.Show("Запись успешно создана", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            string user_name;
            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string query = "SELECT user_name FROM users_time WHERE host_name = @host_name AND start_hour <= @hours AND end_hour >= @hours AND start_minute <= @minutes AND end_minute >= @minutes AND start_second <= @seconds AND end_second >= @seconds";
                using (var command = new SqliteCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@host_name", comboBox4.Text);
                    command.Parameters.AddWithValue("@hours", hours.Value);
                    command.Parameters.AddWithValue("@minutes", minutes.Value);
                    command.Parameters.AddWithValue("@seconds", seconds.Value);

                    var result = command.ExecuteScalar();
                    if (result != null)
                    {
                        user_name = Convert.ToString(result);
                        textBox3.Text = user_name;
                    }
                    else
                    {
                        MessageBox.Show("Пользователь не найден!", "Ошибка!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    }
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string selectQuery = $"SELECT DISTINCT user_name FROM users_time WHERE host_name = '{comboBox2.Text}'";
                using (var command = new SqliteCommand(selectQuery, connection))
                {
                    using (var reader = command.ExecuteReader())
                    {
                        comboBox3.Items.Clear();

                        while (reader.Read())
                        {
                            string name = reader.GetString(0);
                            comboBox3.Items.Add(name);
                        }
                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            TimeSpan result = TimeSpan.Parse("00:00:00");
            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string selectQuery = @"SELECT DISTINCT u.hour
                           FROM users_time ut
                           JOIN users u ON ut.user_name = u.user
                           WHERE ut.host_name = @hostName";


                using (var command = new SqliteCommand(selectQuery, connection))
                {
                    command.Parameters.AddWithValue("@hostName", comboBox1.Text);

                    using (var reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            string hours = reader.GetString(0);
                            TimeSpan duration1 = TimeSpan.Parse(hours);
                            result += duration1;
                        }
                    }
                }
            }
            textBox4.Text = result.ToString(@"hh\:mm\:ss");
        }
    }
}
