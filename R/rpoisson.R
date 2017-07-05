rpoisson <-
function(n, lambda=1, T=1, drop = TRUE)
{
	return( .Call(.C_rpoisson, n=n, lambda=as.double(lambda), T=as.double(T), drop=as.logical(drop)) )
}

evalpoisson <-
function(P, t=1)
{
	return( .Call(.C_evalpoisson, P=P, t=as.double(t)))
}

rinpoisson <-
function(n, lambda, T=1, drop = TRUE)
{
	if(!is.function(lambda))
	{
		stop("For rinpoisson (inhomogenous Poisson process), lambda must be a function (the intensity function). For lambda constant see rpoisson (homogeneous Poisson proces)")
	}
	m <- 10^4
	int <- numeric(m+1)
	for(i in 1L:m)
		int[i+1L] <- int[i] + integrate(lambda, (i-1L)*T/m, i*T/m)$value

	P <- rpoisson(n, 1L, int[m+1L], drop)
	
	if(n == 1L && drop)
	{
		for(j in 1L:length(P))
		{
			index <- which(int > P[j])[1L]
			coefinterp <- (P[j]-int[index-1L])/(int[index]-int[index-1L])
			P[j] <- (index-1L)*T/m + coefinterp*T/m
		}
		return(P)
	}
	else
	{
		for(i in 1L:n)
		{
			for(j in 1L:length(P[[i]]))
			{
				index <- which(int > P[[i]][j])[1L]
				coefinterp <- (P[[i]][j]-int[index-1L])/(int[index]-int[index-1L])
				P[[i]][j] <- (index-1L)*T/m + coefinterp*T/m
			}
		}
		return(P)
	}
}
