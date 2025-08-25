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
    /// Логика взаимодействия для CustomButton.xaml
    /// </summary>
    public partial class CustomButton : UserControl
    {
        public CustomButton()
        {
            InitializeComponent();
        }

        public static readonly RoutedEvent ClickDirectEvent =
            EventManager.RegisterRoutedEvent("ClickDirect", RoutingStrategy.Direct, typeof(RoutedEventHandler), typeof(CustomButton));
        public static readonly RoutedEvent ClickBubblingEvent =
            EventManager.RegisterRoutedEvent("ClickBubbling", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(CustomButton));
        public static readonly RoutedEvent ClickTunnelingEvent =
            EventManager.RegisterRoutedEvent("ClickTunneling", RoutingStrategy.Tunnel, typeof(RoutedEventHandler), typeof(CustomButton));

        public event RoutedEventHandler ClickDirect
        {
            add => AddHandler(ClickDirectEvent, value);
            remove => RemoveHandler(ClickDirectEvent, value);
        }

        public event RoutedEventHandler ClickBubbling
        {
            add => AddHandler(ClickBubblingEvent, value);
            remove => RemoveHandler(ClickBubblingEvent, value);
        }

        public event RoutedEventHandler ClickTunneling
        {
            add => AddHandler(ClickTunnelingEvent, value);
            remove => RemoveHandler(ClickTunnelingEvent, value);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            RaiseEvent(new RoutedEventArgs(ClickTunnelingEvent));
            RaiseEvent(new RoutedEventArgs(ClickBubblingEvent));
            RaiseEvent(new RoutedEventArgs(ClickDirectEvent));
        }
    }
}
