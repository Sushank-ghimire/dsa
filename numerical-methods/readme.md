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

## Comparison

| Feature              | Bisection Method               | Newton-Raphson Method          | Secant Method        |
| -------------------- | ------------------------------ | ------------------------------ | -------------------- |
| Convergence Rate     | Linear                         | Quadratic                      | Superlinear (~1.618) |
| Initial Requirements | Two points with opposite signs | One initial guess + derivative | Two initial guesses  |
| Reliability          | Always converges               | May diverge                    | May diverge          |
| Speed                | Slow                           | Fast                           | Moderate             |
| Derivative Needed    | No                             | Yes                            | No                   |

---
