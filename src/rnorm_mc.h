#pragma once

#include "rnorm_rpgm.h"

#ifdef _OPENMP
void rnorm_rpgm01_mc(int N, double * vector, int nthreads);
#endif
