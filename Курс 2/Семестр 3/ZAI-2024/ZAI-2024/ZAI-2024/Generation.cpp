#include "Generation.h"
#include <sstream>
#include <cstring>
#include <iosfwd>
#include <xstring>

using namespace std;

namespace Gener
{
	static int conditionnum = 0;

	string itoS(int x) 
	{
		stringstream r;  r << x;  return r.str(); 
	}

	string genCallFuncCode(Lex::LEX& tables, Log::LOG& log, int i)
	{
		string str;

		IT::Entry e = ITENTRY(i);

		stack <IT::Entry> temp;

		for (int j = i + 2; LEXEMA(j) != LEX_RIGHTTHESIS; j++)
		{
			if (LEXEMA(j) == LEX_LEFTTHESIS)
				continue;

			if (LEXEMA(j + 2) == LEX_ID || LEXEMA(j) == LEX_LITERAL)
			{
				temp.push(ITENTRY(j));
			}
		}

		str += "\n";

		str = str + "call " + reinterpret_cast<char*>((e.id)) + IN_CODE_ENDL;

		return str;
	}

	string genEqualCode(Lex::LEX& tables, Log::LOG& log, int i)
	{
		string str;

		IT::Entry e1 = ITENTRY(i - 1);

		switch (e1.iddatatype)
		{
		case IT::IDDATATYPE::SHR:
		{
			bool first = true;

			for (int j = i + 1; LEXEMA(j) != LEX_SEMICOLON; j++)
			{
				switch (tables.lextable.table[j].lexema)
				{
				case LEX_LITERAL:
				case LEX_ID:
				{
					IT::Entry entry = tables.idtable.table[tables.lextable.table[j].idxTI];

					if (entry.idtype == IT::IDTYPE::F)
					{
						str += genCallFuncCode(tables, log, j);
						str += "push eax\n";

						while (LEXEMA(j) != LEX_RIGHTTHESIS) j++;
						break;
					}
					else
					{
						str = str + "push " + reinterpret_cast<char*>(entry.id) + "\n";
					}
					break;
				}
				case LEX_OPERATOR:
				{
					switch (ITENTRY(j).id[0])
					{
					case '+':
						str += "pop bx\npop ax\nadd ax, bx\npush ax\n"; break;
					case '-':
						str += "pop bx\npop ax\nsub ax, bx\npush ax\n"; break;
					case '*':
						str += "pop bx\npop ax\nimul ax, bx\npush ax\n"; break;
					case '/':
						str += "\npop bx\npop ax\ntest bx, bx\njz EXIT_DIV_ON_NULL\ncdq\nidiv bx\npush ax\n"; break;
					case '%':
						str += "\npop bx\npop ax\ntest bx, bx\njz EXIT_DIV_ON_NULL\ncdq\nidiv bx\npush dx\n"; break;
					default:
						break;
					}

					break;
				}
				case '@':
				{
					str = str + "call " + reinterpret_cast<char*>(ITENTRY(j).id) + "\npush ax\n";
					break;
				}
				}
			}

			str = str + "\npop bx\nmov " + reinterpret_cast<char*>(e1.id) + ", bx\n";
			break;
		}
		case IT::IDDATATYPE::STR:
		{
			char lex = LEXEMA(i + 1);

			IT::Entry e2 = ITENTRY(i + 1);

			if (lex == LEX_ID && (e2.idtype == IT::IDTYPE::F))
			{
				str += genCallFuncCode(tables, log, i + 1);
				str = str + "mov " + reinterpret_cast<char*>(e1.id) + ", ax";
			}
			else if (lex == LEX_LITERAL)
			{
				str = str + "mov " + reinterpret_cast<char*>(e1.id) + ", offset " + reinterpret_cast<char*>(e2.id);
			}
			else
			{
				str = str + "mov ecx, " + reinterpret_cast<char*>(e2.id) + "\nmov " + reinterpret_cast<char*>(e1.id) + ", ecx";
			}

			break;
		}
		case IT::IDDATATYPE::CHR:
		{
			char lex = LEXEMA(i + 1);
			IT::Entry e2 = ITENTRY(i + 1);

			if (lex == LEX_LITERAL)
			{
				str = str + "mov byte ptr [" + reinterpret_cast<char*>(e1.id) + "], '" + e2.value.vchar + "'\n";
				str = str + "mov byte ptr [" + reinterpret_cast<char*>(e1.id) + " + 1], 0";
			}
			else
			{
				str = str + "mov al, byte ptr [" + reinterpret_cast<char*>(e2.id) + "]\n";
				str = str + "mov byte ptr [" + reinterpret_cast<char*>(e1.id) + "], al\n";
				str = str + "mov byte ptr [" + reinterpret_cast<char*>(e1.id) + " + 1], 0";
			}

			break;
		}
		case IT::IDDATATYPE::BOOL:
		{
			char lex = LEXEMA(i + 1);
			IT::Entry e2 = ITENTRY(i + 1);

			str = str + "mov al, byte ptr [" + reinterpret_cast<char*>(e2.id) + "]\nmov [" + reinterpret_cast<char*>(e1.id) + "], al\n";
			break;
		}
		}

		return str;
	}


