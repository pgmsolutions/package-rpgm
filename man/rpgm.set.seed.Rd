\name{rpgm.set.seed}
\alias{rpgm.set.seed}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Set Seed for RPGM Mersenne Twister Random Number Generator
}
\description{
	The function fixes the seed of the random numbers generated with rpgm.
}
\usage{
rpgm.set.seed(seed)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{seed}{
	integer, seed.
}
}

\value{
	Return the value of the seed.
}

\author{
Nicolas Baradel - PGM Solutions
}


%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
rpgm.set.seed(123)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
