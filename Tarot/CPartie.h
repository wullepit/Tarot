#pragma once
#include "CDonne.h"
#include "CJoueur.h"

class CPartie
{
private:
	CJoueur *lesJoueurs[4];//Agrégation
	CDonne **lesDonnes;//Composition
	int nDonne;
	int bouts;
	int point;
	contrat typ_ctr;
public:
	CPartie(CJoueur *joueurs[]);
	~CPartie();
	void SetPetitAuBout(camp petit);
	void CreerUneDonne(CJoueur * leDonneur);
	void SetPoignee(camp p, poignee type);
	void SetChelem(chelem t);
	void SetContrat(CJoueur *lesJoueurs, contrat t,CJoueur *lesD[]);
};