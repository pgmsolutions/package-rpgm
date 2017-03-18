\name{jarquebera}
\alias{jarquebera}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	The Jarque-Bera Test for Normality
}
\description{
	This test, based on the \code{skewness} and the \code{kurtosis} of the vector, computes the p-value associated to the normality of the distribution.
}
\usage{
jarquebera(x)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x}{
	numeric, vector of independent and identical random variables
}
}
\details{

The Jarque-Bera test is based of the convergence, if the vector is i.i.d. normal random variables, of
			\deqn{\texttt{skewness}(x) \rightarrow \mathcal{N}(0, 6) ; \texttt{kurtosis}(x) \rightarrow \mathcal{N}(3, 24)}{skewness(x) -> N(0, 6) ; kurtosis(x) -> N(3, 24)}
and moreover, both are asymptotically independent. Then, we have the statistic 
			\deqn{J = \frac{n}{6}\left(S^2 + \frac{(K-3)^2}{4}\right) \rightarrow \chi^{2}(2)}{J = (n/6)(S^2 + (K-3)^2/4) -> chi^2}
}
\value{
The p-value associated to the test : \code{1-pchisq(J, 2)}.
}
\references{
https://en.wikipedia.org/wiki/Jarque%E2%80%93Bera_test
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
If you choose a test of level alpha, then you reject the null hypothesis of a normal distribution if the p-value returned by the function is lower than alpha.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
jarquebera(rpgm.rnorm(10^5))
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
