#pragma once


#ifdef _OPENMP

#include "rnorm_rpgm.h"
#include "threads.h"

extern MT_Threads mt_threads;

void rnorm_rpgm01_mc(int N, double * vector, int nthreads);
void rnorm_rpgm_mc(int N, double * vector, double mu_, double sd_, int nthreads);

SEXP rbrownian_mc(int N, int M, double delta, double mdelta, double sdelta, SEXP & B0, SEXP & drop, int NTHREADS);

#endif
