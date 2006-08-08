//	wordbreak.cpp
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

#include "wordbreak.h"

/*****************************************************************************/

// Structure permettent d'avancer et de reculer dans
// un buffer de texte.

struct TextPointer
{
	const char*	buffer;		// début du buffer de texte
	int			length;		// longueur du texte
	int			position;	// position du pointeur
	int			start;		// début effectif du mot
	int			banned;		// position coupure interdite
	int			root;		// longueur préposition
	
	int  GetChar (int index = 0) const;
	bool Recede ();
	bool Advance ();
	bool IsDouble ();
	bool SkipVoyelles ();
	bool SkipConsonnes (bool first);
	bool IsRestConsonne () const;
	bool SearchDico (const char *dico[], const char *&found) const;
	bool IsSyllable(bool first);
	void Exception(int *&list);
};

/*****************************************************************************/

// Dictionnaires
// -------------

// Dictionnaire de tous les débuts possibles de syllabes (cette
// liste ne doit contenir que des consonnes) :

static const char *dico_sy[] =
{
	"BL",		// re-blochon
	"BR",		// cham-bre
	"CH",		// al-chimie
	"CL",		// in-cliner
	"CR",		// convain-cre
	"DR",		// suspen-dre
	"FL",		// in-fluence
	"FR",		// bé-froid
	"GL",		// jon-gleur
	"GN",		// ma-gnétique
	"GR",		// bi-gre
	"PH",		// phos-phore
	"PL",		// exem-plaire
	"PR",		// com-préhension
	"PS",		// rha-psodie
	"SCH",		// (pour l'allemand)
	"TH",		// or-thographe
	"TR",		// cons-truction
	"VR",		// fiè-vre
	0
};

// Dictionnaire de tous les mots (ou débuts de mots) à couper
// normalement (cette liste est parcourue AVANT la liste des
// divisions étymoligiques dico_ex) :

static const char *dico_ne[] =
{
	"DESERT",	// dé-sert
	"DESID",	// dé-sidératif
	"DESIGN",	// dé-signer
	"DESIR",	// dé-sirer
	"DESIS",	// dé-sister
	"DESOL",	// dé-solé
	"DESORM",	// dé-sormais

	"HEMIE",	// hemiè-dre

	"INIQ",		// ini-que
	"INIT",		// ini-tiative

	"NONA",		// no-nante

	"PREN",		// pren-dre
	"PRESB",	// pres-byte
	"PRESCR",	// pres-crire
	"PRESQ",	// pres-que
	"PRESS",	// pres-sion
	"PREST",	// pres-tence
	"PREU",		// preu-ve

	"REINE",	// rei-ne
	"RETROU",	// retrou-ver

	"SURAN",	// su-ranné
	"SUREA",	// su-reau
	"SUREMEN",	// su-rement
	"SURET",	// su-reté
	"SURICA",	// su-ricate
	"SUROI",	// su-roît
	"SUROS",	// su-ros
	"SURIR",	// su-rir
	"SUPERI",	// su-pé-rio-ri-té

	"TRANSI",	// tran-sistor
	0
};

// Dictionnaire de tous les mots (ou débuts de mots) à couper
// spécialement (divisions étymologiques) :

