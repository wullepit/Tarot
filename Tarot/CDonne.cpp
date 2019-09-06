#include "CDonne.h"

CDonne::CDonne(int nbpts, int bts, int pts, camp cmp_pgn, camp petit, contrat type, chelem typ_chlm, poignee typ_pgn)
{
	nb_points = nbpts;
	nb_bouts = bts;
	points = pts;
	camp_poignee = cmp_pgn;
	camp_petit_au_bout = petit;
	type_contrat = type;
	type_poignee = typ_pgn;
	type_chelem = typ_chlm;
}

CDonne::~CDonne()
{

}