rpgm.rnorm <-
function(n, mean = 0, sd = 1)
{
	.Call(.C_rn, n, mean, sd)
}
