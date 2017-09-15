maxthreads <-
function()
{
	.Call(.C_getmaxthreads)
}
