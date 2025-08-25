using Sportics.Model;
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
    /// Логика взаимодействия для MembershipCard.xaml
    /// </summary>
    public partial class MembershipCard : UserControl
    {
        public static readonly DependencyProperty MembershipProperty =
        DependencyProperty.Register("Membership", typeof(Membership), typeof(MembershipCard), new PropertyMetadata(null));

        public Membership Membership
        {
            get => (Membership)GetValue(MembershipProperty);
            set => SetValue(MembershipProperty, value);
        }

        public ICommand DeleteCommand
        {
            get => (ICommand)GetValue(DeleteCommandProperty);
            set => SetValue(DeleteCommandProperty, value);
        }

        public static readonly DependencyProperty DeleteCommandProperty =
            DependencyProperty.Register("DeleteCommand", typeof(ICommand), typeof(MembershipCard), new PropertyMetadata(null));

        public MembershipCard()
        {
            InitializeComponent();
        }
    }
}
