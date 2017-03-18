rbrownian <-
function(n, m, b0=0, mu=0, sd=1, T=1, drop = TRUE)
{
	return( .Call(.C_rbrownian, n=n, m=m, mu=as.double(mu), sd=as.double(sd), T=as.double(T), B0=as.double(b0), drop=as.logical(drop)) )
}
