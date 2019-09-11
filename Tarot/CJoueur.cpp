#include "CJoueur.h"
#include "CDonne.h"
#include <iostream>
using namespace std;

CJoueur::CJoueur(string nom, int score)
{
	string n = nom;
	int s = score;
}
string CJoueur::lireNom()
{
	return(nom);
}

int CJoueur::lireScore()
{
	return (score);
}

int CJoueur::majScore(int s)
{
	score = score + s;
	return(score);
}

string CJoueur::ajout_nom(string nom_joueur)
{
	nom = nom_joueur;
	return string();
}
	                        