#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>
#include "rnorm_rpgm.h"

void rcantor_rpgm(int N, double * vector)
{
	unsigned char j;

	static double deux_sur_3_puissance_jp1[32] = {0.6666666666666666667, // 2/3^1
	0.222222222222222222,
	0.074074074074074074,
	0.024691358024691357,
	0.00823045267489712,		// 2/3^5
	0.0027434842249657062,
	0.00091449474165523545,
	0.00030483158055174517,
	0.00010161052685058171,
	3.3870175616860571e-05,		// 2/3^10
	1.1290058538953524e-05,
	3.7633528463178416e-06,
	1.2544509487726139e-06,
	4.1815031625753794e-07,
	1.3938343875251265e-07,		// 2/3^15
	4.6461146250837546e-08,
	1.5487048750279183e-08,
	5.1623495834263941e-09,
	1.7207831944754647e-09,
	5.7359439815848827e-10,		// 2/3^20
	1.911981327194961e-10,
	6.37327109064987e-11,
	2.12442369688329e-11,
	7.0814123229442994e-12,
	2.3604707743147665e-12,		//j=25
	7.8682359143825549e-13,
	2.622745304794185e-13,
	8.7424843493139495e-14,
	2.9141614497713167e-14,
	9.7138714992377229e-15,		// j=30
	3.2379571664125742e-15,
	1.079319055470858e-15		//j=32
	};

	
	long unsigned int u, x;
	
	for(int i=0 ; i != N ; ++i)
	{
		vector[i] = 0.;
		u = mt_rand();
		for(j=0 ; j != 32 ; ++j)
		{
			x = u & 1;
			u >>= 1;
			if(x)
				vector[i] += deux_sur_3_puissance_jp1[j];
		}
	}
}


// [[register]]
SEXP rc(SEXP n)
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
	
	rcantor_rpgm(N, vector);

	UNPROTECT(1);

	return vector_sexp;
}
