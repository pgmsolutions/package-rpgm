#include "rnorm_rpgm.h"
#include "rnorm_mc.h"

	//xm[-1] = 0.
static double xm[128] = {0.311549762734902, 0.394827136599868, 0.454225566387616, 0.50220924313581, 0.543279742266934, 0.579639897529477, 0.612552128820833, 0.642815238863252, 0.67097058109871, 0.697403946732634, 0.722401202838573, 0.746180745801969, 0.768913670568072, 0.790736846861158, 0.811761718090499, 0.832080355225629, 0.851769894560759, 0.870895657018182, 0.8895135227982, 0.90767177595221, 0.925412435556013, 0.942772342630704, 0.959784048630258, 0.976476464586133, 0.992875410981362, 1.00900410190565, 1.02488347753257, 1.04053254302841, 1.05596860574421, 1.0712074904379, 1.08626372863558, 1.10115071727497, 1.11588084922237, 1.13046563436993, 1.14491577111859, 1.15924128686043, 1.17345154728781, 1.18755537890949, 1.20156110380832, 1.21547657929234, 1.22930927786423, 1.2430662877988, 1.25675439812622, 1.27038008686452, 1.2839495506611, 1.29746879588626, 1.3109435784517, 1.32437949346955, 1.33778194842586, 1.35115620739598, 1.3645074174643, 1.3778405977949, 1.39116069326365, 1.40447253452635, 1.4177809106043, 1.43109053774839, 1.44440611417907, 1.45773229803392, 1.47107371343673, 1.48443501716334, 1.49782083590736, 1.51123584398354, 1.52468473055863, 1.53817224906439, 1.55170319461908, 1.56528242293161, 1.57891488130088, 1.59260561940704, 1.60635977807994, 1.62018263419992, 1.63407960259345, 1.64805622606893, 1.66211826009911, 1.67627161908922, 1.69052242857156, 1.70487705703408, 1.71934211241006, 1.7339244768987, 1.74863133193683, 1.76347019899159, 1.77844897086189, 1.79357590443921, 1.80885972586339, 1.82430958849682, 1.83993523217854, 1.85574692063925, 1.87175555524074, 1.88797274009433, 1.904410855348, 1.92108309050771, 1.93800361656652, 1.95518760962725, 1.97265140097843, 1.99041263103579, 2.00849035167425, 2.02690525891066, 2.04567984456814, 2.06483865352033, 2.084408542792, 2.10441900754474, 2.12490261142918, 2.14589528981233, 2.16743702294253, 2.18957237425901, 2.21235137555386, 2.23583025870866, 2.26007283444133, 2.28515167992376, 2.3111501223468, 2.33816434027243, 2.36630626814928, 2.39570727352756, 2.42652317653594, 2.45894055152049, 2.49318588988594, 2.52953772912713, 2.56834462759071, 2.61005071766409, 2.65523530047036, 2.70467453178574, 2.75944430342958, 2.8210999968197, 2.89201859213699, 2.97611656243127, 3.08059170482418, 3.22120335812882, 3.44646647189953, 6.66043688926158};

	//ym[-1] = 1.
