using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_07
{
    public interface IGeneralization<T>
    {
        void Add(T item);

        void Remove(T item);

        bool View(T item);
    }
}
