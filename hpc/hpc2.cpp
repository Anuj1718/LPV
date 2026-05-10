// Write a program to implement Parallel Bubble Sort and Merge sort using OpenMP. Use
// existing algorithms and measure the performance of sequential and parallel algorithms.

#include <iostream>     // for input and output
#include <algorithm>    // for swap()
#include <omp.h>        // for OpenMP
using namespace std;

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

// ---------- Print Function ----------
void printArray(int arr[], int n) {

    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }

    cout << endl;
}

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