static double ym[128] = {0.952627209774166, 0.925016009642539, 0.901982254532733, 0.881520464435188, 0.862796484345928, 0.845361269262811, 0.828937884184518, 0.813340274110161, 0.798435764039109, 0.78412554897089, 0.770333493905141, 0.756999373841575, 0.74407449877996, 0.731518783720104, 0.719298718661849, 0.707385953605059, 0.695756193549618, 0.684388443495426, 0.673264403442396, 0.662367973390451, 0.651684918339523, 0.641202573289552, 0.630909588240483, 0.620795758192269, 0.610851868144865, 0.601069543098231, 0.591441163052331, 0.581959753007131, 0.572618917962602, 0.563412777918715, 0.554335907875444, 0.545383287832765, 0.536550262790657, 0.527832502749098, 0.519225987708069, 0.510726947667552, 0.502331877627532, 0.494037482587991, 0.485840672548915, 0.477738552510291, 0.469728387472105, 0.461807612434346, 0.453973792397001, 0.446224637360059, 0.438557992323511, 0.430971792287346, 0.423464102251556, 0.416033072216131, 0.408676957181063, 0.401394097146344, 0.394182907111967, 0.387041887077925, 0.37996959704421, 0.372964682010816, 0.366025836977738, 0.359151826944968, 0.352341461912502, 0.345593611880334, 0.338907206848459, 0.332281206816871, 0.325714636785567, 0.319206551754542, 0.312756056723792, 0.306362286693312, 0.300024421663098, 0.293741681633147, 0.287513316603455, 0.281338606574019, 0.275216871544836, 0.269147456515902, 0.263129736487215, 0.257163126458771, 0.251247051430568, 0.245380976402603, 0.239564391374875, 0.23379680634738, 0.228077761320116, 0.222406821293082, 0.216783576266275, 0.211207636239693, 0.205678631213336, 0.2001962261872, 0.194760096161285, 0.189369956135589, 0.184025521110111, 0.17872654608485, 0.173472806059805, 0.168264096034974, 0.163100231010357, 0.157981060985953, 0.152906445961762, 0.147876280937782, 0.142890485914014, 0.137949000890457, 0.133051800867111, 0.128198880843976, 0.123390270821053, 0.118626030798341, 0.113906255775841, 0.109231075753554, 0.10460064573148, 0.10001518070962, 0.0954749256879758, 0.0909801806665486, 0.0865312806453399, 0.0821286406243518, 0.0777727156035863, 0.0734640505830462, 0.0692032505627342, 0.0649910155426537, 0.0608281455228087, 0.0567155605032033, 0.0526543004838426, 0.0486455804647323, 0.0446907854458791, 0.0407915404272907, 0.0369497254089762, 0.033167580390946, 0.029447765373213, 0.0257935153557927, 0.0222088053387037, 0.0186986753219703, 0.0152696853056238, 0.0119307652897066, 0.00869486527428043, 0.0055827402594445, 0.00263449024538964, 2.3283064365387e-10};

	//xm[A-1]/xm[A] * 2^32
static unsigned int xm_ratio_maxMT[127] = {3389068070, 3733320545, 3884603836, 3970279226, 4025548854, 4064200067, 4092764454, 4114741400, 4132177220, 4146348499, 4158093810, 4167986632, 4176432502, 4183726358, 4190088144, 4195684698, 4200645406, 4205071951, 4209045153, 4212630437, 4215881147, 4218841087, 4221546805, 4224028950, 4226313263, 4228421780, 4230373233, 4232183815, 4233867544, 4235436586, 4236901557, 4238271784, 4239555460, 4240759933, 4241891527, 4242956112, 4243958731, 4244903982, 4245796038, 4246638540, 4247434909, 4248188079, 4248900856, 4249575790, 4250214993, 4250820658, 4251394576, 4251938530, 4252454073, 4252942599, 4253405468, 4253843812, 4254258829, 4254651447, 4255022644, 4255373192, 4255703897, 4256015513, 4256308572, 4256583764, 4256841532, 4257082396, 4257306721, 4257514921, 4257707348, 4257884256, 4258045868, 4258192432, 4258324072, 4258440908, 4258543089, 4258630545, 4258703355, 4258761470, 4258804770, 4258833161, 4258846473, 4258844495, 4258826935, 4258793452, 4258743746, 4258677299, 4258593724, 4258492300, 4258372497, 4258233566, 4258074666, 4257894850, 4257693163, 4257468343, 4257219159, 4256944149, 4256641623, 4256309794, 4255946515, 4255549480, 4255116018, 4254643130, 4254127381, 4253564735, 4252950862, 4252280455, 4251547580, 4250745086, 4249865019, 4248897510, 4247831334, 4246652624, 4245344957, 4243888252, 4242257869, 4240422877, 4238344713, 4235973456, 4233244571, 4230071659, 4226337866, 4221879119, 4216458817, 4209720285, 4201099943, 4189645342, 4173601743, 4149307837, 4107483804, 4014245659, 2222445919};

