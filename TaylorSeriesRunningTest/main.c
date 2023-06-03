#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double factorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double calculateSine(double x) {
    double sine = 0.0;
    int sign = 1;
    for (int n = 1; n <= 100; n += 2) {
        double term = sign * power(x, n) / factorial(n);
        sine += term;
        sign *= -1;
    }
    return sine;
}

double calculateCosine(double x) {
    double cosine = 1.0;
    int sign = -1;
    for (int n = 2; n <= 100; n += 2) {
        double term = sign * power(x, n) / factorial(n);
        cosine += term;
        sign *= -1;
    }
    return cosine;
}

double calculateTangent(double x) {
    double epsilon = 1e-8;

    if (x == 180.0 || x == 360.0) {
        printf("Error: Tangent is undefined (angle is %.1lf degrees).\n", x);
        return 0;
    }

    double cosine = calculateCosine(x);
    if (fabs(1 - cosine) < epsilon) {
        printf("Error: Tangent is undefined (cosine is close to zero).\n");
        return 0;
    }
    return calculateSine(x) / cosine;
}

void testTrigonometricCalculations() {
    for (int degrees = -360; degrees <= 360; degrees++) {
        double radians = degreesToRadians(degrees);

        double expectedSine = calculateSine(radians);
        double expectedCosine = calculateCosine(radians);
        double expectedTangent = calculateTangent(radians);

        printf("Angle: %d degrees\n", degrees);
        printf("Expected: Sine=%.8lf, Cosine=%.8lf, Tangent=%.8lf\n",
               expectedSine, expectedCosine, expectedTangent);

        double calculatedSine = calculateSine(radians);
        double calculatedCosine = calculateCosine(radians);
        double calculatedTangent = calculateTangent(radians);

        printf("Calculated: Sine=%.8lf, Cosine=%.8lf, Tangent=%.8lf\n",
               calculatedSine, calculatedCosine, calculatedTangent);

        printf("\n");
    }
}

int main() {
    testTrigonometricCalculations();
    return 0;
}