static const char *dico_ex[] =
{
	"AERO 4",		// aéro-spatial
	"ANTIA 24",		// anti-alcoolique
	"ANTISP 24",	// anti-spasmodique
	"ATMO 24",		// atmo-sphère

	"CAOU 4",		// caou-tchouc
	"COO 2",		// co-opération
	"CIS 3",		// cis-alpin

	"DES 3",		// dés-aveu
	"DIAGN 4",		// diag-nostique

	"EXTRAO 25",	// extra-ordinaire

	"HEMI 4",		// hemi-sphère

	"INA 2",		// in-actif
	"INE 2",		// in-égal
	"INI 2",		// in-imaginable
	"INO 2",		// in-oubliable
	"INSTAB 2",		// in-stable
	"INU 2",		// in-utiliser

	"KILO 24",		// kilo-octets

	"MALADR 3",		// mal-adroit
	"MALAP 3",		// mal-appris
	"MALENT 3",		// mal-entendu
	"MALINT 3",		// mal-intensionné
	"MALODO 3",		// mal-odorant
	"MESAL 3",		// mes-alliance
	"MESAV 3",		// mes-aventure
	"MESE 3",		// mes-estimer
	"MESI 3",		// mes-intelligence
	"MICRO 25",		// micro-ordinateur

	"NON 3",		// non-obstant

	"OTORH 3",		// oto-rhinolaryngologiste

	"PRE 3",		// pré-occuper
	"PROE 3",		// pro-éminent

	"REAB 2",		// ré-abonner
	"REAC 2",		// ré-action
	"REAF 2",		// ré-affirmer
	"REAG 2",		// ré-agir
	"REAR 2",		// ré-armer
	"REAS 2",		// ré-assigner
	"REAT 2",		// ré-atteler
	"REE 2",		// ré-élection
	"REI 2",		// ré-intégrer
	"REO 2",		// ré-organiser
	"RETRO 25",		// rétro-spectif

	"SUBLU 3",		// sub-lunaire
	"SUBO 3",		// sub-ordonner
	"SUBRO 3",		// sub-rogateur
	"SUBUR 3",		// sub-urbain
	"SUR 3",		// sur-élever
	"SUPER 25",		// su-per-struc-tu-re

	"TRANS 5",		// trans-atlantique
	"TECH 4",		// tech-nique
	"TELE 24",		// télé-scope
	0
};

// Dictionnaire de tous les débuts de mots à ne pas couper
// (exceptions très spéciales) :

const char *dico_nc[] =
{
	"CON 3",		// con-cierge
	"ELLE 2",		// el-le
	"HYMNE 3",		// hym-ne
	0
};

/*****************************************************************************/

// Donne un caractère. Si index=0, c'est le caractère sous
// le pointeur qui est rendu. La valeur d'index peut être
// positive ou négative.

int
TextPointer::GetChar (int index) const
{
	if (this->position + index < 0)
		return 0;
	
	if (this->position+index >= this->length)
		return 0;
	
	return this->buffer[this->position+index];
}

// Recule le pointeur.

bool
TextPointer::Recede ()
{
	if (this->position == 0)
		return false;
	
	this->position--;
	
	return true;
}

// Avance le pointeur.

bool
TextPointer::Advance ()
{
	if (this->position >= this->length)
		return false;
	
	this->position++;
	
	return true;
}


// Test si le caractère est une voyelle, c'est-à-dire :
//  "A" , "E" , "I" , "O" , "U"  ou  "Y"
// La lettre "X" suit les mêmes règles que la lettre "Y".
// De plus, une voyelle peut être un apostrophe pour résoudre
// les cas du genre  "l'écran"  "qu'il"  "d'apprendre"  etc.
// (on suppose qu'un apostrophe est toujours suivit d'une
// voyelle).

bool IsVoyelle(int letter)
{
	switch (letter)
	{
		case 'A': case 'E': case 'I': case 'O': case 'U':
		case 'Y': case 'X': case '\'':
			return true;
	}
	
	return false;
}

// Test s'il y a deux mêmes lettres qui se suivent.

bool
TextPointer::IsDouble ()
{
	// Reste moins de 2 lettres ?
	if (this->length-this->position < 2 )
		return false;

	// Deux lettres différentes ?
	if (this->GetChar(0) != this->GetChar(1) )
		return false;
	
	// Vérifie si la coupure est dans une terminaison "féminin pluriel",
	// c'est-à-dire "ées", pour éviter de couper "commencé-es" !
	
	if ( this->length-this->position == 3
	  && this->GetChar(0) == 'E'
	  && this->GetChar(1) == 'E'
	  && this->GetChar(2) == 'S' )
	{
		return false;
	}
	
	this->Advance ();
	return true;
}

