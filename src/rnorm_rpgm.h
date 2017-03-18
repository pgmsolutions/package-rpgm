#pragma once

#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>

unsigned int mt_rand(void);

void rnorm_vect(int N, double * vector, SEXP * mu, SEXP * sd);
void rnorm_rpgm01(int N, double * vector);
void rnorm_rpgm(int N, double * vector, double mu_, double sd_);
