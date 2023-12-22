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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace LR5
{
    public partial class Form2 : Form
    {
        private readonly Form1 previousForm;
        readonly string connectionString;
        TimeSpan start; 
        readonly string user; string host;
        int hours, minutes, seconds;
        public Form2(string name, string host_name1, Form1 previous, string connString)
        {
            connectionString = connString;
            InitializeComponent();
            DateTime check1 = DateTime.Now;
            start = check1.TimeOfDay;

            hours = start.Hours;
            minutes = start.Minutes;
            seconds = start.Seconds;

            user = name; host = host_name1;
            label1.Text = name;
            previousForm = previous;

            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                var query = "INSERT INTO users_time (host_name, user_name, start_hour, start_minute, start_second, end_hour, end_minute, end_second) VALUES (@host_name, @user_name, @start_hour, @start_minute, @start_second, 0, 0, 0)";
                using (var command = new SqliteCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@host_name", host);
                    command.Parameters.AddWithValue("@user_name", user);
                    command.Parameters.AddWithValue("@start_hour", hours);
                    command.Parameters.AddWithValue("@start_minute", minutes);
                    command.Parameters.AddWithValue("@start_second", seconds);
                    command.ExecuteNonQuery();
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Вы работаете", "Отлично");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            DateTime check2 = DateTime.Now;
            TimeSpan end = check2.TimeOfDay;
            hours = end.Hours;
            minutes = end.Minutes;
            seconds = end.Seconds;

            string hour = "";

            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string query = "SELECT hour FROM users WHERE user = @user";
                using (var command = new SqliteCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@user", user);
                    var result = command.ExecuteScalar();
                    if (result != null)
                    {
                        hour = Convert.ToString(result);
                    }
                }
            }

            TimeSpan parsedHour = TimeSpan.Parse(hour);
            parsedHour = parsedHour + (end - start);
            hour = parsedHour.ToString(@"hh\:mm\:ss");

            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string updateQuery = $"UPDATE users SET hour = '{hour}' WHERE user = '{user}'";
                using (var command = new SqliteCommand(updateQuery, connection))
                {
                    command.CommandText = updateQuery;
                    command.ExecuteScalar();
                }
            }

            using (var connection = new SqliteConnection(connectionString))
            {
                connection.Open();

                string updateQuery = $"UPDATE users_time SET end_hour = @hours, end_minute = @minutes, end_second = @seconds WHERE end_hour = 0 AND end_minute = 0 AND end_second = 0";
                using (var command = new SqliteCommand(updateQuery, connection))
                {
                    command.Parameters.AddWithValue("@hours", hours);
                    command.Parameters.AddWithValue("@minutes", minutes);
                    command.Parameters.AddWithValue("@seconds", seconds);

                    command.ExecuteScalar();
                }
            }

            previousForm.Show();
            this.Close();
        }
    }
}
