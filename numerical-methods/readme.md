# Numerical Methods

This repository contains implementations of various numerical methods for finding roots of equations.

---

## 1. Bisection Method

### Description

The Bisection Method is a root-finding algorithm that repeatedly bisects an interval and selects the subinterval where the root must lie.

### How It Works

1. Start with two points `a` and `b` such that `f(a)` and `f(b)` have opposite signs (i.e., `f(a) × f(b) < 0`)
2. Calculate the midpoint: `mid = (a + b) / 2`
3. Check the sign of `f(mid)`:
   - If `f(a) × f(mid) < 0`, the root lies in `[a, mid]`, so set `b = mid`
   - Otherwise, the root lies in `[mid, b]`, so set `a = mid`
4. Repeat until `|f(mid)| < tolerance`

### Formula

$$mid = \frac{a + b}{2}$$

### Convergence

- **Order of Convergence**: Linear (1)
- **Error after n iterations**: $\frac{b - a}{2^n}$

### Advantages

- Simple and robust
- Always converges if initial interval is valid

### Disadvantages

- Slow convergence compared to other methods
- Requires initial interval with opposite signs

### Program Implementation

```c
// Used function for the calculations
float f(float x) {
    return (x * x - 4);   // Function: x^2 - 4
}

int main() {
    float a, b, mid; // Value of a and b taken from user
    int iteration = 0;
    float tolerance = 0.0001;

    // Check if the given interval is valid
    if (f(a) * f(b) > 0) {
        printf("Invalid interval! f(a) and f(b) must have opposite signs.\n");
        return 0;
    }

    // Bisection Method
    do {
        mid = (a + b) / 2.0;
        iteration++;
        if (f(a) * f(mid) < 0)
            b = mid;
        else
            a = mid;
    } while (fabs(f(mid)) > tolerance);
    return 0;
}
```

---

## 2. Newton-Raphson Method

### Description

The Newton-Raphson Method is an iterative root-finding algorithm that uses the tangent line at a point to approximate the root.

### How It Works

1. Start with an initial guess `x₀`
2. Calculate the next approximation using the formula
3. Repeat until `|h| < error` where `h = f(x) / f'(x)`

### Formula

$$x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$$

Or equivalently:
$$h = \frac{f(x_n)}{f'(x_n)}, \quad x_{n+1} = x_n - h$$

### Convergence

- **Order of Convergence**: Quadratic (2)
- Converges very fast near the root

### Advantages

- Fast convergence (quadratic)
- Requires only one initial guess

### Disadvantages

- Requires derivative of the function
- May diverge if initial guess is far from root
- Fails if `f'(x) = 0`

---

### Program Implementation

```c
// define the function for the root finding
double f(double x) {
	return x*x - 4; // function f(x) = x^2-4
}

// define the derative of the function
double fd(double x) {
	return 2*x; // derative of f i.e 2x
}

int main() {
  // maxIterations is taken from the user
	int iteration, maxIterations;
  // initial value x0 is also taken from user along with the error rate
	double x0, x1, error, h;

	for(iteration=1; iteration <= maxIterations; iteration++) {
		h = f(x0)/fd(x0);
		x1 = x0 - h;
		if(fabs(h) < error) {
			printf("\nAfter %d iterations, root = %.5lf\n", iteration, x1);
			return 0;
		}
		x0 = x1;
	}
	return 0;
}
```

---

## 3. Secant Method

### Description

The Secant Method is a root-finding algorithm that uses a succession of roots of secant lines to approximate the root. It is similar to Newton-Raphson but doesn't require the derivative of the function.

### How It Works

1. Start with two initial guesses `x₀` and `x₁`
2. Calculate the next approximation using the secant line formula
3. Update: `x₀ = x₁` and `x₁ = x`
4. Repeat until `|x₁ - x₀| < error` or maximum iterations reached

### Formula

$$x_{n+1} = \frac{x_{n-1} \cdot f(x_n) - x_n \cdot f(x_{n-1})}{f(x_n) - f(x_{n-1})}$$

Or equivalently:
$$x_{n+1} = x_n - f(x_n) \cdot \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})}$$

