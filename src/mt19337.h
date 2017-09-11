#ifndef RPGM_MT19937
#define RPGM_MT19937

#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include <random>

#define INV_MAX_MT 2.3283064365386963e-10

unsigned int mt_rand();
extern "C" 
{
SEXP mt_set_seed(SEXP);
}
#endif