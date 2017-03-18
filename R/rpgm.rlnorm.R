rpgm.rlnorm <-
function(n, mean = 0, sd = 1)
{
	.Call(.C_rln, n, mean, sd)
}
