#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define TESTU

using namespace std;

class CJoueur
{
private:
	string nom;
	int score;
public:
	CJoueur(string nom, int score);
	string lireNom();
	int lireScore();
	int majScore(int s);
//	string ajout_nom(string nom_joueur);
};