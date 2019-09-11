#include"CIHM.h"
#include <iostream>
using namespace std;

void CIHM::set_partie(CPartie &une_partie)
{
	lapartie = une_partie;
}
void CIHM::set_joueurs(CJoueur &joueurs)
{
	for (int i = 0; i < 3; i++)
	{
		lesjoueurs[i] = joueurs;
	}
}
void distribution()
{
	int choix;
	int choixJoueur[4];
	int x = 0;
	int nbJoueurs = 4;
	for (int i = 0; i < 4; i++)
	{
		cout << "Annonce du joueur:" << i + 1 << endl
			<< "0 : Passe" << endl
			<< "1 : Prise" << endl
			<< "2 : Garde" << endl
			<< "3 : Garde-Sans" << endl
			<< "4 : Garde-Contre" << endl;
		cin >> choix;
		switch (choix)
		{
		case '0':
			choixJoueur[i] = passe;
			break;
		case '1':
			choixJoueur[i] = prise;
			break;
		case '2':
			choixJoueur[i] = garde;
			break;
		case '3':
			choixJoueur[i] = garde_sans;
			break;
		case '4':
			choixJoueur[i] = garde_contre;
			break;
		}
	}
	
}