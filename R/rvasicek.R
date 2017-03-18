rvasicek <-
function(n, m, x0=0, mu=0, a=1, sd=1, T=1, drop = TRUE)
{
	.Call(.C_rvasicek, n, m, as.double(x0), as.double(mu), as.double(a), as.double(sd), as.double(T), as.logical(drop))
}

dvasicek <-
function(x, mu=0, a=1, sd=1, T=1, log = FALSE)
	.Call(.C_dvasicek, as.double(x), as.double(mu), as.double(a), as.double(sd), as.double(T), as.logical(log))

lvasicek <-
function(x, mu=0, a=1, sd=1, T=1)
	.Call(.C_lvasicek, as.double(x), as.double(mu), as.double(a), as.double(sd), as.double(T))

evasicek <- function(x, a0=1, T=1)
{
	delta = T/(length(x)-1L)
	exp_adelta <- exp(-a0*delta)
	hat.mu <- function(x, delta, exp_adelta)
	{
		return( mean(x[-1L] - exp_adelta*x[-length(x)])/(1-exp_adelta) )
	}
	hat.sd <- function(x, a0, delta, exp_adelta, hat.mu)
	{
	return( sqrt( mean( (x[-1L] - (hat.mu + (x[-length(x)] - hat.mu)*exp_adelta))^2 )*2*a0/(1-exp_adelta^2) ) )
	}
	f <- function(a, x, T)
	{
		exp_adelta <- exp(-a*delta)
		mu <- hat.mu(x, delta, exp_adelta)
		return(-lvasicek(x, mu=mu, a=a, sd=hat.sd(x, a, delta, exp_adelta, mu), T=T))
	}
	a <- nlm(f, a0, x=x, T=T)
	if(a$code == 1L)
	{
		exp_adelta <- exp(-a$estimate*delta)
		mu <- hat.mu(x, delta, exp_adelta)
		return(c(mu = mu, a = a$estimate, sd = hat.sd(x, a$estimate, delta, exp_adelta, mu)))
	}
	else
	{
		try(stop("The minimization in evasicek failed, default value for a is returned"))
		exp_adelta <- exp(-a0*delta)
		mu <- hat.mu(x, delta, exp_adelta)
		return(c(mu = mu, a = a0, sd = hat.sd(x, a0, delta, exp_adelta, mu)))
	}
}
