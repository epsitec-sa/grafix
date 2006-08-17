//	AntiGrain.Win32/agg_text.cpp
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
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
			case 'á': case 'à': case 'â': case 'ä': case 'ã':	return 'A';
			case 'Á': case 'À': case 'Â': case 'Ä': case 'Ã':	return 'A';
			
			case 'ç':											return 'C';
			case 'Ç':											return 'C';
			
			case 'é': case 'è': case 'ê': case 'ë':				return 'E';
			case 'É': case 'È': case 'Ê': case 'Ë':				return 'E';
			case 'í': case 'ì': case 'î': case 'ï':				return 'I';
			case 'Í': case 'Ì': case 'Î': case 'Ï':				return 'I';
			case 'ó': case 'ò': case 'ô': case 'ö': case 'õ':	return 'O';
			case 'Ó': case 'Ò': case 'Ô': case 'Ö': case 'Õ':	return 'O';
			case 'ú': case 'ù': case 'û': case 'ü':				return 'U';
			case 'Ú': case 'Ù': case 'Û': case 'Ü':				return 'U';
			case 'ñ':											return 'N';
			case 'Ñ':											return 'N';
			case 'ÿ': case 'ý':									return 'Y';
			case 'Ÿ': case 'Ý':									return 'Y';
			
			case 'Å': case 'Æ': case 'å': case 'æ':				return 'A';
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
