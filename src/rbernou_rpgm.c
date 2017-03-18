#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include "rnorm_rpgm.h"

#define Max_MT 4294967296.

void rbernou0_rpgm(int N, int * vector)
{	
	static unsigned char j_bernou=0;
	static unsigned int u0_bernou;
	
	int i=0;

	while(i!=N)
	{
		u0_bernou = mt_rand();
		j_bernou = 0;
		while(j_bernou != 32 && i!=N)
		{
			vector[i] = u0_bernou & 1;
			u0_bernou >>= 1;
			++j_bernou;++i;
		}
	}	
}

void rbernou_rpgm(int N, int * vector, double p)
{	
	long unsigned int k = (p*Max_MT); //cast
	for(int i=0; i != N; ++i)
		vector[i] = mt_rand() <= k;	
}


// [[register]]
SEXP rb(SEXP n, SEXP p)
{
	int N;
	
	double p0;
	
	if(TYPEOF(n) == INTSXP)
		N=*INTEGER(n);
	else if(TYPEOF(n) == REALSXP)
		N = (int) *REAL(n);
	else
		N = 0;

	SEXP vector_sexp;
	int* vector;
	PROTECT(vector_sexp = allocVector(INTSXP, N));
	vector = INTEGER(vector_sexp);
	


	if(length(p) == 1)
	{
		if(TYPEOF(p) == REALSXP)
		{
			p0 = *REAL(p);
		}
		else
		{
			p0 = 0.;
		}
		if(p0 == 0.5)
			rbernou0_rpgm(N, vector);
		else
			rbernou_rpgm(N, vector, p0);
	}
	else
	{
//		rgeom_vect(N, vector, &p);
		rbernou_rpgm(N, vector, *REAL(p));
	}

	UNPROTECT(1);

	return vector_sexp;
}
