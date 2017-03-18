reuler <- function(n, m, x0, b, s, t0 = 0, T = 1, all_dates = TRUE, delta = NULL)
{
	if(is.null(delta))
	{
		delta <- (T-t0)/m;
	}
	else
		T <- t0 + delta*m;

	sdelta <- sqrt(delta);
	if(all_dates)
	{
		X <- matrix(x0, n, m+1);
		for(i in 1L:m)
			X[,i+1L] <- rpgm.rnorm(n, X[,i] + b(X[,i])*delta, s(X[,i])*sdelta);
	}
	else
	{
		X <- rep.int(x0, n);
		for(i in 1L:m)
			X <- rpgm.rnorm(n, X + b(X)*delta, s(X)*sdelta);
	}
	return(X);
}
