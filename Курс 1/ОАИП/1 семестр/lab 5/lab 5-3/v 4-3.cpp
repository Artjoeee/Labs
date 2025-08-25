#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");

	int a, b;

	puts("Привет! (1-Здравствуй, 2-Отстань)");
	cin >> a;

	switch (a)
	{
		case 1: puts("Как дела? (1-Всё хорошо, 2-Всё плохо..., 3-Не твоё дело!)");
			cin >> b;

			switch (b)
			{
				case 1: puts("Отлично! Рад за тебя!");
					break;

				case 2: puts("Это ужасно");
					break;

				case 3: puts("Прости...");
					break;

				default: puts("Что ты сказал?");
					break;
			}

			break;

		case 2: puts("Ну ладно");
			break;

		default: puts("Я тебя не понимаю");
			break;
	}

	return 0;
}