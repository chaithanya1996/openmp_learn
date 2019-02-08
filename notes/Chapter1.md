# Introduction

In order to achieve their breakneck speed, today’s computer systems are highly complex  They are made up of multiple components, or functional units, that may be able to operate simultaneously and have specific tasks, such as adding two integer numbers or determining whether a value is greater than zero. As a result, computer might be able to fetch a datum from memory, multiply two floating-point numbers, and evaluate a branch condition all at the same time. This is a very low level of parallel processing and is often referred to as “instruction-level parallelism,”

- The lion’s share of the work of finding such a suitable ordering of operations is performed by the compiler.
- we will refer to shared-memory parallel computers as SMPs,each of them can access any memory location with the same speed; that is, they have a uniform memory access (UMA) time
- Larger shared-memory machines, however, usually do not satisfy this definition; even though the differ- ence may be relatively small, some memory may be “nearer to” one or more of the processors and thus accessed faster by them We say that such machines have cache-coherent non-uniform memory access (cc-NUMA)
- SMPs have some memory that is not shared.
