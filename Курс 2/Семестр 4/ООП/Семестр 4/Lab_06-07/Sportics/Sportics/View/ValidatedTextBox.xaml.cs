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

namespace Sportics.View
{
    /// <summary>
    /// Логика взаимодействия для ValidatedTextBox.xaml
    /// </summary>
    public partial class ValidatedTextBox : UserControl
    {
        public ValidatedTextBox()
        {
            InitializeComponent();
        }

        public static readonly DependencyProperty ValidatedTextProperty =
            DependencyProperty.Register(
                nameof(ValidatedText),
                typeof(string),
                typeof(ValidatedTextBox),
                new FrameworkPropertyMetadata("Default", FrameworkPropertyMetadataOptions.BindsTwoWayByDefault, null, CoerceValidatedText),
                new ValidateValueCallback(ValidateValidatedText));

        public string ValidatedText
        {
            get => (string)GetValue(ValidatedTextProperty);
            set => SetValue(ValidatedTextProperty, value);
        }

        private static bool ValidateValidatedText(object value)
        {
            var text = value as string;
            return !string.IsNullOrWhiteSpace(text);
        }

        private static object CoerceValidatedText(DependencyObject d, object baseValue)
        {
            if (baseValue is string str && str.Length > 20)
                return str.Substring(0, 20);
            return baseValue;
        }
    }
}
