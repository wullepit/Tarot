#pragma once
#include "CJoueur.h"

//Déclaration types énumérés
enum contrat { passe, prise, garde, garde_sans, garde_contre };
enum camp { preneur, personne, defenseur };
enum poignee { non, simple, doublee, triplee, autre };
enum chelem { sans, reussi, perdu, sans_annonce };

class CDonne
{
private:	
	int nb_points;
	int nb_bouts;
	int points;
	camp camp_poignee;
	camp camp_petit_au_bout;
	poignee type_poignee;
	contrat type_contrat;
	chelem type_chelem;
	//Agrégations avec CJoueur
	CJoueur *le_donneur;
	CJoueur *le_preneur;
	CJoueur *les_defenseurs[3];
public:
	CDonne(int nbpts, int bts, int pts, camp cmp_pgn, camp petit, contrat type, chelem typ_chlm, poignee typ_pgn, CJoueur *donneur, CJoueur *preneur, CJoueur *defenseurs[3]);
	~CDonne();
};