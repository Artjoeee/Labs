using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_08
{
    public class Director
    {
        public delegate void Money(string message);

        public event Money MoneyChanged;
        public Director(int cash) => Cash = cash;
        public int Cash { get; private set; }

        public void Reise (int cash)
        {
            Cash += cash;
            MoneyChanged?.Invoke($"\nПовышение зарплаты на {cash}");
        }

        public void Punishment(int cash)
        {
            Cash -= cash;
            MoneyChanged?.Invoke($"Штраф {cash}");
        }
    }
}
