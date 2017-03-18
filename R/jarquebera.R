jarquebera <-
function(x)
{
	.Call(.C_jarquebera, as.double(x))
}