/*
 *	agg_text_unicode_support.h
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

#ifndef AGG_TEXT_UNICODE_SUPPORT_INCLUDED
#define	AGG_TEXT_UNICODE_SUPPORT_INCLUDED

#include "agg_basics.h"

/*****************************************************************************/

namespace agg
{
	/*
	 *	The Unicode Helper class uses the algorithms published by the
	 *	Unicode consortium to identify characters and provided line
	 *	break information.
	 *
	 *	The LineBreak-4.0.0.txt used by the algorithms can be found
	 *	at http://www.unicode.org/Public/4.0-Update/LineBreak-4.0.0.txt
	 */
	
	class unicode_helper
	{
		class internal_text_loader;
		
	public:
		enum break_options_enum
		{
			break_no				= 0,					//	don't break
			break_no_is_alpha		= break_no + 1,			//	don't break; alphabetic character
			break_no_surrogate		= break_no + 2,			//	don't break; second half of a surrogate pair
			
			break_yes				= 4,
			break_yes_always		= break_yes + 0,		//	break always (manual break)
			break_yes_option		= break_yes + 1,		//	break optional
			
			break_hyphenate			= 8,
			break_hyphenate_poor	= break_hyphenate + 0,	//	hyphenate: poor choice
			break_hyphenate_good	= break_hyphenate + 1,	//	hyphenate: good choice
			break_hyphenate_best	= break_hyphenate + 2,	//	hyphenate: best choice
			
			break_horizontal_tab	= 12,					//	this is a horizontal tabulation
			
			break_mask				= 0xfc
		};
		
		enum unicode_code_enum
		{
			StartOfText				= 0x0002,				//	start of inserted text
			EndOfText				= 0x0003,				//	end of inserted text
			StartOfGuardedArea		= 0x0096,
			EndOfGuardedArea		= 0x0097,
			
			HorizontalTab			= 0x0009,
			
			Space					= 0x0020,
			QuotationMark			= 0x0022,
			PercentSign				= 0x0025,
			Ampersand				= 0x0026,
			LessThanSign			= 0x003C,
			GreaterThanSign			= 0x003E,
			
			LineFeed				= 0x000A,				//	don't use internally (LF)
			VerticalTab				= 0x000B,				//	don't use internally (VT)
			FormFeed				= 0x000C,				//	- renamed PageSeparator
			CarriageReturn			= 0x000D,				//	don't use internally (CR)
			NextLine				= 0x0085,				//	don't use internally (NEL)
			
			//	Spaces:
			
			EnQuad					= 0x2000,
			EmQuad					= 0x2001,
			EnSpace					= 0x2002,
			EmSpace					= 0x2003,
			ThreePerEmSpace			= 0x2004,				//	1/3 em
			FourPerEmSpace			= 0x2005,				//	1/4 em
			SixPerEmSpace			= 0x2006,				//	1/6 em
			FigureSpace				= 0x2007,				//	non-breaking, same width as a digit
			PunctuationSpace		= 0x2008,
			ThinSpace				= 0x2009,				//	1/5 em
			HairSpace				= 0x200A,
			ZeroWidthSpace			= 0x200B,				//	may expand in justification
			ZeroWidthNonJoiner		= 0x200C,
			ZeroWidthJoiner			= 0x200D,
			
			Ellipsis				= 0x2026,				//	...
			
			MediumMathSpace			= 0x205F,				//	4/18 em
			WordJoiner				= 0x2060,				//	same as ZeroWidthSpace, not breaking
			
			FunctionApplication		= 0x2061,				//	math: contiguity operator
			InvisibleTimes			= 0x2062,				//	math: contiguity operator
			InvisibleSeparator		= 0x2063,				//	math: contiguity operator (invisible comma)
			
			NoBreakSpace			= 0x00A0,
			NarrowNoBreakSpace		= 0x202F,

			
			//	Formatting characters:
			
			LeftToRightMark				= 0x200E,
			RightToLeftMark				= 0x200F,
			
			LeftToRightEmbedding		= 0x202A,
			RightToLeftEmbedding		= 0x202B,
			PopDirectionalFormatting	= 0x202C,
			LeftToRightOverride			= 0x202D,
			RightToLeftOverride			= 0x202E,
			
			PageSeparator			= FormFeed,
			
			LineSeparator			= 0x2028,
			ParagraphSeparator		= 0x2029,
			
			//	Dashes:
			
			HyphenMinus				= 0x002D,
			SoftHyphen				= 0x00AD,
			
			Hyphen					= 0x2010,
			NonBreakingHyphen		= 0x2011,
			FigureDash				= 0x2012,				//	non-breaking, same width as a digit
			EnDash					= 0x2013,
			EmDash					= 0x2014,
			QuotationDash			= 0x2015,
			
