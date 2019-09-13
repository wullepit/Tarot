#include "CPartie.h"

CPartie::CPartie(CJoueur *joueurs[])
{
	nDonne = 0;
	for (int i = 0; i <= 3; i++)
	{
		this->lesJoueurs[i] = joueurs[i];
	}
}

CPartie::~CPartie()
{
	delete *lesDonnes;
}

void CPartie::SetPetitAuBout(camp petit)
{
	lesDonnes[nDonne - 1]->SetCampPetitAuBout(petit);
}

void CPartie::CreerUneDonne(CJoueur * leDonneur)
{
	lesDonnes[nDonne] = new CDonne(leDonneur);
	nDonne++;
}

void CPartie::SetPoignee(camp p, poignee t)
{
	lesDonnes[nDonne - 1]->SetTypePoignee(p,t);
}

void CPartie::SetChelem(chelem t)
{
	lesDonnes[nDonne - 1]->SetChelemD(t);
}

void CPartie::SetContrat(CJoueur * lePreneur, contrat t)
{
	lesDonnes[nDonne - 1]->SetContratD(lePreneur, t);
}
