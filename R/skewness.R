skewness <-
function(x)
{
	.Call(.C_skewness, as.double(x))
}
