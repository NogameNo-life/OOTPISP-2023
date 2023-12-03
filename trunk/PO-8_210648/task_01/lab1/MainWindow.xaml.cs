
using System.IO;
using System.Windows;
using System.Windows.Documents;

using Microsoft.Win32;

namespace lab1
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private string _path = "";
        private void OpenFile_OnClick(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == true)
            {
                _path = openFileDialog.FileName;
                FileStream fileStream = new FileStream(_path, FileMode.Open);
                TextRange range = new TextRange(MyTextBox.Document.ContentStart, MyTextBox.Document.ContentEnd);
                range.Load(fileStream,DataFormats.Text);
            }
            
        }
        
        private void SaveData(string path)
        {
            FileStream fileStream = new FileStream(path, FileMode.Create);
            TextRange range = new TextRange(MyTextBox.Document.ContentStart, MyTextBox.Document.ContentEnd);
            range.Save(fileStream, DataFormats.Text);
        }
        private void SaveButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (_path == "")
            {
                OpenFileDialog openFileDialog = new OpenFileDialog();
                if (openFileDialog.ShowDialog() == true)
                {
                    SaveData(_path);
                }
            }
            else
            {
                SaveData(_path);
            }
        }
    }
}