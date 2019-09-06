#pragma once
#include "CDonne.h"
#include "CJoueur.h"

class CPartie
{
private:
	CJoueur *les_joueurs[4];//Agrégation
	CDonne la_donne;//Composition
public:
	CPartie(CJoueur *joueurs[]);
	~CPartie();
};