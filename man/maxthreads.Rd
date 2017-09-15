\name{maxthreads}
\alias{maxthreads}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
	Get the Maximum Number of Threads available on your device
}
\description{
	The function returns the maximum number of threads that you can use with multi-core functions.
}
\usage{
maxthreads()
}
%- maybe also 'usage' for other objects documented here.
\details{
The number returned is the number of Threads, not the number of Physical Cores (it is twice the number of physical cores of CPU uses Hyper Threading)
}
\value{
An integer with the number of threads available on the device.
}
\references{
https://en.wikipedia.org/wiki/Thread_(computing)
}
\author{
Nicolas Baradel - PGM Solutions
}
\note{
If you want to always use the maximum number of Threads, you can simply put Inf as input of the number of threads instead of the output of this function.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
\href{http://pgm-solutions.com/packages}{http://pgm-solutions.com/packages}
}
\examples{
maxthreads()
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
