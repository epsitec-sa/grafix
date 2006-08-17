//	AntiGrain.Win32/agg_text.cpp
//
//	Copyright � 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved. 
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

#include "interface.h"

#include "wordbreak.h"

/*****************************************************************************/

char
ReduceToASCIIAndConvertToUpper(int utf)
{
	if ( (utf >= 'A')
	  && (utf <= 'Z') )
	{
		return static_cast<char> (utf);
	}
	
	if ( (utf >= 'a')
	  && (utf <= 'z') )
	{
		return static_cast<char> (utf+'A'-'a');
	}
	
	if (utf < 256)
	{
		switch (static_cast<char> (utf))
		{
			case '�': case '�': case '�': case '�': case '�':	return 'A';
			case '�': case '�': case '�': case '�': case '�':	return 'A';
			
			case '�':											return 'C';
			case '�':											return 'C';
			
			case '�': case '�': case '�': case '�':				return 'E';
			case '�': case '�': case '�': case '�':				return 'E';
			case '�': case '�': case '�': case '�':				return 'I';
			case '�': case '�': case '�': case '�':				return 'I';
			case '�': case '�': case '�': case '�': case '�':	return 'O';
			case '�': case '�': case '�': case '�': case '�':	return 'O';
			case '�': case '�': case '�': case '�':				return 'U';
			case '�': case '�': case '�': case '�':				return 'U';
			case '�':											return 'N';
			case '�':											return 'N';
			case '�': case '�':									return 'Y';
			case '�': case '�':									return 'Y';
			
			case '�': case '�': case '�': case '�':				return 'A';
			case '\'':											return '\'';
			case '-':											return '-';
		}
	}
	
	return '#';
}

/*****************************************************************************/

int
AggTextBreakHyphenateWord(const wchar_t* text, int len,
						  short* breaks, int breaks_length)
{
	int  num = 0;
	
	//	Find the hyphenation points in the text, by applying the language specific
	//	hyphenation rules.
	
	if ((len > 3) &&
		(len < 99))
	{
		char word[100];
		int  list[100];
		
		for (int j = 0; j < len; j++)
		{
			word[j] = ReduceToASCIIAndConvertToUpper (text[j]);
		}
		
		list[0]   = 0;
		word[len] = 0;
		
		//	Call Daniel Roux's COUPE code, which was inherited from the SMAKY computer and
		//	ported to C for the Virtual Pen project :
		
		Break (word, len, list);
		
		int* pos = list;
		
		while (*pos && (num < breaks_length))
		{
			breaks[num++] = static_cast<short> (*pos++);
		}
	}
	
	return num;
}

/*****************************************************************************/
