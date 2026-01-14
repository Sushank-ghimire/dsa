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

## 6. Lagrange's Interpolation

### Description

Lagrange's Interpolation is a polynomial interpolation method that finds a polynomial passing through a given set of data points. It constructs the interpolating polynomial using Lagrange basis polynomials.

### How It Works

1. Given n data points (x₀, y₀), (x₁, y₁), ..., (xₙ₋₁, yₙ₋₁)
2. Construct Lagrange basis polynomials Lᵢ(x) for each point
3. The interpolating polynomial is the sum of yᵢ × Lᵢ(x)

### Formula

$$P(x) = \sum_{i=0}^{n-1} y_i \cdot L_i(x)$$

Where the Lagrange basis polynomial is:

$$L_i(x) = \prod_{j=0, j \neq i}^{n-1} \frac{x - x_j}{x_i - x_j}$$

### Advantages

- Works for unequally spaced data points
- No need to compute difference tables
- Straightforward formula

### Disadvantages

- Computationally expensive for large datasets
- Adding new points requires complete recalculation
- Can suffer from Runge's phenomenon for high-degree polynomials

---

### Program Implementation

```c
#include <stdio.h>
#define MAX 50

void LagrangeInterpolation() {
  float x[MAX], y[MAX], point, numerator, denominator, interpolatedY = 0;
  int i, j, terms;
  printf("Enter the number of terms of the table : ");
  scanf("%d", &terms);
  printf("Enter the respective values of x & y: \n");
  for(i=0; i<terms; i++) {
    printf("Enter the value for x[%d]: ", i+1);
    scanf("%f", &x[i]);
    printf("Enter the value for y[%d]: ", i+1);
    scanf("%f", &y[i]);
  }

  printf("Enter the value of the x to find value of y: ");
  scanf("%f", &point);
  for(i=0; i<terms; i++) {
    numerator = 1;
    denominator = 1;
    for(j=0; j<terms; j++) {
      if(i != j) {
        numerator = numerator * (point - x[j]);
        denominator = denominator * (x[i] - x[j]);
      }
    }
    interpolatedY = interpolatedY + ((numerator / denominator) * y[i]);
  }
  printf("\nThe respective value of the variable is : %.2f", interpolatedY);
}
```

**Key Points**:

- Input: Set of data points (x, y)
- Output: Interpolated y value for given x
- Time: O(n²) for each interpolation
- Space: O(n)

---

## 7. Newton's Interpolation (Forward & Backward Difference)

### Description

Newton's Interpolation methods use finite differences to construct interpolating polynomials. Forward difference is used for interpolation near the beginning of the table, while backward difference is used near the end.

### Newton's Forward Difference Formula

$$P(x) = y_0 + p \cdot \Delta y_0 + \frac{p(p-1)}{2!} \cdot \Delta^2 y_0 + \frac{p(p-1)(p-2)}{3!} \cdot \Delta^3 y_0 + ...$$

Where:
$$p = \frac{x - x_0}{h}$$

### Newton's Backward Difference Formula

$$P(x) = y_n + p \cdot \nabla y_n + \frac{p(p+1)}{2!} \cdot \nabla^2 y_n + \frac{p(p+1)(p+2)}{3!} \cdot \nabla^3 y_n + ...$$

Where:
$$p = \frac{x - x_n}{h}$$

### How It Works

1. Construct a difference table (forward or backward)
2. Calculate step size h = x₁ - x₀
3. Compute p based on the interpolation point
4. Apply the respective formula

### Advantages

- Efficient for equally spaced data
- Easy to add new data points
- Difference table can be reused

### Disadvantages

- Requires equally spaced data points
- Forward method less accurate at end of table
- Backward method less accurate at beginning of table

---

### Program Implementation

