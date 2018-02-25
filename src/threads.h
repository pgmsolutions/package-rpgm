
#ifdef _OPENMP
#include <omp.h>
#endif

#include "mt19337.h"

extern std::random_device rd;

class MT_Threads
{
	private:
	int mt_nthreads;
	std::mt19937 **mt_threads;
	
	public:
	MT_Threads();
	~MT_Threads();
	void Init(int nthreads);

	std::mt19937 & operator[](int i);
};
