#include "CJoueur.h"
#include "CDonne.h"
#include "CPartie.h"
#include "CIHM.h"
#include <iostream>
//#define TESTU_MAJSCORE
//#define TESTU_LIRESCORE
#define TESTU_LIRENOM
using namespace std;

CJoueur::CJoueur(string nom, int score)
{
	string n = nom;
	this->score = score;
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
#ifdef TESTU_MAJSCORE
void main()
{
	CJoueur testeur = CJoueur("testeur", 50);
	cout << testeur.majScore(45) << endl;
	cout << testeur.majScore(-10000000000000) << endl;
	cout << testeur.majScore(10000000000000000) << endl;
}
#endif
#ifdef TESTU_LIRESCORE
void main()
{
	CJoueur testeur1 = CJoueur("testeur", 50);
	CJoueur testeur2 = CJoueur("testeur", 100000000000000000);
	CJoueur testeur3 = CJoueur("testeur", -10000000000000000);
	cout << testeur1.lireScore() << endl;
	cout << testeur2.lireScore() << endl;
	cout << testeur3.lireScore() << endl;
}
#endif
#ifdef TESTU_LIRENOM
#endif