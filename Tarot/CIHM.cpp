#pragma once
#include"CIHM.h"
#include <iostream>
using namespace std;

void CIHM::SetPartie()
{
	laPartie = new CPartie(lesJoueurs);
}
void CIHM::NomJoueur()
{
	for (int i = 0; i < 4; i++)
	{
		string n;
		cout << "Choississez votre nom joueur " << i + 1 << " : ";
		cin >> n;
		lesJoueurs[i] = new CJoueur(n, 0);
	}
}

void CIHM::DistributionEncheres()
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

void CIHM::AnnoncePetit()
{
	bool t = false;
	camp petit;
	char c;
	cout << "Y a-t-il eu le petit au bout ? Si oui, par quel camp ?" << endl;
	cout << "1: Pas de petit au bout" << endl << "2: Par le preneur" << endl << "3: Par les defenseurs" << endl;
	cin >> c;
	
	do
	{
		switch (c)
		{
		case '1':
			petit = personne;
			break;
		case '2':
			petit = preneur;
			break;
		case '3':
			petit = defenseur; 
			break;
		default:
			t = true;
			break;
		}
	} while (t==true);
	//demander a la partie de mettre a jour le petit au bout de la donne courante
	laPartie->SetPetitAuBout(petit);
}

void CIHM::Menu()
{
	char c;
	int x;
	cout << "Jeu de tarot :" << endl << "Entrez le nom des joueurs dans l'ordre de donne (sens inverse des aiguilles d'une montre)" << endl;
	Creer();
	cout << "1:Nouvelle Donne" << endl;
	cout << "2:Lire partie" << endl;
	cout << "3:Enregistrer la partie /! NE PAS APPUYER" << endl;

	do
	{
		cin >> c;
		switch (c)
		{
		case '1':
			Jouer();
			x = 1;
			break;
		case '2':
			//	jouer();
			break;
		case '3':
			/* voir csv */
			x = 1;
			break;
		case '4':
			cout << "je vous avais prevenu :p";
			break;
			x = 1;
		default:
			x = 0;
			break;
		}
	} while (x == 0);
}
void CIHM::Creer()
{
	NomJoueur();
	for (int i = 0; i < 4; i++)
	{
		cout << "Joueur" << i + 1 << ":" << lesJoueurs[i]->LireNom() << endl;
	}
	cout << "Le premier donneur est le joueur 1." << endl;
}

void CIHM::Jouer()
{
	/*cr�er une nouvelle donne:

		-annonce des contrats/poign�e
		-calcul des points de la manche
		-petit au bout ?
		-lecture et maj des points totaux
	*/
}