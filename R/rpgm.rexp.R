rpgm.rexp <-
function(n, lambda = 1)
{
	.Call(.C_re, n, lambda)
}