static unsigned char j=0;
static unsigned int u0;

void rnorm_vect(int N, double * vector, SEXP * mu, SEXP * sd)
{
	unsigned int A;
	unsigned int u;

	double u1;

	double* mu_vect = REAL(*mu);
	double* sd_vect = REAL(*sd);
		
	int n_mu = length(*mu);
	int n_sd = length(*sd);

	for(int i=0 ; i != N ; ++i)
	{
		if(!j)
		{
			u0 = mt_rand();
			j=3;
		}
		else
		{
			--j;
		}
		A =  u0 & 127;
		u0 >>= 7;

		vector[i] = 0.;
		while(!vector[i])
		{
			u = mt_rand();
			u1 = static_cast<double>(u)*INV_MAX_MT*xm[A];
			if(A && (u <= xm_ratio_maxMT[A-1]))
			{
				vector[i] = u0 & 1 ? mu_vect[i % n_mu] + sd_vect[i % n_sd]*u1 : mu_vect[i % n_mu] -sd_vect[i % n_sd]*u1; //rbernou() ? u : -u
				u0 >>=1;
			}
			else
			{
				if(runif(ym[A], (A ? ym[A-1] : 1.)) <= exp(-.5*u1*u1))
				{
					vector[i] = u0 & 1 ? mu_vect[i % n_mu] + sd_vect[i % n_sd]*u1 : mu_vect[i % n_mu] -sd_vect[i % n_sd]*u1; 
					u0 >>=1;
				}
			}
		}
	}
}


void rnorm_rpgm01(int N, double * vector)
{
	unsigned int A;
	unsigned int u;
	
	double u1;

	for(int i=0 ; i != N ; ++i)
	{
		if(!j)
		{
			u0 = mt_rand();
			j=3;
		}
		else
		{
			--j;
		}
		A =  u0 & 0x7F; //127
		u0 >>= 0x7; //7

		vector[i] = 0.;
		while(!vector[i])
		{
			u = mt_rand();
			u1 = static_cast<double>(u)*INV_MAX_MT*xm[A];
			if(A && (u <= xm_ratio_maxMT[A-1]))
			{
				vector[i] = u0 & 1 ? u1 : -u1; //rbernou() ? u : -u
				u0 >>=1;
			}
			else
			{
				if(runif(ym[A], (A ? ym[A-1] : 1.)) <= exp(-.5*u1*u1))
				{
					vector[i] = u0 & 1 ? u1 : -u1; 
					u0 >>=1;
				}
			}
		}
	}
}

void rnorm_rpgm(int N, double * vector, double mu_, double sd_)
{
	unsigned int A;
	unsigned int u;
	
	double u1;

	for(int i=0 ; i != N ; ++i)
	{
		if(!j)
		{
			u0 = mt_rand();
			j=3;
		}
		else
		{
			--j;
		}
		A =  u0 & 127;
		u0 >>= 7;

		vector[i] = 0.;
		while(!vector[i])
		{
			u = mt_rand();
			u1 = static_cast<double>(u)*INV_MAX_MT*xm[A];
			if(A && (u <= xm_ratio_maxMT[A-1]))
			{
				vector[i] = u0 & 1 ? mu_ + sd_*u1 : mu_ -sd_*u1; //rbernou() ? u : -u
				u0 >>=1;
			}
			else
			{
				if(runif(ym[A], (A ? ym[A-1] : 1.)) <= exp(-.5*u1*u1))
				{
					vector[i] = u0 & 1 ? mu_ + sd_*u1 : mu_ -sd_*u1; 
					u0 >>=1;
				}
			}
		}
	}
}

