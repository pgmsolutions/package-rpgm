\name{rgpd}
\alias{rgpd}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Fast Simulation of Generalized Pareto Distribution
}
\description{
	The function rgpd generates Generalized Pareto Random Variables.
}
\usage{
rgpd(n, xi, mu = 0, sigma = 1)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of simulations.
}
  \item{xi}{
	double, the shape.
}
  \item{mu}{
	double, the location.
}
  \item{sigma}{
	double, the scale.
}
}

\value{
A vector of i.i.d. Generalized Pareto random variables.
}

\author{
Nicolas Baradel - PGM Solutions
}
\note{
	For xi != 0, the cumulative distribution function is:
	
		F(x) = 1-(1+xi*(x-mu)/sigma)^(-1/xi)
	
	for x >= mu when xi > 0 and mu <= x <= mu - sigma/xi when xi < 0.
	
	If xi = 0, (X - mu)/sigma follows a Exponential distribution of parameter 1.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
x <- rgpd(5, 1)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
