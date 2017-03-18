\name{vasicek}
\alias{rvasicek}
\alias{dvasicek}
\alias{lvasicek}
\alias{evasicek}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Simulation and Density of Vasicek Process
}
\description{
	The definition of the process used here is:
	
		dX_t = -a(X_t - mu) + sd*dW_t,
		
	where (mu, a, sd) are the three real parameters.
}
\usage{
rvasicek(n, m, x0 = 0, mu = 0, a = 1, sd = 1, T = 1, drop = TRUE)
dvasicek(x, mu=0, a=1, sd=1, T=1, log = FALSE)
lvasicek(x, mu=0, a=1, sd=1, T=1)
evasicek(x, a0=1, T=1)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{n}{
	integer, number of paths.
}
  \item{m}{
	integer, number of steps, the step size will be T/m.
}
  \item{x}{
	double, the vector of the observed values of a Vasicek process.
}
  \item{x0}{
	double, the initial value.
}
  \item{mu}{
	double, the value on which the process is centered and has an attraction when it is away.
}
  \item{a}{
	double, the coefficient of how strong is the mean reversion when the process is away from \code{mu}.
}
  \item{sd}{
	double, the volatility.
}
  \item{T}{
	double, the final date on which the brownian motion is simulated.
}
  \item{drop}{
	logical, if \code{n = 1} and \code{drop = TRUE} then the function returns the single path of the brownian motion as a vector instead of a matrix.
}
  \item{log}{
	logical, if TRUE, returns the log-density, if FALSE, returns the density.
}
  \item{a0}{
	double, starting value of \code{a} in the estimation algorithm.
}
}

\value{
\code{rvasicek} returns a \code{(n, m+1)} matrix of n path of the Vasicek process. \code{dvasicek} returns a vector of size \code{length(x)-1}. Note that the first value has no density. \code{lvasicek} returns the log-liklihood associated to \code{dvasicek} and \code{evasicek} returns the Maximum Likelihood Estimator of the parameters \code{(mu, a, sd)}.
}
\references{
https://en.wikipedia.org/wiki/Vasicek_model
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
	If \code{mu = 0}, the process coincides with the Ornstein-Uhlenbeck process.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{https://pgm-solutions.com/packages}{https://pgm-solutions.com/packages}
}
\examples{
x <- rvasicek(5, 10)
dvasicek(x[1L, ])
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }% use one of  RShowDoc("KEYWORDS")
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
