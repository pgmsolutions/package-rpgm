#ifndef RPGM_REXP
#define RPGM_REXP

#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include "rnorm_rpgm.h"

extern std::random_device rd;
extern std::mt19937 mt_rand;

void rexp_vect(int N, double * vector, SEXP * lambda);
void rexp_rpgm(int N, double * vector, double inv_lambda);
extern "C" 
{
SEXP re(SEXP n, SEXP lambda);
}
void rgeom_rpgm(int N, int * vector, double p);
extern "C" 
{
SEXP rg(SEXP n, SEXP p);
}
#endif