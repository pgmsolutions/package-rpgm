#include <R.h>
#include <Rmath.h>
#include <Rinternals.h>

//Pour Real
SEXP rowMaxsR(SEXP * M)
{
	int i, j, nrow, ncol;
	double *pM, *prMax;
	SEXP dimMatrix, rMax;
	pM = REAL(*M);
	dimMatrix = getAttrib(*M, R_DimSymbol);
	nrow = INTEGER(dimMatrix)[0];
	ncol = INTEGER(dimMatrix)[1];
	
	PROTECT(rMax = allocVector(REALSXP, nrow));
	prMax = REAL(rMax);
	
	for(i=0; i != nrow; ++i)
	{
		prMax[i] = pM[i];
		for(j=0; j != ncol; ++j)
			if(pM[i + nrow*j] > prMax[i])
				prMax[i] = pM[i + nrow*j];
	}
	UNPROTECT(1);
	return(rMax);
}

SEXP colMaxsR(SEXP * M)
{
	int i, j, nrow, ncol;
	double *pM, *pcMax;
	SEXP dimMatrix, cMax;
	pM = REAL(*M);
	dimMatrix = getAttrib(*M, R_DimSymbol);
	nrow = INTEGER(dimMatrix)[0];
	ncol = INTEGER(dimMatrix)[1];
	
	PROTECT(cMax = allocVector(REALSXP, ncol));
	pcMax = REAL(cMax);
	
	for(j=0; j != ncol; ++j)
	{
		pcMax[j] = pM[nrow*j];
		for(i=0; i != nrow; ++i)
			if(pM[i + nrow*j] > pcMax[j])
				pcMax[j] = pM[i + nrow*j];
	}
	UNPROTECT(1);
	return(cMax);
}

SEXP rowMinsR(SEXP * M)
{
	int i, j, nrow, ncol;
	double *pM, *prMin;
	SEXP dimMatrix, rMin;
//	M = coerceVector(M, REALSXP);
	pM = REAL(*M);
	dimMatrix = getAttrib(*M, R_DimSymbol);
	nrow = INTEGER(dimMatrix)[0];
	ncol = INTEGER(dimMatrix)[1];
	
	PROTECT(rMin = allocVector(REALSXP, nrow));
	prMin = REAL(rMin);
	
	for(i=0; i != nrow; ++i)
	{
		prMin[i] = pM[i];
		for(j=0; j != ncol; ++j)
			if(pM[i + nrow*j] < prMin[i])
				prMin[i] = pM[i + nrow*j];
	}
	UNPROTECT(1);
	return(rMin);
}

SEXP colMinsR(SEXP * M)
{
	int i, j, nrow, ncol;
	double *pM, *pcMin;
	SEXP dimMatrix, cMin;
	pM = REAL(*M);
	dimMatrix = getAttrib(*M, R_DimSymbol);
	nrow = INTEGER(dimMatrix)[0];
	ncol = INTEGER(dimMatrix)[1];
	
	PROTECT(cMin = allocVector(REALSXP, ncol));
	pcMin = REAL(cMin);
	
	for(j=0; j != ncol; ++j)
	{
		pcMin[j] = pM[nrow*j];
		for(i=0; i != nrow; ++i)
			if(pM[i + nrow*j] < pcMin[j])
				pcMin[j] = pM[i + nrow*j];
	}
	UNPROTECT(1);
	return(cMin);
}


//Pour Integer

SEXP rowMaxsI(SEXP * M)
{
	int i, j, nrow, ncol;
	int *pM, *prMax;
	SEXP dimMatrix, rMax;
	pM = INTEGER(*M);
	dimMatrix = getAttrib(*M, R_DimSymbol);
	nrow = INTEGER(dimMatrix)[0];
	ncol = INTEGER(dimMatrix)[1];
	
	PROTECT(rMax = allocVector(INTSXP, nrow));
	prMax = INTEGER(rMax);
	
	for(i=0; i != nrow; ++i)
	{
		prMax[i] = pM[i];
		for(j=0; j != ncol; ++j)
			if(pM[i + nrow*j] > prMax[i])
				prMax[i] = pM[i + nrow*j];
	}
	UNPROTECT(1);
	return(rMax);
}

