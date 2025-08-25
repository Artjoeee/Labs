#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

void generateField()
{
    int grid[12][12]{}; // Массив для хранения состояния мин на поле
    int sgrid[12][12]{}; // Массив для хранения состояния игрового поля, видимого игроку

    // Генерация случайных мин и расчет количества мин вокруг каждой клетки
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            sgrid[i][j] = 10; // Закрытая клетка
            if (rand() % 5 == 0)
                grid[i][j] = 9; // Мина
            else
                grid[i][j] = 0; // Пустая клетка
        }

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            int n = 0;
            if (grid[i][j] == 9)
                continue;
            if (grid[i + 1][j] == 9)
                n++;
            if (grid[i][j + 1] == 9)
                n++;
            if (grid[i - 1][j] == 9)
                n++;
            if (grid[i][j - 1] == 9)
                n++;
            if (grid[i + 1][j + 1] == 9)
                n++;
            if (grid[i - 1][j - 1] == 9)
                n++;
            if (grid[i - 1][j + 1] == 9)
                n++;
            if (grid[i + 1][j - 1] == 9)
                n++;
            grid[i][j] = n; // Количество мин вокруг клетки
        }
}

int main()
{
    srand(time(0)); // Инициализация генератора случайных чисел на основе текущего времени

    RenderWindow window(VideoMode(400, 400), "Minesweeper!"); // Создание окна размером 400x400 пикселей с заголовком "Minesweeper!"

    int w = 32; // Размер каждой клетки в пикселях
    int grid[12][12]{}; // Массив для хранения состояния мин на поле
    int sgrid[12][12]{}; // Массив для хранения состояния игрового поля, видимого игроку

    Texture t;
    t.loadFromFile("C:\Titles.jpg"); // Загрузка текстуры для отображения клеток
    Sprite tiles(t); // Создание спрайта для отображения текстуры
    
    window.display(); // Отображение нарисованного на экране

    return 0;
}

#include "Game.h"

Game::Game()
    : window(sf::VideoMode(600, 600), "Minesweeper!")
{
    srand(time(0));

    texture.loadFromFile("d:/учёба/tiles.png");
    tiles.setTexture(texture);

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            sgrid[i][j] = 10;

            if (rand() % 5 == 0)
                grid[i][j] = 9;

            else
                grid[i][j] = 0;
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int n = 0;

            if (grid[i][j] == 9)
                continue;
            if (grid[i + 1][j] == 9)
                n++;
            if (grid[i][j + 1] == 9)
                n++;
            if (grid[i - 1][j] == 9)
                n++;
            if (grid[i][j - 1] == 9)
                n++;
            if (grid[i + 1][j + 1] == 9)
                n++;
            if (grid[i - 1][j - 1] == 9)
                n++;
            if (grid[i - 1][j + 1] == 9)
                n++;
            if (grid[i + 1][j - 1] == 9)
                n++;

            grid[i][j] = n;
        }
    }
}