### Convergence

- **Order of Convergence**: Superlinear (~1.618, the golden ratio)
- Faster than Bisection, slightly slower than Newton-Raphson

### Advantages

- Does not require derivative calculation
- Faster than Bisection Method
- Only needs function evaluations

### Disadvantages

- Requires two initial guesses
- May diverge if initial guesses are poor
- Fails if `f(x₁) = f(x₀)` (division by zero)

---

### Program Implementation

```c
// Function
double f(double x) {
    return x * x - 2; // f(x) = x^2 - 2
}

int main() {
    double x0, x1, x, error;
    int iteration = 0, maxIterations;
    // x0, x1, maxIterations, and error are taken from user

    do {
        if (f(x1) == f(x0)) {
            printf("Error: Division by zero.\n");
            return 0;
        }

        x = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
        iteration++;

        if (iteration >= maxIterations)
            break;

        x0 = x1;
        x1 = x;

    } while (fabs(x1 - x0) > error);
    return 0;
}
```

---

## 4. Fixed Point Iteration Method

### Description

The Fixed Point Iteration Method is a root-finding algorithm that rewrites the equation `f(x) = 0` in the form `x = g(x)` and iteratively computes `x_{n+1} = g(x_n)` until convergence.

### How It Works

1. Rewrite `f(x) = 0` as `x = g(x)`
2. Start with an initial guess `x₀`
3. Calculate the next approximation: `x₁ = g(x₀)`
4. Repeat until `|x_{n+1} - x_n| < tolerance` or maximum iterations reached

### Formula

$$x_{n+1} = g(x_n)$$

### Convergence Condition

- The method converges if `|g'(x)| < 1` in the neighborhood of the root
- **Order of Convergence**: Linear (1)

### Advantages

- Simple to implement
- Does not require derivative of original function
- Can be applied to a wide range of problems

### Disadvantages

- May diverge if `|g'(x)| ≥ 1`
- Choice of `g(x)` affects convergence
- Slower than Newton-Raphson

---

### Program Implementation

```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TOL 1.e-6
#define MAX_ITERATION 50

// function g(x)
double g(double x)
{
  return cbrt(1 - x); // cube root of (1-x)
}

int main()
{
  double x0, x1;
  int iteration = 0;
  printf("Enter initial guess : ");
  scanf("%lf", &x0);

  do
  {
    x1 = g(x0);
    printf("Iteration %d: x = %lf\n", iteration + 1, x1);

    if (fabs(x1 - x0) < TOL)
    {
      printf("Root found : %lf\n", x1);
      return 0;
    }
    x0 = x1;
    iteration++;
  } while (iteration < MAX_ITERATION);
  printf("\nMethod did not converge.\n");
  return 0;
}
```

**Key Points**:

- Requires rewriting `f(x) = 0` as `x = g(x)`
- Convergence depends on `|g'(x)| < 1`
- Time: O(n) iterations, each O(1)
- Simple but may not always converge

---

## 5. Synthetic Division

### Description

Synthetic Division is a simplified method for dividing a polynomial by a linear divisor of the form `(x - c)`. It is used to find quotient and remainder efficiently without full polynomial long division.

### How It Works

1. Write the coefficients of the polynomial in descending order of powers
2. Bring down the leading coefficient
3. Multiply by `c` and add to the next coefficient
4. Repeat until all coefficients are processed
5. The last value is the remainder; the rest form the quotient

### Formula

For polynomial `P(x) = aₙxⁿ + aₙ₋₁xⁿ⁻¹ + ... + a₁x + a₀` divided by `(x - c)`:

$$b_n = a_n$$
$$b_i = a_i + c \cdot b_{i+1} \quad \text{for } i = n-1, n-2, ..., 0$$

- Quotient: `bₙxⁿ⁻¹ + bₙ₋₁xⁿ⁻² + ... + b₁`
- Remainder: `b₀`

### Applications

- Polynomial division
- Evaluating polynomial at a point (Remainder Theorem: `P(c) = remainder`)
- Finding roots of polynomials
- Deflating polynomials after finding a root

