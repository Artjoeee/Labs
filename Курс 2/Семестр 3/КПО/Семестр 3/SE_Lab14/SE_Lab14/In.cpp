#include "stdafx.h"
#include "In.h"
#include "Error.h"

namespace In
{
	IN getin(wchar_t infile[])
	{
		IN in{};

		in.lines = 0;
		in.size = 0;
		in.ignor = 0;

		int position = 0;

		unsigned char inText[1024] = "";
		in.text = inText;

		unsigned char inputChar = ' ';

		ifstream fileInput(infile);

		if (fileInput.fail())
			throw ERROR_THROW(110);

		inputChar = fileInput.get();

		while (in.size <= IN_MAX_LEN_TEXT)
		{
			if (fileInput.eof())
			{
				inText[in.size] = '\0';
				break;
			}

			if (inputChar =='\n' && in.code['\n'] != IN::F)
			{
				position = -1;
				in.lines++;
			}

			switch (in.code[(unsigned char)inputChar])
			{
			case IN::T:
				position++;
				inText[in.size] = inputChar;
				in.size++;
				break;

			case IN::F:
				throw ERROR_THROW_IN(111, in.lines, position);

			case IN::I:
				in.ignor++;
				break;

			default:
				inText[in.size] = in.code[(unsigned char)inputChar];
				position++;
				in.size++;
			}

			inputChar = fileInput.get();
		}

		fileInput.close();

		return in;
	}
};