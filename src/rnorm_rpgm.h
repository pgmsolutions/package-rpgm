#ifndef RPGM_RNORM
#define RPGM_RNORM

#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include <random>
#include <omp.h>
#include "mt19337.h"

extern std::random_device rd;
extern std::mt19937 mt_rand;

void rnorm_vect(int N, double * vector, SEXP * mu, SEXP * sd);
void rnorm_rpgm01(int N, double * vector);
void rnorm_rpgm(int N, double * vector, double mu_, double sd_);

extern "C" 
{
SEXP rn(SEXP n, SEXP mu, SEXP sd, SEXP nthreads);
}

#endif