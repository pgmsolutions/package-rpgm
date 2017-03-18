#include <R.h> //Rprintf, ...
#include <Rmath.h> //rnorm, ...
#include <Rinternals.h>
#include "rnorm_rpgm.h"

SEXP rvasicek(SEXP n, SEXP m, SEXP X0, SEXP mu, SEXP a, SEXP sd, SEXP T, SEXP drop)
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

	
	double delta = *REAL(T)/(double) M;
		
	double A = *REAL(a);
	double expmaDelta = exp(-A*delta);

	double mu0 = *REAL(mu);
	double sigma = *REAL(sd);

	double s = sqrt( (0.5*sigma*sigma/A)*(1-exp(-2*A*delta)) );

	SEXP X;
	double* pX;
	
	if(N == 1 && *LOGICAL(drop))
		PROTECT(X = allocVector(REALSXP, M+1));
	else
		PROTECT(X = allocMatrix(REALSXP, N, M+1));
	
	pX = REAL(X);
	
	if(length(X0) != N)
		for(i=0; i != N; ++i)
			pX[i] = *REAL(X0);
	else
		for(i=0; i != N; ++i)
			pX[i] = REAL(X0)[i];

	if(M > 1)
		for(j=1; j != M+1; ++j)
			for(i=0; i != N; ++i)
				 rnorm_rpgm(1, &(pX[i + N*j]), mu0 + (pX[i + N*(j-1)]-mu0)*expmaDelta, s);
	
	UNPROTECT(1);
	return(X);
}

SEXP dvasicek(SEXP X, SEXP mu, SEXP a, SEXP sd, SEXP T, SEXP log)
{
	int j;
	int M= length(X)-1;
	double delta = *REAL(T)/(double) M;
	double *pX = REAL(X);
		
	double A = *REAL(a);
	double expmaDelta = exp(-A*delta);

	double mu0 = *REAL(mu);
	double sigma = *REAL(sd);

	double s = sqrt( (0.5*sigma*sigma/A)*(1-expmaDelta*expmaDelta) );

	SEXP f;
	double* pf;
	
	PROTECT(f = allocVector(REALSXP, M));
	
	pf = REAL(f);
	
	if(M > 1)
		for(j=0; j != M; ++j)
				pf[j] =  dnorm4(pX[j+1], mu0 + (pX[j]-mu0)*expmaDelta, s, *LOGICAL(log));
	
	UNPROTECT(1);
	return(f);
}

SEXP lvasicek(SEXP X, SEXP mu, SEXP a, SEXP sd, SEXP T)
{
	int j;
	int M= length(X)-1;
	double delta = *REAL(T)/(double) M;
	double *pX = REAL(X);
		
	double A = *REAL(a);
	double expmaDelta = exp(-A*delta);

	double mu0 = *REAL(mu);
	double sigma = *REAL(sd);

	double s = sqrt( (0.5*sigma*sigma/A)*(1-expmaDelta*expmaDelta) );

	SEXP f;
	double* pf;
	
	PROTECT(f = allocVector(REALSXP, 1));
	
	pf = REAL(f);
	*pf = 0;
	
	if(M > 1)
		for(j=0; j != M; ++j)
				*pf +=  dnorm4(pX[j+1], mu0 + (pX[j]-mu0)*expmaDelta, s, 1);
	
	UNPROTECT(1);
	return(f);
}
