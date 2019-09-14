#pragma once
#include "CPartie.h"
#include "CJoueur.h"

class CIHM
{
private:
	//Composition
	CPartie * laPartie;
	CJoueur * lesJoueurs[4];
public:
	void SetPartie();
	//void set_joueurs(CJoueur &joueurs);
	void AnnonceContrat();
	void Jouer();
	void Creer();
	void NomJoueur();
	void Menu();
	void AnnoncePetit();
	void AnnoncePoignée();
	void AnnonceChelem();
};
