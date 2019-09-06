#include "CDonne.h"

CDonne::CDonne()
{
}

CDonne::CDonne(int nbpts, int bts, int pts, camp cmp_pgn, camp petit, contrat type_ctr, chelem typ_chlm, poignee typ_pgn, CJoueur *donneur, CJoueur *preneur, CJoueur *defenseurs[3])
{
	nb_points = nbpts;
	nb_bouts = bts;
	points = pts;
	camp_poignee = cmp_pgn;
	camp_petit_au_bout = petit;
	type_contrat = type_ctr;
	type_poignee = typ_pgn;
	type_chelem = typ_chlm;
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

int CDonne::compter_points(int ptf, int bouts, int pts, contrat ctr, chelem chlm, poignee pgn, camp petit_bout)
{
	int objectif;
	int bonus;
	int bonus_pgn;
	int bonus_chlm;
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
	switch (ctr)
	{
	case prise:
		bonus = 1;
	case garde:
		bonus = 2;
	case garde_sans:
		bonus = 4;
	case garde_contre:
		bonus = 6;
	}
	switch (pgn)
	{
	case sans:
		bonus_pgn = 0;
	case simple:
		bonus_pgn = 20;
	case doublee:
		bonus_pgn = 30;
	case triplee:
		bonus_pgn = 40;
	}
	switch (chlm)
	{
	case sans:
		bonus_chlm = 0;
	case reussi:
		bonus_chlm = 400;
	case perdu:
		bonus_chlm = 200;
	case sans_annonce:
		bonus_chlm = 200;
	}
	ptf = (pts - objectif);
	if (ptf < 0)
	{
		ptf = -ptf;
	}
	ptf = (ptf + 25 + bonus_pgn + bonus_chlm) * bonus;
}