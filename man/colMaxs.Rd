\name{colMaxs - rowMaxs - colMins - rowMins}
\alias{colMaxs}
\alias{rowMaxs}
\alias{colMins}
\alias{rowMins}

%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	The Maximum or Minimum of each Column or each Row of a Matrix.
}
\description{
	Form row and column maxs and mins for numeric arrays (or data frames).
}
\usage{
colMaxs(x)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x}{
	numeric or integer, matrix.
}
}
\details{
	These functions are equivalent, per example for \code{colMaxs(X)}, to \code{apply(X, 1, max)}, but are a lot faster. 		

}
\value{
A numeric vector.
}

\author{
Nicolas Baradel - PGM Solutions
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
X <- matrix(rpgm.rnorm(36), 6, 6)
colMaxs(X)
rowMaxs(X)
colMins(X)
rowMins(X)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
