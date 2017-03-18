\name{rpgm.rexp}
\alias{rpgm.rexp}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Fast Simulation of Exponential Random Variables
}
\description{
	The function rpgm.rexp uses the Ziggurat algorithm with a 256-regions table, in order to simulate exponential random variables faster than \code{rexp}.
}
\usage{
rpgm.rexp(n, lambda = 1)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of simulations.
}
  \item{lambda}{
	double, the parameter lambda.
}
}
\details{
The density is lambda * exp(-lambda*x) for x > 0.
}
\value{
A vector of i.i.d. exponential random variables.
}
\references{
https://en.wikipedia.org/wiki/Ziggurat_algorithm
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
For a big number of simulations, it is in general three times faster than the usual \code{rexp}. For one simulution, it is around one half faster.
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