### Advantages

- Much faster than long division
- Easy to implement
- Useful for repeated evaluations

### Disadvantages

- Only works for linear divisors `(x - c)`
- Limited to polynomial functions

---

### Program Implementation

```c
#include <stdio.h>
#define MAX_SIZE 4

void displayPolynomial(int degree, float coeff[MAX_SIZE])
{
  int i;
  for (i = degree; i >= 0; i--)
  {
    if (coeff[i] != 0)
    {
      if (i != degree && coeff[i] > 0)
        printf(" + ");
      else if (coeff[i] < 0)
        printf(" - ");
      printf("%.0f", coeff[i] < 0 ? -coeff[i] : coeff[i]);
      if (i > 0)
        printf("x");
      if (i > 1)
        printf("^%d", i);
    }
  }
  printf("\n");
}

int main()
{
  int degree, i, choice;
  float coefficients[MAX_SIZE]; // degree <= 3
  float divisor;                // divisor x-c

  // Taking the degree from the user
  do
  {
    printf("Enter the degree of the polynomial (max 3): ");
    scanf("%d", &degree);
    if (degree < 0 || degree > 3)
      printf("Please enter a valid degree! Enter a degree between 0 and 3.\n");
  } while (degree < 0 || degree > 3);

  // Taking coefficients from user
  for (i = degree; i >= 0; i--)
  {
    printf("Enter the coefficient of x^%d: ", i);
    scanf("%f", &coefficients[i]);
  }

  // Displaying the polynomial
  printf("Your polynomial is : ");
  displayPolynomial(degree, coefficients);

  // Input divisor from the user
  printf("Enter the value of c for divisor (x-c): ");
  scanf("%f", &divisor);

  // Synthetic Division
  float quotient[degree - 1];
  float temp = coefficients[degree];
  quotient[degree - 1] = temp;

  for (i = degree - 1; i >= 0; i--)
  {
    if (i != 0)
    {
      temp = temp * divisor + coefficients[i];
      quotient[i - 1] = temp;
    }
    else
      temp = temp * divisor + coefficients[i]; // remainder
  }

  // Quotient
  printf("Quotient : ");
  displayPolynomial(degree - 1, quotient);

  // Remainder
  printf("Remainder : %.0f\n", temp);
  return 0;
}
```

**Key Points**:

- Input: Polynomial coefficients and divisor value `c`
- Output: Quotient polynomial and remainder
- Time: O(n) where n is the degree
- Uses Remainder Theorem: `P(c) = remainder`

---

## Comparison

| Feature              | Bisection        | Newton-Raphson  | Secant       | Fixed Point    | Synthetic Division  |
| -------------------- | ---------------- | --------------- | ------------ | -------------- | ------------------- |
| Convergence Rate     | Linear           | Quadratic       | Superlinear  | Linear         | N/A (exact)         |
| Initial Requirements | Interval [a,b]   | x₀ + derivative | Two guesses  | x₀ + g(x) form | Coefficients + c    |
| Reliability          | Always converges | May diverge     | May diverge  | May diverge    | Always works        |
| Speed                | Slow             | Fast            | Moderate     | Slow-Moderate  | Fast                |
| Derivative Needed    | No               | Yes             | No           | No             | No                  |
| Use Case             | Root finding     | Root finding    | Root finding | Root finding   | Polynomial division |

---

## Complexity Cheatsheet

| Method             | Time Complexity    | Space Complexity | Convergence Order |
| ------------------ | ------------------ | ---------------- | ----------------- |
| Bisection          | O(log((b-a)/ε))    | O(1)             | Linear (1)        |
| Newton-Raphson     | O(log(log(1/ε)))   | O(1)             | Quadratic (2)     |
| Secant             | O(log(1/ε)/log(φ)) | O(1)             | ~1.618            |
| Fixed Point        | O(n) iterations    | O(1)             | Linear (1)        |
| Synthetic Division | O(n)               | O(n)             | Exact (1 pass)    |

---
