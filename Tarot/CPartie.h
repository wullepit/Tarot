#pragma once
#include "CDonne.h"
#include "CJoueur.h"

class CPartie
{
private:
	CJoueur *les_joueurs[4];//Agrégation
	CDonne **les_donnes;//Composition
	int bouts;
	int point;
	contrat typ_ctr;
public:
	CPartie(CJoueur *joueurs[]);
	~CPartie();
};