```c
#include <stdio.h>
#define MAX 40

void NewtonForwardDiff() {
  float x[MAX], diffTable[MAX][MAX], point, interpolatedY = 0, productTerm, p, stepSize, factorial;
  int terms, i, j;

  printf("Enter the number of terms of the table : ");
  scanf("%d", &terms);
  printf("Enter the corresponding values of x & y: \n");
  for(i=0; i<terms; i++) {
    printf("Enter the value for x[%d]: ", i+1);
    scanf("%f", &x[i]);
    printf("Enter the value for y[%d]: ", i+1);
    scanf("%f", &diffTable[i][0]);
  }

  // Forward difference table calculation
  for(j=1; j<terms; j++) {
    for(i=0; i<terms - j; i++) {
      diffTable[i][j] = diffTable[i+1][j-1] - diffTable[i][j-1];
    }
  }

  stepSize = x[1] - x[0];

  printf("Enter the value of the x to find value of y: ");
  scanf("%f", &point);

  p = (point - x[0]) / stepSize;
  interpolatedY = diffTable[0][0];
  productTerm = 1;
  factorial = 1;

  for(i=1; i<terms; i++) {
    productTerm *= (p - (i - 1));
    factorial *= i;
    interpolatedY += (productTerm / factorial) * diffTable[0][i];
  }

  printf("\nThe interpolated value at x = %.4f is y = %.4f", point, interpolatedY);
  printf("\nDo you want to continue (0 to exit) ? ");
  scanf("%d", &flag);
}

void NewtonBackwardDiff() {
  float x[MAX], diffTable[MAX][MAX], point, interpolatedY = 0, productTerm, p, stepSize, factorial;
  int terms, i, j;

  // Similar input as forward

  // Backward difference table calculation
  for(j=1; j<terms; j++) {
    for(i=terms - 1; i>=j; i--) {
      diffTable[i][j] = diffTable[i][j-1] - diffTable[i-1][j-1];
    }
  }

  stepSize = x[1] - x[0];

  printf("Enter the value of the x to find value of y: ");
  scanf("%f", &point);

  p = (point - x[terms-1]) / stepSize;
  interpolatedY = diffTable[terms - 1][0];
  productTerm = 1;
  factorial = 1;

  for(i=1; i<terms; i++) {
    productTerm *= (p + (i - 1));
    factorial *= i;
    interpolatedY += (productTerm / factorial) * diffTable[terms - 1][i];
  }

  printf("\nThe interpolated value at x = %.4f is y = %.4f", point, interpolatedY);
}
```

**Key Points**:

- Use Forward difference for interpolation near the beginning
- Use Backward difference for interpolation near the end
- Time: O(n²) for table construction, O(n) for each interpolation
- Space: O(n²) for difference table

---

## 8. Horner's Method

### Description

Horner's Method is an efficient algorithm for evaluating polynomials. It reduces the number of multiplications by rewriting the polynomial in nested form.

### How It Works

1. Start with the leading coefficient
2. Multiply by x and add the next coefficient
3. Repeat until all coefficients are processed

### Formula

For polynomial `P(x) = aₙxⁿ + aₙ₋₁xⁿ⁻¹ + ... + a₁x + a₀`:

Rewrite as:
$$P(x) = (...((a_n \cdot x + a_{n-1}) \cdot x + a_{n-2}) \cdot x + ...) \cdot x + a_0$$

### Algorithm

```
result = aₙ
for i = n-1 down to 0:
    result = result × x + aᵢ
return result
```

### Advantages

- Minimizes number of operations (n multiplications + n additions)
- Numerically stable
- Simple to implement

### Disadvantages

- Only evaluates polynomial at one point at a time
- Not suitable for symbolic computation

---

### Program Implementation

```c
#include <stdio.h>
#define MAX_SIZE 4

void displayPolynomial(int degree, float coeff[MAX_SIZE]) {
  int i;
  for (i = degree; i >= 0; i--) {
    if (coeff[i] != 0) {
      if (i != degree && coeff[i] > 0)
        printf(" + ");
      else if (coeff[i] < 0)
        printf(" - ");
      printf("%.0f", coeff[i] < 0 ? -coeff[i] : coeff[i]);
      if (i > 0) printf("x");
      if (i > 1) printf("^%d", i);
    }
  }
  printf("\n");
}

void HornersMethod() {
  int degree, i;
  float coefficient[MAX_SIZE], result, x;

  printf("\nEnter degree of polynomial (max %d): ", MAX_SIZE - 1);
  scanf("%d", &degree);

  for(i=degree; i>=0; i--) {
    printf("Enter coefficient for x^%d: ", i);
    scanf("%f", &coefficient[i]);
  }

  printf("\nPolynomial: ");
  displayPolynomial(degree, coefficient);

  printf("Enter the value of x: ");
  scanf("%f", &x);

  // Horner's Method evaluation
  result = coefficient[degree];
  for (i = degree - 1; i >= 0; i--) {
    result = result * x + coefficient[i];
  }

  printf("\nValue of polynomial at x = %.2f is %.2f\n", x, result);
}
```