	string genIFCode(Lex::LEX& tables, Log::LOG& log, int i, string napr)
	{
		string str;

		bool first = true;

		for (int j = i + 1; LEXEMA(j) != LEX_LOGOPERATOR && LEXEMA(j) != LEX_ENDIF && LEXEMA(j) != LEX_AND; j++)
		{
			switch (LEXEMA(j))
			{
				case LEX_LITERAL:
				case LEX_ID:
				{
					if (ITENTRY(j).idtype == IT::IDTYPE::F)
					{
						str += genCallFuncCode(tables, log, j);
						str += "push ax\n";

						while (LEXEMA(j) != LEX_RIGHTTHESIS) 
							j++;
						break;
					}
					else  
						str = str + "push " + reinterpret_cast<char*>(ITENTRY(j).id) + "\n";
					break;
				}
				case LEX_OPERATOR: 
				{
					switch (ITENTRY(j).id[0])
					{
						case '+':
							str += "pop bx\npop ax\nadd ax, bx\npush ax\n"; break;
						case '-':
							str += "pop bx\npop ax\nsub ax, ebx\npush ax\n"; break;
						case '*':
							str += "pop bx\npop ax\nimul ax, bx\npush ax\n"; break;
						case '/':
							str += "\npop bx\npop ax\ntest bx, bx\njz EXIT_DIV_ON_NULL\ncdq\nmov\tedx, \t0\nidiv ebx\npush ax"; break;
						case '%':
							str += "\npop bx\npop ax\ntest bx, bx\njz EXIT_DIV_ON_NULL\ncdq\nmov\tedx, \t0\nidiv ebx\npush dx"; break;
						default:
							break;
					}
				}
			}
		}

		str = str + "\npop bx\nmov " + napr + ", bx\n";

		return str;
	}

	string genFunctionCode(Lex::LEX& tables, int i, string funcname, int pcount)
	{
		string str;

		IT::Entry e = ITENTRY(i + 1);
		IT::IDDATATYPE type = e.iddatatype;

		str = str + reinterpret_cast<char*>(e.id) + string(" PROC,\n");

		int j = i + 3;

		while (LEXEMA(j) != LEX_RIGHTTHESIS)
		{
			if (LEXEMA(j) == LEX_ID)
			{
				IT::IDDATATYPE paramType = ITENTRY(j).iddatatype;

				if (paramType == IT::IDDATATYPE::SHR || paramType == IT::IDDATATYPE::SHR16 || paramType == IT::IDDATATYPE::SHR2)
				{
					str =  str + "\t" + reinterpret_cast<char*>(ITENTRY(j).id) + " : sdword, ";
				}
				else
				{
					str = str + "\t" + reinterpret_cast<char*>(ITENTRY(j).id) + " : word, ";
				}
			}

			j++;
		}

		int f = str.rfind(',');

		if (f > 0)
			str[f] = ' ';

		str += "\npush bx\npush dx";

		return str;
	}

