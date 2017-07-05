#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>


// [[register]]
SEXP rpoisson(SEXP n, SEXP lambda, SEXP T, SEXP drop)
{
	int i,j;
	int N;
	int ni; SEXP Ni;
	double* pNi;
	
	if(TYPEOF(n) == INTSXP)
		N=*INTEGER(n);
	else if(TYPEOF(n) == REALSXP)
		N = (int) *REAL(n);
	else
		N = 0;
	
	SEXP P;
	
	double lambdaT = (*REAL(lambda))*(*REAL(T));
	
	if(N == 1 && *LOGICAL(drop))
	{
		ni = rpois(lambdaT);
		PROTECT(P = allocVector(REALSXP, ni));//		vecteur taille du Poisson
		pNi = REAL(P);
		for(j=0 ; j!=ni ; ++j)
		{
			pNi[j] = unif_rand()*(*REAL(T));
		}
		R_rsort(pNi, ni);
		UNPROTECT(1);
	}
	else
	{
		PROTECT(P = allocVector(VECSXP, N));
	
		for(i=0; i!=N; ++i)
		{
			ni = rpois(lambdaT);
			PROTECT(Ni = allocVector(REALSXP, ni));
			pNi = REAL(Ni);
			SET_VECTOR_ELT(P, i, Ni);
			for(j=0 ; j!=ni ; ++j)
			{
				pNi[j] = unif_rand()*(*REAL(T));
			}
			R_rsort(pNi, ni);
			UNPROTECT(1);
		}
		
		UNPROTECT(1);
	}
	return(P);
}

SEXP evalpoisson(SEXP P, SEXP t)//doit gérer le cas vecteur, renvoie une matrice dans ce cas
{
	SEXP evalP;
	int n = TYPEOF(P) == VECSXP ? length(P) : 1;
	int nt = length(t);
	int len;
	
	double* pP;
	double* pt;
		
	pt = REAL(t);
		
	int i=1;
	if(nt > 1)
		while(i < nt)
		{
			if(pt[i-1] > pt[i])
				error("The vector t in parameter must be sorted.");
			++i;
		}
		
	double t0 = *REAL(t);
	
	
	PROTECT(evalP = allocVector(INTSXP, n));

	int* pevalP = INTEGER(evalP);
	
	
	for(i=0 ; i != n ; ++i)
	{
		if(TYPEOF(P) == REALSXP)
		{
			len = length(P);
			pP = REAL(P);
		}
		else //VECSXP
		{
			len = length(VECTOR_ELT(P, i));
			pP = REAL(VECTOR_ELT(P, i));
		}
		pevalP[i] = 0;
		if(len > 0)
			while( (pevalP[i] < len) & (pP[pevalP[i]] <= t0))
				++pevalP[i];
	}
	UNPROTECT(1);
	
	return(evalP);
}
