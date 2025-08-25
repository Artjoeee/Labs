using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        // Выберите нужную задачу для выполнения
        Console.WriteLine("Выберите задачу:");
        Console.WriteLine("1. Вывести процессы");
        Console.WriteLine("2. Работа с доменом");
        Console.WriteLine("3. Поток: Простые числа");
        Console.WriteLine("4. Два потока: Четные/Нечетные");
        Console.WriteLine("5. Таймер");
        Console.WriteLine("6. Задачи повышенного уровня");

        switch (Console.ReadLine())
        {
            case "1": ListProcesses(); break;
            case "2": ManageAppDomain(); break;
            case "3": ThreadPrimes(); break;
            case "4": EvenOddThreads(); break;
            case "5": TimerTask(); break;
            case "6": AdvancedTasks(); break;
            default: Console.WriteLine("Некорректный выбор."); break;
        }
    }

    static void ListProcesses()
    {
        foreach (var process in Process.GetProcesses())
        {
            try
            {
                Console.WriteLine($"ID: {process.Id}, Name: {process.ProcessName}, Priority: {process.BasePriority}, StartTime: {process.StartTime}, State: {(process.Responding ? "Running" : "Not Responding")}, CPU Time: {process.TotalProcessorTime}");
            }
            catch
            {
                Console.WriteLine($"ID: {process.Id}, Name: {process.ProcessName}, (Access Denied)");
            }
        }
    }

    static void ManageAppDomain()
    {
        AppDomain currentDomain = AppDomain.CurrentDomain;
        Console.WriteLine("Current Domain: " + currentDomain.FriendlyName);

        foreach (Assembly assembly in currentDomain.GetAssemblies())
        {
            Console.WriteLine("Assembly: " + assembly.FullName);
        }

        AppDomain newDomain = AppDomain.CreateDomain("NewDomain");
        Console.WriteLine("New Domain Created: " + newDomain.FriendlyName);

        newDomain.DoCallBack(() => Console.WriteLine("Hello from New Domain!"));
        AppDomain.Unload(newDomain);
        Console.WriteLine("New Domain Unloaded");
    }

    static void ThreadPrimes()
    {
        Console.Write("Введите n: ");
        int n = int.Parse(Console.ReadLine());
        Thread thread = new Thread(() => CalculatePrimes(n));
        thread.Start();
        thread.Join(); // Дождемся завершения
    }

    static void CalculatePrimes(int n)
    {
        using (StreamWriter writer = new StreamWriter("primes.txt"))
        {
            for (int i = 2; i <= n; i++)
            {
                if (IsPrime(i))
                {
                    Console.WriteLine(i);
                    writer.WriteLine(i);
                    Thread.Sleep(100); // Задержка
                }
            }
        }
    }

    static bool IsPrime(int number)
    {
        if (number < 2) return false;
        for (int i = 2; i <= Math.Sqrt(number); i++)
            if (number % i == 0) return false;
        return true;
    }

    static void EvenOddThreads()
    {
        Console.Write("Введите n: ");
        int n = int.Parse(Console.ReadLine());

        using (StreamWriter writer = new StreamWriter("even_odd.txt"))
        {
            object lockObj = new object();
            Thread evenThread = new Thread(() => PrintNumbers(0, n, 2, lockObj, writer));
            Thread oddThread = new Thread(() => PrintNumbers(1, n, 2, lockObj, writer));

            evenThread.Start();
            oddThread.Start();

            evenThread.Join();
            oddThread.Join();
        }
    }

    static void PrintNumbers(int start, int n, int step, object lockObj, StreamWriter writer)
    {
        for (int i = start; i <= n; i += step)
        {
            lock (lockObj)
            {
                Console.WriteLine(i);
                writer.WriteLine(i);
                Thread.Sleep(100); // Разная скорость потоков
            }
        }
    }

    static void TimerTask()
    {
        Timer timer = new Timer(state => Console.WriteLine($"Timer Tick: {DateTime.Now}"), null, 0, 1000);
        Console.WriteLine("Нажмите любую клавишу для завершения...");
        Console.ReadKey();
    }

    static void AdvancedTasks()
    {
        Console.WriteLine("Дополнительные задачи:");
        Console.WriteLine("1. Машины на складе");
        Console.WriteLine("2. Пул ресурсов");

        switch (Console.ReadLine())
        {
            case "1": WarehouseSimulation(); break;
            case "2": ResourcePoolSimulation(); break;
            default: Console.WriteLine("Некорректный выбор."); break;
        }
    }

    static void WarehouseSimulation()
    {
        int stock = 100;
        object stockLock = new object();

        void LoadUnloadMachine(string name, int speed)
        {
            while (true)
            {
                lock (stockLock)
                {
                    if (stock > 0)
                    {
                        stock--;
                        Console.WriteLine($"{name} unloaded one item. Stock: {stock}");
                    }
                    else
                    {
                        Console.WriteLine($"{name} finished. Stock empty.");
                        break;
                    }
                }
                Thread.Sleep(speed);
            }
        }

        Thread machine1 = new Thread(() => LoadUnloadMachine("Machine 1", 100));
        Thread machine2 = new Thread(() => LoadUnloadMachine("Machine 2", 200));
        Thread machine3 = new Thread(() => LoadUnloadMachine("Machine 3", 150));

        machine1.Start();
        machine2.Start();
        machine3.Start();

        machine1.Join();
        machine2.Join();
        machine3.Join();
    }

    static void ResourcePoolSimulation()
    {
        Semaphore semaphore = new Semaphore(2, 2); // Максимум 2 канала

        void ClientTask(string name)
        {
            Console.WriteLine($"{name} is waiting for a resource.");
            if (semaphore.WaitOne(5000)) // Ждем максимум 5 секунд
            {
                Console.WriteLine($"{name} acquired a resource.");
                Thread.Sleep(2000); // Использование ресурса
                Console.WriteLine($"{name} released a resource.");
                semaphore.Release();
            }
            else
            {
                Console.WriteLine($"{name} timed out waiting for a resource.");
            }
        }

        List<Thread> clients = new List<Thread>();
        for (int i = 1; i <= 5; i++)
        {
            int clientId = i;
            clients.Add(new Thread(() => ClientTask($"Client {clientId}")));
        }

        clients.ForEach(client => client.Start());
        clients.ForEach(client => client.Join());
    }
}
