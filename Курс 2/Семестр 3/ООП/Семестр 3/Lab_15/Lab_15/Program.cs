using System;
using System.Collections.Concurrent;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    static async Task Main()
    {
        Console.WriteLine("Выберите задачу для выполнения:");
        Console.WriteLine("1. Длительная задача (решето Эратосфена)");
        Console.WriteLine("2. Длительная задача с отменой (CancellationToken)");
        Console.WriteLine("3. Три задачи с возвратом результата");
        Console.WriteLine("4. Задача продолжения");
        Console.WriteLine("5. Распараллеливание циклов (Parallel.For)");
        Console.WriteLine("6. Parallel.Invoke");
        Console.WriteLine("7. BlockingCollection (поставщики и потребители)");
        Console.WriteLine("8. Async и Await");

        var choice = Console.ReadLine();
        switch (choice)
        {
            case "1":
                await LongTaskExample();
                break;
            case "2":
                await LongTaskWithCancellationExample();
                break;
            case "3":
                await TasksWithResultsExample();
                break;
            case "4":
                await ContinuationTaskExample();
                break;
            case "5":
                ParallelForExample();
                break;
            case "6":
                ParallelInvokeExample();
                break;
            case "7":
                await BlockingCollectionExample();
                break;
            case "8":
                await AsyncAwaitExample();
                break;
            default:
                Console.WriteLine("Неверный выбор");
                break;
        }
    }

    static async Task LongTaskExample()
    {
        int n = 1000000;
        Stopwatch stopwatch = new Stopwatch();

        var primeTask = Task.Run(() => FindPrimes(n));

        Console.WriteLine($"Task ID: {primeTask.Id}");
        stopwatch.Start();

        while (!primeTask.IsCompleted)
        {
            Console.WriteLine($"Task Status: {primeTask.Status}");
            await Task.Delay(500);
        }

        stopwatch.Stop();
        var primes = await primeTask;

        Console.WriteLine($"Task Status after completion: {primeTask.Status}");
        Console.WriteLine($"Elapsed Time: {stopwatch.ElapsedMilliseconds} ms");
        Console.WriteLine($"Total Primes Found: {primes.Length}");
    }

    static async Task LongTaskWithCancellationExample()
    {
        int n = 1000000;
        CancellationTokenSource cts = new CancellationTokenSource();

        Console.WriteLine("Press 'C' to cancel");
        _ = Task.Run(() =>
        {
            if (Console.ReadKey(true).KeyChar == 'C') cts.Cancel();
        });

        try
        {
            var primes = await FindPrimesAsync(n, cts.Token);
            Console.WriteLine($"Total Primes Found: {primes.Length}");
        }
        catch (OperationCanceledException)
        {
            Console.WriteLine("Task was canceled!");
        }
    }

    static async Task<int[]> FindPrimesAsync(int max, CancellationToken token)
    {
        return await Task.Run(() =>
        {
            token.ThrowIfCancellationRequested();
            bool[] isPrime = Enumerable.Repeat(true, max + 1).ToArray();
            isPrime[0] = isPrime[1] = false;

            for (int i = 2; i * i <= max; i++)
            {
                token.ThrowIfCancellationRequested();
                if (isPrime[i])
                {
                    for (int j = i * i; j <= max; j += i)
                    {
                        isPrime[j] = false;
                    }
                }
            }

            return Enumerable.Range(0, max + 1).Where(x => isPrime[x]).ToArray();
        }, token);
    }

    static async Task TasksWithResultsExample()
    {
        var task1 = Task.Run(() => 2 + 2);
        var task2 = Task.Run(() => 3 * 3);
        var task3 = Task.Run(() => 5 - 1);

        var resultTask = Task.WhenAll(task1, task2, task3);

        var results = await resultTask;
        int finalResult = results.Sum();
        Console.WriteLine($"Final Result: {finalResult}");
    }

    static async Task ContinuationTaskExample()
    {
        var task1 = Task.Run(() => 10);
        var task2 = Task.Run(() => 20);

        var continuation = Task.WhenAll(task1, task2).ContinueWith(t =>
        {
            var results = t.Result;
            return results.Sum();
        });

        Console.WriteLine($"Sum: {await continuation}");
    }

    static void ParallelForExample()
    {
        Parallel.For(0, 10, i =>
        {
            Console.WriteLine($"Task {i} started");
            Thread.Sleep(1000);
            Console.WriteLine($"Task {i} completed");
        });
    }

    static void ParallelInvokeExample()
    {
        Parallel.Invoke(
            () => Console.WriteLine("Task 1"),
            () => Console.WriteLine("Task 2"),
            () => Console.WriteLine("Task 3")
        );
    }

    static async Task BlockingCollectionExample()
    {
        BlockingCollection<string> warehouse = new BlockingCollection<string>(5);

        var producers = Enumerable.Range(1, 5).Select(i => Task.Run(() =>
        {
            while (true)
            {
                string item = $"Item-{i}-{Guid.NewGuid()}";
                warehouse.Add(item);
                Console.WriteLine($"Producer {i} added: {item}");
                Thread.Sleep(1000);
            }
        }));

        var consumers = Enumerable.Range(1, 10).Select(i => Task.Run(() =>
        {
            foreach (var item in warehouse.GetConsumingEnumerable())
            {
                Console.WriteLine($"Consumer {i} bought: {item}");
                Thread.Sleep(500);
            }
        }));

        await Task.WhenAll(producers.Concat(consumers));
    }

    static async Task AsyncAwaitExample()
    {
        await DoWorkAsync();
        Console.WriteLine("Work Completed");
    }

    static async Task DoWorkAsync()
    {
        Console.WriteLine("Starting Work...");
        await Task.Delay(2000);
        Console.WriteLine("Work Finished");
    }

    static int[] FindPrimes(int max)
    {
        bool[] isPrime = Enumerable.Repeat(true, max + 1).ToArray();
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= max; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= max; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        return Enumerable.Range(0, max + 1).Where(x => isPrime[x]).ToArray();
    }
}
