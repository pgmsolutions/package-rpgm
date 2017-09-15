#ifndef RPGM_RCANTOR
#define RPGM_RCANTOR


#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include <random>
#include "mt19337.h"

extern std::random_device rd;
extern std::mt19937 mt_rand;

void rcantor_rpgm(int N, double * vector);

extern "C" 
{
SEXP rc(SEXP n);
}

#endif