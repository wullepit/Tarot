#include "CJoueur.h"
#include "CDonne.h"
#include "CPartie.h"
#include "CIHM.h"
#include <iostream>
//#define TESTU_MAJSCORE
//#define TESTU_LIRESCORE
//#define TESTU_LIRENOM

using namespace std;

CJoueur::CJoueur(string nom, int score)
{
	this ->nom = nom;
	this->score = score;
}

//ok
string CJoueur::LireNom()
{
	return(nom);
}

//ok
int CJoueur::LireScore()
{
	return (score);
}

//ok
int CJoueur::MajScore(int s)
{
	score = score + s;
	return(score);
}

#ifdef TESTU_MAJSCORE
void main()
{
	CJoueur testeur = CJoueur("testeur", 50);
	cout << testeur.majScore(45) << endl;
	cout << testeur.majScore(-10000000000) << endl;
	cout << testeur.majScore(100000000000) << endl;
}
#endif

#ifdef TESTU_LIRESCORE
void main()
{
	CJoueur testeur1 = CJoueur("testeur", 50);
	CJoueur testeur2 = CJoueur("testeur", 10000000000000);
	CJoueur testeur3 = CJoueur("testeur", -10000000000000);
	cout << testeur1.lireScore() << endl;
	cout << testeur2.lireScore() << endl;
	cout << testeur3.lireScore() << endl;
}
#endif

#ifdef TESTU_LIRENOM
void main()
{	CJoueur testeur3 = CJoueur("testeur", 50);
	CJoueur testeur1 = CJoueur("azertyuiopqsdfghjklmwxcvbn", 50);
	CJoueur testeur2 = CJoueur("756890370", 50);
	CJoueur testeur4 = CJoueur("и_з-_з'и-_зи", 50);
	cout << testeur1.LireNom() << endl;
	cout << testeur2.LireNom() << endl;
	cout << testeur3.LireNom() << endl;
	cout << testeur4.LireNom() << endl;
}
#endif