// Saute une ou plusieurs voyelles.
// Retourne true si doubles lettres.

bool
TextPointer::SkipVoyelles ()
{
	while ( true )
	{
		if ( this->position == this->length )
			return false;
		
		if ( this->IsDouble () )
			return true;
		
		if ( !IsVoyelle (this->GetChar ()) )
			return false;
		
		this->Advance ();
	}
}

// Saute une ou plusieurs consonnes.
// Retourne true si doubles lettres.

bool
TextPointer::SkipConsonnes (bool bFirstSyllable)
{
	if ( !bFirstSyllable )
	{
		while ( true )
		{
			if ( this->position == this->length )
				return false;
			if ( !IsVoyelle (this->GetChar ()) )
				break;
			
			this->Advance ();
		}
	}

	while ( true )
	{
		if ( this->position == this->length )
			return false;
		if ( this->IsDouble () )
			return true;
		if ( IsVoyelle (this->GetChar ()) )
			return false;
		
		this->Advance ();
	}
}

// Teste s'il ne reste plus que des consonnes dans le mot.

bool
TextPointer::IsRestConsonne () const
{
	int		letter;
	TextPointer tmp = *this;

	while ( true )
	{
		letter = tmp.GetChar ();
		if ( letter != 'X'
		  && IsVoyelle (letter) )
		{
			return false;
		}
		
		if ( !tmp.Advance () )
			return true;
	}
}

// Cherche un groupe de lettres dans un dictionnaire.

bool
TextPointer::SearchDico (const char *dico[], const char *&found) const
{
	const char*	key;

	if ( this->position == this->length )
		return false;

	for (int i = 0; (key = dico[i]) != 0; i++ )
	{
		for (int j = 0; ; j++)
		{
			if ( key[j] == 0 )
			{
				found = key+j;
				return true;
			}
			if ( key[j] == ' ' )
			{
				found = key+j+1;
				return true;
			}

			if ( this->GetChar (j) != key[j] )
				break;
		}
	}
	
	return false;
}

// Cherche s'il s'agit d'une syllabe normale, c'est-à-dire:
//  - une ou plusieurs consonnes quelconques (voir *)
//  - une ou plusieurs voyelles quelconques (voir *)
//  - éventuellement quelques consonnes (jusqu'au début de la
//    syllabe suivante)
// (*) Considère qu'il s'agit d'une syllabe lorsque deux mêmes
// lettres sont trouvées.

bool
TextPointer::IsSyllable (bool bFirstSyllable)
{
	TextPointer	tp;
	const char* found;
	
	// Reste moins de 2 lettres ?
	if ( this->length-this->position < 2 )
		return false;
	
	tp = *this;
	if ( tp.SkipConsonnes (bFirstSyllable) )
	{
		*this = tp;
		return true;
	}

	if ( tp.SkipVoyelles () )
	{
		*this = tp;
		return true;
	}

	while ( true )
	{
		// Début de syllabe ?
		if ( tp.SearchDico (dico_sy, found) )
		{
			*this = tp;
			return true;
		}

		// Doubles lettres ?
		if ( tp.IsDouble () )
		{
			*this = tp;
			return true;
		}

		if ( tp.length-tp.position < 2 )
			return false;

		// Consonne-voyelle ?
		if ( IsVoyelle (tp.GetChar (1)) )
		{
			*this = tp;
			return true;
		}

		tp.Advance ();
	}
}

// Cherche dans les dictionnaires si le mot est une exception.

void
TextPointer::Exception(int *&list)
{
	const char* found;

	if ( this->SearchDico (dico_ne, found) )
	{
		return;
	}

	if ( this->SearchDico (dico_nc, found) )
	{
		this->banned = *found-'0';
		return;
	}
	
	if ( this->SearchDico (dico_ex, found) )
	{
		while ( *found != 0 )
		{
			this->root = (*found)-'0';  // offset préposition
			*list++ = this->start+(*found++)-'0';
		}
		*list = 0;
		return;
	}
}

