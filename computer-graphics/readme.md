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
4. [Comparison Tables](#comparison-tables)
5. [Setup & Compilation](#setup--compilation)

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

---

## 8-Connected Variants

Both filling algorithms can be extended to 8-connected versions:

```c
// Additional recursive calls for 8-connected
fill(x + 1, y + 1, ...);  // Bottom-right
fill(x - 1, y - 1, ...);  // Top-left
fill(x + 1, y - 1, ...);  // Top-right
fill(x - 1, y + 1, ...);  // Bottom-left
```

---

## Setup & Compilation

### Compilation

```bash
# Compile any program
gcc program.c -o program -lgraph

# Run
./program
```

### Alternative: SDL2 Setup

```bash
# Install SDL2
sudo apt-get install libsdl2-dev

# Compile with SDL2
gcc program.c -o program -lSDL2
```

---

## Quick Reference

| Algorithm            | Purpose       | Key Function               |
| -------------------- | ------------- | -------------------------- |
| **DDA**              | Draw lines    | Incremental floating-point |
| **Bresenham's**      | Draw lines    | Integer decision parameter |
| **Midpoint Circle**  | Draw circles  | 8-way symmetry             |
| **Midpoint Ellipse** | Draw ellipses | 4-way symmetry, 2 regions  |
| **Flood Fill**       | Fill region   | Replace old color          |
| **Boundary Fill**    | Fill region   | Stop at boundary           |

---
