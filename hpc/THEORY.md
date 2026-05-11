# HPC Folder — Theory & Viva Questions

This file summarizes the key theory behind the `hpc` practicals and lists common viva questions with concise answers.

## Topics covered
- OpenMP basics: pragmas, parallel for, parallel sections, reduction, critical.
- Parallel algorithms: odd-even transposition (parallel bubble), parallel merge sort, parallel reductions.
- Performance measurement: `omp_get_wtime()` for timings.
- Parallel correctness: race conditions, use of `critical` and `reduction` to protect shared state.

## Short viva questions and answers

- Q: What is OpenMP?
  - A: OpenMP is an API for shared-memory parallel programming in C/C++ and Fortran. It provides pragmas to parallelize loops and sections.

- Q: How does `reduction` work?
  - A: `reduction` creates a private copy of the reduction variable per thread, combines results at the end using the specified operator (e.g., `+`, `min`, `max`).

- Q: Why is `critical` used in BFS/DFS implementations here?
  - A: `critical` serializes access to shared updates (like marking `visited` and pushing to the queue) to prevent race conditions.

- Q: What are limitations of the provided parallel DFS approach?
  - A: Recursion inside a critical region serializes the recursive calls and can cause stack growth; more sophisticated tasking or work-stealing approaches are preferable.

- Q: How to measure parallel speedup?
  - A: Measure execution time of sequential and parallel runs (using `omp_get_wtime()`), then compute speedup = T_seq / T_par.

- Q: What risks does using fixed-size arrays (like `int arr[100]`) introduce?
  - A: If input size exceeds array size, it causes buffer overflow and undefined behavior. Use dynamic allocation or `std::vector`.

## Suggested answers for viva (expanded)
- Explain how odd-even transposition sort becomes parallel: each phase compares disjoint pairs so comparisons are independent and can be done in parallel.
- Explain merge sort parallelization: recursively sort halves in parallel then merge; merging is generally sequential unless parallel merge algorithms are used.
- Discuss synchronisation overhead: `critical` sections and false sharing can limit scalability.

---

Place this file next to the source files for quick revision before viva.
