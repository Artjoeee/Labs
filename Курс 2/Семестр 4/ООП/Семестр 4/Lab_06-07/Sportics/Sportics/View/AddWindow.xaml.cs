using Sportics.Model;
using Sportics.ViewModel;
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
using System.Windows.Shapes;

namespace Sportics.View
{
    /// <summary>
    /// Логика взаимодействия для AddWindow.xaml
    /// </summary>
    public partial class AddWindow : Window
    {
        public Membership NewMembership { get; set; } // ← Добавьте это свойство

        public AddWindow()
        {
            InitializeComponent();

            if (DataContext is AddViewModel vm)
            {
                vm.RequestClose += () =>
                {
                    NewMembership = vm.CreatedMembership; // ← Получаем объект из ViewModel
                    this.DialogResult = true;
                    this.Close();
                };
            }
        }
    }
}
