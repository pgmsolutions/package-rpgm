\name{rpgm.rnorm}
\alias{rpgm.rnorm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Fast Simulation of Normal Random Variables
}
\description{
	The function rpgm.rnorm uses the Ziggurat algorithm with a 128-regions table, in order to simulate normal random variables faster than \code{rnorm}.
}
\usage{
rpgm.rnorm(n, mean = 0, sd = 1)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of simulations.
}
  \item{mean}{
	double, the mean (or the vector of means).
}
  \item{sd}{
	double, the standard deviation (or the vector of standard deviations).
}
}
\details{
If \code{mean} or \code{sd} are not specified they assume the default values of 0 and 1, respectively.
}
\value{
A vector of i.i.d. normal random variables.
}
\references{
https://en.wikipedia.org/wiki/Ziggurat_algorithm
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
For a big number of simulations, it is approximately four times faster than the usual \code{rnorm}. For one simulution, it is around one half faster.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
rpgm.rnorm(5)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
