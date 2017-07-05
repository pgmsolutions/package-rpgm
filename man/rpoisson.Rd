\name{rpoisson}
\alias{rpoisson}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Simulation of homogeneous Poisson Processes
}
\description{
	The function \code{rpoisson} is a C-level function which simulates the jumping times of a Poisson process, returning each path as a vector of a list.
}
\usage{
rpoisson(n, lambda = 1, T = 1, drop = TRUE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of paths.
}
  \item{lambda}{
	double, intensity of the Poisson process.
}
  \item{T}{
	double, end time of the simulations.
}
  \item{drop}{
	logical, if \code{n = 1} and \code{drop = TRUE}, returns the single path as a vector instead of a list.
}
}

\value{
\code{rpoisson} returns a list of n paths of a Poisson process of intensity lambda. Each element of the list is the vector of the jumping times.
}
\references{
https://en.wikipedia.org/wiki/Poisson_point_process#Homogeneous_Poisson_point_process
}
\author{
Nicolas Baradel - PGM Solutions
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{https://pgm-solutions.com/packages}{https://pgm-solutions.com/packages}
}
\examples{
x <- rpoisson(5, 5)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }% use one of  RShowDoc("KEYWORDS")
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
