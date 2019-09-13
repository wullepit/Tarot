#include "CDonne.h"
#include "CJoueur.h"
#include <iostream>
using namespace std;
//#define TESTU_COMPTERPOINTS


CDonne::CDonne(CJoueur * donneur)
{
	le_donneur = donneur;
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

/*camp CDonne::annonce_petit()
{
	bool t = false;
	camp petit;
	char c;
	cout << "Y a-t-il eu le petit au bout ? Si oui, par quel camp ?" << endl;
	cout << "1: Pas de petit au bout" << endl << "2: Par le preneur" << endl << "3: Par les defenseurs" << endl;
	cin >> c;

	do
	{
		switch (c)
		{
		case '1':
			petit = personne;
			break;
		case '2':
			petit = preneur;
			break;
		case '3':
			petit = defenseur;
			break;
		default:
			t = true;
			break;
		}
	} while (t == true);
	return (petit);
}*/
void CDonne::CompterPoints(int bouts, int pts, poignee pgn, camp cmp)
{
	int ptf;
	int bonus_pgn;
	int bonus_ctr;
	int objectif;
	int score_preneur;
	int score_defenseurs;
	bool victoire;
	//camp_petit_au_bout = annonce_petit();  mise a jour du camp du petit au bout
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
	le_preneur->MajScore(score_preneur);
	for (int i = 0; i <= 2; i++)
	{
		les_defenseurs[i]->MajScore(score_defenseurs);
	}
}

void CDonne::SetCampPetitAuBout(camp p)
{
	camp_petit_au_bout= p;
}

#ifdef TESTU_COMPTERPOINTS
void main()
{
	CDonne donne = CDonne();
	donne.compter_points(0, 55, non, preneur);
	
	donne.compter_points(0, 58, non, preneur);
	donne.compter_points(1, 50, non, preneur);
	donne.compter_points(1, 52, non, preneur);
	donne.compter_points(2, 40, non, preneur);
	donne.compter_points(2, 42, non, preneur);
	donne.compter_points(3, 35, non, preneur);
	donne.compter_points(3, 37, non, preneur);
}
#endif