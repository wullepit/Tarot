#include <iostream>
#include "CIHM.h"
#include "CDonne.h"
#include "CJoueur.h"
#include "CPartie.h"
//#define PASDETEST

#ifndef PASDETEST
void main()
{
	CIHM ihm = CIHM();
	ihm.menu();
}
#endif