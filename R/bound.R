#place x dans [m, +infty[ de force
lbound <- function(x, m)
	return(.Call(.C_lbound, as.double(x), m))

#place x dans ]-infty, M] de force
ubound <- function(x, M)
	return(.Call(.C_ubound, as.double(x), M))

#place x dans [m, M] de force
bound <- function(x, m, M)
	return(.Call(.C_bound, as.double(x), m, M))

