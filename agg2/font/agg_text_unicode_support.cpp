/*
 *	agg_text_unicode_support.cpp
 *
 *	Unicode support code.
 *
 *	(C) Copyright 2002-2004, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
 *		CH-1400 YVERDON, Switzerland. All rights reserved. 
 *		Contact: pierre.arnaud@opac.ch, http://www.opac.ch
 *
 *	This file may be distributed and used under the same terms and conditions as
 *	the Anti-Grain Geometry software (http://www.antigrain.com).
 *
 *	Permission to copy, use, modify, sell and distribute this software 
 *	is granted provided this copyright notice appears in all copies. 
 *	This software is provided "as is" without express or implied
 *	warranty, and with no claim as to its suitability for any purpose.
 */

/*****************************************************************************/

#include "agg_text_unicode_support.h"
#include "agg_strsafe.h"

/*****************************************************************************/

#if defined(_MSC_VER)
#include <malloc.h>
#else
#include <alloca.h>
#endif

#include <stdio.h>
#include <assert.h>

/*****************************************************************************/

/*
 *	Private loader class, used to load a text file line by line. We
 *	know from the file's format that lines won't exceed 100 characters
 *	each, so allocate fixed blocks.
 */

class agg::unicode_helper::internal_text_loader
{
private:
	FILE*			file;
	
	const char*		source_data;
	size_t			source_length;
	size_t			source_offset;
	
	char			line[100];
	char			buffer[100];
	char			comment[200];
	size_t			offset;
	size_t			length;
	
public:
	internal_text_loader(FILE* open_file) : file (open_file), offset (0), length (0), source_data (0), source_length (0), source_offset (0)
	{
		this->comment[0] = 0;
	}
	
	internal_text_loader(const char* data, size_t length) : file (0), offset (0), length (0), source_data (data), source_length (length), source_offset (0)
	{
		this->comment[0] = 0;
	}
	
	~internal_text_loader()
	{
		if (this->file)
		{
			fclose (this->file);
		}
	}
	
	bool is_valid() const
	{
		return (this->file != 0) || (this->source_data && this->source_length);
	}
	
	const char* get_next_line()
	{
		bool  comment = false;
		char* line    = this->line;
		char* line_c  = this->comment;
		int   max     = sizeof (this->line) - 1;
		int   max_c   = sizeof (this->comment) - 1;
		
		while (max)
		{
			if (this->length == 0)
			{
				if (this->file)
				{
					this->length = fread (this->buffer, 1, sizeof (this->buffer), this->file);
				}
				else if (this->source_data && (this->source_offset < this->source_length))
				{
					size_t copy_length = sizeof (this->buffer);
					size_t more_length = this->source_length - this->source_offset;
					
					if (copy_length > more_length)
					{
						copy_length = more_length;
					}
					
					memcpy (this->buffer, this->source_data + this->source_offset, copy_length);
					
					this->source_offset += copy_length;
					this->length         = copy_length;
				}
				else
				{
					this->length = 0;
				}
				
				this->offset = 0;
				
				if (this->length == 0)
				{
					return 0;
				}
			}
			
			char c = this->buffer[this->offset++];
			this->length--;
			
			if ((c == 13) || (c == 10))
			{
				if (line == this->line)
				{
					comment = false;
					continue;
				}
				else
				{
					break;
				}
			}
			
			if (c == '#')
			{
				comment = true;
			}
			
			if (!comment)
			{
				*line++ = c;
				max--;
			}
			else if (max_c)
			{
				*line_c++ = c;
				max_c--;
			}
		}
		
		*line   = 0;
		*line_c = 0;
		
		return this->line;
	}
	
	const char* Comment() const
	{
		return this->comment;
	}
};

/*****************************************************************************/

/*
 *	Return hex integer value read from the input string. Default to value in case
 *	there is no value specified.
 */

 int agg::unicode_helper::get_num_arg (const char* & script, int value)
{
	int  base  = 16;
	bool reset = true;
	
	while (script[0])
	{
		char c = script[0];
		
		switch (c)
		{
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9':
				c -= '0';
value:			if (c >= base)
				{
					break;
				}
				if (reset)
				{
					value = 0;
					reset = false;
				}
				value *= base;
				value += c;
				script++;
				continue;
			
			case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
				c -= 'a';
				c += 10;
				goto value;
			
			case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
				c -= 'A';
				c += 10;
				goto value;
		}
		break;
	}
	
	return value;
}

