#ifndef RPGM_RCANTOR
#define RPGM_RCANTOR


#include "mt19337.h"

extern std::random_device rd;
extern std::mt19937 mt_rand;

void rcantor_rpgm(int N, double * vector);

extern "C" 
{
SEXP rc(SEXP n);
}

#endif