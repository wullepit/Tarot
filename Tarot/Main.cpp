#include <iostream>
#include "CIHM.h"
#include "CDonne.h"
#include "CJoueur.h"
#include "CPartie.h"
#define TEST

#ifndef TEST
void main()
{
	CIHM ihm = CIHM();
	ihm.menu();
}
#endif