SEXP colMaxsI(SEXP * M)
{
	int i, j, nrow, ncol;
	int *pM, *pcMax;
	SEXP dimMatrix, cMax;
	pM = INTEGER(*M);
	dimMatrix = getAttrib(*M, R_DimSymbol);
	nrow = INTEGER(dimMatrix)[0];
	ncol = INTEGER(dimMatrix)[1];
	
	PROTECT(cMax = allocVector(INTSXP, ncol));
	pcMax = INTEGER(cMax);
	
	for(j=0; j != ncol; ++j)
	{
		pcMax[j] = pM[nrow*j];
		for(i=0; i<nrow; ++i)
			if(pM[i + nrow*j] > pcMax[j])
				pcMax[j] = pM[i + nrow*j];
	}
	UNPROTECT(1);
	return(cMax);
}

SEXP rowMinsI(SEXP * M)
{
	int i, j, nrow, ncol;
	int *pM, *prMin;
	SEXP dimMatrix, rMin;
//	M = coerceVector(M, REALSXP);
	pM = INTEGER(*M);
	dimMatrix = getAttrib(*M, R_DimSymbol);
	nrow = INTEGER(dimMatrix)[0];
	ncol = INTEGER(dimMatrix)[1];
	
	PROTECT(rMin = allocVector(INTSXP, nrow));
	prMin = INTEGER(rMin);
	
	for(i=0; i<nrow; i++)
	{
		prMin[i] = pM[i];
		for(j=0; j<ncol; j++)
			if(pM[i + nrow*j] < prMin[i])
				prMin[i] = pM[i + nrow*j];
	}
	UNPROTECT(1);
	return(rMin);
}

SEXP colMinsI(SEXP * M)
{
	int i, j, nrow, ncol;
	int *pM, *pcMin;
	SEXP dimMatrix, cMin;
//	M = coerceVector(M, REALSXP);
	pM = INTEGER(*M);
	dimMatrix = getAttrib(*M, R_DimSymbol);
	nrow = INTEGER(dimMatrix)[0];
	ncol = INTEGER(dimMatrix)[1];
	
	PROTECT(cMin = allocVector(INTSXP, ncol));
	pcMin = INTEGER(cMin);
	
	for(j=0; j<ncol; j++)
	{
		pcMin[j] = pM[nrow*j];
		for(i=0; i<nrow; i++)
			if(pM[i + nrow*j] < pcMin[j])
				pcMin[j] = pM[i + nrow*j];
	}

	UNPROTECT(1);
	return(cMin);
}

SEXP colMaxs(SEXP M)
{
	if(TYPEOF(M) == REALSXP)
		return colMaxsR(&M);
	else if(TYPEOF(M) == INTSXP)
		return colMaxsI(&M);
	else
		return( allocVector(REALSXP, 0));
}

SEXP rowMaxs(SEXP M)
{
	if(TYPEOF(M) == REALSXP)
		return rowMaxsR(&M);
	else if(TYPEOF(M) == INTSXP)
		return rowMaxsI(&M);
	else
	{
		return( allocVector(REALSXP, 0));
	}
}

SEXP colMins(SEXP M)
{
	if(TYPEOF(M) == REALSXP)
		return colMinsR(&M);
	else if(TYPEOF(M) == INTSXP)
		return colMinsI(&M);
	else
		return( allocVector(REALSXP, 0));
}

SEXP rowMins(SEXP M)
{
	if(TYPEOF(M) == REALSXP)
		return rowMinsR(&M);
	else if(TYPEOF(M) == INTSXP)
		return rowMinsI(&M);
	else
		return( allocVector(REALSXP, 0));
}

