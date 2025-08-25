using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
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
using ValidationResult = System.ComponentModel.DataAnnotations.ValidationResult;

namespace Test1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var text = new ValidText { Text = ValidTextBox.Text };
            var context = new ValidationContext(text) { MemberName = nameof(ValidText.Text) };
            var results = new List<ValidationResult>();

            if (!Validator.TryValidateProperty(text.Text, context, results))
            {
                MessageBox.Show(results[0].ErrorMessage, "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
                ValidTextBox.Text = string.Empty;
            }
            else
            {
                MessageBox.Show("Валидация прошла успешно!", "ОК", MessageBoxButton.OK, MessageBoxImage.Information);
            }
        }

        private void ValidTextBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            var text = new ValidText { Text = ValidTextBox.Text };
            var context = new ValidationContext(text) { MemberName = nameof(ValidText.Text) };
            var results = new List<ValidationResult>();

            if (!Validator.TryValidateProperty(text.Text, context, results))
            {
                MessageBox.Show(results[0].ErrorMessage, "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
                ValidTextBox.Text = string.Empty;
            }
        }
    }
}