/*****************************************************************************/

static const char* break_class_names[agg::unicode_helper::last_break_class_value + 1] =
{
	"XX",
	"BK", "CM", "SG", "ZW", "GL", "CB", "SP",
	"BA", "BB", "B2", "HY",
	"IN", "NS", "OP", "CL", "QU", "EX",
	"NU", "IS", "SY", "PR", "PO",
	"AL", "ID", "AI", "SA",
	0
};

const char*	agg::unicode_helper::m_break_file_name;
const char*	agg::unicode_helper::m_break_data_source;
size_t		agg::unicode_helper::m_break_data_length;


void agg::unicode_helper::setup_line_break_file(const char* file_name)
{
	m_break_file_name = file_name;
}

void agg::unicode_helper::setup_line_break_data(const char* data, size_t length)
{
	m_break_data_source = data;
	m_break_data_length = length;
}

const agg::unicode_helper& agg::unicode_helper::current()
{
	static unicode_helper* helper = 0;
	
	if (helper == 0)
	{
		if (m_break_file_name)
		{
			helper = new unicode_helper (m_break_file_name);
			m_break_file_name = 0;
		}
		else if (m_break_data_source && m_break_data_length)
		{
			helper = new unicode_helper (m_break_data_source, m_break_data_length);
			m_break_data_source = 0;
			m_break_data_length = 0;
		}
	}
	
	if (helper == 0)
	{
		throw "Cannot load line break information.";
	}
	
	return *helper;
}

agg::unicode_helper::unicode_helper(const char* file_path)
	:
	m_break_list_head (0),
	m_break_list_tail (0)
{
	agg::memory_zero (m_break_table_1, sizeof (m_break_table_1));
	agg::memory_zero (m_break_table_2, sizeof (m_break_table_2));
	
	if (! this->load_line_break_information (file_path))
	{
		throw "Cannot load line break information.";
	}
}

agg::unicode_helper::unicode_helper(const char* data, size_t length)
	:
	m_break_list_head (0),
	m_break_list_tail (0)
{
	agg::memory_zero (m_break_table_1, sizeof (m_break_table_1));
	agg::memory_zero (m_break_table_2, sizeof (m_break_table_2));
	
	if (! this->load_line_break_information (data, length))
	{
		throw "Cannot load line break information.";
	}
}

agg::unicode_helper::~unicode_helper()
{
	break_elem_record* elem = m_break_list_head;
	
	while (elem)
	{
		break_elem_record* next = elem->next;
		delete elem;
		elem = next;
	}
	
	m_break_list_head = 0;
	m_break_list_tail = 0;
}


/*
 *	Load the LineBreak file, as provided by the Unicode consortium, and
 *	populate the internal tables.
 */

bool agg::unicode_helper::load_line_break_information(const char* name)
{
	internal_text_loader loader (fopen ("LineBreak-4.0.0.txt", "rt"));
	return load_line_break_information (loader);
}

bool agg::unicode_helper::load_line_break_information(const char* data, size_t length)
{
	internal_text_loader loader (data, length);
	return load_line_break_information (loader);
}