extern "C" 
{
// [[register]]	
SEXP rn(SEXP n, SEXP mu, SEXP sd, SEXP nthreads)
{
	int N, NTHREADS;
	
	double mu_;
	double sd_;
	
	if(TYPEOF(n) == INTSXP)
		N=*INTEGER(n);
	else if(TYPEOF(n) == REALSXP)
		N = (int) *REAL(n);
	else
		N = 0;
	
	if(TYPEOF(nthreads) == INTSXP)
		NTHREADS=*INTEGER(nthreads);
	else if(TYPEOF(nthreads) == REALSXP)
		NTHREADS = (int) *REAL(nthreads);
	else
		NTHREADS = 1;
	
	if(NTHREADS != 1)
	{
#ifdef _OPENMP
		if(NTHREADS < 1)
		{
			warning("Negative number of threads: nthreads = %d, one is used (no multi-core).\n", NTHREADS);
			NTHREADS = 1;
		}
		else if (NTHREADS > omp_get_max_threads())
		{
			warning("Number of threads: nthreads = %d is greater than the maximum: maxthreads() = %d, %d are used.\n", NTHREADS, omp_get_max_threads(), omp_get_max_threads());
			NTHREADS = omp_get_max_threads();
		}
#else
			warning("Number of threads: nthreads = %d is greater than the maximum: maxthreads() = %d, %d are used.\n", NTHREADS, 1, 1);
			NTHREADS = 1;
#endif
	}

	SEXP vector_sexp;
	double* vector;
	PROTECT(vector_sexp = allocVector(REALSXP, N));
	vector = REAL(vector_sexp);
	


	if(length(mu) == 1 && length(sd) == 1)
	{
		if(TYPEOF(mu) == REALSXP)
		{
			mu_ = *REAL(mu);
		}
		else if(TYPEOF(mu) == INTSXP)
		{
			mu_ = (double) *INTEGER(mu);
		}
		else
		{
			mu_ = 0.;
		}
		
		if(TYPEOF(sd) == REALSXP)
		{
			sd_ = *REAL(sd);
		}
		else if(TYPEOF(sd) == INTSXP)
		{
			sd_ = (double) *INTEGER(sd);
		}
		else
		{
			sd_ = 1.;
		}
		
		if(mu_ == 0. && sd_ == 1.)
			#ifdef _OPENMP
			if(NTHREADS == 1)
				rnorm_rpgm01(N, vector);
			else
				rnorm_rpgm01_mc(N, vector, NTHREADS);
			#else
				rnorm_rpgm01(N, vector);
			#endif
		else
			#ifdef _OPENMP
			if(NTHREADS == 1)
				rnorm_rpgm(N, vector, mu_, sd_);
			else
				rnorm_rpgm_mc(N, vector, mu_, sd_, NTHREADS);
			#else
				rnorm_rpgm(N, vector, mu_, sd_);
			#endif
	}
	else
	{
		rnorm_vect(N, vector, &mu, &sd);
	}

	UNPROTECT(1);

	return vector_sexp;
}

}

//Log-normal

void rlnorm_vect(int N, double * vector, SEXP * mu, SEXP * sd)
{
	unsigned int A;
	unsigned int u;
	
	double u1;
	
	double* mu_vect = REAL(*mu);
	double* sd_vect = REAL(*sd);
		
	int n_mu = length(*mu);
	int n_sd = length(*sd);

	for(int i=0 ; i != N ; ++i)
	{
		if(!j)
		{
			u0 = mt_rand();
			j=3;
		}
		else
		{
			--j;
		}
		A =  u0 & 127;
		u0 >>= 7;

		vector[i] = 0.;
		while(!vector[i])
		{
			u = mt_rand();
			u1 = static_cast<double>(u)*INV_MAX_MT*xm[A];
			if(A && (u <= xm_ratio_maxMT[A-1]))
			{
				vector[i] = u0 & 1 ? exp(mu_vect[i % n_mu] + sd_vect[i % n_sd]*u1) : exp(mu_vect[i % n_mu] -sd_vect[i % n_sd]*u1); //rbernou() ? u : -u
				u0 >>=1;
			}
			else
			{
				if(runif(ym[A], (A ? ym[A-1] : 1.)) <= exp(-.5*u1*u1))
				{
					vector[i] = u0 & 1 ? exp(mu_vect[i % n_mu] + sd_vect[i % n_sd]*u1) : exp(mu_vect[i % n_mu] -sd_vect[i % n_sd]*u1);
					u0 >>=1;
				}
			}
		}
	}
}


