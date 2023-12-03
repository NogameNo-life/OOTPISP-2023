using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
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
using Microsoft.Win32;

namespace lab2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private static string _fileName = "";
        private static bool _canSave = false;
        
        public MainWindow()
        {
            InitializeComponent();
            ComboBoxFont.ItemsSource = Fonts.SystemFontFamilies.OrderBy(f => f.Source);
            ComboBoxSize.ItemsSource = new List<double>() { 8, 9, 10, 11, 12, 14, 16, 18, 20, 22, 24, 26, 28, 36, 48, 72 };
            
        }

        private void CloseWindow(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void NewCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void NewCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            _fileName = "";
            _canSave = false;
            TextRange textRange = new TextRange(TextEditor.Document.ContentStart, TextEditor.Document.ContentEnd);
            textRange.Text = "";
        }

        private void OpenCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "Rich Text Format (*.rtf)|*.rtf|All files (*.*)|*.*";
            if(dlg.ShowDialog() == true)
            {
                _canSave = true;
                _fileName = dlg.FileName;
                FileStream fileStream = new FileStream(_fileName, FileMode.Open);
                TextRange range = new TextRange(TextEditor.Document.ContentStart, TextEditor.Document.ContentEnd);
                range.Load(fileStream, DataFormats.Rtf);
            }
        }

        private void SaveAsCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            SaveFileDialog dlg = new SaveFileDialog();
            dlg.Filter = "Rich Text Format (*.rtf)|*.rtf|All files (*.*)|*.*";
            if(dlg.ShowDialog() == true)
            {
                _canSave = true;
                _fileName = dlg.FileName;
                FileStream fileStream = new FileStream(_fileName, FileMode.Create);
                TextRange range = new TextRange(TextEditor.Document.ContentStart, TextEditor.Document.ContentEnd);
                range.Save(fileStream, DataFormats.Rtf);
            }
        }

        private void SaveCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            FileStream fileStream = new FileStream(_fileName, FileMode.Open);
            TextRange range = new TextRange(TextEditor.Document.ContentStart, TextEditor.Document.ContentEnd);
            range.Save(fileStream, DataFormats.Rtf);
        }

        private void SaveCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = _canSave;
        }

        private void ComboBoxFont_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(ComboBoxFont.SelectedItem != null)
                TextEditor.Selection.ApplyPropertyValue(Inline.FontFamilyProperty, ComboBoxFont.SelectedItem);
        }
        private void ComboBoxSize_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            TextEditor.Selection.ApplyPropertyValue(Inline.FontSizeProperty, ComboBoxSize.Text);
        }
        

        private void TextEditor_OnSelectionChanged(object sender, RoutedEventArgs e)
        {
            object temp = TextEditor.Selection.GetPropertyValue(Inline.FontWeightProperty);
            ButtonBold.IsChecked = (temp != DependencyProperty.UnsetValue) && (temp.Equals(FontWeights.Bold));
            temp = TextEditor.Selection.GetPropertyValue(Inline.FontStyleProperty);
            ButtonItalic.IsChecked = (temp != DependencyProperty.UnsetValue) && (temp.Equals(FontStyles.Italic));
            temp = TextEditor.Selection.GetPropertyValue(Inline.TextDecorationsProperty);
            ButtonUnderline.IsChecked = (temp != DependencyProperty.UnsetValue) && (temp.Equals(TextDecorations.Underline));

            temp = TextEditor.Selection.GetPropertyValue(Inline.FontFamilyProperty);
            ComboBoxFont.SelectedItem = temp;
            temp = TextEditor.Selection.GetPropertyValue(Inline.FontSizeProperty);
            ComboBoxSize.Text = temp.ToString();
        }

        

        private void MenuItem_OnClick(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Текстовый редактор, что тут непонятно?") ;
        }

        private void MainWindow_OnClosing(object? sender, CancelEventArgs e)
        {
            var result = MessageBox.Show("Save file?","Save?" ,MessageBoxButton.YesNo, MessageBoxImage.Question, MessageBoxResult.Yes);
            if (result == MessageBoxResult.Yes)
            {
                if (_canSave == true)
                {
                    FileStream fileStream = new FileStream(_fileName, FileMode.Open);
                    TextRange range = new TextRange(TextEditor.Document.ContentStart, TextEditor.Document.ContentEnd);
                    range.Save(fileStream, DataFormats.Rtf);
                }
                else
                {
                    SaveFileDialog dlg = new SaveFileDialog();
                    dlg.Filter = "Rich Text Format (*.rtf)|*.rtf|All files (*.*)|*.*";
                    if(dlg.ShowDialog() == true)
                    {
                        _canSave = true;
                        _fileName = dlg.FileName;
                        FileStream fileStream = new FileStream(_fileName, FileMode.Create);
                        TextRange range = new TextRange(TextEditor.Document.ContentStart, TextEditor.Document.ContentEnd);
                        range.Save(fileStream, DataFormats.Rtf);
                    }   
                }
                    
            }
        }
    }
}