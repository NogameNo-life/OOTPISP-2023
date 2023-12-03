# Лабораторная работа №1 #

## Использование библиотеки элементов графического интерфейса Qt ##

## Реализация/ход работы ##

## Цель работы ##

Научиться использовать библиотеку элементов графического интерфейса WPF.

### План ###

+ простейшее графическое приложение на WPF
+ работа с компоновщиками
+ создание приложения 
+ использование FileDialog - создание простейшего обозревателя текста



#### Создание приложения ColorViewer ####

MainWindow.xaml

``` xaml
<Window x:Class="lab1_1.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:xctk="http://schemas.xceed.com/wpf/xaml/toolkit"
        xmlns:local="clr-namespace:lab1_1"
        mc:Ignorable="d"
        Title="MainWindow" Height="150" Width="400">
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition></RowDefinition>
            <RowDefinition></RowDefinition>
            <RowDefinition></RowDefinition>
        </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition Width="Auto"></ColumnDefinition>
            <ColumnDefinition Width="50"></ColumnDefinition>
            <ColumnDefinition></ColumnDefinition>
            <ColumnDefinition></ColumnDefinition>
        </Grid.ColumnDefinitions>
        <Label Grid.Row="0" Grid.Column="0" Content="Red: "></Label>
        <Label Grid.Row="1" Grid.Column="0" Content="Green: "></Label>
        <Label Grid.Row="2" Grid.Column="0" Content="Blue: "></Label>
        <xctk:IntegerUpDown ValueChanged="UdRed_OnValueChanged" Grid.Row="0" Grid.Column="1" Minimum="0" Maximum="255" x:Name="UdRed"></xctk:IntegerUpDown>
        <xctk:IntegerUpDown ValueChanged="UdGreen_OnValueChanged" Grid.Row="1" Grid.Column="1" Minimum="0" Maximum="255" x:Name="UdGreen"></xctk:IntegerUpDown>
        <xctk:IntegerUpDown ValueChanged="UdBlue_OnValueChanged" Grid.Row="2" Grid.Column="1" Minimum="0" Maximum="255" x:Name="UdBlue"></xctk:IntegerUpDown>
        <Slider x:Name="SliderRed" Grid.Column="2" Grid.Row="0" ValueChanged="SliderRed_OnValueChanged" Value="0" Minimum="0" Maximum="255" SelectionStart="0" Height="30" IsSelectionRangeEnabled="True"/>
        <Slider x:Name="SliderGreen" Grid.Column="2" Grid.Row="1" ValueChanged="SliderGreen_OnValueChanged" Value="0" Minimum="0" Maximum="255" SelectionStart="0" Height="30" IsSelectionRangeEnabled="True"/>
        <Slider x:Name="SliderBlue" Grid.Column="2" Grid.Row="2" ValueChanged="SliderBlue_OnValueChanged" Value="0" Minimum="0" Maximum="255" SelectionStart="0" Height="30" IsSelectionRangeEnabled="True"/>
        <TextBox x:Name="TextBox"  Grid.Column="3" Grid.Row="0" Grid.RowSpan="3"></TextBox>
    </Grid>
</Window>

```

MainWindow.xaml.cs

``` csharp
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
```

#### Результат работы программы ####

![img1.jpg](src/img1.jpg)

#### Cоздание простейшего обозревателя текста ####

MainWindow.xaml.cs

``` xaml
<Window x:Class="lab1.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:lab1"
        mc:Ignorable="d"
        Title="MainWindow" Height="450" Width="800">
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition></RowDefinition>
            <RowDefinition Height="Auto"></RowDefinition>
        </Grid.RowDefinitions>
        <Grid.ColumnDefinitions>
            <ColumnDefinition></ColumnDefinition>
            <ColumnDefinition></ColumnDefinition>
        </Grid.ColumnDefinitions>
        <RichTextBox x:Name="MyTextBox" Grid.Column="0" Grid.Row="0" Grid.ColumnSpan="2" Margin="10">
            <RichTextBox.Resources>
                <Style TargetType="{x:Type Paragraph}">
                    <Setter Property="Margin" Value="0"></Setter>
                </Style>
            </RichTextBox.Resources>
        </RichTextBox>
        <Button x:Name="OpenFileButton" Click="OpenFile_OnClick" Grid.Column="0" Grid.Row="1" Content="Open file" Margin="10,0,5,10"></Button>
        <Button x:Name="SaveButton" Click="SaveButton_OnClick" Grid.Column="1" Grid.Row="1" Content="Save" Margin="5,0,10,10"></Button>
    </Grid>
</Window>
```

MainWindow.xaml.cs

``` csharp

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
```
#### Результат работы программы ####

![img2.png](src/img2.png)

#### Вывод ####

Научились использовать библиотеку элементов графического интерфейса WPF.
