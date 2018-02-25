#include "rnorm_rpgm.h"
#include "rnorm_mc.h"


SEXP rbrownian_rpgm(int N, int M, double delta, double mdelta, double sdelta, SEXP & B0, SEXP & drop)
{
	int i,j;
	
	SEXP B;
	double* pB;
	
	if(N == 1 && *LOGICAL(drop))
		PROTECT(B = allocVector(REALSXP, M+1));
	else
		PROTECT(B = allocMatrix(REALSXP, N, M+1));
	
	pB = REAL(B);

	if(length(B0) != N)
		for(i=0; i!=N; ++i)
			pB[i] = *REAL(B0);
	else
		for(i=0; i!=N; ++i)
			pB[i] = REAL(B0)[i];
	
	if(M > 1)
		for(j=1; j!=M+1; ++j)
			for(i=0; i!=N; ++i)
				rnorm_rpgm(1, &(pB[i + N*j]), pB[i + N*(j-1)] + mdelta, sdelta);//pB[i + N*j] =  rnorm(pB[i + N*(j-1)] + mdelta, sdelta);
	
	UNPROTECT(1);
	return(B);
}

// [[register]]
extern "C" 
{
SEXP rbrownian(SEXP n, SEXP m, SEXP mu, SEXP sd, SEXP T, SEXP B0, SEXP drop, SEXP nthreads)
{
	int N, M, NTHREADS;
			
	if(TYPEOF(n) == INTSXP)
		N=*INTEGER(n);
	else if(TYPEOF(n) == REALSXP)
		N = (int) *REAL(n);
	else
		N = 0;
	
	if(TYPEOF(m) == INTSXP)
		M=*INTEGER(m);
	else if(TYPEOF(m) == REALSXP)
		M = (int) *REAL(m);
	else
		M = 0;
	
	if(TYPEOF(nthreads) == INTSXP)
		NTHREADS=*INTEGER(nthreads);
	else if(TYPEOF(nthreads) == REALSXP)
		NTHREADS = (int) *REAL(nthreads);
	else
		NTHREADS = 1;
	
	if(NTHREADS != 1)
	{
#ifdef _OPENMP
		if(NTHREADS < 1)
		{
			warning("Negative number of threads: nthreads = %d, one is used (no multi-core).\n", NTHREADS);
			NTHREADS = 1;
		}
		else if (NTHREADS > omp_get_max_threads())
		{
			warning("Number of threads: nthreads = %d is greater than the maximum: maxthreads() = %d, %d are used.\n", NTHREADS, omp_get_max_threads(), omp_get_max_threads());
			NTHREADS = omp_get_max_threads();
		}
#else
			warning("Number of threads: nthreads = %d is greater than the maximum: maxthreads() = %d, %d are used.\n", NTHREADS, 1, 1);
			NTHREADS = 1;
#endif
	}
	
	double delta = *REAL(T)/(double)M;
	double mdelta = *REAL(mu)*delta;
	double sdelta = *REAL(sd)*sqrt(delta);

		
#ifdef _OPENMP
	if(NTHREADS == 1)
		return(rbrownian_rpgm(N, M, delta, mdelta, sdelta, B0, drop));
	else
		return(rbrownian_mc(N, M, delta, mdelta, sdelta, B0, drop, NTHREADS));
#else
		return(rbrownian_rpgm(N, M, delta, mdelta, sdelta, B0, drop));
#endif
	
}
}