bool agg::unicode_helper::load_line_break_information(internal_text_loader& loader)
{
	if (loader.is_valid () == false)
	{
		return false;
	}
	
	for (;;)
	{
		const char* line = loader.get_next_line ();
		
		if (line == 0)
		{
			break;
		}
		
		int              cur_value = get_num_arg (line, -1);
		break_class_enum cur_class = get_break_class_from_name (strstr (line, ";") + 1);
		
		if (cur_class != agg::unicode_helper::XX_Unknown)
		{
			if ( (line[0] == '.')
			  && (line[1] == '.') )
			{
				line += 2;
				int end_value = get_num_arg (line, -1);
again_range:
				if (cur_value < 0x003200)				//	0x000000 - 0x0031FF, use table 1
				{
					m_break_table_1[cur_value - 0x000000] = static_cast<int8u> (cur_class);
					
					if (++cur_value < end_value)
					{
						goto again_range;
					}
				}
				else if (cur_value < 0x00F900)			//	0x003200 - 0x00F8FF, known range
				{
					continue;
				}
				else if (cur_value < 0x010000)			//	0x00F900 - 0x00FFFF, use table 2
				{
					m_break_table_2[cur_value - 0x00F900] = static_cast<int8u> (cur_class);
					
					if (++cur_value < end_value)
					{
						goto again_range;
					}
				}
				else									//	above 0x010000, use a list
				{
					if ( (m_break_list_tail == 0)
					  || (m_break_list_tail->break_class != cur_class)
					  || (m_break_list_tail->code_end+1  != cur_value) )
					{
						break_elem_record* elem = new break_elem_record;
						
						elem->next        = 0;
						elem->break_class = cur_class;
						elem->code_begin  = cur_value;
						elem->code_end    = end_value;
						
						(m_break_list_tail ? m_break_list_tail->next : m_break_list_head) = elem;
						(m_break_list_tail												) = elem;
					}
					else
					{
						m_break_list_tail->code_end = end_value;
					}
				}
			}
			else
			{
				int8u info       = static_cast<int8u> (cur_class);
				bool  is_capital = false;
				
				if ( (cur_class == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol)
				  && (strstr (loader.Comment (), "CAPITAL LETTER")) )
				{
					info      |= agg::unicode_helper::flag_capital_letter;
					is_capital = true;
				}
				
				if (cur_value < 0x003200)				//	0x000000 - 0x0031FF, use table 1
				{
					m_break_table_1[cur_value - 0x000000] = info;
				}
				else if (cur_value < 0x00F900)			//	0x003200 - 0x00F8FF, known range
				{
					continue;
				}
				else if (cur_value < 0x010000)			//	0x00F900 - 0x00FFFF, use table 2
				{
					m_break_table_2[cur_value - 0x00F900] = info;
				}
				else									//	above 0x010000, use a list
				{
					if ( (m_break_list_tail == 0)
					  || (m_break_list_tail->break_class != cur_class)
					  || (m_break_list_tail->is_capital  != is_capital)
					  || (m_break_list_tail->code_end+1  != cur_value) )
					{
						break_elem_record* elem = new break_elem_record;
						
						elem->next        = 0;
						elem->is_capital  = is_capital;
						elem->break_class = cur_class;
						elem->code_begin  = cur_value;
						elem->code_end    = cur_value;
						
						(m_break_list_tail ? m_break_list_tail->next : m_break_list_head) = elem;
						(m_break_list_tail												) = elem;
					}
					else
					{
						m_break_list_tail->code_end = cur_value;
					}
				}
			}
		}
	}
	
	return true;
}

/*****************************************************************************/

/*
 *	Convert the short Break Class name into its internal representation.
 */

agg::unicode_helper::break_class_enum agg::unicode_helper::get_break_class_from_name(const char* find)
{
	for (int i = 0; ; i++)
	{
		const char* name = break_class_names[i];
		
		if (name == 0)
		{
			break;
		}
		
		if ( (name[0] == find[0])
		  && (name[1] == find[1]) )
		{
			return static_cast<agg::unicode_helper::break_class_enum> (i);
		}
	}
	
	return agg::unicode_helper::XX_Unknown;
}

/*
 *	Convert a Break Class representation into its short name.
 */

const char* agg::unicode_helper::get_break_class_name(agg::unicode_helper::break_class_enum break_class)
{
	if ( (break_class < agg::unicode_helper::last_break_class_value)
	  && (break_class >= 0) )
	{
		return break_class_names[break_class];
	}
	
	return "XX";
}

/*****************************************************************************/

/*
 *	Convert a UTF-16 encoded character (which can span 2 words) into an un-encoded
 *	UTF-32 character. An Invalid character will be returned whenever the encoded
 *	sequence is broken.
 *
 *	Return true when the character code returned was encoded using a surrogate
 *	pair, false for standard characters.
 */

bool agg::unicode_helper::read_character_code(const wchar_t* text, int32u& code)
{
	int16u w1 = static_cast<int16u> (text[0]);
	int16u w2;
	
	if ( (w1 < 0xD800)
	  || (w1 > 0xDFFF) )
	{
		code = static_cast<int32u> (w1);
		
		return false;
	}
	
	if (w1 < 0xDC00)
	{																	//	U+D800..U+DBFF (lower surrogate)
		w2 = text[1];
		
		if ( (w2 >= 0xDC00)
		  && (w2 <= 0xDFFF) )
		{																//	..followed by high surrogate => valid pair where
																		//	it is possible to extract the 20-bit UTF-32 offset.
			code = ( (static_cast<int32u> (w1 & 0x03FF) << 10)
				   | (static_cast<int32u> (w2 & 0x03FF)) ) + 0x10000;	//	surrogate maps to U+10000..U+10FFFF
			
			return true;
		}
	}
	
	code = agg::unicode_helper::Invalid;
	
	return false;
}

