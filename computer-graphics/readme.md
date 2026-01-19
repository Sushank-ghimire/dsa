# Computer Graphics Algorithms

> A collection of fundamental computer graphics algorithms implemented in C using the graphics.h library.

---

## Table of Contents

1. [Line Drawing Algorithms](#line-drawing-algorithms)
   - [DDA Algorithm](#1-dda-digital-differential-analyzer-algorithm)
   - [Bresenham's Algorithm](#2-bresenhams-line-algorithm)
2. [Circle & Ellipse Drawing](#circle--ellipse-drawing)
   - [Midpoint Circle Algorithm](#3-midpoint-circle-algorithm)
   - [Midpoint Ellipse Algorithm](#4-midpoint-ellipse-algorithm)
3. [Region Filling Algorithms](#region-filling-algorithms)
   - [Flood Fill Algorithm](#5-flood-fill-algorithm)
   - [Boundary Fill Algorithm](#6-boundary-fill-algorithm)
4. [2D Transformations](#2d-transformations)
   - [Translation](#7-translation)
   - [Scaling](#8-scaling)
   - [Rotation](#9-rotation)
   - [Reflection](#10-reflection)
   - [Shearing](#11-shearing)
5. [Comparison Tables](#comparison-tables)
6. [Setup & Compilation](#setup--compilation)

---

## Line Drawing Algorithms

### 1. DDA (Digital Differential Analyzer) Algorithm

#### Description

DDA is an incremental scan conversion algorithm for drawing lines. It uses floating-point arithmetic to calculate intermediate pixel positions between two endpoints.

#### How It Works

1. Calculate `dx = x2 - x1` and `dy = y2 - y1`
2. Determine steps as `max(|dx|, |dy|)`
3. Calculate increments: `xInc = dx/steps`, `yInc = dy/steps`
4. Plot pixels by incrementing x and y, rounding to nearest integer

#### Algorithm

```
DDA(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    steps = max(|dx|, |dy|)

    xInc = dx / steps
    yInc = dy / steps

    x = x1, y = y1
    for i = 0 to steps:
        plot(round(x), round(y))
        x += xInc
        y += yInc
```

#### Advantages

- Simple to implement and understand
- Faster than direct line equation method
- No multiplication required in the loop

#### Disadvantages

- Uses floating-point arithmetic (slower than integer-only)
- Rounding errors can accumulate
- Round-off can cause pixel drift

#### Complexity

| Metric    | Value                              |
| --------- | ---------------------------------- |
| **Time**  | O(n) where n = max(\|dx\|, \|dy\|) |
| **Space** | O(1)                               |

---

### 2. Bresenham's Line Algorithm

#### Description

Bresenham's algorithm is an efficient line-drawing algorithm that uses only integer arithmetic. It determines which pixel to plot by evaluating a decision parameter.

#### How It Works

1. Calculate `dx`, `dy`, and direction signs
2. Initialize error term: `err = dx - dy`
3. For each step, plot pixel and update coordinates based on error
4. Adjust error term after each move

#### Algorithm

```
Bresenham(x1, y1, x2, y2):
    dx = |x2 - x1|
    dy = |y2 - y1|
    sx = sign(x2 - x1)
    sy = sign(y2 - y1)
    err = dx - dy

    while true:
        plot(x1, y1)
        if x1 == x2 and y1 == y2: break

        e2 = 2 * err
        if e2 > -dy:
            err -= dy
            x1 += sx
        if e2 < dx:
            err += dx
            y1 += sy
```

#### Advantages

- Uses only integer arithmetic (fast)
- No floating-point operations
- Produces accurate lines
- Works for all octants

#### Disadvantages

- Slightly more complex logic than DDA
- Decision parameter calculation required

#### Complexity

| Metric    | Value                              |
| --------- | ---------------------------------- |
| **Time**  | O(n) where n = max(\|dx\|, \|dy\|) |
| **Space** | O(1)                               |

---

## Circle & Ellipse Drawing

### 3. Midpoint Circle Algorithm

#### Description

The Midpoint Circle Algorithm uses the circle's 8-way symmetry to draw circles efficiently. It evaluates a decision parameter to choose between two candidate pixels.

#### How It Works

1. Start at point (0, r) where r is radius
2. Use decision parameter `d = 1 - r`
3. Plot 8 symmetric points simultaneously
4. Move east (x++) or south-east (x++, y--) based on d
5. Continue until x > y

#### Algorithm

```
MidpointCircle(xc, yc, r):
    x = 0, y = r
    d = 1 - r

    while x <= y:
        plot8SymmetricPoints(xc, yc, x, y)

        if d < 0:
            d += 2*x + 3
        else:
            d += 2*(x - y) + 5
            y--
        x++
```

#### 8-Way Symmetry Points

```
(xc + x, yc + y)    (xc - x, yc + y)
(xc + x, yc - y)    (xc - x, yc - y)
(xc + y, yc + x)    (xc - y, yc + x)
(xc + y, yc - x)    (xc - y, yc - x)
```

#### Advantages

- Uses only integer arithmetic
- Exploits 8-way symmetry (computes only 1/8 of circle)
- Very efficient

#### Disadvantages

- Only works for circles (not ellipses)

#### Complexity

| Metric    | Value                  |
| --------- | ---------------------- |
| **Time**  | O(r) where r is radius |
| **Space** | O(1)                   |

---

### 4. Midpoint Ellipse Algorithm

#### Description

The Midpoint Ellipse Algorithm extends the midpoint concept to ellipses. It divides the ellipse into two regions based on the slope and uses different decision parameters for each.

#### How It Works

1. **Region 1**: Slope magnitude < 1 (move primarily in x direction)
2. **Region 2**: Slope magnitude > 1 (move primarily in y direction)
3. Use 4-way symmetry to plot points
4. Switch regions when `2*ry²*x >= 2*rx²*y`

#### Algorithm

```
MidpointEllipse(xc, yc, rx, ry):
    x = 0, y = ry
    rxSq = rx², rySq = ry²

    // Region 1
    d1 = rySq - rxSq*ry + rxSq/4
    while 2*rySq*x < 2*rxSq*y:
        plot4SymmetricPoints(xc, yc, x, y)
        if d1 < 0:
            d1 += 2*rySq*x + rySq
        else:
            d1 += 2*rySq*x - 2*rxSq*y + rySq
            y--
        x++

    // Region 2
    d2 = rySq*(x+0.5)² + rxSq*(y-1)² - rxSq*rySq
    while y >= 0:
        plot4SymmetricPoints(xc, yc, x, y)
        if d2 > 0:
            d2 += rxSq - 2*rxSq*y
        else:
            d2 += 2*rySq*x - 2*rxSq*y + rxSq
            x++
        y--
```

#### 4-Way Symmetry Points

```
(xc + x, yc + y)    (xc - x, yc + y)
(xc + x, yc - y)    (xc - x, yc - y)
```

#### Advantages

- Efficient for drawing ellipses
- Uses symmetry to reduce computation
- Handles both circular and elliptical shapes

#### Disadvantages

- More complex than circle algorithm
- Requires handling two separate regions

#### Complexity

| Metric    | Value      |
| --------- | ---------- |
| **Time**  | O(rx + ry) |
| **Space** | O(1)       |

---

## Region Filling Algorithms

### 5. Flood Fill Algorithm

#### Description

Flood Fill determines the area connected to a given node in a multi-dimensional array. It replaces all pixels of a specific color (old color) with a new color, starting from a seed point.

#### How It Works

1. Start at a seed point (x, y)
2. Check if the current pixel has the old color
3. If yes, replace it with the new color
4. Recursively apply the same process to all 4 neighboring pixels
5. Stop when boundary or already-filled pixels are encountered

#### Algorithm (4-Connected)

```
floodFill(x, y, oldColor, newColor):
    if x < 0 or x >= width or y < 0 or y >= height:
        return
    if getPixel(x, y) != oldColor:
        return

    setPixel(x, y, newColor)

    floodFill(x + 1, y, oldColor, newColor)  // Right
    floodFill(x - 1, y, oldColor, newColor)  // Left
    floodFill(x, y + 1, oldColor, newColor)  // Down
    floodFill(x, y - 1, oldColor, newColor)  // Up
```

#### Connectivity Types

| Type            | Neighbors | Directions            |
| --------------- | --------- | --------------------- |
| **4-Connected** | 4         | Up, Down, Left, Right |
| **8-Connected** | 8         | + 4 Diagonals         |

#### Advantages

- Simple to understand and implement
- Works with any shape boundary
- Fills entire connected region uniformly

#### Disadvantages

- Recursive implementation can cause stack overflow for large regions
- Requires knowing the original color of the region
- Slower than scanline-based methods

#### Complexity

| Metric    | Value                         |
| --------- | ----------------------------- |
| **Time**  | O(n) where n = pixels to fill |
| **Space** | O(n) due to recursion stack   |

---

### 6. Boundary Fill Algorithm

#### Description

Boundary Fill fills an area defined by a boundary color. Starting from a seed point, it replaces all pixels that are neither the boundary color nor the fill color with the specified fill color.

#### How It Works

1. Start at a seed point (x, y)
2. Check if the current pixel is the boundary color or already filled
3. If neither, fill it with the new color
4. Recursively apply the same process to all 4 neighboring pixels
5. Stop when boundary pixels or already-filled pixels are encountered

#### Algorithm (4-Connected)

```
boundaryFill(x, y, boundaryColor, fillColor):
    if x < 0 or x >= width or y < 0 or y >= height:
        return

    currentColor = getPixel(x, y)

    if currentColor == boundaryColor or currentColor == fillColor:
        return

    setPixel(x, y, fillColor)

    boundaryFill(x + 1, y, boundaryColor, fillColor)  // Right
    boundaryFill(x - 1, y, boundaryColor, fillColor)  // Left
    boundaryFill(x, y + 1, boundaryColor, fillColor)  // Down
    boundaryFill(x, y - 1, boundaryColor, fillColor)  // Up
```

#### Advantages

- Works with boundaries of any shape
- Can fill regions with multiple interior colors
- Intuitive boundary-based approach

#### Disadvantages

- Recursive implementation can cause stack overflow
- Boundary must be completely closed (no gaps)
- Slower than scanline-based methods

#### Complexity

| Metric    | Value                         |
| --------- | ----------------------------- |
| **Time**  | O(n) where n = pixels to fill |
| **Space** | O(n) due to recursion stack   |

---

## 2D Transformations

### 7. Translation

#### Description

Translation moves an object from one position to another by adding translation distances (tx, ty) to the original coordinates.

#### How It Works

1. Take original coordinates (x, y)
2. Add translation factors: `x' = x + tx`, `y' = y + ty`
3. Apply to all vertices of the object

#### Transformation Matrix

```
| x' |   | 1  0  tx |   | x |
| y' | = | 0  1  ty | × | y |
| 1  |   | 0  0  1  |   | 1 |
```

#### Algorithm

```
Translation(x, y, tx, ty):
    x' = x + tx
    y' = y + ty
    return (x', y')
```

#### Advantages

- Simplest transformation
- Preserves shape and size
- No distortion

#### Disadvantages

- Cannot be combined with other transformations using 2×2 matrix (requires homogeneous coordinates)

#### Complexity

| Metric    | Value                       |
| --------- | --------------------------- |
| **Time**  | O(n) where n = num vertices |
| **Space** | O(1)                        |

---

### 8. Scaling

#### Description

Scaling changes the size of an object by multiplying coordinates by scaling factors (sx, sy). Scaling can be uniform (sx = sy) or non-uniform.

#### How It Works

1. Take original coordinates (x, y)
2. Multiply by scaling factors: `x' = x × sx`, `y' = y × sy`
3. Apply to all vertices

#### Transformation Matrix

```
| x' |   | sx  0  |   | x |
| y' | = | 0   sy | × | y |
```

#### Algorithm

```
Scaling(x, y, sx, sy):
    x' = x * sx
    y' = y * sy
    return (x', y')
```

#### Types of Scaling

| Type            | Condition | Effect                 |
| --------------- | --------- | ---------------------- |
| **Uniform**     | sx = sy   | Proportional scaling   |
| **Non-uniform** | sx ≠ sy   | Stretching/compression |
| **Enlargement** | s > 1     | Object grows           |
| **Reduction**   | s < 1     | Object shrinks         |

#### Advantages

- Simple multiplication operation
- Can enlarge or reduce objects

#### Disadvantages

- Scales about origin (may need translation for scaling about arbitrary point)
- Non-uniform scaling can distort shape

#### Complexity

| Metric    | Value                       |
| --------- | --------------------------- |
| **Time**  | O(n) where n = num vertices |
| **Space** | O(1)                        |

---

### 9. Rotation

#### Description

Rotation rotates an object about a pivot point (usually origin) by a specified angle θ. Positive angles rotate counter-clockwise.

#### How It Works

1. Convert angle from degrees to radians: `rad = θ × π / 180`
2. Apply rotation formulas:
   - `x' = x × cos(θ) - y × sin(θ)`
   - `y' = x × sin(θ) + y × cos(θ)`

#### Transformation Matrix

```
| x' |   | cos(θ)  -sin(θ) |   | x |
| y' | = | sin(θ)   cos(θ) | × | y |
```

#### Algorithm

```
Rotation(x, y, angle):
    rad = angle * PI / 180
    x' = x * cos(rad) - y * sin(rad)
    y' = x * sin(rad) + y * cos(rad)
    return (x', y')
```

#### Rotation About Arbitrary Point (xp, yp)

```
1. Translate to origin: (x - xp, y - yp)
2. Rotate about origin
3. Translate back: add (xp, yp)
```

#### Advantages

- Preserves shape and size
- Can rotate to any angle

#### Disadvantages

- Requires trigonometric functions
- Floating-point arithmetic needed

#### Complexity

| Metric    | Value                       |
| --------- | --------------------------- |
| **Time**  | O(n) where n = num vertices |
| **Space** | O(1)                        |

---

### 10. Reflection

#### Description

Reflection creates a mirror image of an object about a specified axis or line.

#### How It Works

Different reflection axes have different transformations:

| Reflection About | x'  | y'  |
| ---------------- | --- | --- |
| **X-axis**       | x   | -y  |
| **Y-axis**       | -x  | y   |
| **Origin**       | -x  | -y  |
| **Line y = x**   | y   | x   |
| **Line y = -x**  | -y  | -x  |

#### Transformation Matrices

**Reflection about X-axis:**

```
| x' |   | 1   0  |   | x |
| y' | = | 0  -1  | × | y |
```

**Reflection about Y-axis:**

```
| x' |   | -1  0 |   | x |
| y' | = | 0   1 | × | y |
```

**Reflection about Origin:**

```
| x' |   | -1  0  |   | x |
| y' | = | 0  -1  | × | y |
```

#### Algorithm

```
ReflectionAboutXAxis(x, y):
    x' = x
    y' = -y
    return (x', y')
```

#### Advantages

- Creates perfect mirror images
- Useful for symmetrical designs

#### Disadvantages

- Limited to predefined axes without complex calculations

#### Complexity

| Metric    | Value                       |
| --------- | --------------------------- |
| **Time**  | O(n) where n = num vertices |
| **Space** | O(1)                        |

---

### 11. Shearing

#### Description

Shearing slants the shape of an object. It shifts one coordinate in proportion to the other, creating a "skewed" effect.

#### How It Works

1. **X-shear**: `x' = x + shx × y`, `y' = y`
2. **Y-shear**: `x' = x`, `y' = y + shy × x`
3. **Combined**: `x' = x + shx × y`, `y' = y + shy × x`

#### Transformation Matrices

**X-Shear:**

```
| x' |   | 1   shx |   | x |
| y' | = | 0   1   | × | y |
```

**Y-Shear:**

```
| x' |   | 1   0   |   | x |
| y' | = | shy 1   | × | y |
```

#### Algorithm

```
Shearing(x, y, shx, shy):
    x' = x + shx * y
    y' = y + shy * x
    return (x', y')
```

#### Shearing Effects

| Factor  | Effect                       |
| ------- | ---------------------------- |
| shx > 0 | Slants right (positive x)    |
| shx < 0 | Slants left (negative x)     |
| shy > 0 | Slants upward (positive y)   |
| shy < 0 | Slants downward (negative y) |

#### Advantages

- Creates italic/slanted effects
- Useful for creating 3D illusions

#### Disadvantages

- Distorts the original shape
- Area may change with combined shearing

#### Complexity

| Metric    | Value                       |
| --------- | --------------------------- |
| **Time**  | O(n) where n = num vertices |
| **Space** | O(1)                        |

---

## Comparison Tables

### Line Drawing Algorithms

| Feature        | DDA                | Bresenham's           |
| -------------- | ------------------ | --------------------- |
| **Arithmetic** | Floating-point     | Integer only          |
| **Speed**      | Slower             | Faster                |
| **Accuracy**   | May have drift     | More accurate         |
| **Complexity** | Simple             | Moderate              |
| **Operations** | Division, rounding | Addition, subtraction |

### Circle vs Ellipse

| Feature        | Midpoint Circle | Midpoint Ellipse |
| -------------- | --------------- | ---------------- |
| **Symmetry**   | 8-way           | 4-way            |
| **Regions**    | Single          | Two regions      |
| **Parameters** | Center, radius  | Center, rx, ry   |
| **Complexity** | O(r)            | O(rx + ry)       |

### Flood Fill vs Boundary Fill

| Aspect                   | Flood Fill               | Boundary Fill                  |
| ------------------------ | ------------------------ | ------------------------------ |
| **Input**                | Old color, new color     | Boundary color, fill color     |
| **Stopping Condition**   | Pixel ≠ old color        | Pixel = boundary or fill color |
| **Interior Requirement** | Uniform color            | Any color (non-boundary)       |
| **Best For**             | Replacing specific color | Filling enclosed boundaries    |

### 2D Transformations

| Transformation  | Preserves Shape | Preserves Size | Matrix Type     |
| --------------- | --------------- | -------------- | --------------- |
| **Translation** | ✓               | ✓              | 3×3 Homogeneous |
| **Scaling**     | ✓ (if uniform)  | ✗              | 2×2             |
| **Rotation**    | ✓               | ✓              | 2×2             |
| **Reflection**  | ✓               | ✓              | 2×2             |
| **Shearing**    | ✗               | ✗              | 2×2             |

---

## Setup & Compilation

### Compilation

```bash
# Compile any program
gcc program.c -o program -lgraph

# Run
./program
```

## Quick Reference

| Algorithm            | Purpose       | Key Function               |
| -------------------- | ------------- | -------------------------- |
| **DDA**              | Draw lines    | Incremental floating-point |
| **Bresenham's**      | Draw lines    | Integer decision parameter |
| **Midpoint Circle**  | Draw circles  | 8-way symmetry             |
| **Midpoint Ellipse** | Draw ellipses | 4-way symmetry, 2 regions  |
| **Flood Fill**       | Fill region   | Replace old color          |
| **Boundary Fill**    | Fill region   | Stop at boundary           |
| **Translation**      | Move object   | Add (tx, ty)               |
| **Scaling**          | Resize object | Multiply (sx, sy)          |
| **Rotation**         | Rotate object | Trigonometric functions    |
| **Reflection**       | Mirror object | Negate coordinates         |
| **Shearing**         | Slant object  | Add proportional offset    |

---
