\name{reuler}
\alias{reuler}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Euler Scheme for Stochastic Differential Equations
}
\description{
	If the process X_t is the unique strong solution of the process
	
		dX_t = b(X_t)dt + s(X_t)dW_t,
		
	then the Euler Scheme is
		X[t+h] = X[t] + b(X[t])h + s(X[t])sqrt(h)Z,
	where Z ~ N(0,1).
}
\usage{
reuler(n, m, x0, b, s, t0 = 0, T = 1, all_dates = TRUE, delta = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of paths.
}
  \item{m}{
	integer, number of steps, the step size will be T/m.
}
  \item{x0}{
	numeric, starting point of the process.
}
  \item{b}{
	function, the drift, a function which can take a vector and returns a vector.
}
  \item{s}{
	function, the volatility, a function which can take a vector and returns a vector.
}
  \item{t0}{
	double, the starting date of the process.
}
  \item{T}{
	double, the final date of the process.
}
  \item{all_dates}{
	logical, if TRUE, returns all steps from all paths. If FALSE, only returns the n final value X_T.
}
  \item{delta}{
	double, the step size.
}
}

\value{
If \code{all_dates = TRUE}, it returns a n x m+1 matrix : n paths with m steps (+ the first value). Else, it returns a vector of length n with the simulations of the final dates X_T.
}
\references{
https://en.wikipedia.org/wiki/Euler%E2%80%93Maruyama_method
}
\author{
Nicolas Baradel - PGM Solutions
}


%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{https://pgm-solutions.com/packages}{https://pgm-solutions.com/packages}
}
\examples{
mu <- 0.07
sigma <- 0.20
reuler(5, 10, 1, function(x) return(mu*x), function(x) return(sigma*x))
}
\keyword{ ~kwd1 }% use one of  RShowDoc("KEYWORDS")
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