			//	Special:
			
			ObjectReplacement		= 0xFFFC,
			
			Invalid					= 0xFFFF,
		};
		
		/*
		 *	Breaking classes, as defined by the Unicode Standard Annex #14, version 3.2.0.
		 */
		
		enum break_class_enum						
		{
			XX_Unknown = 0,									//	unknown line breaking behaviour
			
			//	Normative Properties
			
			BK_MandatoryBreak,								//	cause a line break (after)
			CM_CombiningMarks,								//	prohibit a line break between char and preceding char
			SG_Surrogates,									//	prohibit a break between high and following low surrogate
			ZW_ZeroWidthSpace,								//	optional break
			GL_NonBreakingGlue,								//	prohibit a line break before or after
			CB_ContingentBreakOpportunity,					//	provide a line break opportunity contingent on add. info.
			SP_Space,										//	generally provide a line break opportunity after, enables indirect breaks
			
			//	Break Opportunities
			
			BA_BreakOpportunityAfter,						//	generally provide a line break opportunity after
			BB_BreakOpportunityBefore,						//	generally provide a line break opportunity before
			B2_BreakOpportunityBeforeAndAfter,				//	provide a line break opportunity before and after
			HY_Hyphen,										//	provide a line break opportunity after, except in numeric context
			
			//	Characters Prohibiting Certain Breaks
			
			IN_Inseparable,									//	allow only indirect line breaks between pairs
			NS_NonStarter,									//	allow only indirect line breaks before
			OP_OpeningPunctuation,							//	prohibit a line break after
			CL_ClosingPunctuation,							//	prohibit a line break before
			QU_AmbiguousQuotation,							//	act as they are both opening and closing
			EX_ExclamationInterrogation,					//	prohibit line break before
			
			//	Numeric Context
			
			NU_Numeric,										//	form numeric expressions
			IS_InfixSeparatorNumeric,						//	prevent breaks after any and before numeric
			SY_SymbolsAllowingBreaks,						//	prevent a break before and allow a break after
			PR_PrefixNumeric,								//	don't break in front of a numeric expression
			PO_PostfixNumeric,								//	don't break following a numeric expression
			
			//	Other Characters
			
			AL_OrdinaryAlphabeticAndSymbol,					//	...
			ID_Ideographic,									//	break before or after, except in some numeric context
			AI_AmbiguousAlphabeticOrIdeographic,			//	...
			SA_ComplexContextSouthEastAsian,				//	...
			
			last_break_class_value
		};
		
	private:
		enum break_class_flags_enum
		{
			mask_break_class	= 0x3F,
			flag_capital_letter	= 0x80,
		};
		
		struct break_elem_record
		{
			break_elem_record*	next;
			bool				is_capital;
			int8u				break_class;
			int32u				code_begin;
			int32u				code_end;
		};
		
		int8u					m_break_table_1[0x3200];	//	Unicode range 000000-0031FF
		int8u					m_break_table_2[0x0700];	//	Unicode range 00F900-00FFFF
		break_elem_record*		m_break_list_head;
		break_elem_record*		m_break_list_tail;
		
	private:
		bool load_line_break_information (const char* file_name);
		bool load_line_break_information (const char* source, size_t length);
		bool load_line_break_information (internal_text_loader& loader);
		
		unicode_helper(const char* file_path);
		unicode_helper(const char* data, size_t length);
		~unicode_helper();
		
		unicode_helper (const unicode_helper & );
		unicode_helper & operator = (const unicode_helper & );
		
		static int get_num_arg (const char* & script, int value);
		
		static const char*		m_break_file_name;
		static const char*		m_break_data_source;
		static size_t			m_break_data_length;
		
	public:
		static break_class_enum get_break_class_from_name(const char* find);
		static break_class_enum get_break_class(int32u code);
		static const char* get_break_class_name(agg::unicode_helper::break_class_enum break_class);
		
		static bool is_capital_letter(int32u code);
		static bool is_space_break_class(int32u code, agg::unicode_helper::break_class_enum break_class);
		static bool is_space_break_class(int32u code);
		static bool is_stretchable_space_class(int32u code, agg::unicode_helper::break_class_enum break_class);
		
		static void analyse_breaks(const wchar_t* text, size_t length, int8u* breaks);
		static bool read_character_code(const wchar_t* text, int32u& code);
		
		static void setup_line_break_file(const char* file_name);
		static void setup_line_break_data(const char* data, size_t length);
		
		static const unicode_helper& current();
	};
}

/*****************************************************************************/

#endif /* AGG_TEXT_UNICODE_SUPPORT_INCLUDED */
