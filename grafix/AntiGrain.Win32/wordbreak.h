//	wordbreak.h
//
//	Copyright © 2002,	   Daniel ROUX, EPSITEC SA, Ch. de la Mouette 5,
//						   CH-1092 BELMONT, Switzerland. All rights reserved.
//
//	Copyright © 2003-2006, Pierre ARNAUD, OPaC bright ideas, Ch. du Fontenay 6,
//	                       CH-1400 YVERDON, Switzerland. All rights reserved.
//
//	Contact: pierre.arnaud@opac.ch, http://www.opac.ch
//	License: see license.txt

// Algorithme de césure pour les mots français.
// Ce système a été inventé en 1985 pour le logiciel
// Text sur Smaky. Il était initialement programmé en
// assembleur Calm 2 pour le processeur Mototola 68000.
// Ceci explique son approche très compacte et efficace,
// avec 4 dictionnaires extrèmement courts.
// Ce système permet de gérer tous les mots, même s'ils
// n'existent pas ou s'ils sont mal orthographiés, selon
// la logique utilisée dans la langue française :
//   antichenit    -> an/ti/che/nit
//   bisouillage   -> bi/souil/la/ge
//   fradornère    -> fra/dor/nè/re
//   franssaize    -> frans/sai/ze
//   fummée        -> fum/mée
//   ortografe     -> or/to/gra/fe
//   ponturer      -> pon/tu/rer
//   tralalèrement -> tra/la/lè/re/ment
// Le mot pris en entrée doit être entièrement en majuscules
// non accentuées.

extern bool Break (const char* word, int length, int* list);
extern char ReduceToASCIIAndConvertToUpper (int utf);
