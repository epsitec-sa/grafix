#include "agg_text_break.h"
#include "agg_text_unicode_support.h"

#include "interface.h"
#include "wordbreak.h"

/*****************************************************************************/

static void fix_multi_spaces(wchar_t* text)
{
	while (*text)
	{
		wchar_t code = *text++;
		
		if (code == ' ')
		{
			while (*text == ' ')
			{
				*text++ = 160;
			}
		}
	}
}

static void make_images_breakable(const wchar_t* text, agg::int8u* breaks)
{
	int len = 0;
	
	while (*text)
	{
		if (*text == 0xfffc)
		{
			if (len > 0)
			{
				if (breaks[-1] != agg::unicode_helper::break_yes_always)
				{
					breaks[-1] = agg::unicode_helper::break_yes_option;
				}
				
				breaks[0]  = agg::unicode_helper::break_yes_option;
			}
		}
		
		breaks++;
		text++;
		len++;
	}
}

/*****************************************************************************/

void AggTextBreakInitialiseLineBreak(const void* data, size_t length)
{
	agg::unicode_helper::setup_line_break_data (reinterpret_cast<const char*> (data), length);
	agg::unicode_helper::current ();
}

agg::text_break* AggTextBreakNew()
{
	return new agg::text_break ();
}

void AggTextBreakDelete(agg::text_break* tb)
{
	if (tb)
	{
		delete tb;
	}
}

bool AggTextBreakIsValid(agg::text_break* tb)
{
	if (tb)
	{
		return tb->is_valid ();
	}
	
	return false;
}

bool AggTextBreakSetFontFaces(agg::text_break* tb, int n, agg::font_face** faces)
{
	if (tb)
	{
		return tb->define_font_faces (n, faces);
	}
	
	return false;
}

bool AggTextBreakSetTextRuns(agg::text_break* tb, int n, const agg::int16u* run_lengths, const agg::int16u* font_ids, const double* scales)
{
	if (tb)
	{
		return tb->define_text_runs (n, run_lengths, font_ids, scales);
	}
	
	return false;
}

bool AggTextBreakSetText(agg::text_break* tb, const wchar_t* text, int mode)
{
	if (tb)
	{
		if (tb->define_text (text))
		{
			fix_multi_spaces (tb->text ());
			tb->define_text_break_mode (static_cast<agg::text_break::text_break_mode_enum> (mode));
			make_images_breakable (tb->text (), tb->text_breaks ());
			return true;
		}
	}
	
	return false;
}

const wchar_t* AggTextBreakGetText(agg::text_break* tb)
{
	if (tb)
	{
		return tb->text ();
	}
	
	return 0;
}

int AggTextBreakGetTextLength(agg::text_break* tb)
{
	if (tb)
	{
		return static_cast<int> (tb->text_length ());
	}
	
	return 0;
}

const agg::int8u* AggTextBreakGetTextBreaks(agg::text_break* tb)
{
	if (tb)
	{
		return tb->text_breaks ();
	}
	
	return 0;
}

void AggTextBreakRewind(agg::text_break* tb)
{
	if (tb)
	{
		tb->rewind ();
	}
}

const wchar_t* AggTextBreakFindNextBreak(agg::text_break* tb, double& width, int& n_chars)
{
	if (tb)
	{
		return tb->find_next_break (width, n_chars);
	}
	
	width   = 0.0;
	n_chars = 0;
	
	return 0;
}



void AggTextBreakSetFontFaceCount(agg::text_break* tb, int n)
{
	if (tb)
	{
		tb->allocate_font_faces (n);
	}
}

void AggTextBreakSetNthFontFace(agg::text_break* tb, int nth, agg::font_face* face)
{
	if (tb)
	{
		tb->define_nth_font_face (nth, face);
	}
}
		
void AggTextBreakSetRunCount(agg::text_break* tb, int n)
{
	if (tb)
	{
		tb->allocate_text_runs (n);
	}
}

void AggTextBreakSetNthRun(agg::text_break* tb, int nth, int run_length, int face_index, double scale)
{
	if (tb)
	{
		tb->define_nth_run (nth, run_length, face_index, scale);
	}
}

/*****************************************************************************/

static char reduce_to_upper_ascii(int utf)
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

static void hyphenate_text(const wchar_t* text, size_t text_length, agg::int8u* text_breaks, bool (*smaky_coupe_func)(const char*, int, int*))
{
	if (smaky_coupe_func == 0)
	{
		return;
	}
	
	//	Find the hyphenation points in the text, by applying the language specific
	//	hyphenation rules.
	
	int len   = static_cast<int> (text_length);
	int start = 0;
	
	for (int i = 0; i < len; i++)
	{
		if ( (text_breaks[i] != agg::unicode_helper::break_no_is_alpha)
		  || (i == len-1) )
		{
			int n = i - start;
			
			if ((n > 3) &&
				(n < 99))
			{
				char word[100];
				int  list[100];
				
				for (int j = 0; j < n; j++)
				{
					word[j] = reduce_to_upper_ascii (text[start+j]);
				}
				
				list[0] = 0;
				word[n] = 0;
				
				//	Call Daniel Roux's COUPE code, which was inherited from the SMAKY computer and
				//	ported to C for the Virtual Pen project :
				
				smaky_coupe_func (word, n, list);
				
				int* pos = list;
				
				while (*pos)
				{
					int p = *pos++;
					text_breaks[start + p] = agg::unicode_helper::break_hyphenate_good;
				}
			}
			
			start = i+1;
		}
	}
}

/*****************************************************************************/

void AggTextBreakHyphenate(agg::text_break* tb)
{
	if (tb)
	{
		const wchar_t* text   = tb->text ();
		agg::int8u*    breaks = tb->text_breaks ();
		
		hyphenate_text (text, tb->text_length (), breaks, Break);
	}
}

