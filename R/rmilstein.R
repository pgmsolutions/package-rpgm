rmilstein <- function(n, m, x0, b, s, sx, t0 = 0, T = 1, all_dates = TRUE, delta = NULL)
{
	if(is.null(delta))
	{
		delta <- (T-t0)/m;
	}
	else
	T <- t0 + delta*m;

	sdelta <- sqrt(delta);
	Z <- matrix(rpgm.rnorm(n*m, 0, sdelta), n, m);
	
	if(all_dates)
	{
	X <- matrix(x0, n, m+1);
	for(i in 1L:m)
		X[,i+1L] <- X[,i] + b(X[,i])*delta + s(X[,i])*Z[,i] + 0.5*s(X[,i])*sx(X[,i])*(Z[,i]^2-delta);
	}
	else
	{
		X <- rep.int(x0, n);
		for(i in 1L:m)
			X <- X + b(X)*delta + s(X)*Z[,i] + 0.5*s(X)*sx(X)*(Z[,i]^2-delta);
	}
	return(X);
}


