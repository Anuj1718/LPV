# HPC Practicals — Viva Questions & Answers (30+)

Q1: What is OpenMP?
- A1: OpenMP is an API for parallel programming on shared-memory systems using pragmas to control parallel regions, loops, and synchronization.

Q2: What is a race condition?
- A2: A race happens when multiple threads access and modify shared data concurrently without proper synchronization, leading to unpredictable results.

Q3: How to avoid race conditions in OpenMP?
- A3: Use `critical`, `atomic`, `reduction`, or private/thread-local variables where appropriate.

Q4: What is `reduction` and when to use it?
- A4: `reduction` safely combines per-thread partial results (e.g., sums, mins) at the end of a parallel region to compute a global result.

Q5: Difference between `critical` and `atomic`?
- A5: `critical` enforces a block to run by one thread at a time (more general); `atomic` is lighter-weight for simple read-modify-write operations on scalars.

Q6: What is false sharing?
- A6: False sharing occurs when threads modify different variables that reside on the same cache line, causing unnecessary cache coherence traffic.

Q7: What is Amdahl's Law?
- A7: Amdahl's Law states the theoretical speedup limit is 1 / (serial_fraction + parallel_fraction/num_threads), showing diminishing returns with limited parallelizable work.

Q8: What is Gustafson's Law?
- A8: Gustafson's Law argues that increasing problem size allows greater speedup, scaling parallel efficiency with larger workloads.

Q9: How to choose number of threads?
- A9: Choose based on CPU cores, hyperthreading, memory bandwidth, and testing; set `OMP_NUM_THREADS` or `omp_set_num_threads()`.

Q10: What is `parallel for` scheduling and its types?
- A10: `schedule` controls loop iteration assignment: `static`, `dynamic`, or `guided` distribute iterations differently to balance load.

Q11: When to use `parallel sections` vs `parallel for`?
- A11: Use `parallel sections` for distinct independent tasks; `parallel for` for distributing loop iterations across threads.

Q12: How to measure performance in OpenMP programs?
- A12: Use `omp_get_wtime()` for wall-time, profile CPU/GPU counters, and measure speedup and efficiency across varying thread counts.

Q13: What is thread affinity and why set it?
- A13: Affinity binds threads to specific CPU cores to improve cache locality and reduce context-switching overhead.

Q14: What is task parallelism vs data parallelism?
- A14: Task parallelism runs different tasks concurrently; data parallelism splits data among threads executing the same task.

Q15: How to avoid deadlocks in parallel programs?
- A15: Avoid circular waits, minimize nested locks, and use timeout strategies or avoid manual locking when possible.

Q16: What is `collapse` clause used for?
- A16: `collapse(n)` combines nested loops into a single loop for parallelization when iterations are independent across loops.

Q17: Why use `threadprivate` variables?
- A17: To give each thread a private copy of a global variable across parallel regions.

Q18: How to debug incorrect parallel output?
- A18: Reproduce with single thread, add logging with thread IDs, use race detectors, and simplify the code to isolate race conditions.

Q19: What is memory bandwidth limitation?
- A19: When many threads access memory intensively, memory bandwidth becomes the bottleneck, limiting scalability.

Q20: What is vectorization and SIMD?
- A20: Vectorization uses single-instruction-multiple-data to process multiple data elements per instruction, accelerating numeric loops.

Q21: How to minimize synchronization overhead?
- A21: Reduce use of `critical`, use reductions or atomics where possible, and restructure algorithms to minimize shared writes.

Q22: What are parallel skeletons and libraries?
- A22: High-level patterns (map, reduce, stencil) and libraries abstract common parallel operations for easier implementation.

Q23: How to handle I/O in parallel programs?
- A23: Serialize I/O, use thread-safe I/O libraries, or aggregate results per thread and output from a single thread to avoid interleaving.

Q24: What is strong vs weak scaling?
- A24: Strong scaling measures performance with fixed problem size as threads increase; weak scaling measures performance while increasing problem size proportionally.

Q25: How to profile OpenMP applications?
- A25: Use profilers (gprof, Intel VTune, perf), and OpenMP-specific tools to measure hotspots and thread imbalance.

Q26: What is load imbalance and how to fix it?
- A26: Load imbalance occurs when work is unevenly distributed; fix with dynamic scheduling or better partitioning.

Q27: Why prefer `std::vector` over raw arrays in parallel code?
- A27: `std::vector` handles dynamic sizing and RAII; careful with concurrent access but safer for bounds and allocation.

Q28: How to parallelize recursive algorithms?
- A28: Use tasking (`#pragma omp task`) to spawn subtasks for recursive calls and synchronize with `taskwait`.

Q29: What is the effect of hyperthreading on OpenMP performance?
- A29: Hyperthreading may help hide latency but can reduce per-thread performance due to shared core resources; test empirically.

Q30: Practical viva tip: how to show your parallel code scales?
- A30: Provide timing results across varying thread counts, plot speedup and efficiency, and discuss bottlenecks and scaling limits.
