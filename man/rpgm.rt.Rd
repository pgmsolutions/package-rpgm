\name{rpgm.rt}
\alias{rpgm.rt}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Fast Simulation of Student Random Variables
}
\description{
	The function rpgm.rt uses \code{rpgm.rnorm} in order to simulate student random variables faster than \code{rt}.
}
\usage{
rpgm.rt(n, df)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of simulations.
}
  \item{df}{
	double, degrees of freedom (> 0, maybe non-integer).
}
}
\details{
If \code{df = 1}, the distribition if the Cauchy one. The mean exists when \code{df > 1} and the variance when \code{df > 2}.
}
\value{
A vector of i.i.d. student random variables.
}
\references{
https://en.wikipedia.org/wiki/Ziggurat_algorithm
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
For a big number of simulations, it is in general two times faster than the usual \code{rt}.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
rpgm.rt(5, 4)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
