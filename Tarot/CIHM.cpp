#pragma once
#include"CIHM.h"
#include "CPartie.h"
#include "CDonne.h"
#include <iostream>
#include <Windows.h>
using namespace std;
//#define TESTU_SETPARTIE
//#define TESTU_NOMJOUEUR
//#define TESTU_MENU
//#define TESTU_CREER
//#define TESTU_JOUER
#define TESTU_ANNONCEPETIT
//#define TESTU_ANNONCEPOIGNEE
//#define TESTU_ANNONCECHELEM
//#define TESTU_ANNONCECONTRAT

//ok
void CIHM::SetPartie()
{
	laPartie = new CPartie(lesJoueurs);
}

//ok
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

//ok
void CIHM::AnnonceContrat()
{
	int j, p;
	int n = 0;
	char c;
	string a;
	bool jouer = true;
	CJoueur *lesDef[3];
	contrat choixJoueur;
	int x = 0;
	cout << "Y a-t-il un preneur" << endl <<
		"1:oui" << endl << "2:non" << endl;
	cin >> p;
	if (p == 1)
	{
		do
		{
			cout << "Qui est le preneur ? " << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1 << ":" << lesJoueurs[i]->LireNom() << endl;
			}
			cin >> j;
			j++;
		} while (j <0  || j > 5);
		cout << "Annonce du preneur:" << endl
			<< "1 : Prise" << endl
			<< "2 : Garde" << endl
			<< "3 : Garde-Sans" << endl
			<< "4 : Garde-Contre" << endl;

		do
		{
			cin >> c;
			switch (c)
			{
				/*	case '0':
						choixJoueur[j] = passe;
						break;
				*/
			case '1':
				choixJoueur = prise;
				c = 'v';
				break;
			case '2':
				choixJoueur = garde;
				c = 'v';
				break;
			case '3':
				choixJoueur = garde_sans;
				c = 'v';
				break;
			case '4':
				choixJoueur = garde_contre;
				c = 'v';
				break;
			}
		} while (c != 'v');

		cout << "ca marche";
		for (int l = 0; l < 4; l++)
		{
			if (lesJoueurs[l] != lesJoueurs[j])
			{
				lesDef[n] = lesJoueurs[l];
				n++;
			}
		}
		laPartie->SetContrat(lesJoueurs[j], choixJoueur, lesDef);
		
	}
	else
	{
		// Distribuez une nouvelle donne
	}
}


//ok
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

//ok
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
		cout << "qui a la poignée?"<<endl;
		cin >> cmpP;
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
		t = false;
		do {
			cout << "Type de poignee ?" << endl;
			cin >> typeP;
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
				t = true;
				break;
			}
		} while (t == true);
	}
	else
	{
		typePoignee = non;
	}
	//Appel de méthode pour mettre a jour la poignee
	laPartie->SetPoignee(campP, typePoignee);
}

//à finir
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

//ok
void CIHM::Creer()
{
	cout << "Entrez le nom des joueurs dans l'ordre de donne (sens inverse des aiguilles d'une montre) :" << endl;
	NomJoueur();
	for (int i = 0; i < 4; i++)
	{
		cout << "Joueur" << i + 1 << ":" << lesJoueurs[i]->LireNom() << endl;
	}
	cout << "Le donneur est " << lesJoueurs[0]->LireNom() << endl;
	laPartie->CreerUneDonne(lesJoueurs[0]);
	//DistributionEncheres();
}

//marche pas (variable pas initialisée)
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

//à faire
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
void main()
{
	CIHM ihm;
	ihm.SetPartie();
}
#endif

#ifdef TESTU_NOMJOUEUR
void main()
{
	CIHM ihm;
	ihm.NomJoueur();
}
#endif

#ifdef TESTU_DISTRIBUTION
#endif

#ifdef TESTU_MENU
void main()
{
	CIHM ihm;
	ihm.Menu();
}
#endif

#ifdef TESTU_CREER
void main()
{
	CIHM ihm;
	ihm.SetPartie();
	ihm.Creer();
}
#endif

#ifdef TESTU_JOUER
#endif

#ifdef TESTU_ANNONCEPETIT
void main()
{
	CIHM ihm;
	ihm.SetPartie();
	ihm.Creer();
	ihm.AnnoncePetit();
}
#endif

#ifdef TESTU_ANNONCECONTRAT
#include "CPartie.h"
void main()
{
	CIHM ihm;
	ihm.SetPartie();
	ihm.Creer();
	ihm.AnnonceContrat();
}
#endif

#ifdef TESTU_ANNONCECHELEM
void main()
{
	CIHM ihm;
	ihm.SetPartie();
	ihm.Creer();
	ihm.AnnonceChelem();
}
#endif

#ifdef TESTU_ANNONCEPOIGNEE
void main()
{
	CIHM ihm;
	ihm.SetPartie();
	ihm.Creer();
	ihm.AnnoncePoignée();
}
#endif