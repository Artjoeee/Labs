using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab_12
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Логирование
            ZAILog.WriteLog("Старт", "Запуск программы");

            // Диск
            ZAIDiskInfo.DisplayDiskInfo();

            // Файл
            string testFile = "test.txt";
            File.WriteAllText(testFile, "Hello, World!");
            ZAIFileInfo.DisplayFileInfo(testFile);

            // Директория
            ZAIDirInfo.DisplayDirectoryInfo(Environment.CurrentDirectory);

            // FileManager
            ZAIFileManager.InspectDirectory(Environment.CurrentDirectory);

            // Архивирование
            string sourceDir = Path.Combine(Environment.CurrentDirectory, "ZAIInspect");
            string archivePath = "archive.zip";
            ZAIFileManager.ArchiveFiles(sourceDir, archivePath);
            ZAIFileManager.ExtractArchive(archivePath, "Extracted");

            ZAILog.WriteLog("Конец", "Завершение программы");

            ZAILog.SearchLogByDate(DateTime.Now);
            ZAILog.SearchLogByKeyword("Старт");
        }
    }
}
