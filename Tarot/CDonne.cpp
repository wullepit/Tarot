#include "CDonne.h"

CDonne::CDonne()
{
}

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

void CDonne::compter_points(int bouts, int pts, contrat ctr, poignee pgn, camp cmp)
{
	int ptf;
	int bonus_pgn;
	int bonus_ctr;
	int objectif;
	int score_preneur;
	int score_defenseurs;
	bool victoire;
	switch (ctr)
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
	case'0':
		objectif = 56;
		break;
	case'1':
		objectif = 51;
		break;
	case'2':
		objectif = 41;
		break;
	case'3':
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
	le_preneur->majScore(score_preneur);
	for (int i = 0; i <= 2; i++)
	{
		les_defenseurs[i]->majScore(score_defenseurs);
	}
}

void CDonne::petit_bout()
{

}