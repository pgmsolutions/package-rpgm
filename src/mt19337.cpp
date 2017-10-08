#include "mt19337.h"

//initilize default mt generator
//currrently used for:
//rpgm.rnorm, rpgm.rlnorm, rpgm.rt, rpgm.rexp, rpgm.rgeom, rpgm.rbernou, rpgm.rcantor

std::random_device rd;
std::mt19937 mt_rand(rd());

extern "C" 
{
// [[register]]	
SEXP mt_set_seed(SEXP seed)
{
	mt_rand.seed(static_cast<unsigned int>(*INTEGER(seed)));
	return seed;
}
}