// Coupe un mot selon un certain nombre de règles basées sur
// les voyelles et les consonnes.
// Rend une liste des coupures possibles, terminée par zéro.

bool
Break (const char* word, int length, int* list)
{
	TextPointer	text;
	int			i, letter, len, iList;
	bool		bFirstSyllable;

	text.buffer   = word;
	text.length   = length;
	text.position = 0;
	text.start    = 0;
	text.banned   = 0;
	text.root     = 0;
	
	iList = 0;
	list[iList] = 0;  // aucune coupure

	// Ignore les caractères à la fin qui ne sont pas des lettres,
	// pour résoudre les cas du type:  (commencé-e)
	for ( i=text.length-1 ; i>=0 ; i-- )
	{
		letter = text.GetChar (i);
		
		if ( letter >= 'A' && letter <= 'Z' )
			break;
		
		text.length --;  // ignore un caractère à la fin
	}

	// Reste moins de 5 lettres ?
	if ( text.length-text.position < 5 )
		return false;

#if 0
	// Cherche si le mot contient un "-". Si oui, permet une seule
	// coupure, à l'endroit où est le premier "-". Cette position
	// est signalée dans la liste avec le bit 2^7 à un pour indiquer
	// qu'il ne faut pas rajouter un "-".
	// Exemples: aime-/t-il  c'est-/à-dire  viendra-/t-on  ...
	for ( i=0 ; i<text.length ; i++ )
	{
		if ( GetChar(text,i) == '-' )
		{
			list[iList++] = -(i+1);  // coupure "spéciale"
			list[iList] = 0;
			return true;
		}
	}
#endif

	// Avance dans le mot jusqu'à ce qu'une lettre soit rencontrée.
	len = 0;
	for ( i=0 ; i<text.length ; i++ )
	{
		letter = text.GetChar (i);
		
		if ( letter >= 'A' && letter <= 'Z' )
			break;
		
		len ++;
	}
	
	text.buffer += len;
	text.length -= len;
	text.start  += len;

	// Reste moins de 5 lettres ?
	if ( text.length-text.position < 5 )
		return false;

	// Test si la 2ème ou 3ème lettre du mot est un apostrophe,
	// pour résoudre les cas du genre:  l'extra-ordinaire  qu'elles
	if ( text.GetChar(2) == '\'' )
	{
		text.buffer += 3;
		text.length -= 3;
		text.start  += 3;
	}
	else if ( text.GetChar(1) == '\'' )
	{
		text.buffer += 2;
		text.length -= 2;
		text.start  += 2;
	}

	// Reste moins de 5 lettres ?
	if ( text.length-text.position < 5 )
		return false;

	// Cherche dans le dictionnaire des exceptions si le mot en fait
	// partie ou pas.
	text.Exception (list);

	// Avance dans le mot syllabes par syllabes ...
	bFirstSyllable = true;
	while ( true )
	{
		if ( text.length-text.position == 0 )
			return false;

		if ( !text.IsSyllable(bFirstSyllable) )
		{
			text.Advance ();
			continue;
		}

		// Teste si la coupure est une coupure interdite à cause d'une
		// exception dans dico_nc.
		
		if ( text.position == text.banned )
			continue;

		// Teste si la coupure est trop proche du début du mot (par
		// exemple: é-cole) ou trop proche de la fin du mot (par
		// exemple: école-s).
		
		if ( text.position < text.root+2 )
			continue;
		
		if ( text.position > text.length-2 )
			continue;

		bFirstSyllable = false;

		// Teste s'il ne reste que des consonnes depuis cette éventuelle
		// coupure (par exemple: rangeme-nts)
		if ( text.IsRestConsonne () )
			break;

		// Si on est juste après un apostrophe, il faut ignorer
		// la coupure. Par exemple dans:  aujourd'hui
		if ( text.GetChar(-1) == '\'' )
			continue;
		if ( text.GetChar(-2) == '\'' )
			continue;

		list[iList++] = text.start+text.position;
		list[iList] = 0;
	}
	
	return false;
}
