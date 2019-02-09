# Introduction

In order to achieve their breakneck speed, today’s computer systems are highly complex  They are made up of multiple components, or functional units, that may be able to operate simultaneously and have specific tasks, such as adding two integer numbers or determining whether a value is greater than zero. As a result, computer might be able to fetch a datum from memory, multiply two floating-point numbers, and evaluate a branch condition all at the same time. This is a very low level of parallel processing and is often referred to as “instruction-level parallelism,”

- The lion’s share of the work of finding such a suitable ordering of operations is performed by the compiler.

- we will refer to shared-memory parallel computers as SMPs,each of them can access any memory location with the same speed; that is, they have a uniform memory access (UMA) time

- Larger shared-memory machines, however, usually do not satisfy this definition; even though the differ- ence may be relatively small, some memory may be “nearer to” one or more of the processors and thus accessed faster by them We say that such machines have cache-coherent non-uniform memory access (cc-NUMA)

- SMPs have some memory that is not shared.very fast memory called cache memory, or “cache” for short, supplies the processor with data and instructions at high rates. Each processor of an SMP needs its own private cache if it is to be fed quickly; hence, not all memory is shared.

- In a uniprocessor system, new values computed by the processor are written back to cache, This strategy does not work for SMP systems.This is known as the memory consistency problem.

- OpenMP’s directives let the user tell the compiler which instructions to execute in parallel and how to distribute them among the threads that will run the code.

- A different programming model has been proposed for distributed-memory systems. Generically referred to as “message passing,” this model assumes that programs will be executed by one or more processes, each of which has its own pri-vate address space


- OpenMP
  - Automatic parallelization: Many compilers provide a flag, or option, for automatic program parallelization. When this is selected, the compiler analyzes the program, searching for independent sets of instructions
- MPI
  - The Message Passing Interface [137] was developed to facilitate portable programming for distributed-memory architectures (MPPs), where multiple pro- cesses execute independently and communicate data as needed by exchanging mes- sages.

-Pthreads
	- It realizes the shared-memory programming model via a collection of routines for creating, managing and coordinating a col- lection of threads. Thus, like MPI, it is a library.
 
 
## Program For Dot Product In different Paradrigms

*** Sequential***

``` c
int main(int argc,char *argv[]){
	double sum;
	double a [256], b [256];
	int n;
	n = 256;
	for (i = 0; i < n; i++) {
		a [i] = i * 0.5;
		b [i] = i * 2.0;
	}
	sum = 0;
	for (i = 1; i <= n; i++ ) {
		sum = sum + a[i]*b[i];
	}
		printf ("sum = %f", sum);
}
```
**MPI**

```c
int main(argc,argv)
int argc;
char *argv[];
{
double sum, sum_local;
double a [256], b [256];
int n, numprocs, myid, my_first, my_last;
n = 256;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&myid);
my_first = myid * n/numprocs;
my_last = (myid + 1) * n/numprocs;
for (i = 0; i < n; i++) {
a [i] = i * 0.5;
b [i] = i * 2.0;
}
sum_local = 0;
for (i = my_first; i < my_last; i++) {
sum_local = sum_local + a[i]*b[i];
}
MPI_Allreduce(&sum_local, &sum, 1, MPI_DOUBLE, MPI_SUM,
MPI_COMM_WORLD);
if (iam==0) printf ("sum = %f", sum);
}
```

**OpenMP Directives**
```c
int main(argc,argv)
int argc; char *argv[];
{
double sum;
double a [256], b [256];
int status;
int n=256;
for (i = 0; i < n; i++) {
a [i] = i * 0.5;
b [i] = i * 2.0;
}
sum = 0;
#pragma omp for reduction(+:sum)
for (i = 1; i <= n; i++ ) {
sum = sum + a[i]*b[i];
}
printf ("sum = %f \n", sum);
}
```


**pthreads**

```c
#define NUMTHRDS 4
double sum;
double a [256], b [256];
int status;
int n=256;
pthread_t thd[NUMTHRDS];
pthread_mutex_t mutexsum;
int main(argc,argv)
int argc;
char *argv[];
{
pthread_attr_t attr;
for (i = 0; i < n; i++) {
a [i] = i * 0.5;
b [i] = i * 2.0;
}
thread_mutex_init(&mutexsum, NULL);
pthread_attr_init(&attr);
pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
for(i=0;i<NUMTHRDS;i++)
{
pthread_create( &thds[i], &attr, dotprod, (void *)i);
}
pthread_attr_destroy(&attr);
for(i=0;i<NUMTHRDS;i++) {
pthread_join( thds[i], (void **)&status);
}
printf ("sum = %f \n", sum);
pthread_mutex_destroy(&mutexsum);
pthread_exit(NULL);
}
void *dotprod(void *arg)
{
int myid, i, my_first, my_last;
double sum_local;
myid = (int)arg;
my_first = myid * n/NUMTHRDS;
my_last = (myid + 1) * n/NUMTHRDS;
sum_local = 0;
for (i = my_first; i <= my_last; i++) {
sum_local = sum_local + a [i]*b[i];
}
pthread_mutex_lock (&mutex_sum);
sum = sum + sum_local;
pthread_mutex_unlock (&mutex_sum);
pthread_exit((void*) 0);
}
```
