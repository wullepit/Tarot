#pragma once
enum contrat { passe, prise, garde, garde_sans, garde_contre };
enum camp { preneur, personne, defenseur };
enum poignee { sans, simple, doublee, triplee, autre };
enum chelem { sans, reussi, perdu, sans_annonce };

class CDonne
{
private:
	contrat type_contrat;
	int nb_points;
	int nb_bouts;
	int points;
	camp camp_poignee;
	poignee type_poignee;
	camp camp_petit_au_bout;
	chelem type_chelem;
public:
	CDonne(int nbpts, int bts, int pts, camp cmp_pgn, camp petit, contrat type, chelem typ_chlm, poignee typ_pgn);
	~CDonne();
};