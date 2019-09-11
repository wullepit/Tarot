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

int CDonne::compter_points(int ptf, int bouts, int pts, contrat ctr)
{
	int bonus_ctr;
	int objectif;
	int score_preneur;
	int score_defenseurs;
	switch (ctr)
	{
	case prise:
		bonus_ctr = 1;
	case garde:
		bonus_ctr = 2;
	case garde_sans:
		bonus_ctr = 4;
	case garde_contre:
		bonus_ctr = 6;
	}
	switch (bouts)
	{
	case'0':
		objectif = 56;
	case'1':
		objectif = 51;
	case'2':
		objectif = 41;
	case'3':
		objectif = 36;
	}
	ptf = (pts - objectif);
	if (ptf < 0)
	{
		score_preneur = ((ptf - 25)*bonus_ctr) * 3;
		score_defenseurs = (ptf + 25)*bonus_ctr;
	}
	ptf = (ptf + 25 + bonus_pgn + bonus_chlm) * bonus;
}