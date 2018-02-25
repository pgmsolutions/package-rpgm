
#include "threads.h"


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


MT_Threads::MT_Threads()
{
	mt_nthreads = 0;
	mt_threads = nullptr;
}

MT_Threads::~MT_Threads()
{
		for(int i = 0 ; i != mt_nthreads ; ++i)
			delete mt_threads[i];
		delete[] mt_threads;
}


void MT_Threads::Init(int nthreads)
{
	if(nthreads > mt_nthreads)
	{
		mt_threads = new std::mt19937* [nthreads];
		for(int i = mt_nthreads ; i != nthreads ; ++i)
			mt_threads[i] = new std::mt19937(rd());
		
		mt_nthreads = nthreads;
	}
}

std::mt19937 & MT_Threads::operator[](int i)
{
	return *(mt_threads[i]);
}


MT_Threads mt_threads;



