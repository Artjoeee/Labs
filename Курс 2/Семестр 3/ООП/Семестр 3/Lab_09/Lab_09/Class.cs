using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Lab_09
{
    public class Worker
    {
        public string Name { get; set; }
        public int Salary { get; set; }

        public Worker(string name, int salary) 
        {
            Name = name;
            Salary = salary;
        }

        public override string ToString()
        {
            return $"{Name}: {Salary}";
        }
    }

    public class WorkerHashtable : IEnumerable<Worker>
    {
        private readonly Hashtable hashtable = new Hashtable();

        public delegate void WorkerDelegate(string message);
        public event WorkerDelegate CollectionChange;

        public void Add(Worker worker) 
        {
            hashtable.Add(worker.Name, worker);
            CollectionChange?.Invoke($"Добавлен {worker}");
        }

        public void Remove(string name) 
        {
            hashtable.Remove(name);
            CollectionChange?.Invoke($"Удален {name}\n");
        }

        public bool ContainsKey(string name) 
        {
            return hashtable.ContainsKey(name);
        }

        public IEnumerator<Worker> GetEnumerator()
        {
            foreach (DictionaryEntry item in hashtable)
            {
                yield return (Worker)item.Value;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
