// nomjoujou.cpp : définit le point d'entrée pour l'application console.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()

{
	int nombreDeJoueurs;
	int x = 0;

	cout << "Combien de joueurs etes vous? : " << endl;
	cin >> nombreDeJoueurs;
	cout << endl << "L'ordre de saisie correspondra à l'ordre des donneurs. Le premier saisi sera le premier donneur" << endl << endl;

	vector<string> listeNoms(nombreDeJoueurs, "Sans nom");
	//Crée un tableau de strings valant toutes « Sans nom »
	for (int i = 1; i <= nombreDeJoueurs; i++)
	{
		cout << "Nom joueur : " << i << endl;
		cin >> listeNoms[x];
		cout << "le joueur " << i << " s'appelle " << listeNoms[x] << endl << endl;
		x++;
	 }
	cout << "les joueurs sont " << endl;
	for (int nom = 0 ; nom < x ; nom++)
	{
		cout << listeNoms[nom] << endl;
	}
	return 0;
}