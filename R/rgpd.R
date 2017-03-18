rgpd <-
function(n, xi, mu = 0, sigma = 1)
{
	.Call(.C_rgpd, n, as.double(xi), as.double(mu), as.double(sigma))
}
