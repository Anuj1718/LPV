// Implement HPC application for AI/ML domain.

#include <iostream>     // for input and output
#include <omp.h>        // for OpenMP parallel programming

using namespace std;

// ---------- Main Function ----------
int main() {

    int n;   // number of data points

    // input number of values
    cout << "Enter number of data points : ";
    cin >> n;

    // arrays for x and y values
    double x[100], y[100];

    // input x values
    cout << "Enter x values : ";

    for(int i = 0; i < n; i++) {

        cin >> x[i];
    }

    // input y values
    cout << "Enter y values : ";

    for(int i = 0; i < n; i++) {

        cin >> y[i];
    }

    // variables required for linear regression formula
    double sumX = 0;     // stores sum of x values
    double sumY = 0;     // stores sum of y values
    double sumXY = 0;    // stores sum of x*y
    double sumX2 = 0;    // stores sum of x^2

    // variables for slope and intercept
    double m, c;

    // set number of threads
    omp_set_num_threads(4);

    // variables for execution time
    double startTime, endTime;

    // start timer
    startTime = omp_get_wtime();

    // ---------- Parallel Reduction ----------
    #pragma omp parallel for reduction(+:sumX,sumY,sumXY,sumX2)

    for(int i = 0; i < n; i++) {

        // calculate sum of x values
        sumX += x[i];

        // calculate sum of y values
        sumY += y[i];

        // calculate sum of x*y
        sumXY += x[i] * y[i];

        // calculate sum of x^2
        sumX2 += x[i] * x[i];
    }

    // ---------- Linear Regression Formula ----------

    // calculate slope
    m = ((n * sumXY) - (sumX * sumY)) /
        ((n * sumX2) - (sumX * sumX));

    // calculate intercept
    c = (sumY - (m * sumX)) / n;

    // stop timer
    endTime = omp_get_wtime();

    // ---------- Output ----------
    cout << "\nLinear Regression Equation : " << endl;

    // display equation
    cout << "y = " << m << "x + " << c << endl;

    // display execution time
    cout << "\nExecution Time : "
         << endTime - startTime << endl;

    return 0;
}