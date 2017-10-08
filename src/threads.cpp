
#ifdef _OPENMP
#include <omp.h>
#endif

#include <R.h>
#include <Rmath.h>
#include <Rinternals.h>

extern "C" 
{
// [[register]]
SEXP getmaxthreads()
{	SEXP maxthreads;
	PROTECT(maxthreads = allocVector(INTSXP, 1));
#ifdef _OPENMP
	*INTEGER(maxthreads) = omp_get_max_threads();
#else
	*INTEGER(maxthreads) = 1;
#endif
	UNPROTECT(1);
	return maxthreads;
}
}