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
	int pt_final;
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
	CDonne();//Constructeur par défaut pour la composition
	CDonne(CJoueur *donneur, CJoueur *preneur, CJoueur *defenseurs[3]);
	~CDonne();
	void compter_points(int ptf, int bouts, int pts, contrat ctr);
};