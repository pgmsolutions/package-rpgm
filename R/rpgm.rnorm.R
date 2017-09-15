rpgm.rnorm <-
function(n, mean = 0, sd = 1, nthreads = 1L)
{
	.Call(.C_rn, n, mean, sd, nthreads)
}
