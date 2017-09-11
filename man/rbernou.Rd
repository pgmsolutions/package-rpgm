\name{rbernou}
\alias{rbernou}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Fast Simulation of Bernoulli Random Variables
}
\description{
	The function rbernou generates Bernoulli Random Variables faster than using \code{rbinom(n, 1, prob)} or \code{runif(n) <= prob} by using a C-level integer comparison.
}
\usage{
rbernou(n, prob=0.5)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of simulations.
}
  \item{prob}{
	double, probability.
}
}
\details{
The case \code{prob = 0.5} is twice time faster than the general case \code{0 <= proba <= 1}, using a specific C-level binary algorithm.
}
\value{
A vector of i.i.d. Bernoulli random variables.
}
\references{
https://en.wikipedia.org/wiki/Bernoulli_distribution
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
For a big number of simulations, it is approximately eleven times faster than the usual \code{rbinom(n, 1, prob)}.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
rbernou(5)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
