#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>

#include <omp.h>


extern "C" 
{
// [[register]]
SEXP getmaxthreads()
{	SEXP maxthreads;
	PROTECT(maxthreads = allocVector(INTSXP, 1));
	*INTEGER(maxthreads) = omp_get_max_threads();
	UNPROTECT(1);
	return maxthreads;
}
}