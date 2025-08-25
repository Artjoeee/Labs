#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

void generateField()
{
    int grid[12][12]{}; // ������ ��� �������� ��������� ��� �� ����
    int sgrid[12][12]{}; // ������ ��� �������� ��������� �������� ����, �������� ������

    // ��������� ��������� ��� � ������ ���������� ��� ������ ������ ������
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            sgrid[i][j] = 10; // �������� ������
            if (rand() % 5 == 0)
                grid[i][j] = 9; // ����
            else
                grid[i][j] = 0; // ������ ������
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
            grid[i][j] = n; // ���������� ��� ������ ������
        }
}

int main()
{
    srand(time(0)); // ������������� ���������� ��������� ����� �� ������ �������� �������

    RenderWindow window(VideoMode(400, 400), "Minesweeper!"); // �������� ���� �������� 400x400 �������� � ���������� "Minesweeper!"

    int w = 32; // ������ ������ ������ � ��������
    int grid[12][12]{}; // ������ ��� �������� ��������� ��� �� ����
    int sgrid[12][12]{}; // ������ ��� �������� ��������� �������� ����, �������� ������

    Texture t;
    t.loadFromFile("C:\Titles.jpg"); // �������� �������� ��� ����������� ������
    Sprite tiles(t); // �������� ������� ��� ����������� ��������
    
    window.display(); // ����������� ������������� �� ������

    return 0;
}

#include "Game.h"

Game::Game()
    : window(sf::VideoMode(600, 600), "Minesweeper!")
{
    srand(time(0));

    texture.loadFromFile("d:/�����/tiles.png");
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