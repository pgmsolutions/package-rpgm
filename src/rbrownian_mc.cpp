
#ifdef _OPENMP

#include "rnorm_mc.h"

SEXP rbrownian_mc(int N, int M, double delta, double mdelta, double sdelta, SEXP & B0, SEXP & drop, int NTHREADS)
{
	int i;
	
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
	{
#pragma omp parallel num_threads(NTHREADS) private(i)
		{
#pragma omp for
			for(int j=1; j < M+1; ++j)
				for(i=0; i!=N; ++i)
					rnorm_rpgm(1, &(pB[i + N*j]), pB[i + N*(j-1)] + mdelta, sdelta);//pB[i + N*j] =  rnorm(pB[i + N*(j-1)] + mdelta, sdelta);
			
		}
	}
	
	UNPROTECT(1);
	return(B);
}


#endif