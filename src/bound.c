#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>

SEXP lbound(SEXP x, SEXP m)
{
	int N = length(x);
	double M;
	
	if(TYPEOF(m) == INTSXP)
		M=*INTEGER(m);
	else if(TYPEOF(m) == REALSXP)
		M = (int) *REAL(m);
	else
		return x;
	
	double * px = REAL(x);
	
	SEXP X;
	double * pX;
	
	PROTECT(X = allocVector(REALSXP, N));
	pX = REAL(X);

	int i;
	for(i=0; i != N; ++i)
		if(px[i] < M)
			pX[i] = M;
		else
			pX[i] = px[i];
		
	UNPROTECT(1);
	return X;
}

SEXP ubound(SEXP x, SEXP m)
{
	int N = length(x);
	double M;
	
	if(TYPEOF(m) == INTSXP)
		M=*INTEGER(m);
	else if(TYPEOF(m) == REALSXP)
		M = (int) *REAL(m);
	else
		return x;

	double * px = REAL(x);
	
	SEXP X;
	double * pX;
	
	PROTECT(X = allocVector(REALSXP, N));
	pX = REAL(X);

	int i;
	for(i=0; i != N; ++i)
		if(px[i] > M)
			pX[i] = M;
		else
			pX[i] = px[i];
		
	UNPROTECT(1);
	return X;
}



SEXP bound(SEXP x, SEXP m1, SEXP m2)
{
	int N = length(x);
	double M1;
	double M2;
	
	if(TYPEOF(m1) == INTSXP)
		M1=*INTEGER(m1);
	else if(TYPEOF(m1) == REALSXP)
		M1 = (int) *REAL(m1);
	else
		return ubound(x, m2);

	if(TYPEOF(m2) == INTSXP)
		M2=*INTEGER(m2);
	else if(TYPEOF(m2) == REALSXP)
		M2 = (int) *REAL(m2);
	else
		return lbound(x, m1);

	
	double * px = REAL(x);
	
	SEXP X;
	double * pX;
	
	PROTECT(X = allocVector(REALSXP, N));
	pX = REAL(X);
	
	int i;
	for(i=0; i != N; ++i)
		if(px[i] < M1)
			pX[i] = M1;
		else if(px[i] > M2)
			pX[i] = M2;
		else
			pX[i] = px[i];
		
	UNPROTECT(1);
	return X;
}
