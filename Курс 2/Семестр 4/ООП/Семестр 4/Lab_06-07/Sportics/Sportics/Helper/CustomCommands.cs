using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Sportics.Helper
{
    public static class CustomCommands
    {
        public static readonly RoutedUICommand SayHello =
            new RoutedUICommand("Say Hello", "SayHello", typeof(CustomCommands));
    }

}
