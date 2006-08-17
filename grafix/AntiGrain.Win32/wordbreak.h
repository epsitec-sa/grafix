//	wordbreak.h
//
//	Copyright � 2002,	   Daniel ROUX, EPSITEC SA, Ch. de la Mouette 5,
//						   CH-1092 BELMONT, Switzerland. All rights reserved.
//
//	Copyright � 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved.
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

// Algorithme de c�sure pour les mots fran�ais.
// Ce syst�me a �t� invent� en 1985 pour le logiciel
// Text sur Smaky. Il �tait initialement programm� en
// assembleur Calm 2 pour le processeur Mototola 68000.
// Ceci explique son approche tr�s compacte et efficace,
// avec 4 dictionnaires extr�mement courts.
// Ce syst�me permet de g�rer tous les mots, m�me s'ils
// n'existent pas ou s'ils sont mal orthographi�s, selon
// la logique utilis�e dans la langue fran�aise :
//   antichenit    -> an/ti/che/nit
//   bisouillage   -> bi/souil/la/ge
//   fradorn�re    -> fra/dor/n�/re
//   franssaize    -> frans/sai/ze
//   fumm�e        -> fum/m�e
//   ortografe     -> or/to/gra/fe
//   ponturer      -> pon/tu/rer
//   tralal�rement -> tra/la/l�/re/ment
// Le mot pris en entr�e doit �tre enti�rement en majuscules
// non accentu�es.

extern bool Break (const char* word, int length, int* list);
extern char ReduceToASCIIAndConvertToUpper (int utf);
