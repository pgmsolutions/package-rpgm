#ifndef RPGM_RBERNOU
#define RPGM_RBERNOU

#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include <random>
#include "mt19337.h"

extern std::random_device rd;
extern std::mt19937 mt_rand;

void rbernou0_rpgm(int N, int * vector);

extern "C" 
{
SEXP rb(SEXP n, SEXP p);
}

#endif