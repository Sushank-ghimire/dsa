# Computer Graphics

### This repository contains implementations of various computer graphics algorithms.

## 1. Flood Fill Algorithm

### Description

Flood Fill is a region-filling algorithm that determines the area connected to a given node in a multi-dimensional array. It replaces all pixels of a specific color (old color) with a new color, starting from a seed point.

### How It Works

1. Start at a seed point (x, y)
2. Check if the current pixel has the old color
3. If yes, replace it with the new color
4. Recursively apply the same process to all 4 neighboring pixels (up, down, left, right)
5. Stop when boundary or already-filled pixels are encountered

### Algorithm (4-Connected)

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

### Connectivity

- **4-Connected**: Fills pixels connected horizontally and vertically
- **8-Connected**: Also includes diagonal neighbors (8 directions)

### Advantages

- Simple to understand and implement
- Works with any shape boundary
- Fills entire connected region uniformly

### Disadvantages

- Recursive implementation can cause stack overflow for large regions
- Requires knowing the original color of the region
- Slower than scanline-based methods

### Time & Space Complexity

- **Time Complexity**: O(n) where n is the number of pixels to fill
- **Space Complexity**: O(n) due to recursion stack (worst case)

---

## 2. Boundary Fill Algorithm

### Description

Boundary Fill is a region-filling algorithm that fills an area defined by a boundary color. Starting from a seed point, it replaces all pixels that are neither the boundary color nor the fill color with the specified fill color.

### How It Works

1. Start at a seed point (x, y)
2. Check if the current pixel is the boundary color or already filled
3. If neither, fill it with the new color
4. Recursively apply the same process to all 4 neighboring pixels
5. Stop when boundary pixels or already-filled pixels are encountered

### Algorithm (4-Connected)

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

### Difference from Flood Fill

| Aspect                 | Flood Fill                    | Boundary Fill                                   |
| ---------------------- | ----------------------------- | ----------------------------------------------- |
| **Stopping Condition** | Stops when pixel ≠ old color  | Stops when pixel = boundary color or fill color |
| **Input Required**     | Old color to replace          | Boundary color to detect                        |
| **Use Case**           | Replace specific color region | Fill within defined boundary                    |
| **Interior Colors**    | Must be uniform               | Can have multiple colors                        |

### Advantages

- Works with boundaries of any shape
- Can fill regions with multiple interior colors
- Intuitive boundary-based approach

### Disadvantages

- Recursive implementation can cause stack overflow
- Boundary must be completely closed (no gaps)
- Slower than scanline-based methods

### Time & Space Complexity

- **Time Complexity**: O(n) where n is the number of pixels to fill
- **Space Complexity**: O(n) due to recursion stack (worst case)

---

## Comparison Table

| Feature                  | Flood Fill               | Boundary Fill                  |
| ------------------------ | ------------------------ | ------------------------------ |
| **Input**                | Old color, new color     | Boundary color, fill color     |
| **Stopping Condition**   | Pixel ≠ old color        | Pixel = boundary or fill color |
| **Interior Requirement** | Uniform color            | Any color (non-boundary)       |
| **Time Complexity**      | O(n)                     | O(n)                           |
| **Space Complexity**     | O(n)                     | O(n)                           |
| **Best For**             | Replacing specific color | Filling enclosed boundaries    |

---

## 8-Connected Variants

Both algorithms can be extended to 8-connected versions by adding diagonal neighbors:

```c
// Additional recursive calls for 8-connected
fill(x + 1, y + 1, ...);  // Bottom-right
fill(x - 1, y - 1, ...);  // Top-left
fill(x + 1, y - 1, ...);  // Top-right
fill(x - 1, y + 1, ...);  // Bottom-left
```

---

## SDL2 Setup (Linux)

Install SDL2 development libraries:

```bash
sudo apt-get install libsdl2-dev
```

Compile any program:

```bash
gcc program.c -o program -lSDL2
```

---

## Key Points Summary

| Algorithm         | Use Case                          | Key Difference                |
| ----------------- | --------------------------------- | ----------------------------- |
| **Flood Fill**    | Paint bucket tool (replace color) | Checks against original color |
| **Boundary Fill** | Fill within drawn boundary        | Checks against boundary color |

---
