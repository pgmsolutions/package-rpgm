#ifndef RPGM_MT19937
#define RPGM_MT19937

#include <random>
#include <Rmath.h>
#include <R.h>
#include <Rinternals.h>

#define INV_MAX_MT 2.3283064365386963e-10

extern "C" 
{
SEXP mt_set_seed(SEXP);
}
#endif