rpgm.rgeom <-
function(n, prob)
{
	.Call(.C_rg, n, prob)
}
