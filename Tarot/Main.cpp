#include <iostream>
#include "CIHM.h"
#include "CDonne.h"
#include "CJoueur.h"
#include "CPartie.h"
#define MODETEST

#ifndef MODETEST
void main()
{
	CIHM ihm = CIHM();
	ihm.Menu();
}
#endif