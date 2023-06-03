# TaylorSeriesC
Implementations of Taylor-Maclaurin series to Sine, Cosine and Tangent calculation in pure C without using any Math library.

# Taylor-Maclaurin Series for Trigonometric Functions

The Taylor-Maclaurin series is a mathematical tool that allows us to approximate complicated functions using a series of simpler polynomial terms. In the case of trigonometric functions, the Taylor-Maclaurin series provides a way to compute sine, cosine, and tangent functions with increasing accuracy.

## Sine and Cosine Functions

The Taylor-Maclaurin series expansions for the sine (sin(x)) and cosine (cos(x)) functions are as follows:

```
sin(x) = x - (x^3 / 3!) + (x^5 / 5!) - (x^7 / 7!) + ...
cos(x) = 1 - (x^2 / 2!) + (x^4 / 4!) - (x^6 / 6!) + ...
```

These series represent an infinite sum of terms, where each term is a power of x divided by the factorial of an odd or even number. By including more terms in the series, we can obtain a more accurate approximation of the original function. It is important to note that these series converge for all real values of x, meaning that as we include more terms, the approximation becomes increasingly precise.

## Tangent Function

The tangent (tan(x)) function can be computed using the sine and cosine functions:

```
tan(x) = sin(x) / cos(x)
```

By substituting the Taylor-Maclaurin series expansions for sine and cosine into the above equation, we can approximate the tangent function. However, it is important to exercise caution when calculating the tangent near values where the cosine is equal to zero, as this would result in a division by zero error.

## Practical Considerations

The Taylor-Maclaurin series offers a way to approximate the values of trigonometric functions by breaking them down into simpler polynomial terms. By truncating the series after a certain number of terms, we can achieve a reasonable level of accuracy based on our specific requirements.

It is worth noting that there are alternative series expansions, such as the Fourier series, that can also approximate these functions. However, the Taylor-Maclaurin series is often used due to its simplicity and ease of computation.

When working with the Taylor-Maclaurin series, it is important to be aware of the convergence properties of these series and exercise caution when dealing with specific values, especially near points where the functions exhibit special behavior.

## Conclusion

The Taylor-Maclaurin series is a valuable tool for approximating trigonometric functions, including sine, cosine, and tangent. By expanding these functions into polynomial terms and including more terms in the series, we can achieve increasingly accurate approximations. Understanding the convergence properties and being mindful of special cases is crucial for utilizing the Taylor-Maclaurin series effectively.

If you have any further questions or would like to explore this topic in more detail, please feel free to reach out.

# Taylor Series Algorithm Tester

This program in the folder <b>TaylorSeriesRunningTest</b> is designed to test the implementation of the Taylor Series algorithm for calculating trigonometric functions in C. The program runs through all possible angles in the range of -360 to 360 degrees and verifies if there are any errors in the computed values.

## How it Works

The program utilizes the Taylor Series expansions for sine, cosine, and tangent functions to approximate their values. The Taylor Series expansions are implemented in C code, and the program calculates the trigonometric functions using these implementations.

The algorithm tests the accuracy of the implemented Taylor Series by comparing the computed values against the known values of trigonometric functions. The known values are obtained from a trusted mathematical library or predefined lookup tables.

The program iterates through all angles in the range of -360 to 360 degrees, converting them to radians, and calculates the trigonometric functions using the Taylor Series implementations. It then compares the computed values with the known values for each angle.

## Error Verification

The primary objective of this program is to verify the accuracy of the Taylor Series algorithm by detecting any errors in the computed trigonometric function values. The following steps are typically followed for error verification:

1. Compute the trigonometric functions (sine, cosine, and tangent) using the Taylor Series algorithm for each angle in the range.
2. Obtain the known values of the trigonometric functions using a trusted mathematical library or predefined lookup tables.
3. Compare the computed values with the known values for each angle.
4. Check for discrepancies or errors between the computed and known values.
5. Record any inconsistencies or differences found during the verification process.

If the program does not identify any errors or discrepancies, it provides confidence in the correctness of the implemented Taylor Series algorithm. On the other hand, if errors are detected, it indicates that there might be issues in the implementation that need to be addressed.

## Usage and Results

To use this program, you need to compile and run it in a C environment or compiler. It will output the results of the error verification process, indicating whether any errors were found and providing details on the specific angles or values where discrepancies occurred.

Please note that the execution of this program may take some time due to the large number of angles to be tested. However, it is a crucial step to ensure the accuracy of the Taylor Series algorithm implementation for trigonometric calculations.

## Conclusion

The Taylor Series Algorithm Tester program provides a means to verify the correctness of the implemented Taylor Series algorithm for calculating trigonometric functions. By running the program for all possible angles in the range of -360 to 360 degrees, it performs an extensive error verification process, comparing computed values against known values.

By utilizing this program and ensuring the accuracy of the Taylor Series algorithm, you can have confidence in the correctness of your trigonometric function calculations in C.

If you encounter any issues or have further questions, please feel free to reach out.

## <b>ALL THE VERSIONS ARE IN /BIN ALREADY COMPILED WITH GCC AND CODEBLOCKS, UPX AND ZIP WAS USED TO MAKE IT SMALLER. FEEL FREEE TO COMPILE AGAIN!</b>


## References

- [Wikipedia: Taylor series](https://en.wikipedia.org/wiki/Taylor_series)
- [Trigonometric Functions](https://en.wikipedia.org/wiki/Trigonometric_functions)

