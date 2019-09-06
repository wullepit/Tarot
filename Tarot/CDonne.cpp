#include "CDonne.h"

CDonne::CDonne()
{
}

CDonne::CDonne(int nbpts, int bts, int pts, camp cmp_pgn, camp petit, contrat type, chelem typ_chlm, poignee typ_pgn, CJoueur *donneur, CJoueur *preneur, CJoueur *defenseurs[3])
{
	nb_points = nbpts;
	nb_bouts = bts;
	points = pts;
	camp_poignee = cmp_pgn;
	camp_petit_au_bout = petit;
	type_contrat = type;
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