rpgm.set.seed <-
function(n)
{
	.Call(.C_mt_set_seed, as.integer(n))
}
