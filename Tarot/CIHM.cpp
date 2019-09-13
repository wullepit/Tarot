#pragma once
#include"CIHM.h"
#include <iostream>
#include <Windows.h>
using namespace std;
#define TESTU_SETPARTIE
#define TESTU_NOMJOUEUR
#define TESTU_DISTRIBUTION
#define TESTU_MENU
#define TESTU_CREER
#define TESTU_JOUER
#define TESTU_ANNONCEPETIT
#define TESTU_ANNONCEPOIGNEE
#define TESTU_ANNONCECHELEM
#define TESTU_ANNONCECONTRAT

//à tester
void CIHM::SetPartie()
{
	laPartie = new CPartie(lesJoueurs);
}

//à tester
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

//à tester
void CIHM::DistributionEncheres()
{
	int j, p;
	char choix;
	bool jouer = true;
	contrat choixJoueur;
	int x = 0;
	cout << "Y a-t-il un preneur" << endl <<
		"1:oui" << endl << "2:non" << endl;
	cin >> p;
	if (p == 1)
	{
		cout << "Qui est le preneur ? " << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << ":" << lesJoueurs[i]->LireNom();
		}
		cin >> j;
		cout << "Annonce du preneur:" << endl
			<< "1 : Prise" << endl
			<< "2 : Garde" << endl
			<< "3 : Garde-Sans" << endl
			<< "4 : Garde-Contre" << endl;
		cin >> choix;
		switch (choix)
		{
			/*	case '0':
					choixJoueur[j] = passe;
					break;
			*/
		case '1':
			choixJoueur = prise;
			break;
		case '2':
			choixJoueur = garde;
			break;
		case '3':
			choixJoueur = garde_sans;
			break;
		case '4':
			choixJoueur = garde_contre;
			break;
		}
		laPartie->SetContrat(lesJoueurs[j], choixJoueur);
	}
	else
	{
		// Distribuez une nouvelle donne
	}
}

//à tester
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
	} while (t == true);
	//demander a la partie de mettre a jour le petit au bout de la donne courante
	laPartie->SetPetitAuBout(petit);
}

//à tester
void CIHM::AnnoncePoignée()
{
	char cmpP;
	char typeP;
	camp campP;
	poignee typePoignee;
	bool t = false;
	bool p;
	do
	{
		switch (cmpP)//Dans quel camp est la poignée
		{
		case '1':
			campP = preneur;
			p = true;
			break;
		case '2':
			campP = defenseur;
			p = true;
			break;
		case '3':
			campP = personne;
			p = false;
			break;
		default:
			t = true;
			break;
		}
	} while (t == true);
	if (p == true)
	{
		//Type de poignee ?
		do {
			switch (typeP)
			{
			case '1':
				typePoignee = simple;
				break;
			case '2':
				typePoignee = doublee;
				break;
			case '3':
				typePoignee = triplee;
				break;
			default:
				t = false;
				break;
			}
		} while (t == false);
	}
	else
	{
		typePoignee = non;
	}
	//Appel de méthode pour mettre a jour la poignee
	laPartie->SetPoignee(campP, typePoignee);
}

//à tester
void CIHM::Menu()
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
			Creer();
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

//à tester
void CIHM::Creer()
{
	cout << "Entrez le nom des joueurs dans l'ordre de donne (sens inverse des aiguilles d'une montre) :" << endl;
	NomJoueur();
	for (int i = 0; i < 4; i++)
	{
		cout << "Joueur" << i + 1 << ":" << lesJoueurs[i]->LireNom() << endl;
	}
	cout << "Le donneur est " << lesJoueurs[0]->LireNom() << endl;


}

//à tester
void CIHM::AnnonceChelem()
{
	char c;
	bool x = false;
	chelem type;
	do
	{
		switch (c)
		{
		case '1':
			type = sans;
			break;
		case '2':
			type = reussi;
			break;
		case '3':
			type = perdu;
			break;
		case '4':
			type = sans_annonce;
			break;
		default:
			x = true;
			break;
		}

	} while (x == true);
	laPartie->SetChelem(type);
}

//à tester
void CIHM::AnnonceContrat()
{

}

//à tester
void CIHM::Jouer()
{
	/*créer une nouvelle donne:

		-annonce des contrats/poignée
		-calcul des points de la manche
		-petit au bout ?
		-lecture et maj des points totaux
	*/
}

#ifdef TESTU_SETPARTIE
#endif

#ifdef TESTU_NOMJOUEUR
#endif

#ifdef TESTU_DISTRIBUTION
#endif

#ifdef TESTU_MENU
#endif

#ifdef TESTU_CREER
#endif

#ifdef TESTU_JOUER
#endif

#ifdef TESTU_ANNONCEPETIT
#endif

#ifdef TESTU_ANNONCECONTRAT
#endif

#ifdef TESTU_ANNONCECHELEM
#endif

#ifdef TESTU_ANNONCEPOIGNEE
#endif