kurtosis <-
function(x)
{
	.Call(.C_kurtosis, as.double(x))
}
