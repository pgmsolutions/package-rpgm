\name{evalpoisson}
\alias{evalpoisson}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Evaluate the Poisson Process paths at date t
}
\description{
	The function \code{evalpoisson} evalutes all paths of Poisson processes at date t and returns a vector with the corresponding values
}
\usage{
evalpoisson(P, t = 1)}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{P}{
	list of double vector, a Poisson process simulation of n paths from \code{rpoisson} or \code{rinpoisson}.
}
  \item{t}{
	double, atomic vector for evaluating each path at date \code{t} (do not support yet a vector).
}
}

\value{
\code{evalpoisson} returns an integer vector of the size of the number of paths. The ith element is the value of the ith path of the Poisson process at date t.
}
\references{
https://en.wikipedia.org/wiki/Poisson_point_process
}
\author{
Nicolas Baradel - PGM Solutions
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{https://pgm-solutions.com/packages}{https://pgm-solutions.com/packages}
}
\examples{
P <- rpoisson(5, 5)
evalpoisson(P, 0.5)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }% use one of  RShowDoc("KEYWORDS")
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
