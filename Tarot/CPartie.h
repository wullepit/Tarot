#pragma once
#include "CDonne.h"
#include "CJoueur.h"

class CPartie
{
private:
	CJoueur *les_joueurs[4];//Agr�gation
	CDonne la_donne;//Composition
public:
	CPartie(CJoueur *joueurs[]);
	~CPartie();
};