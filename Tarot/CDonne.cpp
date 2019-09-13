#include "CDonne.h"
#include "CJoueur.h"
#include <iostream>
using namespace std;
//#define TESTU_COMPTERPOINTS
//#define TESTU_SETCAMPPETIT
//#define TESTU_SETPOIGNEE
//#define TESTU_SETCHELEM
//#define TESTU_SETCONTRAT

CDonne::CDonne(CJoueur * donneur)
{
	le_donneur = donneur;
}

//vieux constructeur
/*
CDonne::CDonne(CJoueur *donneur, CJoueur *preneur, CJoueur *defenseurs[3])
{
	this->le_donneur = donneur;
	this->lePreneur = preneur;
	for (int i = 0; i <= 2; i++)
	{
		this->les_defenseurs[i] = defenseurs[i];
	}
}
*/

CDonne::~CDonne()
{
	delete le_donneur;
	delete lePreneur;
	for (int i = 0; i <= 2; i++)
	{
		delete les_defenseurs[i];
	}
}

//à tester
void CDonne::CompterPoints(int bouts, int pts, poignee pgn, camp cmp)
{
	int ptf = 0;
	int bonus_pgn = 0;
	int bonus_ctr = 1;
	int objectif = 0;
	int score_preneur = 0;
	int score_defenseurs = 0;
	bool victoire = false;
	switch (typeContrat)//pas ok
	{
	case prise:
		bonus_ctr = 1;
		break;
	case garde:
		bonus_ctr = 2;
		break;
	case garde_sans:
		bonus_ctr = 4;
		break;
	case garde_contre:
		bonus_ctr = 6;
		break;
	}
	switch (bouts)//ok
	{
	case 0:
		objectif = 56;
		break;
	case 1:
		objectif = 51;
		break;
	case 2:
		objectif = 41;
		break;
	case 3:
		objectif = 36;
		break;
	}
	switch (pgn)
	{
	case simple:
		bonus_pgn = 10;
		break;
	case doublee:
		bonus_pgn = 20;
		break;
	case triplee:
		bonus_pgn = 30;
		break;
	}
	ptf = (pts - objectif);
	if (ptf < 0)//ok
	{
		score_preneur = ((ptf - 25)*bonus_ctr) * 3;
		score_defenseurs = ((-ptf) + 25)*bonus_ctr;
		victoire = false;
	}
	else if (ptf >= 0)//ok
	{
		score_preneur = ((ptf + 25)*bonus_ctr) * 3;
		score_defenseurs = ((-ptf) - 25)*bonus_ctr;
		victoire = true;
	}
	if (campPetitAuBout != personne)//pas ok
	{
		if (campPetitAuBout == preneur)
		{
			score_preneur = score_preneur + ((10 * bonus_ctr) * 3);
			score_defenseurs = score_defenseurs - (10 * bonus_ctr);
		}
		else if (campPetitAuBout == defenseur)
		{
			score_preneur = score_preneur - ((10 * bonus_ctr) * 3);
			score_defenseurs = score_defenseurs + (10 * bonus_ctr);
		}
	}
	if (campPoignee != personne)//pas ok
	{
		if ((campPoignee == preneur && victoire == false) || (campPoignee == defenseur && victoire == false))
		{
			score_preneur = score_preneur - (3 * bonus_pgn);
			score_defenseurs = score_defenseurs + bonus_pgn;
		}
		else if ((campPoignee == preneur && victoire == true) || (campPoignee == defenseur && victoire == true))
		{
			score_preneur = score_preneur + (3 * bonus_pgn);
			score_defenseurs = score_defenseurs - bonus_pgn;
		}
	}
	lePreneur->MajScore(score_preneur);
	for (int i = 0; i <= 2; i++)
	{
		les_defenseurs[i]->MajScore(score_defenseurs);
	}
}

//ok
void CDonne::SetCampPetitAuBout(camp p)
{
	campPetitAuBout = p;
}

//ok
void CDonne::SetTypePoignee(camp poigne, poignee typ)
{
	typePoignee = typ;
	campPoignee = poigne;

}

//ok
void CDonne::SetChelemD(chelem type)
{
	typeChelem = type;
}

void CDonne::SetContratD(CJoueur *d, contrat c,CJoueur * lesDefenseurs[])
{
	typeContrat = c;
	lePreneur = d;
	for (int i = 0; i < 3; i++)
	{
		les_defenseurs[i] = lesDefenseurs[i];

	}
}

#ifdef TESTU_COMPTERPOINTS
void main()
{
	CJoueur le_donneur = CJoueur("testeur_donneur", 0);
	CDonne donne(&le_donneur);
	donne.CompterPoints(0, 55, non, preneur);//perdu
	donne.CompterPoints(0, 57, non, preneur);//gagné
	donne.CompterPoints(1, 50, non, preneur);//perdu
	donne.CompterPoints(1, 52, non, preneur);//gagné
	donne.CompterPoints(2, 40, non, preneur);//perdu
	donne.CompterPoints(2, 42, non, preneur);//gagné
	donne.CompterPoints(3, 35, non, preneur);//perdu
	donne.CompterPoints(3, 37, non, preneur);//gagné
}
#endif

#ifdef TESTU_SETCAMPPETIT
void main()
{
	CJoueur le_donneur = CJoueur("testeur_donneur", 0);
	CDonne donne(&le_donneur);
	donne.SetCampPetitAuBout(personne);
	donne.SetCampPetitAuBout(preneur);
	donne.SetCampPetitAuBout(defenseur);
}	
#endif

#ifdef TESTU_SETPOIGNEE
void main()
{
	CJoueur le_donneur = CJoueur("testeur_donneur", 0);
	CDonne donne(&le_donneur);
	donne.SetTypePoignee(personne, non);
	donne.SetTypePoignee(personne, simple);
	donne.SetTypePoignee(personne, doublee);
	donne.SetTypePoignee(personne, triplee);
	donne.SetTypePoignee(preneur, non);
	donne.SetTypePoignee(preneur, simple);
	donne.SetTypePoignee(preneur, doublee);
	donne.SetTypePoignee(preneur, triplee);
	donne.SetTypePoignee(defenseur, non);
	donne.SetTypePoignee(defenseur, simple);
	donne.SetTypePoignee(defenseur, doublee);
	donne.SetTypePoignee(defenseur, triplee);
}
#endif

#ifdef TESTU_SETCHELEM
void main()
{
	CJoueur le_donneur = CJoueur("testeur_donneur", 0);
	CDonne donne(&le_donneur);
	donne.SetChelemD(sans);
	donne.SetChelemD(reussi);
	donne.SetChelemD(perdu);
	donne.SetChelemD(sans_annonce);
}
#endif

#ifdef TESTU_SETCONTRAT
void main()
{
	CJoueur le_donneur = CJoueur("testeur_donneur", 0);
	CDonne donne(&le_donneur);
	donne.SetContratD()
}
#endif