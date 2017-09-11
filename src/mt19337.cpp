#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include <ctime>

#include "mt19337.h"

//initilize default mt generator
//currrently used for:
//rpgm.rnorm, rpgm.rlnorm, rpgm.rt, rpgm.rexp, rpgm.rgeom, rpgm.rbernou, rpgm.rcantor

std::mt19937 mt(time(0));

unsigned int mt_rand()
{
	return mt();
}

extern "C" 
{
// [[register]]	
SEXP mt_set_seed(SEXP seed)
{
	mt.seed(static_cast<unsigned int>(*INTEGER(seed)));
	return seed;
}
}
