#include "FST.h"

using namespace std;

int _tmain(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	char str[] = "abobbnbcbbbbbf";

	FST::FST fst(		// Недетерминированный конечный автомат
		str,			// Цепочка для распознавания
		9,				// Количество состояний
		FST::NODE(1, FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(6, FST::RELATION('b', 2), FST::RELATION('c', 3), FST::RELATION('o', 4), FST::RELATION('n', 5), FST::RELATION('b', 7), FST::RELATION('f', 8)),
		FST::NODE(1, FST::RELATION('b', 6)),
		FST::NODE(1, FST::RELATION('b', 6)),
		FST::NODE(1, FST::RELATION('b', 6)),
		FST::NODE(6, FST::RELATION('b', 6), FST::RELATION('b', 7), FST::RELATION('c', 3), FST::RELATION('o', 4), FST::RELATION('n', 5), FST::RELATION('f', 8)),
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('f', 8)),
		FST::NODE()
		);

	if (FST::execute(fst)) // Выполнить разбор
		cout << "Цепочка " << fst.string << " распознана" << endl;
	else 
		cout << "Цепочка " << fst.string << " не распознана" << endl;

	system("pause");
	return 0;
}