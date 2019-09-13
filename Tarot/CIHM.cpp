#pragma once
#include"CIHM.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void CIHM::set_partie(CPartie &une_partie)
{
	lapartie = &une_partie;
}
void CIHM::nom_joueur()
{
	for (int i = 0; i < 4; i++)
	{
		string n;
		cout << "Choississez votre nom joueur " << i + 1 << " : ";
		cin >> n;
		lesjoueurs[i] = new CJoueur(n, 0);
	}
}
/*void CIHM::set_joueurs(CJoueur &joueurs)
{

}*/
void CIHM::distributionEncheres()
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

/*int CIHM::annonce_petit()
{

}*/

void CIHM::menu()
{
	char c;
	int x;
	do
	{

		cout << "Jeu de tarot :" << endl << endl
			<< "1:Creer une partie" << endl
			<< "2:Lire partie" << endl 
			<< "q:quitter" << endl << endl << ">";

		cin >> c;
		switch (c)
		{
		case '1':
			system("cls");
			creer();
			x = 1;
			break;

		case '2':
			/* voir csv */
			x = 1;
			break;
		case 'Q':
		case 'q':
			x = 1;
			break;
		default:
			system("cls");
			cout << "choix non valide";
			Sleep(1000);
			system("cls");
			x = 0;
			break;
		}
	} while (x == 0);
}
void CIHM::creer()
{
	cout << "Entrez le nom des joueurs dans l'ordre de donne (sens inverse des aiguilles d'une montre) :" << endl;
	nom_joueur();
	for (int i = 0; i < 4; i++)
	{
		cout << "Joueur" << i + 1 << ":" << lesjoueurs[i]->lireNom() << endl;
	}
	cout << "Le donneur est " <<lesjoueurs[0]->lireNom() << endl;


}

void CIHM::jouer()
{
	/*créer une nouvelle donne:
		-annonce des contrats/poignée
		-calcul des points de la manche
		-petit au bout?
		-lecture et maj des points totaux
	*/
}