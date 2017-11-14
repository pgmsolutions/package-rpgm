#pragma once


#ifdef _OPENMP

#include "rnorm_rpgm.h"
#include "threads.h"

extern int mt_nthreads;
extern std::mt19937** mt_threads;

void rnorm_rpgm01_mc(int N, double * vector, int nthreads);
void rnorm_rpgm_mc(int N, double * vector, double mu_, double sd_, int nthreads);
#endif