/*****************************************************************************/

/*
 *	Find the break class for a specified Unicode character. We have split
 *	the Unicode range into following ranges:
 *
 *	- 0x000000 - 0x0031FF : table 1
 *	- 0x003200 - 0x00D7FF : known to be ideographic
 *	- 0x00D800 - 0x00DFFF : known to be surrogates
 *	- 0x00E000 - 0x00F8FF : known to be custom
 *	- 0x00F900 - 0x00FFFF : table 2
 *	- 0x010000 - ...      : list of ranges
 *
 *	The most used zone will map into table 1 (or will be ideographic, which
 *	will be found very quickly too). Less used codes usually reside in table 2
 *	or in the list.
 *
 *	The tables take up less than 15 KB. Let us hope that the accesses in the
 *	first pages will be done in the CPUs cache.
 */

agg::unicode_helper::break_class_enum agg::unicode_helper::get_break_class(int32u code)
{
	const agg::unicode_helper & helper = agg::unicode_helper::current ();
	
	if (code < 0x003200)
	{
		return static_cast<agg::unicode_helper::break_class_enum> (helper.m_break_table_1[code - 0x000000] & agg::unicode_helper::mask_break_class);
	}
	else if (code < 0x00D800)
	{
		return agg::unicode_helper::ID_Ideographic;
	}
	else if (code < 0x00E000)
	{
		return agg::unicode_helper::SG_Surrogates;
	}
	else if (code < 0x00F900)
	{
		return agg::unicode_helper::XX_Unknown;
	}
	else if (code < 0x010000)
	{
		return static_cast<agg::unicode_helper::break_class_enum> (helper.m_break_table_2[code - 0x00F900] & agg::unicode_helper::mask_break_class);
	}
	
	//	...for all other cases, search in the list...
	
	break_elem_record* elem = helper.m_break_list_head;
	
	while (elem)
	{
		if ( (elem->code_begin <= code)
		  && (elem->code_end   >= code) )
		{
			return static_cast<agg::unicode_helper::break_class_enum> (elem->break_class);
		}
		
		elem = elem->next;
	}
	
	return agg::unicode_helper::XX_Unknown;
}

/*
 *	Return true if the UTF32 code maps to a capital letter. We have split
 *	the Unicode range into following ranges:
 *
 *	- 0x000000 - 0x0031FF : table 1
 *	- 0x003200 - 0x00D7FF : known to be ideographic - always false
 *	- 0x00D800 - 0x00DFFF : known to be surrogates	- always false
 *	- 0x00E000 - 0x00F8FF : known to be custom		- always false
 *	- 0x00F900 - 0x00FFFF : table 2
 *	- 0x010000 - ...      : list of ranges
 */

bool agg::unicode_helper::is_capital_letter(int32u code)
{
	const agg::unicode_helper & helper = agg::unicode_helper::current ();
	
	if (code < 0x003200)
	{
		return (helper.m_break_table_1[code - 0x000000] & agg::unicode_helper::flag_capital_letter) ? true : false;
	}
	else if (code < 0x00F900)
	{
		return false;
	}
	else if (code < 0x010000)
	{
		return (helper.m_break_table_2[code - 0x00F900] & agg::unicode_helper::flag_capital_letter) ? true : false;
	}
	
	//	...for all other cases, search in the list...
	
	break_elem_record* elem = helper.m_break_list_head;
	
	while (elem)
	{
		if ( (elem->code_begin <= code)
		  && (elem->code_end   >= code) )
		{
			return elem->is_capital;
		}
		
		elem = elem->next;
	}
	
	return false;
}

/*
 *	Return true if the character belongs to a space break class.
 */

bool agg::unicode_helper::is_space_break_class(int32u code, agg::unicode_helper::break_class_enum break_class)
{
	switch (break_class)
	{
		case agg::unicode_helper::ZW_ZeroWidthSpace:
		case agg::unicode_helper::SP_Space:
		case agg::unicode_helper::BK_MandatoryBreak:
			return true;
		
		default:
			break;
	}
	
	return false;
}

