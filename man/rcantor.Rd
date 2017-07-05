\name{rcantor}
\alias{rcantor}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Fast Simulation of Cantor Random Variables
}
\description{
	The function generates uniformly random variable on the Cantor set. The distribution provided is singular (neither dsicrite nor absolutely continuous nor a mixture).
}
\usage{
rcantor(n)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of simulations.
}
}
\details{
The Cantor set is uncountable with Lebesgue's measure 0 which leads to a singular probability distribution. The corresponding cumulative probability distribution is the Devil's staircase. The cantor set can be viewed as the number of the form sum(j=1, +Inf) c_j / 3^j with c_j in \{0, 2\} and the corresping probability distribution simulates uniformely the c_j (here, to j=32).
}
\value{
A vector of i.i.d. Cantor random variables.
}
\references{
https://en.wikipedia.org/wiki/Cantor_distribution
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
This distribution is provided only for theorical use, not practical.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
rcantor(5)
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
