#pragma once

#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include <omp.h>
#include "mt19337.h"
#include "rnorm_rpgm.h"

void rnorm_rpgm01_mc(int N, double * vector, int nthreads);

