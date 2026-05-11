# hpc2.cpp — Line-by-line explanation

This file documents each line of `hpc2.cpp` without modifying the original source.

```cpp
// Write a program to implement Parallel Bubble Sort and Merge sort using OpenMP. Use
// existing algorithms and measure the performance of sequential and parallel algorithms.

#include <iostream>     // for input and output
#include <algorithm>    // for swap()
#include <omp.h>        // for OpenMP
using namespace std;
```
- Header comment describes the assignment.
- `iostream` provides `cin`/`cout`, `algorithm` provides `swap`, `omp.h` for OpenMP, and `using namespace std;` for convenience.

```cpp
// ---------- Sequential Bubble Sort ----------
void bubbleSort(int arr[], int n) {

    // repeat for all passes
    for(int i = 0; i < n-1; i++) {

        // compare adjacent elements
        for(int j = 0; j < n-i-1; j++) {

            // swap if wrong order
            if(arr[j] > arr[j+1]) {

                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```
- `bubbleSort` implements standard sequential bubble sort: nested loops comparing adjacent elements and swapping when out of order.

```cpp
// ---------- Parallel Bubble Sort ----------
void parallelBubbleSort(int arr[], int n) {

    // odd-even transposition sort
    for(int i = 0; i < n; i++) {

        // parallel loop
        #pragma omp parallel for

        // even phase when i even
        // odd phase when i odd
        for(int j = i%2; j < n-1; j += 2) {

            // compare and swap
            if(arr[j] > arr[j+1]) {

                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```
- `parallelBubbleSort` uses odd-even transposition sorting: on even iterations it compares (0,1),(2,3)..., on odd iterations (1,2),(3,4)...
- The inner loop is parallelized with `#pragma omp parallel for` because non-overlapping pairs can be compared/swapped concurrently.

```cpp
// ---------- Merge Function ----------
void merge(int arr[], int start, int mid, int end) {

    int temp[50];   // temporary array

    // dynamic array size
    // int temp[end - start + 1];

    int i = start;      // left half start
    int j = mid + 1;    // right half start
    int k = 0;          // temp index

    // merge sorted halves
    while(i <= mid && j <= end) {

        if(arr[i] <= arr[j]) {

            temp[k] = arr[i];
            i++;
        }
        else {

            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // remaining left elements
    while(i <= mid) {

        temp[k] = arr[i];
        i++;
        k++;
    }

    // remaining right elements
    while(j <= end) {

        temp[k] = arr[j];
        j++;
        k++;
    }

    // copy back to original array
    for(int idx = 0; idx < k; idx++) {

        arr[idx + start] = temp[idx];
    }
}
```
- `merge` merges two sorted subarrays [start..mid] and [mid+1..end] into `temp`, then copies `temp` back into `arr`.

```cpp
// ---------- Sequential Merge Sort ----------
void mergeSort(int arr[], int start, int end) {

    // if more than one element
    if(start < end) {

        // find middle
        int mid = (start + end) / 2;

        // left half
        mergeSort(arr, start, mid);

        // right half
        mergeSort(arr, mid + 1, end);

        // merge both halves
        merge(arr, start, mid, end);
    }
}
```
- `mergeSort` is standard recursive merge sort splitting, sorting, merging.

```cpp
// ---------- Parallel Merge Sort ----------
void parallelMergeSort(int arr[], int start, int end) {

    // if more than one element
    if(start < end) {

        // find middle
        int mid = (start + end) / 2;

        // parallel sections
        #pragma omp parallel sections
        {

            // left section
            #pragma omp section
            parallelMergeSort(arr, start, mid);

            // right section
            #pragma omp section
            parallelMergeSort(arr, mid + 1, end);
        }

        // merge sorted halves
        merge(arr, start, mid, end);
    }
}
```
- `parallelMergeSort` divides work into OpenMP parallel sections: left and right halves are processed concurrently, then merged.

```cpp
// ---------- Print Function ----------
void printArray(int arr[], int n) {

    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }

    cout << endl;
}
```
- `printArray` simply prints elements separated by spaces.

```cpp
// ---------- Main Function ----------
int main() {

    int n;

    // input size
    cout << "Enter number of elements : ";
    cin >> n;

    int a[50], b[50];

    // input array elements
    cout << "Enter array elements : ";

    for(int i = 0; i < n; i++) {

        cin >> a[i];

        // copy same values into b
        b[i] = a[i];
    }

    // control number of threads
    omp_set_num_threads(4);

    double startTime, endTime;

    // original array
    cout << "\nOriginal Array : ";
    printArray(a, n);

    // ---------- Sequential Bubble Sort ----------
    startTime = omp_get_wtime();

    bubbleSort(a, n);

    endTime = omp_get_wtime();

    cout << "\nSequential Bubble Sort : ";
    printArray(a, n);

    cout << "Time : " << endTime - startTime << endl;

    // reset array
    for(int i = 0; i < n; i++) {

        a[i] = b[i];
    }

    // ---------- Parallel Bubble Sort ----------
    startTime = omp_get_wtime();

    parallelBubbleSort(a, n);

    endTime = omp_get_wtime();

    cout << "\nParallel Bubble Sort : ";
    printArray(a, n);

    cout << "Time : " << endTime - startTime << endl;

    // ---------- Sequential Merge Sort ----------
    startTime = omp_get_wtime();

    mergeSort(b, 0, n-1);

    endTime = omp_get_wtime();

    cout << "\nSequential Merge Sort : ";
    printArray(b, n);

    cout << "Time : " << endTime - startTime << endl;

    // reset array
    for(int i = 0; i < n; i++) {

        b[i] = n - i;
    }

    // ---------- Parallel Merge Sort ----------
    startTime = omp_get_wtime();

    parallelMergeSort(b, 0, n-1);

    endTime = omp_get_wtime();

    cout << "\nParallel Merge Sort : ";
    printArray(b, n);

    cout << "Time : " << endTime - startTime << endl;

    return 0;
}
```
- `main()` reads `n` and elements, duplicates the array to `b`, times sequential and parallel versions of bubble and merge sorts, prints results and timings.

---

Notes:
- Temporary arrays have fixed sizes (`int temp[50]`) which may overflow; production code should allocate dynamically based on `n`.
- Parallel constructs rely on the programmer ensuring thread-safety (e.g., critical sections used in bubble sort implementation).