	string genExitCode(Lex::LEX& tables, int i, string funcname, int pcount)
	{
		string str = "\npop dx\npop bx\n";

		if (LEXEMA(i + 1) != LEX_SEMICOLON)
		{
			str = str + "mov ax, " + reinterpret_cast<char*>(ITENTRY(i + 1).id) + "\n";
		}

		str += "ret\n";
		str += funcname + " ENDP\n";

		return str;
	}

	string genConditionCode(Lex::LEX& tables, int i, string& cyclecode)
	{
		string str;
		string buf;

		conditionnum++;

		cyclecode.clear();

		bool t = false, f = false;

		string wstr, rstr;

		int u = 0;

		for (int j = i; LEXEMA(j) != ':'; j--) 
		{ 
			u = j;
		}

		str = str + "mov dx, " + "left" + "\ncmp dx, " + "right" + "\n";

		switch (ITENTRY(i).id[0]) {
		case '>':
			rstr = "jg";
			wstr = "jle";
			break;
		case '<':
			rstr = "jl";
			wstr = "jge";
			break;
		case '~':
			rstr = "jz";
			wstr = "jnz";
			break;
		case '!':
			rstr = "jnz";
			wstr = "jz";
			break;
		}

		// Проходим по таблице лексем, чтобы определить состояние ветвей
		for (int j = i + 1; tables.lextable.table[j - 2].lexema != LEX_BRACELET; j++) {
			if (tables.lextable.table[j].lexema == LEX_ENDIF) {
				t = true; // Условие "истинно"
			}
			if (tables.lextable.table[j].lexema == LEX_ASK) {
				f = true; // Условие "ложно"
			}
		}

		// Генерация кода для условных переходов
		if (t) str += "\n" + rstr + " right" + itoS(conditionnum);   // Переход при истинном условии
		if (f) str += "\n" + wstr + " wrong" + itoS(conditionnum);   // Переход при ложном условии
		if (t && !f) str += "\njmp next" + itoS(conditionnum);       // Переход на следующую инструкцию, если есть только "истинная" ветка
		if (t) str += "\nright" + itoS(conditionnum) + ":";          // Метка для "истинной" ветки

		return str;

	}

	vector <string> startFillVector(Lex::LEX& tables)
	{
		vector <string> v;
		v.push_back(BEGIN);
		v.push_back(EXTERN);

		vector <string> vlt;
		vlt.push_back(CONST);

		vector <string> vid;
		vid.push_back(DATA);

		for (int i = 0; i < tables.idtable.size; i++)
		{
			IT::Entry e = tables.idtable.table[i];
			string str = reinterpret_cast<char*>(e.id);

			if (tables.idtable.table[i].idtype == IT::IDTYPE::L) // Литералы
			{
				switch (e.iddatatype)
				{
					case IT::IDDATATYPE::SHR:
						str = "\t" + str + " sword " + itoS(e.value.vint);
						break;
					case IT::IDDATATYPE::STR:
						str = "\t" + str + " byte '" + reinterpret_cast<char*>(e.value.vstr.str) + "', 0";
						break;
					case IT::IDDATATYPE::CHR:
						str = "\t" + str + " byte '" + e.value.vchar + "', 0";
						break;
					case IT::IDDATATYPE::BOOL:
						str = "\t" + str + " byte " + (e.value.vbool ? "1" : "0");
						break;
				}

				vlt.push_back(str);
			}
			else if (tables.idtable.table[i].idtype == IT::IDTYPE::V) // Переменные
			{
				switch (e.iddatatype)
				{
					case IT::IDDATATYPE::SHR:
						str = "\t" + str + " sword 0";
						break;
					case IT::IDDATATYPE::STR:
						str = "\t" + str + " dword ?";
						break;
					case IT::IDDATATYPE::CHR:
						str = "\t" + str + " byte 0";
						break;
					case IT::IDDATATYPE::BOOL:
						str = "\t" + str + " byte 0";
						break;
				}

				vid.push_back(str);
			}
		}

		// Дополнительные переменные
		string str = "\tleft word ?\n\tright word ?\n\tresult sword ?\n\tresult_str byte 4 dup(0)";

		vid.push_back(str);

		// Объединение секций
		v.insert(v.end(), vlt.begin(), vlt.end());
		v.insert(v.end(), vid.begin(), vid.end());
		v.push_back(CODE);

		return v;
	}

