#include <stdio.h>
#include <stdlib.h>

// Function to be integrated: 2x^2+9x+4
double f(double x) {
    return 2 * x * x + 9 * x + 4.0;
}

// Main function (handles integration logic)
int main() {
    // Interval definition
    double a = 3.0;
    double b = 12.0;

    // Number of steps
    int n = 1000;

    double step = (b-a)/n;
    double result = 0.0;

    // If a = b, then the result is 0, other wise perform trapezoidal integration 
    if (a != b) { 
        result = (f(a) + f(b)) * step / 2;
        for (int i = 1; i < n; i++) {
            result += step * f(a + step * i);
        }
    }

    // Output result
    printf("Interval: [%lf, %lf], n: %d, result=%lf\n", a, b, n, result);

    return 0;
}
