#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>

void mean_and_var(double*x, int n, double* m, double* v)
{
	double m2=0.;
	for(int i=0 ; i!=n ; ++i)
	{
		*m+=x[i];	
		m2+=x[i]*x[i];	
	}
	double n_ = (double) n;
	*m /= n_;
	*v = m2/n_ - (*m)*(*m);
}

// [[register]]
SEXP skewness(SEXP x)
{
	double *vector = REAL(x);
	double *m = malloc(sizeof(double));
	double *v = malloc(sizeof(double));
	int n = length(x);
	
	*m = 0.;
	mean_and_var(vector, n, m, v);
		
//	Rprintf("x[0] : %f, n : %i, m: %f, v: %f\n", vector[0], n, *m, *v);
	
	double s3 = *v;
	s3 *= sqrt(*v);

	SEXP skewness_sexp;

	PROTECT(skewness_sexp = allocVector(REALSXP, 1));

	double* skewness = REAL(skewness_sexp);
		*skewness = 0.;

	for(int i=0 ; i != n ; ++i)
		*skewness += (vector[i]-*m)*(vector[i]-*m)*(vector[i]-*m);

	s3 *= (double) n;
	*skewness /= s3;

	UNPROTECT(1);

	return skewness_sexp;	
}

// [[register]]
SEXP kurtosis(SEXP x)
{
	double *vector = REAL(x);
	double *m = malloc(sizeof(double));
	double *v = malloc(sizeof(double));
	int n = length(x);
	
	*m = 0.;
	mean_and_var(vector, n, m, v);
		
//	Rprintf("x[0] : %f, n : %i, m: %f, v: %f\n", vector[0], n, *m, *v);
	
	double s4 = *v;
	s4 *= *v;
	
	double alpha;

	SEXP kurtosis_sexp;

	PROTECT(kurtosis_sexp = allocVector(REALSXP, 1));

	double* kurtosis = REAL(kurtosis_sexp);
		*kurtosis = 0.;

	for(int i=0 ; i != n ; ++i)
	{
		alpha = (vector[i]-*m);
		alpha*=alpha;alpha*=alpha;
		*kurtosis += alpha;
	}

	s4 *= (double) n;
	*kurtosis /= s4;

	UNPROTECT(1);

	return kurtosis_sexp;	
}


// [[register]]
SEXP jarquebera(SEXP x)
{
	double n = (double) length(x);

	double S = REAL(skewness(x))[0];
	double K = REAL(kurtosis(x))[0];
		
	SEXP jb;

	PROTECT(jb = allocVector(REALSXP, 1));
	
	REAL(jb)[0] = 1-pchisq(  (S*S + .25*(K-3.)*(K-3.))*n*0.1666666666666666666666666667  , 2., 1, 0);

	UNPROTECT(1);

	return jb;	
}
