\name{rbrownian}
\alias{rbrownian}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Simulation of Brownian Motions
}
\description{
	The function \code{rbrownian} is a C-level function which uses the Ziggurat in order to simulate the normal random variables.
}
\usage{
rbrownian(n, m, b0=0, mu=0, sd=1, T=1, drop=TRUE, nthreads=1L)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of paths.
}
  \item{m}{
	integer, number of steps, the step size will be T/m.
}
  \item{b0}{
	double, the initial value (or a vector of initial values of size \code{n}).
}
  \item{mu}{
	double, the mean.
}
  \item{sd}{
	double, the standard deviation.
}
  \item{T}{
	double, the final date on which the brownian motion is simulated.
}
  \item{drop}{
	logical, if \code{n = 1} and \code{drop = TRUE} then the function returns the single path of the brownian motion as a vector instead of a matrix.
}
  \item{nthreads}{
	integer, the number of threads to use for parallelism.
}
}
%\details{
 
%}
\value{
Returns a n x m+1 matrix of n path of the brownian motion.
}
\references{
https://en.wikipedia.org/wiki/Brownian_motion
}
\author{
Nicolas Baradel - PGM Solutions
}


%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{https://pgm-solutions.com/packages}{https://pgm-solutions.com/packages}
}
\examples{
rbrownian(5, 10)
#rbrownian(5, 10, nthreads = maxthreads())
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
