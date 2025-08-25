using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_12
{
    // 1. Класс для работы с логом
    public static class ZAILog
    {
        private static readonly string logFilePath = "zailogfile.txt";

        public static void WriteLog(string action, string details)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(logFilePath, true))
                {
                    writer.WriteLine($"[{DateTime.Now}] Действие: {action}, Детали: {details}");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка записи в log: {ex.Message}");
            }
        }

        public static void SearchLogByDate(DateTime date)
        {
            try
            {
                using (StreamReader reader = new StreamReader(logFilePath))
                {
                    string line;
                    int count = 0;

                    while ((line = reader.ReadLine()) != null)
                    {
                        if (line.Contains(date.ToString("dd.MM.yyyy")))
                        {
                            Console.WriteLine(line);
                            count++;
                        }
                    }
                    Console.WriteLine($"Найдено {count} записей за {date:dd.MM.yyyy}.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка поиска в log: {ex.Message}");
            }
        }

        public static void SearchLogByKeyword(string keyword)
        {
            try
            {
                using (StreamReader reader = new StreamReader(logFilePath))
                {
                    string line;
                    int count = 0;

                    while ((line = reader.ReadLine()) != null)
                    {
                        if (line.Contains(keyword))
                        {
                            Console.WriteLine(line);
                            count++;
                        }
                    }
                    Console.WriteLine($"Найдено {count} записей со словом '{keyword}'.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка поиска в log: {ex.Message}");
            }
        }
    }

    // 2. Класс для работы с дисками
    public static class ZAIDiskInfo
    {
        public static void DisplayDiskInfo()
        {
            try
            {
                foreach (var drive in DriveInfo.GetDrives())
                {
                    if (drive.IsReady)
                    {
                        Console.WriteLine($"Диск: {drive.Name}");
                        Console.WriteLine($"  Метка тома: {drive.VolumeLabel}");
                        Console.WriteLine($"  Файловая система: {drive.DriveFormat}");
                        Console.WriteLine($"  Размер диска: {drive.TotalSize} байт");
                        Console.WriteLine($"  Свободное место: {drive.TotalFreeSpace} байт");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка вывода информации о диске: {ex.Message}");
            }
        }
    }

    // 3. Класс для работы с файлами
    public static class ZAIFileInfo
    {
        public static void DisplayFileInfo(string filePath)
        {
            try
            {
                FileInfo fileInfo = new FileInfo(filePath);
                if (fileInfo.Exists)
                {
                    Console.WriteLine($"Полный путь: {fileInfo.FullName}");
                    Console.WriteLine($"Размер: {fileInfo.Length} байт");
                    Console.WriteLine($"Расширение: {fileInfo.Extension}");
                    Console.WriteLine($"Дата создания: {fileInfo.CreationTime}");
                    Console.WriteLine($"Последнее изменение: {fileInfo.LastWriteTime}");
                }
                else
                {
                    Console.WriteLine("Файл не существует.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка вывода информации о файле: {ex.Message}");
            }
        }
    }

    // 4. Класс для работы с директориями
    public static class ZAIDirInfo
    {
        public static void DisplayDirectoryInfo(string directoryPath)
        {
            try
            {
                DirectoryInfo dirInfo = new DirectoryInfo(directoryPath);
                if (dirInfo.Exists)
                {
                    Console.WriteLine($"Директория: {dirInfo.FullName}");
                    Console.WriteLine($"Количество файлов: {dirInfo.GetFiles().Length}");
                    Console.WriteLine($"Поддиректории: {dirInfo.GetDirectories().Length}");
                    Console.WriteLine($"Дата создания: {dirInfo.CreationTime}");
                    Console.WriteLine($"Родительская директория: {dirInfo.Parent?.FullName}");
                }
                else
                {
                    Console.WriteLine("Директории не существует.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка вывода информации о директории: {ex.Message}");
            }
        }
    }

    // 5. Класс FileManager
    public static class ZAIFileManager
    {
        public static void InspectDirectory(string path)
        {
            try
            {
                string inspectDir = Path.Combine(path, "ZAIInspect");
                Directory.CreateDirectory(inspectDir);

                string infoFile = Path.Combine(inspectDir, "zaidirinfo.txt");
                using (StreamWriter writer = new StreamWriter(infoFile))
                {
                    foreach (var file in Directory.GetFiles(path))
                        writer.WriteLine(file);

                    foreach (var dir in Directory.GetDirectories(path))
                        writer.WriteLine(dir);
                }

                string copiedFile = Path.Combine(inspectDir, "copied.txt");
                File.Copy(infoFile, copiedFile);
                File.Delete(infoFile);

                ZAILog.WriteLog("InspectDirectory", $"Завершена проверка директории {path}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка проверки директории: {ex.Message}");
            }
        }

        public static void ArchiveFiles(string sourceDir, string archivePath)
        {
            try
            {
                if (Directory.Exists(sourceDir))
                {
                    ZipFile.CreateFromDirectory(sourceDir, archivePath);
                    ZAILog.WriteLog("ArchiveFiles", $" {sourceDir} архивировано в {archivePath}");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка архивирования файлов: {ex.Message}");
            }
        }

        public static void ExtractArchive(string archivePath, string extractPath)
        {
            try
            {
                ZipFile.ExtractToDirectory(archivePath, extractPath);
                ZAILog.WriteLog("ExtractArchive", $"{archivePath} распакован в {extractPath}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка распаковки архива: {ex.Message}");
            }
        }
    }
}
