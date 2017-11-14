
#include "threads.h"

std::mt19937** mt_threads = nullptr;
int mt_nthreads=0;


void mt_threads_init(int nthreads)
{
	for(int i=0 ; i != mt_nthreads ; ++i)
		delete mt_threads[i];
	
	delete[] mt_threads;
	
	
	mt_threads = new std::mt19937*[nthreads];

	for(int i=0 ; i != nthreads ; ++i)
		mt_threads[i] = new std::mt19937(rd());
	
	mt_nthreads = nthreads;
}

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

