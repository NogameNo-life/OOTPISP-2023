
# Лабораторная работа №2 #

## Основы Qt ##

## Реализация/ход работы ##

## Цель работы ##

Целью этой лабораторной работы является применение полученных на предыдущих лекциях знаний и повторение их на практических примерах. Задачей будет разработка законченного оконного приложения — текстового редактора, работающего с несколькими документами с возможностями открытия и сохранения, отмены действий, работы с буфером обмена и другими.

### Создание приложения TextEditor ###
**Разметка окна приложения**
```xaml
<Window x:Class="lab2.MainWindow"
        Closing="MainWindow_OnClosing"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:lab2"
        mc:Ignorable="d"
        Title="MainWindow" Height="450" Width="800">
        
    <Window.CommandBindings>
        <CommandBinding Command="New" CanExecute="NewCommand_CanExecute" Executed="NewCommand_Executed"/>
        <CommandBinding Command="Open" Executed="OpenComфmand_Executed" />
        <CommandBinding Command="SaveAs" Executed="SaveAsCommand_Executed" />
        <CommandBinding Command="Save" CanExecute="SaveCommand_CanExecute" Executed="SaveCommand_Executed"></CommandBinding>
        <CommandBinding ></CommandBinding>
    </Window.CommandBindings>
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"></RowDefinition>
            <RowDefinition Height="Auto"></RowDefinition>
            <RowDefinition></RowDefinition>
        </Grid.RowDefinitions>
        <Menu Grid.Row="0" Height="Auto" VerticalAlignment="Top">
            <MenuItem Header="File">
                <MenuItem Command="New">
                    <MenuItem.Icon>
                        <Image Source="/res/new.png"/>
                    </MenuItem.Icon>
                </MenuItem>
                <MenuItem Command="Open">
                    <MenuItem.Icon>
                        <Image Source="/res/open.png"/>
                    </MenuItem.Icon>
                </MenuItem>
                <MenuItem Command="Save">
                    <MenuItem.Icon>
                        <Image Source="/res/save.png"/>
                    </MenuItem.Icon>
                </MenuItem>
                <MenuItem Command="SaveAs">
                    <MenuItem.Icon >
                        <Image Source="/res/save.png"/>
                    </MenuItem.Icon>
                </MenuItem>
                <Separator></Separator>
                <MenuItem Header="_Close" Click="CloseWindow"></MenuItem>
            </MenuItem>
            <MenuItem Header="Edit">
                <MenuItem Command="Cut">
                    <MenuItem.Icon>
                        <Image Source="res/cut.png"></Image>
                    </MenuItem.Icon>
                </MenuItem>
                <MenuItem Command="Copy">
                    <MenuItem.Icon>
                        <Image Source="res/copy.png"></Image>
                    </MenuItem.Icon>
                </MenuItem>
                <MenuItem Command="Paste">
                    <MenuItem.Icon>
                        <Image Source="res/paste.png"></Image>
                    </MenuItem.Icon>
                </MenuItem>
                <MenuItem Command="Undo"></MenuItem>
                <MenuItem Command="Redo"></MenuItem>
            </MenuItem>
            <MenuItem Header="Info" Click="MenuItem_OnClick"></MenuItem>
        </Menu>
        <ToolBar Grid.Row="1" VerticalAlignment="Top">
            <ToggleButton x:Name="ButtonBold" Command="ToggleBold">
                <Image Source="res/bold.png" Width="16"></Image>
            </ToggleButton>
            <Separator></Separator>
            <ToggleButton x:Name="ButtonItalic" Command="ToggleItalic">
                <Image Source="res/italic.png" Width="16"></Image>
            </ToggleButton>
            <Separator></Separator>
            <ToggleButton x:Name="ButtonUnderline" Command="ToggleUnderline">
                <Image Source="res/underline.png" Width="16"></Image>
            </ToggleButton>
            <Separator></Separator>
            <ComboBox x:Name="ComboBoxFont" SelectionChanged="ComboBoxFont_OnSelectionChanged"></ComboBox>
            <Separator></Separator>
            <ComboBox x:Name="ComboBoxSize" IsEditable="True" TextBoxBase.TextChanged="ComboBoxSize_OnTextChanged"></ComboBox>
        </ToolBar>
        <RichTextBox x:Name="TextEditor" Grid.Row="2" SelectionChanged="TextEditor_OnSelectionChanged">
            <RichTextBox.Resources>
                <Style TargetType="{x:Type Paragraph}">
                    <Setter Property="Margin" Value="0"></Setter>
                </Style>
            </RichTextBox.Resources>
        </RichTextBox>
    </Grid>
</Window>

```

**MainWindow.xaml.cs** содержит реализацию класса TextEditor.

Реализации действия **Save и SaveAS**:

```csharp
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
```
ComboBox для выбора типа и размера шрифта
```csharp
private void ComboBoxFont_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(ComboBoxFont.SelectedItem != null)
                TextEditor.Selection.ApplyPropertyValue(Inline.FontFamilyProperty, ComboBoxFont.SelectedItem);
        }
        private void ComboBoxSize_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            TextEditor.Selection.ApplyPropertyValue(Inline.FontSizeProperty, ComboBoxSize.Text);
        }
```

Подтверждение при закрытии измененного окна:

```csharp
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
```

Реализации действия **Open и New**:

```csharp
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
```

#### Результат работы программы ####

![img.png](src/img2.png)
![img.png](src/img.png)


#### Вывод ####

Разработали законченное оконное приложение — текстовый редактор, работающий с несколькими документами с возможностями открытия и сохранения, отмены действий, работы с буфером обмена и другими.
