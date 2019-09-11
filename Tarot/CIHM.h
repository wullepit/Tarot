#pragma once
#include "CPartie.h"
#include "CJoueur.h"

class CIHM
{
private:
	//Composition
	CPartie * lapartie;
	CJoueur * lesjoueurs[4];
public:
	void set_partie(CPartie &une_partie);
	void set_joueurs(CJoueur &joueurs);
	void distributionEncheres();
	void jouer();
	void nom_joueur();
	void menu();
	void annonce_petit();
};
