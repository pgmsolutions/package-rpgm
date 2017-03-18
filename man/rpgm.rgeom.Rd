\name{rpgm.rgeom}
\alias{rpgm.rgeom}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Fast Simulation of Geometric Random Variables
}
\description{
	The function rpgm.geom uses \code{rpgm.exp} in order to simulate geometric random variables faster than \code{rgeom}.
}
\usage{
rpgm.rgeom(n, prob)
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
The argument \code{prob} must be in ]0, 1], else, NA are produced.
}
\value{
A vector of i.i.d. geometric random variables.
}
\references{
https://en.wikipedia.org/wiki/Ziggurat_algorithm
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
For a big number of simulations, it is in general nine times faster than the usual \code{rgeom}.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
rpgm.rgeom(5, 0.5)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
