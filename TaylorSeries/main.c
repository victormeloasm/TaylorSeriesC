#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282


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
    for (int n = 1; n <=100 ; n += 2) {
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

    if (fabs(x - 180.0) < epsilon) {
        printf("Error: Tangent is undefined (angle is 180 degrees).\n");
        return 0;
    } else if (fabs(x - 90.0) < epsilon) {
        printf("Error: Tangent is undefined (angle is 90 degrees).\n");
        return 0;
    } else if (fabs(x - 360.0) < epsilon) {
        printf("Error: Tangent is undefined (angle is 360 degrees).\n");
        return 0;
    } else if (fabs(x - 270.0) < epsilon) {
        printf("Error: Tangent is undefined (angle is 270 degrees).\n");
        return 0;
    } else {
        double cosine = calculateCosine(x);
        if (fabs(1 - cosine) < epsilon) {
            printf("Error: Tangent is undefined (cosine is close to zero).\n");
            return 0;
        }
        return calculateSine(x) / cosine;
    }
}

int validateInput(double *value) {
    char input[100];
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return 0;
    }

    int i = 0;
    while (input[i] != '\0' && input[i] != '\n') {
        if (!isdigit(input[i]) && input[i] != '-' && input[i] != '.' && input[i] != '\n') {
            printf("Error: Invalid input. Please enter a numeric value.\n");
            return 0;
        }
        i++;
    }

    *value = atof(input);
    return 1;
}

void testTrigonometricCalculations() {
    for (int degrees = -360; degrees <= 360; degrees++) {
        double radians = degreesToRadians(degrees);

        double expectedSine = calculateSine(radians);
        double expectedCosine = calculateCosine(radians);
        double expectedTangent = calculateTangent(radians);

        double calculatedSine = sin(radians);
        double calculatedCosine = cos(radians);
        double calculatedTangent = tan(radians);

        double sineDiff = fabs(expectedSine - calculatedSine);
        double cosineDiff = fabs(expectedCosine - calculatedCosine);
        double tangentDiff = fabs(expectedTangent - calculatedTangent);

        if (sineDiff > 1e-8 || cosineDiff > 1e-8 || tangentDiff > 1e-8) {
            printf("Error: Calculation mismatch for angle %d degrees.\n", degrees);
            printf("Expected: Sine=%.8lf, Cosine=%.8lf, Tangent=%.8lf\n",
                   expectedSine, expectedCosine, expectedTangent);
            printf("Calculated: Sine=%.8lf, Cosine=%.8lf, Tangent=%.8lf\n",
                   calculatedSine, calculatedCosine, calculatedTangent);
            printf("\n");
        }
    }
}

int main() {
    char restartOption = 'r';

    while (restartOption != 'q') {
        system("clear");

        printf("Trigonometric Calculator\n");
        printf("------------------------\n");

        double degrees;
        printf("Enter an angle in degrees (-360 to 360): ");

        if (!validateInput(&degrees)) {
            printf("Press 'r' to restart or 'q' to quit...\n");
            restartOption = getchar();
            while (getchar() != '\n');
            continue;
        }

        if (degrees < -360 || degrees > 360) {
            printf("Error: Angle must be in the range of -360 to 360 degrees.\n");
            printf("Press 'r' to restart or 'q' to quit...\n");
            restartOption = getchar();
            while (getchar() != '\n');
            continue;
        }

        while (degrees <= -180) {
            degrees += 360;
        }
        while (degrees > 180) {
            degrees -= 360;
        }

        double radians = degreesToRadians(degrees);

        double sine, cosine, tangent;

        if (degrees == 180 || degrees == 360) {
            sine = 0.0;
            cosine = -1.0;
            tangent = 0.0;
        } else if (degrees == 90 || degrees == 270) {
            sine = (degrees == 90) ? 1.0 : -1.0;
            cosine = 0.0;
            printf("Error: Tangent is undefined (angle is %g degrees).\n", degrees);
            tangent = 0.0;
        } else {
            sine = calculateSine(radians);
            cosine = calculateCosine(radians);
            tangent = calculateTangent(radians);
        }

        printf("Sine: %.8lf\n", sine);
        printf("Cosine: %.8lf\n", cosine);
        if (tangent != 0) {
            printf("Tangent: %.8lf\n", tangent);
        }

        printf("Press 'r' to restart or 'q' to quit...\n");
        restartOption = getchar();
        while (getchar() != '\n');
    }

    return 0;
}
