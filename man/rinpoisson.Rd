\name{rinpoisson}
\alias{rinpoisson}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Simulation of inhomogeneous Poisson Processes
}
\description{
	The function \code{rinpoisson} is a R-level function which simulates the jumping times of an inhomogeneous Poisson process, returning each path as a vector of a list.
}
\usage{
rinpoisson(n, lambda, T = 1, drop = TRUE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of paths.
}
  \item{lambda}{
	double, function of the intensity of the inhomogeneous Poisson processes over the time.
}
  \item{T}{
	double, end time of the simulations.
}
  \item{drop}{
	logical, if \code{n = 1} and \code{drop = TRUE}, returns the single path as a vector instead of a list.
}
}

\value{
\code{rinpoisson} returns a list of n paths of an inhomogeneous Poisson process of intensity function \code{lambda}. Each element of the list is the vector of the jumping times.
}
\references{
https://en.wikipedia.org/wiki/Poisson_point_process#Inhomogeneous_Poisson_point_process
}
\author{
Nicolas Baradel - PGM Solutions
}

\note{
	The function \code{lambda} must be vectorial in the sense that, if given an argument x, it returns a vector of the same size.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{https://pgm-solutions.com/packages}{https://pgm-solutions.com/packages}
}
\examples{
lambda <- function(t) return(400*(1+sin(-pi/2+2*pi*t)))
P <- rinpoisson(5, lambda, T=4)

plot(density(P[[1]], bw = 0.05))
lines((0:400)/100, lambda((0:400)/100)/integrate(lambda, 0, 4)$value, col="red")
length(P[[1]])
integrate(lambda, 0, 4)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }% use one of  RShowDoc("KEYWORDS")
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
