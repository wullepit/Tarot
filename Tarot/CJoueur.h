#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class CJoueur
{
private:
	string nom;
	int score;
public:
	CJoueur::CJoueur(string nom, int score);
	string lireNom();
	int lireScore();
	int majScore(int s);
};