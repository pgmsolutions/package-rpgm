#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include "rnorm_rpgm.h"

// [[register]]
SEXP rbrownian(SEXP n, SEXP m, SEXP mu, SEXP sd, SEXP T, SEXP B0, SEXP drop)
{
	int i,j;
	int N, M;
	
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

	
	double delta = *REAL(T)/(double)M;
	double mdelta = *REAL(mu)*delta;
	double sdelta = *REAL(sd)*sqrt(delta);
	
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