void rlnorm_rpgm01(int N, double * vector)
{
	unsigned int A;
	unsigned int u;
	
	double u1;
	
	for(int i=0 ; i != N ; ++i)
	{
		if(!j)
		{
			u0 = mt_rand();
			j=3;
		}
		else
		{
			--j;
		}
		A =  u0 & 127;
		u0 >>= 7;

		vector[i] = 0.;
		while(!vector[i])
		{
			u = mt_rand();
			u1 = static_cast<double>(u)*INV_MAX_MT*xm[A];
			if(A && (u <= xm_ratio_maxMT[A-1])) //pr�calculer xm[A] / xm[A-1] pour comparer U0. Et m�me pr�calculer Max_MT*(xm[A] / xm[A-1]) en integer pour comparaison avec mt_rand()
			{
				vector[i] = u0 & 1 ? exp(u1) : exp(-u1); //rbernou() ? u : -u
				u0 >>=1;
			}
			else
			{
				if(runif(ym[A], (A ? ym[A-1] : 1.)) <= exp(-.5*u1*u1))
				{
					vector[i] = u0 & 1 ? exp(u1) : exp(-u1); 
					u0 >>=1;
				}
			}
		}
	}
}

void rlnorm_rpgm(int N, double * vector, double mu_, double sd_)
{
	unsigned int A;
	unsigned int u;
	
	double u1;

	for(int i=0 ; i != N ; ++i)
	{
		if(!j)
		{
			u0 = mt_rand();
			j=3;
		}
		else
		{
			--j;
		}
		A =  u0 & 127;
		u0 >>= 7;

		vector[i] = 0.;
		while(!vector[i])
		{
			u = mt_rand();
			u1 = static_cast<double>(u)*INV_MAX_MT*xm[A];
			if(A && (u <= xm_ratio_maxMT[A-1])) //pr�calculer xm[A] / xm[A-1] pour comparer U0. Et m�me pr�calculer Max_MT*(xm[A] / xm[A-1]) en integer pour comparaison avec mt_rand()
			{
				vector[i] = u0 & 1 ? exp(mu_ + sd_*u1) : exp(mu_ -sd_*u1); //rbernou() ? u : -u
				u0 >>=1;
			}
			else
			{
				if(runif(ym[A], (A ? ym[A-1] : 1.)) <= exp(-.5*u1*u1))
				{
					vector[i] = u0 & 1 ? exp(mu_ + sd_*u1) : exp(mu_ -sd_*u1); 
					u0 >>=1;
				}
			}
		}
	}
}


extern "C" 
{
// [[register]]
SEXP rln(SEXP n, SEXP mu, SEXP sd)
{
	int N;
	
	double mu_;
	double sd_;

		if(TYPEOF(n) == INTSXP)
		N=*INTEGER(n);
	else if(TYPEOF(n) == REALSXP)
		N = (int) *REAL(n);
	else
		N = 0;

	SEXP vector_sexp;
	double* vector;
	PROTECT(vector_sexp = allocVector(REALSXP, N));
	vector = REAL(vector_sexp);
	


	if(length(mu) == 1 && length(sd) == 1)
	{
		if(TYPEOF(mu) == REALSXP)
		{
			mu_ = *REAL(mu);
		}
		else if(TYPEOF(mu) == INTSXP)
		{
			mu_ = (double) *INTEGER(mu);
		}
		else
		{
			mu_ = 0.;
		}
		
		if(TYPEOF(sd) == REALSXP)
		{
			sd_ = *REAL(sd);
		}
		else if(TYPEOF(sd) == INTSXP)
		{
			sd_ = (double) *INTEGER(sd);
		}
		else
		{
			sd_ = 1.;
		}
		
		if(mu_ == 0. && sd_ == 1.)
			rlnorm_rpgm01(N, vector);
		else
			rlnorm_rpgm(N, vector, mu_, sd_);
	}
	else
	{
		rlnorm_vect(N, vector, &mu, &sd);
	}

	UNPROTECT(1);

	return vector_sexp;
}
}
//student


