using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_09
{
    internal class Program
    {
        static void Main(string[] args)
        {
            WorkerHashtable hashtable = new WorkerHashtable();
            

            Worker worker1 = new Worker("Василий", 1000);
            Worker worker2 = new Worker("Евгений", 2000);
            Worker worker3 = new Worker("Владимир", 3000);
            Worker worker4 = new Worker("Анатолий", 4000);

            hashtable.Add(worker1);
            hashtable.Add(worker2);
            hashtable.Add(worker3);
            hashtable.Add(worker4);

            hashtable.Remove("Евгений");

            Console.WriteLine(hashtable.ContainsKey("Владимир"));

            foreach (Worker worker in hashtable)
            {
                Console.WriteLine(worker);
            }

            Console.WriteLine();

            List<int> list = new List<int>(new List<int> { 1, 2, 3 });

            foreach (var item in list)
            {
                Console.WriteLine(item);
            }
            Console.WriteLine();

            list.RemoveRange(0, list.Count - 1);

            list.Add(52);
            list.AddRange(list);

            foreach (var item in list)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine();

            HashSet<int> set = new HashSet<int>(list);

            foreach (var item in set)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine(set.Contains(52));

            ObservableCollection<Worker> collection = new ObservableCollection<Worker>();

            collection.CollectionChanged += DisplayMessage;

            Console.WriteLine();

            collection.Add(worker1);
            collection.Add(worker2);

            collection.Remove(worker1);

            foreach (var item in collection)
            {
                Console.WriteLine(item);
            }

            void DisplayMessage(object sender, NotifyCollectionChangedEventArgs e)
            {
                switch (e.Action)
                {
                    case NotifyCollectionChangedAction.Add:
                        if (e.NewItems?[0] is Worker newWorker)
                            Console.WriteLine($"Добавлен новый объект: {newWorker.Name}");
                        break;
                    case NotifyCollectionChangedAction.Remove:
                        if (e.OldItems?[0] is Worker oldWorker)
                            Console.WriteLine($"Удален объект: {oldWorker.Name}");
                        break;
                }
            }
        }
    }
}
