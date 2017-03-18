#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include "rexp_rpgm.h"

void rgpd_rpgm(int N, double * vector, double ksi, double mu, double sigma)
{	
	double sigma_sur_ksi = sigma/ksi;
	double mksi = -ksi;
	for(int i=0; i != N; ++i)
		vector[i] = mu + sigma_sur_ksi*(pow(unif_rand(), mksi)-1);
}


// [[register]]
SEXP rgpd(SEXP n, SEXP xi, SEXP mu, SEXP sigma)
{
	int N;
		
	if(TYPEOF(n) == INTSXP)
		N=*INTEGER(n);
	else if(TYPEOF(n) == REALSXP)
		N = (int) *REAL(n);
	else
		N = 0;

	SEXP vector_sexp;
	double* vector;
	PROTECT(vector_sexp = allocVector(REALSXP, N));
	vector = REAL(vector_sexp);
	
	if(*REAL(xi) != 0.)
		rgpd_rpgm(N, vector, *REAL(xi), *REAL(mu), *REAL(sigma));
	else
	{
		rexp_rpgm(N, vector, 1.);

		double s = *REAL(sigma);
		double m = *REAL(mu);

		for(int i=0 ; i != N ; ++i)
		{
			vector[i] *= s;
			vector[i] += m;
		}		
	}
	
	UNPROTECT(1);

	return vector_sexp;
}