bool agg::unicode_helper::is_space_break_class(int32u code)
{
	agg::unicode_helper::break_class_enum break_class = agg::unicode_helper::get_break_class (code);
	return agg::unicode_helper::is_space_break_class (code, break_class);
}

bool agg::unicode_helper::is_stretchable_space_class(int32u code, agg::unicode_helper::break_class_enum break_class)
{
	switch (code)
	{
		case agg::unicode_helper::Space:
		case agg::unicode_helper::NoBreakSpace:
			return true;
	}
	
	return false;
}

/*****************************************************************************/

void agg::unicode_helper::analyse_breaks (const wchar_t* text, size_t length, int8u* breaks)
{
	if (length == 0)
	{
		return;
	}
	
	size_t mem_size   = (length + 1) * 2;
	int8u* tmp_memory = (length > 1000) ? new int8u[mem_size] : 0;
	int8u* cclass     = tmp_memory ? tmp_memory : reinterpret_cast<int8u*> (alloca (mem_size));
	int8u* cpairs     = cclass + mem_size / 2;
	int8u  cpairs_or  = 0;
	
	int32u cur_unicode;
	int32u prv_unicode;
	
	memory_zero (cpairs, length);
	
	bool surrogate;
	
	agg::unicode_helper::break_class_enum cur_class;
	agg::unicode_helper::break_class_enum prv_class = agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol;
	
	for (size_t i = 0; i < length; i++)
	{
		surrogate = read_character_code (text++, cur_unicode);
		cur_class = get_break_class (cur_unicode);
		
		if (surrogate)
		{
			//	We have just consumed a surrogate pair. Fix the text length accordingly.
			
			cpairs[i] = 1;
			cpairs_or = 1;
			length--;
			text++;
		}
		
		//	Replace some breaking classes with others, in order to simplify further processing.
		
		switch (cur_class)
		{
			case agg::unicode_helper::CM_CombiningMarks:
				if (prv_class == agg::unicode_helper::SP_Space)
				{
					cur_class = agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol;
				}
				else
				{
					cur_class = prv_class;
				}
				break;
			
			case agg::unicode_helper::AI_AmbiguousAlphabeticOrIdeographic:
				cur_class = agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol;
				break;
			
			case agg::unicode_helper::SA_ComplexContextSouthEastAsian:
				cur_class = agg::unicode_helper::ID_Ideographic;
				break;
				
			case agg::unicode_helper::CB_ContingentBreakOpportunity:
				cur_class = agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol;
				break;
			
			case agg::unicode_helper::XX_Unknown:
				cur_class = agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol;
				break;
			
			case agg::unicode_helper::SP_Space:
				if ( (prv_class == agg::unicode_helper::OP_OpeningPunctuation)					//	support for LB 9
				  || (prv_class == agg::unicode_helper::B2_BreakOpportunityBeforeAndAfter) )	//	support for LB 11a
				{
					cur_class = prv_class;
				}
				break;
				
			case agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol:
				if ( (i > 1)
				  && (cclass[i-2] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol)
				  && (prv_unicode == '\'') )
				{
					cclass[i-1] = agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol;			//	replace a'a with aaa to account for French words, where..
				}																				//	..the apostrophe behaves just as an alphabetic character
				break;
		}
		
		//	We will never find surrogate pairs here, since UTF-8 characters never need to encode surrogates
		//	using surrogate pairs... And contingent breaks must have been resolved.
		
		assert (cur_class != agg::unicode_helper::SG_Surrogates);
		assert (cur_class != agg::unicode_helper::CB_ContingentBreakOpportunity);
		
		cclass[i]   = cur_class;
		prv_class   = cur_class;
		prv_unicode = cur_unicode;
	}
	
	cclass[length] = agg::unicode_helper::BK_MandatoryBreak;
	
	breaks[0] = (cclass[0] == agg::unicode_helper::BK_MandatoryBreak)
				? agg::unicode_helper::break_yes_always
				: agg::unicode_helper::break_no;
	
	for (size_t i = 1; i < length; i++)
	{
		if ( (cclass[i-1] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol)
		  && (breaks[i-1] == agg::unicode_helper::break_no) )
		{
			breaks[i-1] = agg::unicode_helper::break_no_is_alpha;
		}
		
		if (cclass[i] == agg::unicode_helper::BK_MandatoryBreak)					//	LB 3a / Always break after hard line breaks
		{
			breaks[i] = agg::unicode_helper::break_yes_always;
			continue;
		}
		if ( (cclass[i+1] == agg::unicode_helper::BK_MandatoryBreak)				//	LB 3b / Don't break before hard line breaks
		  || (cclass[i+1] == agg::unicode_helper::SP_Space)							//	LB 4  / Don't break before spaces or zero-width space
		  || (cclass[i+1] == agg::unicode_helper::ZW_ZeroWidthSpace) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if (cclass[i] == agg::unicode_helper::ZW_ZeroWidthSpace)					//	LB 5  / Break after zero-width space
		{
			breaks[i] = agg::unicode_helper::break_yes_option;
			continue;
		}
		
		//	LB 6 and LB 7 are specific to combining marks, which have been mapped to the appropriate breaking classes
		//	in the preliminary conversion; no need to handle these rules here.
		
		if ( (cclass[i+1] == agg::unicode_helper::CL_ClosingPunctuation)			//	LB 8  / Don't break before ']', '!', ';', '/', even after spaces
		  || (cclass[i+1] == agg::unicode_helper::EX_ExclamationInterrogation)
		  || (cclass[i+1] == agg::unicode_helper::IS_InfixSeparatorNumeric)
		  || (cclass[i+1] == agg::unicode_helper::SY_SymbolsAllowingBreaks) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if (cclass[i] == agg::unicode_helper::OP_OpeningPunctuation)				//	LB 9  / Don't break after '[', even after spaces
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
#if 0
		if (cclass[i] == agg::unicode_helper::QU_AmbiguousQuotation)				//	LB 10 / Don't break within '"[', even with intervening spaces
		{
			Count j = i+1;
			
			while ( (j < length)
				 && (cclass[j] == agg::unicode_helper::SP_Space) )
			{
				j++;		//	skip the spaces
			}
			
			if (cclass[j] == agg::unicode_helper::OP_OpeningPunctuation)
			{
				breaks[i] = agg::unicode_helper::break_no;
                continue;
			}
		}
		if (cclass[i] == agg::unicode_helper::CL_ClosingPunctuation)				//	LB 11 / Don't break within ']<non starter>', even with intervening spaces
		{
			Count j = i+1;
			
			while ( (j < length)
				 && (cclass[j] == agg::unicode_helper::SP_Space) )
			{
				j++;		//	skip the spaces
			}
			
			if (cclass[j] == agg::unicode_helper::NS_NonStarter)
			{
				breaks[i] = agg::unicode_helper::break_no;
                continue;
			}
		}
#endif
		if (cclass[i] == agg::unicode_helper::B2_BreakOpportunityBeforeAndAfter)	//	LB 11a/ Don't break within '-- --', even with intervening spaces
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if (cclass[i] == agg::unicode_helper::SP_Space)								//	LB 12 / Break after spaces
		{
			breaks[i] = agg::unicode_helper::break_yes_option;
			continue;
		}
		if ( (cclass[i] == agg::unicode_helper::GL_NonBreakingGlue)					//	LB 13 / Don't break before or after NBSP or WORD JOINER
		  || (cclass[i+1] == agg::unicode_helper::GL_NonBreakingGlue) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if ( (cclass[i] == agg::unicode_helper::QU_AmbiguousQuotation)				//	LB 14 / Don't break before or after '"'
		  || (cclass[i+1] == agg::unicode_helper::QU_AmbiguousQuotation) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if ( (cclass[i+1] == agg::unicode_helper::BA_BreakOpportunityAfter)			//	LB 15 / Don't break before hyphen-minus, etc. or after accute accents
		  || (cclass[i+1] == agg::unicode_helper::HY_Hyphen)
		  || (cclass[i+1] == agg::unicode_helper::NS_NonStarter)
		  || (cclass[i] == agg::unicode_helper::BB_BreakOpportunityBefore) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if ( (cclass[i] == agg::unicode_helper::HY_Hyphen)							//	LB 15b/ Break after hyphen-minus and before accute accents
		  || (cclass[i+1] == agg::unicode_helper::BB_BreakOpportunityBefore) )
		{
			breaks[i] = agg::unicode_helper::break_yes_option;
			continue;
		}
		if ( (cclass[i+1] == agg::unicode_helper::IN_Inseparable)					//	LB 16 / Don't break between two ellipses, or between letters or numbers and ellipsis
		  && ( (cclass[i] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol)
		    || (cclass[i] == agg::unicode_helper::ID_Ideographic)
			|| (cclass[i] == agg::unicode_helper::IN_Inseparable)
			|| (cclass[i] == agg::unicode_helper::NU_Numeric) ) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if ( ( (cclass[i] == agg::unicode_helper::ID_Ideographic)					//	LB 17 / Don't break within 'a9', '3a' or '<ideogram>%'
			&& (cclass[i+1] == agg::unicode_helper::PO_PostfixNumeric) )
		  || ( (cclass[i] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol)
			&& (cclass[i+1] == agg::unicode_helper::NU_Numeric) )
		  || ( (cclass[i] == agg::unicode_helper::NU_Numeric)
			&& (cclass[i+1] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol) ) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if ( ( (cclass[i+1] == agg::unicode_helper::NU_Numeric)						//	LB 18 / Don't break between the following pairs of classes ...
			&& ( (cclass[i] == agg::unicode_helper::HY_Hyphen)						//			which accepts numbers in the form ...
			  || (cclass[i] == agg::unicode_helper::IS_InfixSeparatorNumeric)		//			PR ? ( OP | HY ) ? NU ( NU | IS ) * CL ? PO ?
			  || (cclass[i] == agg::unicode_helper::NU_Numeric)
			  || (cclass[i] == agg::unicode_helper::PR_PrefixNumeric)
			  || (cclass[i] == agg::unicode_helper::SY_SymbolsAllowingBreaks) ) )
		  || ( (cclass[i] == agg::unicode_helper::PR_PrefixNumeric)
			&& ( (cclass[i+1] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol)
			  || (cclass[i+1] == agg::unicode_helper::HY_Hyphen)
			  || (cclass[i+1] == agg::unicode_helper::ID_Ideographic)
			  || (cclass[i+1] == agg::unicode_helper::OP_OpeningPunctuation) ) )
		  || ( (cclass[i+1] == agg::unicode_helper::PO_PostfixNumeric)
		    && ( (cclass[i] == agg::unicode_helper::CL_ClosingPunctuation)
			  || (cclass[i] == agg::unicode_helper::NU_Numeric) ) ) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		if ( (cclass[i] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol)		//	LB 19 / Don't break between alphabetics
		  && (cclass[i+1] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol) )
		{
			breaks[i] = agg::unicode_helper::break_no;
			continue;
		}
		
		breaks[i] = agg::unicode_helper::break_yes_option;									//	LB 20 / Break everywhere else
	}
	
	if (breaks[length-1] == agg::unicode_helper::break_no)
	{
		if (cclass[length-1] == agg::unicode_helper::AL_OrdinaryAlphabeticAndSymbol)
		{
			breaks[length-1] = agg::unicode_helper::break_no_is_alpha;
		}
		
		if (cclass[length-1] == agg::unicode_helper::SP_Space)
		{
			breaks[length-1] = agg::unicode_helper::break_yes_option;
		}
		
		if (cclass[length-1] == agg::unicode_helper::ZW_ZeroWidthSpace)
		{
			breaks[length-1] = agg::unicode_helper::break_yes_option;
		}
	}
	
	if (cpairs_or)
	{
		//	Fix the output buffer. UTF-16 character pairs (surrogates) must be accounted for in
		//	the output buffer. The internal buffers 
		
		int8u* breaks_src = cclass;
		int8u* breaks_dst = breaks;
		
		memcpy (breaks_src, breaks, length);
		
		for (size_t i = 0; i < length; i++)
		{
			*breaks_dst++ = *breaks_src++;
			
			if (cpairs[i])
			{
				//	The break in the surrogate pair will be attached only to the first surrogate, the
				//	second one should never be considered, anyway.
				
				*breaks_dst++ = agg::unicode_helper::break_no_surrogate;
			}
		}
	}
	
	if (tmp_memory)
	{
		delete tmp_memory;
	}
}

/*****************************************************************************/
