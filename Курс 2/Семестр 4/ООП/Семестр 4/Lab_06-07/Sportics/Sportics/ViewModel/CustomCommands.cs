using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Sportics.ViewModel
{
    public static class CustomCommands
    {
        public static readonly RoutedUICommand SayHelloCommand = new RoutedUICommand(
            "Сказать привет", "SayHello", typeof(CustomCommands));
    }

}