**Key Points**:

- Input: Polynomial coefficients and value of x
- Output: P(x) evaluated at given x
- Time: O(n)
- Space: O(1) for evaluation

---

## 9. Finding Maxima and Minima from Data Points

### Description

This method finds the maximum and minimum values of y from a given set of discrete data points (x, y). It performs a simple linear search through the data.

### How It Works

1. Initialize max and min with the first y value
2. Traverse through all data points
3. Update max/min and corresponding x values when found

### Algorithm

```
maxY = minY = y[0]
maxX = minX = x[0]
for i = 1 to n-1:
    if y[i] > maxY:
        maxY = y[i], maxX = x[i]
    if y[i] < minY:
        minY = y[i], minX = x[i]
```

### Advantages

- Simple and straightforward
- Works with any data distribution
- O(n) time complexity

### Disadvantages

- Only finds discrete max/min from given points
- Does not find true extrema between data points
- No interpolation for more accurate results

---

### Program Implementation

```c
#include <stdio.h>
#define MAX 30

void findMinMax(float x[], float y[], int n) {
  int i;
  float maxY = y[0], minY = y[0];
  float maxX = x[0], minX = x[0];

  for (i = 1; i < n; i++) {
    if (y[i] > maxY) {
      maxY = y[i];
      maxX = x[i];
    }
    if (y[i] < minY) {
      minY = y[i];
      minX = x[i];
    }
  }

  printf("\nMaximum Value: y = %.4f at x = %.4f\n", maxY, maxX);
  printf("Minimum Value: y = %.4f at x = %.4f\n", minY, minX);
}

int main() {
  float x[MAX], y[MAX];
  int terms, i;

  printf("Enter the number of terms of the table : ");
  scanf("%d", &terms);
  printf("Enter the corresponding values of x & y: \n");

  for (i = 0; i < terms; i++) {
    printf("Enter the value for x[%d]: ", i+1);
    scanf("%f", &x[i]);
    printf("Enter the value for y[%d]: ", i+1);
    scanf("%f", &y[i]);
  }

  findMinMax(x, y, terms);
  return 0;
}
```

**Key Points**:

- Input: Set of data points (x, y)
- Output: Maximum and minimum y values with corresponding x
- Time: O(n)
- Space: O(1)

---

## Comparison Table

| Feature              | Bisection       | Newton-Raphson   | Secant       | Fixed Point  | Synthetic Div. | Lagrange      | Newton Interp. | Horner's   |
| -------------------- | --------------- | ---------------- | ------------ | ------------ | -------------- | ------------- | -------------- | ---------- |
| Type                 | Root Finding    | Root Finding     | Root Finding | Root Finding | Division       | Interpolation | Interpolation  | Evaluation |
| Convergence Rate     | Linear          | Quadratic        | Superlinear  | Linear       | N/A            | N/A           | N/A            | N/A        |
| Time Complexity      | O(log((b-a)/ε)) | O(log(log(1/ε))) | O(n)         | O(n)         | O(n)           | O(n²)         | O(n²)          | O(n)       |
| Space Complexity     | O(1)            | O(1)             | O(1)         | O(1)         | O(n)           | O(n)          | O(n²)          | O(1)       |
| Equal Spacing Needed | No              | No               | No           | No           | No             | No            | Yes            | No         |

---

## Complexity Cheatsheet

| Method                  | Time Complexity    | Space Complexity | Notes                         |
| ----------------------- | ------------------ | ---------------- | ----------------------------- |
| Bisection               | O(log((b-a)/ε))    | O(1)             | Linear convergence            |
| Newton-Raphson          | O(log(log(1/ε)))   | O(1)             | Quadratic convergence         |
| Secant                  | O(log(1/ε)/log(φ)) | O(1)             | Superlinear (~1.618)          |
| Fixed Point             | O(n) iterations    | O(1)             | Linear convergence            |
| Synthetic Division      | O(n)               | O(n)             | Single pass, exact            |
| Lagrange Interpolation  | O(n²)              | O(n)             | Works for unequal spacing     |
| Newton Forward/Backward | O(n²) + O(n)       | O(n²)            | Requires equal spacing        |
| Horner's Method         | O(n)               | O(1)             | Optimal polynomial evaluation |
| Min/Max from Data       | O(n)               | O(1)             | Simple linear search          |

---
