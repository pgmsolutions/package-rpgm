\name{rpgm.rlnorm}
\alias{rpgm.rlnorm}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Fast Simulation of Log-Normal Random Variables
}
\description{
	The function rpgm.rlnorm uses \code{rpgm.rnorm} in order to simulate log-normal random variables faster than \code{rlnorm}.
}
\usage{
rpgm.rlnorm(n, mean = 0, sd = 1)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of simulations.
}
  \item{mean}{
	double, the mean (or the vector of means) of the logarithm of the log-normal variable.
}
  \item{sd}{
	double, the standard deviation (or the vector of standard deviations) of the logarithm of the log-normal variable.
}
}
\details{
If \code{mean} or \code{sd} are not specified they assume the default values of 0 and 1, respectively.
}
\value{
A vector of i.i.d. log-normal random variables.
}
\references{
https://en.wikipedia.org/wiki/Ziggurat_algorithm
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
For a big number of simulations, it is in general two times faster than the usual \code{rnorm}.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
rpgm.rlnorm(5)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
