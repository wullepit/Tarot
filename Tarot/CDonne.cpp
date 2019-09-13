#include "CDonne.h"
#include "CJoueur.h"
#define TESTU_COMPTERPOINTS
//#define TEST

CDonne::CDonne(CJoueur *donneur, CJoueur *preneur, CJoueur *defenseurs[3])
{
	this->le_donneur = donneur;
	this->le_preneur = preneur;
	for (int i = 0; i <= 2; i++)
	{
		this->les_defenseurs[i] = defenseurs[i];
	}
}

CDonne::~CDonne()
{
	delete le_donneur;
	delete le_preneur;
	for (int i = 0; i <= 2; i++)
	{
		delete les_defenseurs[i];
	}
}

void CDonne::compter_points(int bouts, int pts, poignee pgn, camp cmp)
{
	int ptf = 0;
	int bonus_pgn = 0;
	int bonus_ctr = 1;
	int objectif = 0;
	int score_preneur = 0;
	int score_defenseurs = 0;
	bool victoire = false;
	switch (type_contrat)
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
	switch (bouts)
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
	if (ptf < 0)
	{
		score_preneur = ((ptf - 25)*bonus_ctr) * 3;
		score_defenseurs = ((-ptf) + 25)*bonus_ctr;
		victoire = false;
	}
	else if (ptf >= 0)
	{
		score_preneur = ((ptf + 25)*bonus_ctr) * 3;
		score_defenseurs = ((-ptf) - 25)*bonus_ctr;
		victoire = true;
	}
	if (camp_petit_au_bout != personne)
	{
		if (camp_petit_au_bout == preneur)
		{
			score_preneur = score_preneur + ((10 * bonus_ctr) * 3);
			score_defenseurs = score_defenseurs - (10 * bonus_ctr);
		}
		else if (camp_petit_au_bout == defenseur)
		{
			score_preneur = score_preneur - ((10 * bonus_ctr) * 3);
			score_defenseurs = score_defenseurs + (10 * bonus_ctr);
		}
	}
	if (camp_poignee != personne)
	{
		if ((camp_poignee == preneur && victoire == false) || (camp_poignee == defenseur && victoire == false))
		{
			score_preneur = score_preneur - (3 * bonus_pgn);
			score_defenseurs = score_defenseurs + bonus_pgn;
		}
		else if ((camp_poignee == preneur && victoire == true) || (camp_poignee == defenseur && victoire == true))
		{
			score_preneur = score_preneur + (3 * bonus_pgn);
			score_defenseurs = score_defenseurs - bonus_pgn;
		}
	}
	le_preneur->majScore(score_preneur);
	for (int i = 0; i <= 2; i++)
	{
		les_defenseurs[i]->majScore(score_defenseurs);
	}
}

#ifdef TESTU_COMPTERPOINTS
void main()
{
	CJoueur le_donneur = CJoueur("testeur_donneur", 0);
	CJoueur le_preneur = CJoueur("testeur_preneur", 0);
	CJoueur *les_defenseurs[3];
	for (int i = 0; i <= 2; i++)
	{
		les_defenseurs[i] = new CJoueur("testeur_defenseur" + i, 0);
	}
	CDonne donne(&le_donneur, &le_preneur, les_defenseurs);
	donne.compter_points(0, 55, non, preneur);
	CJoueur le_preneur("testeur_preneur", 0);
	donne.compter_points(0, 57, non, preneur);
	CJoueur le_preneur("testeur_preneur", 0);
	donne.compter_points(1, 50, non, preneur);
	CJoueur le_preneur("testeur_preneur", 0);
	donne.compter_points(1, 52, non, preneur);
	CJoueur le_preneur("testeur_preneur", 0);
	donne.compter_points(2, 40, non, preneur);
	CJoueur le_preneur("testeur_preneur", 0);
	donne.compter_points(2, 42, non, preneur);
	CJoueur le_preneur("testeur_preneur", 0);
	donne.compter_points(3, 35, non, preneur);
	CJoueur le_preneur("testeur_preneur", 0);
	donne.compter_points(3, 37, non, preneur);
}
#endif

#ifdef TEST
#endif