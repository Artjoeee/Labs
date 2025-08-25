#include "Error.h"		// Обработка ошибок
#include "Parm.h"		// Обработка параметров
#include "Log.h"		// Работв с протоколом
#include "In.h"			// Ввод исходного файла
#include "Out.h"		// Вывод обработанного файла

int _tmain(int argc, _TCHAR* argv[]) 
{
	setlocale(LC_ALL, "ru");

	/*argv[0] = (_TCHAR*)L"-in:C:\\Users\\HomeUser\\Desktop\\КПО\\SE_Lab14\\x64\\Debug\\in.txt";*/

	//-----------------------------------------------------------------------------------
	 
	/*cout << "---- тест Error::geterror ----\n\n";

	try 
	{
		throw ERROR_THROW(100);
	}
	catch (Error::ERROR e) 
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
	}*/

	/*cout << "---- тест Error::geterrorin ----\n\n";

	try 
	{
		throw ERROR_THROW_IN(111, 7, 7);
	}
	catch (Error::ERROR e) 
	{
		cout << "Ошибка " << e.id << ": " << e.message 
			<< ", строка " << e.inext.line 
			<< ", позиция " << e.inext.col << endl << endl;
	}*/
	 
	//-----------------------------------------------------------------------------------
	
	/*cout << "---- тест Parm::getparm ----\n\n";

	try 
	{
		Parm::PARM parm = Parm::getparm(argc, argv);

		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << endl << endl;
	}
	catch (Error::ERROR e) 
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
	}*/
	 
	//-----------------------------------------------------------------------------------

	/*cout << "---- тест In::getin ----\n\n";

	try 
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);

		cout << in.text << endl;

		cout << "Всего символов: " << in.size << endl;
		cout << "Всего строк: " << in.lines << endl;
		cout << "Пропущено: " << in.ignor << endl;
	}
	catch (Error::ERROR e) 
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
	}*/

	//-----------------------------------------------------------------------------------

	cout << "---- тест In::getin ----\n\n";

	try 
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);

		cout << in.text << endl;

		cout << "Всего символов: " << in.size << endl;
		cout << "Всего строк: " << in.lines << endl;
		cout << "Пропущено: " << in.ignor << endl;
	}
	catch (Error::ERROR e) 
	{
		cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
		cout << "строка " << e.inext.line << " позиция " << e.inext.col << endl << endl;
	}

	//-----------------------------------------------------------------------------------

	Log::LOG log = Log::INITLOG;

	try 
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);

		Log::WriteLine(log, (char*)"Тест:", (char*)" без ошибок \n", "");
		Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L" без ошибок \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);

		In::IN in = In::getin(parm.in);

		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e) 
	{
		Log::WriteError(log, e);
	}

	//-----------------------------------------------------------------------------------

	Out::OUT out = Out::INITOUT;

	try 
	{
		Parm::PARM parm = Parm::getparm(argc, argv);

		out = Out::getout(parm.out);

		In::IN in = In::getin(parm.in);

		Out::WriteInOut(out, in);
	}
	catch (Error::ERROR e)
	{
		Out::WriteErrorOut(out, e);
	};

	system("pause");

	return 0;
}