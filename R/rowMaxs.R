
rowMaxs <- function(x)
{
	if(class(x) == "matrix")
	{
		.Call(.C_rowMaxs, x)
	}
	else
	{
		.Call(.C_rowMaxs, as.matrix(x))
	}
}

colMaxs <- function(x)
{
	if(class(x) == "matrix")
	{
		.Call(.C_colMaxs, x)
	}
	else
	{
		.Call(.C_colMaxs, as.matrix(x))
	}
}


rowMins <- function(x)
{
	if(class(x) == "matrix")
	{
		.Call(.C_rowMins, x)
	}
	else
	{
		.Call(.C_rowMins, as.matrix(x))
	}
}

colMins <- function(x)
{
	if(class(x) == "matrix")
	{
		.Call(.C_colMins, x)
	}
	else
	{
		.Call(.C_colMins, as.matrix(x))
	}
}
