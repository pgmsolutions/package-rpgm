\name{bound}
\alias{lbound}
\alias{ubound}
\alias{bound}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Set a Minimum or a Maximum or Both to a Vector.
}
\description{
	The function \code{lbound} sets a minimum to the elements of a vector, \code{ubound} a maximum and \code{bound} both.
}
\usage{
lbound(x, m)
ubound(x, M)
bound(x, m, M)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x}{
	double, vector to put in [m, M].
}
  \item{m}{
	double, the minimum.
}
  \item{M}{
	double, the maximum.
}
}

\value{
A vector with the values of \code{x} on which all values lower that \code{m} has been replaced by \code{m} and all values greater than \code{M} has been replace by \code{M}.
}

\author{
Nicolas Baradel - PGM Solutions
}
\note{
\code{x <- lbound(x, a)} replaces \code{x <- x*(x >= a) + a*(x < a)} and \code{x[x < a] <- a} in a much faster way.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
K <- 1
x <- rpgm.rnorm(12, 0.5)
lbound(x-K, 0)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