	void CodeGeneration(Lex::LEX& tables, Parm::PARM& parm, Log::LOG& log)
	{
		vector <string> v = startFillVector(tables);
		ofstream ofile;

		ofile.open("..\\ASM\\Asm.asm");

		if (!ofile.is_open())
			throw ERROR_THROW(114);

		string funcname;
		string cyclecode;

		int pcount;

		string str;
		string buf;

		bool r = false, l = false, w = false;
		bool t = false, f = false;
		bool commbr = false;

		for (int i = 0; i < tables.lextable.size; i++)
		{
			switch (tables.lextable.table[i].lexema)
			{
				case LEX_MAIN:
				{
					str = str + "\nmain PROC";
					break;
				}
				case LEX_FUNCTION:
				{
					funcname = reinterpret_cast<char*>(ITENTRY(i + 1).id);
					pcount = ITENTRY(i + 1).parm;

					str = genFunctionCode(tables, i, funcname, pcount);
					break;
				}
				case LEX_RETURN:
				{
					if (funcname != "main")
						str = genExitCode(tables, i, funcname, pcount);
				
					funcname = "main";
					buf.clear();
					break;
				}
				case LEX_ID:
				{
					if (LEXEMA(i + 1) == LEX_LEFTTHESIS && LEXEMA(i - 1) != LEX_FUNCTION)
						str = genCallFuncCode(tables, log, i);
					break;
				}
				case ':':
				{
					str = genIFCode(tables, log, i, "left");

					if (!str.empty())
						v.push_back(str);

					buf = buf + str;
					str.clear();

					while (LEXEMA(++i) != LEX_LOGOPERATOR);

					int lop = i;

					str = genIFCode(tables, log, i, "right");

					if (!str.empty())
						v.push_back(str);

					buf = buf + str;
					str.clear();

					str = genConditionCode(tables, lop, cyclecode);

					while (LEXEMA(++i) != LEX_LOGOPERATOR && LEXEMA(i - 1) != LEX_ENDIF);

					break;
				}
				case '&':
				{
					str = genIFCode(tables, log, i, "left");

					if (!str.empty())
						v.push_back(str);

					str.clear();

					while (LEXEMA(++i) != LEX_LOGOPERATOR);

					int lop = i;

					str = genIFCode(tables, log, i, "right");

					if (!str.empty())
						v.push_back(str);

					str.clear();
					str = genConditionCode(tables, lop, cyclecode);

					break;
				}
				case LEX_BRACELET:
				{
					for (int j = i - 6; tables.lextable.table[j - 2].lexema != LEX_BRACELET; j++) 
					{
						if (tables.lextable.table[j].lexema == LEX_ENDIF) 
						{
							t = true;
						}

						if (tables.lextable.table[j].lexema == LEX_ASK) 
						{
							f = true;
						}
					}

					if (l || (t && !f)) 
					{
						str += "next" + itoS(conditionnum) + ":";

						l = false;
						t = false;
						f = false;
					}

					break;
				}
				case LEX_ENDIF:
				{
					if (!r) 
					{
						str = str + "right" + itoS(conditionnum) + ":";
						r = false;
					}

					break;
				}
				case LEX_ASK:
				{
					str = str + "\njmp next" + itoS(conditionnum) + "\n";

					str = str + "wrong" + itoS(conditionnum) + ":";

					l = true;
					break;
				}
				case LEX_EQUAL:
				{
					str = genEqualCode(tables, log, i);

					while (LEXEMA(++i) != LEX_SEMICOLON);
					break;
				}
				case LEX_SHOW:
				{
					IT::Entry e = tables.idtable.table[tables.lextable.table[i + 1].idxTI];

					if (e.idtype != IT::IDTYPE::F)
					{
						switch (e.iddatatype)
						{
							case IT::IDDATATYPE::SHR:
								str = str + "mov ax, " + reinterpret_cast<char*>(e.id) + "\nmov result, ax\n";
								str = str + "INVOKE int_to_char, offset result_str, result\nINVOKE outw, offset result_str\n";
								i++;
								break;

							case IT::IDDATATYPE::STR:
								if (e.idtype == IT::IDTYPE::L)
									str = str + "\nINVOKE outw, offset " + reinterpret_cast<char*>(e.id) + "\n";
								else
									str = str + "\nINVOKE outw, " + reinterpret_cast<char*>(e.id) + "\n";
								i++;
								break;

							case IT::IDDATATYPE::CHR:
							{
								str = str + "INVOKE outw, offset " + reinterpret_cast<char*>(e.id) + "\n";
								i++;
								break;
							}
							case IT::IDDATATYPE::BOOL:
							{
								str = str + "cmp " + reinterpret_cast<char*>(e.id) + ", 1\n";
								str = str + "je print_true_" + reinterpret_cast<char*>(e.id) + "\n\n";
								str = str + "mov text, offset false_str\n";
								str = str + "INVOKE outw, text\n";
								str = str + "jmp done_" + reinterpret_cast<char*>(e.id) + "\n\n";
								str = str + "print_true_" + reinterpret_cast<char*>(e.id) + ":\nmov text, offset true_str\n";
								str = str + "INVOKE outw, text\n\ndone_" + reinterpret_cast<char*>(e.id) + ":\n";
								i++;
								break;
							}
						}
					}

					break;
				}
				case LEX_SHOWLINE:
				{
					IT::Entry e = tables.idtable.table[tables.lextable.table[i + 1].idxTI];

					if (e.idtype != IT::IDTYPE::F)
					{
						switch (e.iddatatype)
						{
						case IT::IDDATATYPE::SHR:
							str = str + "mov ax, " + reinterpret_cast<char*>(e.id) + "\nmov result, ax\n";
							str = str + "INVOKE int_to_char, offset result_str, result\nINVOKE outwf, offset result_str\n";
							i++;
							break;

						case IT::IDDATATYPE::STR:
							if (e.idtype == IT::IDTYPE::L)
								str = str + "\nINVOKE outwf, offset " + reinterpret_cast<char*>(e.id) + "\n";
							else
								str = str + "\nINVOKE outwf, " + reinterpret_cast<char*>(e.id) + "\n";
							i++;
							break;

						case IT::IDDATATYPE::CHR:
						{
							str = str + "INVOKE outwf, offset " + reinterpret_cast<char*>(e.id) + "\n";
							i++;
							break;
						}
						case IT::IDDATATYPE::BOOL:
						{
							str = str + "cmp " + reinterpret_cast<char*>(e.id) + ", 1\n";
							str = str + "je print_true_" + reinterpret_cast<char*>(e.id) + "\n\n";
							str = str + "mov text, offset false_str\n";
							str = str + "INVOKE outwf, text\n";
							str = str + "jmp done_" + reinterpret_cast<char*>(e.id) + "\n\n";
							str = str + "print_true_" + reinterpret_cast<char*>(e.id) + ":\nmov text, offset true_str\n";
							str = str + "INVOKE outwf, text\n\ndone_" + reinterpret_cast<char*>(e.id) + ":\n";
							i++;
							break;
						}
						}
					}

					break;
				}
			}

			if (!str.empty())
				v.push_back(str);

			str.clear();
		}

		v.push_back(END);

		for (auto x : v)
			ofile << x << endl;

		ofile.close();
	}

}