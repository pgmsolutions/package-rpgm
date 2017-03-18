rbernou <-
function(n, prob = 0.5)
{
	.Call(.C_rb, n, prob)
}
