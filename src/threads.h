
#ifdef _OPENMP
#include <omp.h>
#endif

#include "mt19337.h"

extern std::random_device rd;

void mt_threads_init(int nthreads);