void rt_vect(int N, double * vector, SEXP * df)
{
	unsigned int A;
	unsigned int u;
	
	double u1;
	
	double* df_vect = REAL(*df);
		
	int n_df = length(*df);

	for(int i=0 ; i != N ; ++i)
	{
		if(!j)
		{
			u0 = mt_rand();
			j=3;
		}
		else
		{
			--j;
		}
		A =  u0 & 127;
		u0 >>= 7;

		vector[i] = 0.;
		while(!vector[i])
		{
			u = mt_rand();
			u1 = static_cast<double>(u)*INV_MAX_MT*xm[A];
			if(A && (u <= xm_ratio_maxMT[A-1])) //pr�calculer xm[A] / xm[A-1] pour comparer U0. Et m�me pr�calculer Max_MT*(xm[A] / xm[A-1]) en integer pour comparaison avec mt_rand()
			{
				vector[i] = u0 & 1 ? u1/sqrt(rchisq(df_vect[i % n_df])/df_vect[i % n_df]) :  -u1/sqrt(rchisq(df_vect[i % n_df])/df_vect[i % n_df]); //rbernou() ? u : -u
				u0 >>=1;
			}
			else
			{
				if(runif(ym[A], (A ? ym[A-1] : 1.)) <= exp(-.5*u1*u1))
				{
					vector[i] = u0 & 1 ?  u1/sqrt(rchisq(df_vect[i % n_df])/df_vect[i % n_df]) : -u1/sqrt(rchisq(df_vect[i % n_df])/df_vect[i % n_df]); 
					u0 >>=1;
				}
			}
		}
	}
}


void rt_rpgm(int N, double * vector, double df)
{
	unsigned int A;
	unsigned int u;
	
	double u1;

	double inv_df = 1/df;
	
	for(int i=0 ; i != N ; ++i)
	{
		if(!j)
		{
			u0 = mt_rand();
			j=3;
		}
		else
		{
			--j;
		}
		A =  u0 & 127;
		u0 >>= 7;

		vector[i] = 0.;
		while(!vector[i])
		{
			u = mt_rand();
			u1 = static_cast<double>(u)*INV_MAX_MT*xm[A];
			if(A && (u <= xm_ratio_maxMT[A-1])) //pr�calculer xm[A] / xm[A-1] pour comparer U0. Et m�me pr�calculer Max_MT*(xm[A] / xm[A-1]) en integer pour comparaison avec mt_rand()
			{
				vector[i] = u0 & 1 ? u1/sqrt(inv_df*rchisq(df)): -u1/sqrt(inv_df*rchisq(df)); //rbernou() ? u : -u
				u0 >>=1;
			}
			else
			{
				if(runif(ym[A], (A ? ym[A-1] : 1.)) <= exp(-.5*u1*u1))
				{
					vector[i] = u0 & 1 ? u1/sqrt(inv_df*rchisq(df)) : -u1/sqrt(inv_df*rchisq(df)); 
					u0 >>=1;
				}
			}
		}
	}
}

extern "C" 
{
// [[register]]
SEXP rtt(SEXP n, SEXP df)
{
	int N;
	
	double df_;

	if(TYPEOF(n) == INTSXP)
		N=*INTEGER(n);
	else if(TYPEOF(n) == REALSXP)
		N = (int) *REAL(n);
	else
		N = 0;

	SEXP vector_sexp;
	double* vector;
	PROTECT(vector_sexp = allocVector(REALSXP, N));
	vector = REAL(vector_sexp);
	


	if(length(df) == 1)
	{
		if(TYPEOF(df) == REALSXP)
		{
			df_ = *REAL(df);
		}
		else if(TYPEOF(df) == INTSXP)
		{
			df_ = (double) *INTEGER(df);
		}
		else
		{
			df_ = 1.;
		}
		
		rt_rpgm(N, vector, df_);
	}
	else
	{
		rt_vect(N, vector, &df);
	}

	UNPROTECT(1);

	return vector_sexp;
}
}