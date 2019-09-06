#include"CIHM.h"

void CIHM::set_partie(CPartie &une_partie)
{
	lapartie = une_partie;
}
void CIHM::set_joueurs(CJoueur &joueurs)
{
	for (int i = 0; i < 3; i++)
	{
		lesjoueurs[i] = joueurs;
	}
}