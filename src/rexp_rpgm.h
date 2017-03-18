#pragma once

#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include "rnorm_rpgm.h"

void rexp_vect(int N, double * vector, SEXP * lambda);
void rexp_rpgm(int N, double * vector, double inv_lambda);
SEXP re(SEXP n, SEXP lambda);
void rgeom_rpgm(int N, int * vector, double p);
SEXP rg(SEXP n, SEXP p);

