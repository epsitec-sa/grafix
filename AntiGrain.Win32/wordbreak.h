// wordbreak.h
//

// (c) 2002 - EPSITEC & Daniel Roux
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
