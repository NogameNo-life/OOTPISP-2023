using System;
using System.Collections.Generic;
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

namespace lab1_1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private byte _red = 0;
        private byte _green = 0;
        private byte _blue = 0;

        private void ChangeTextBoxColor()
        {
            TextBox.Background = new SolidColorBrush(Color.FromRgb(_red,_green, _blue));
        }
        private void UdBlue_OnValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            _blue = (byte)UdBlue.Value;
            ChangeTextBoxColor();
        }

        private void UdGreen_OnValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            _green = (byte)UdGreen.Value;
            ChangeTextBoxColor();
            
        }

        private void UdRed_OnValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            _red = (byte)UdRed.Value;
            ChangeTextBoxColor();
        }

        private void SliderRed_OnValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            UdRed.Value = (int)SliderRed.Value;
        }

        private void SliderGreen_OnValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            UdGreen.Value = (int)SliderGreen.Value;
        }

        private void SliderBlue_OnValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            UdBlue.Value = (int)SliderBlue.Value;
        }
    }
}