#include "CPartie.h"

CPartie::CPartie(CJoueur *joueurs[])
{
	for (int i = 0; i <= 3; i++)
	{
		this->les_joueurs[i] = joueurs[i];
	}
}

CPartie::~CPartie()
{
}