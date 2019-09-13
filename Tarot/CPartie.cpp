#include "CPartie.h"
#define TESTU_SETPETITBOUT
//#define TESTU_CREERUNEDONNE

CPartie::CPartie(CJoueur *joueurs[])
{
	nDonne = 0;
	for (int i = 0; i <= 3; i++)
	{
		this->lesJoueurs[i] = joueurs[i];
	}
	lesDonnes = new CDonne*[100];
}

CPartie::~CPartie()
{
	delete *lesDonnes;
}

//pas ok
void CPartie::SetPetitAuBout(camp petit)
{
	lesDonnes[nDonne - 1]->SetCampPetitAuBout(petit);
}

//ok
void CPartie::CreerUneDonne(CJoueur * leDonneur)
{
	lesDonnes[nDonne] = new CDonne(leDonneur);
	nDonne++;
}

void CPartie::SetPoignee(camp p, poignee t)
{
	lesDonnes[nDonne - 1]->SetTypePoignee(p, t);
}

void CPartie::SetChelem(chelem t)
{
	lesDonnes[nDonne - 1]->SetChelemD(t);
}

void CPartie::SetContrat(CJoueur * lePreneur, contrat t, CJoueur * lesD)
{
	lesDonnes[nDonne - 1]->SetContratD(lePreneur, t, lesD);
}

#ifdef TESTU_SETPETITBOUT
void main()
{
	CJoueur *les_joueurs[4];
	for (int i = 0; i <= 2; i++)
	{
		les_joueurs[i] = new CJoueur("joueur" + i, 0);
	}
	CPartie partie(les_joueurs);

	partie.SetPetitAuBout(personne);
	partie.SetPetitAuBout(preneur);
	partie.SetPetitAuBout(defenseur);
}
#endif

#ifdef TESTU_CREERUNEDONNE
void main()
{
	CJoueur *les_joueurs[4];
	CJoueur le_donneur("donneur", 0);
	for (int i = 0; i <= 3; i++)
	{
		les_joueurs[i] = new CJoueur("joueur" + i, 0);
	}
	CPartie partie(les_joueurs);
	CPartie partie1(les_joueurs);
	partie.CreerUneDonne(les_joueurs[0]);
	partie1.CreerUneDonne(les_joueurs[1]);
	partie.CreerUneDonne(les_joueurs[2]);
	partie1.CreerUneDonne(les_joueurs[3]);
}
#endif
