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

## References

- [Wikipedia: Taylor series](https://en.wikipedia.org/wiki/Taylor_series)
- [Wolfram MathWorld: Taylor Series](https://mathworld.wolfram.com/TaylorSeries.html)
