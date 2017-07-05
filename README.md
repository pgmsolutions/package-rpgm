# rpgm package

[![rpackages.io rank](https://www.rpackages.io/badge/rpgm.svg)](https://www.rpackages.io/package/rpgm)

RPGM is a R package implementing fast simulation methods for some random variables than the usual native functions, including rnorm() and rexp(), using Ziggurat method, reference: MARSAGLIA, George, TSANG, Wai Wan, and al. (2000) <doi:10.18637/jss.v005.i08>, and fast simulation of stochastic differential equations / Poisson processes.
Reference: MARSAGLIA, George, TSANG, Wai Wan, and al. (2000) <DOI:10.18637/jss.v005.i08>.

## Installation

Either with CRAN:

```
install.packages("rpgm")
```

Or with devtools:
```
install.packages("devtools")
devtools::install_github("pgmsolutions/package-rpgm")
```