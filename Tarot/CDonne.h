#pragma once
#include "CJoueur.h"

//Déclaration types énumérés
enum contrat { passe, prise, garde, garde_sans, garde_contre };
enum camp { preneur, personne, defenseur };
enum poignee { non, simple, doublee, triplee};
enum chelem { sans, reussi, perdu, sans_annonce };

class CDonne
{
private:
	int nb_points;
	int nb_bouts;
	int points;
	int pt_final;
	camp campPoignee;
	camp campPetitAuBout;
	poignee typePoignee;
	contrat typeContrat;
	chelem typeChelem;
	//Agrégations avec CJoueur
	CJoueur *le_donneur;
	CJoueur *lePreneur;
	CJoueur *les_defenseurs[3];
public:
	CDonne(CJoueur *donneur);
	//CDonne(CJoueur *donneur, CJoueur *preneur, CJoueur *defenseurs[3]);
	~CDonne();
	void CompterPoints(int bouts, int pts, poignee pgn, camp cmp);
	void SetCampPetitAuBout(camp p);
	void SetTypePoignee(camp poigne, poignee typ);
	void SetChelemD(chelem type);
	void SetContratD(CJoueur *d, contrat c,CJoueur *lesDefenseurs[]);
};