# Overview Of OpenMP
A thread is a runtime entity that is able to independently execute a stream of instructions.If multiple threads collaborate to execute a program, they will share the resources,including the address space, of the corresponding process.It supports the so-called fork-join programming model.

The OpenMP API comprises a set of compiler directives, runtime library routines, and environment variables to specify shared-memory parallelism in Fortran and C/C++ programs. An OpenMP directive is a specially formatted comment or pragma that generally applies to the executable code immediately following it in the program.

If the programmer does not specify how the work in a parallel region is to be shared among the executing threads, they will each redundantly execute all of the code.

## Work Sharing In OpenMP
- **Number of iterations in the loop Overview of OpenMP upon entry, and this number may not change while the loop is executing.**

- **Furthermore, a loop is suitable for sharing among threads only if its iterations are independent. By this, we mean that the order in which the iterations are performed has no bearing on the outcome.**

## OpenMP Memory Model

OpenMP is based on the shared-memory model; hence, by default, data is shared among the threads and is visible to all of them. Sometimes, however, one needs variables that have thread-specific values. When each thread has its own copy of a variable, so that it may potentially have a different value for each of them, we say that the variable is private.


OpenMP also has a feature called flush, to synchronize memory. A flush operation makes sure that the thread calling it has the same values for shared data objects as does main memory.

OpenMP gets threads to wait at the end of a work-sharing construct or parallel region until all threads in the team executing it have finished their portion of the work. Only then can they proceed. This is known as a barrier. Synchronizing the actions of a subset of threads is harder to accomplish in OpenMP and requires care in programming because there is no explicit support for this.
