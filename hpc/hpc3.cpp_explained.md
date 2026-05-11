# hpc3.cpp — Line-by-line explanation

This file documents each line of `hpc3.cpp` without modifying the original source.

```cpp
// 3. Implement Min, Max, Sum and Average operations using Parallel Reduction.


#include <iostream>
#include <omp.h>

using namespace std;

// ---------- Main Function ----------
int main() {

    int n;

    // input size
    cout << "Enter number of elements : ";
    cin >> n;

    int arr[100];

    // input array elements
    cout << "Enter array elements : ";

    for(int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    // variables
    int minValue = arr[0];
    int maxValue = arr[0];
    int sum = 0;

    double average;

    // control number of threads
    omp_set_num_threads(4);

    double startTime, endTime;

    // start time
    startTime = omp_get_wtime();

    // ---------- Parallel Reduction ----------
    #pragma omp parallel for reduction(min:minValue) reduction(max:maxValue) reduction(+:sum)

    for(int i = 0; i < n; i++) {

        // find minimum
        if(arr[i] < minValue) {

            minValue = arr[i];
        }

        // find maximum
        if(arr[i] > maxValue) {

            maxValue = arr[i];
        }

        // calculate sum
        sum += arr[i];
    }

    // calculate average
    average = (double)sum / n;

    // end time
    endTime = omp_get_wtime();

    // ---------- Output ----------
    cout << "\nMinimum Value : " << minValue << endl;

    cout << "Maximum Value : " << maxValue << endl;

    cout << "Sum : " << sum << endl;

    cout << "Average : " << average << endl;

    cout << "Execution Time : " << endTime - startTime << endl;

    return 0;
}
```

- Program reads `n`, then `n` integers into `arr`.
- Initializes `minValue` and `maxValue` with first element and `sum` to 0.
- Uses `#pragma omp parallel for` with OpenMP reductions: `min` and `max` reductions update `minValue` and `maxValue` correctly across threads, `+:sum` sums elements in parallel.
- After the loop, compute average and display min, max, sum, average, and execution time measured with `omp_get_wtime()`.

Notes:
- The array size is fixed to 100; ensure `n <= 100` to avoid overflow.
