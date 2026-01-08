# Computer Architecture - C Programs

This folder contains C programs demonstrating fundamental **Computer Architecture** concepts including number system conversions, binary arithmetic, and signed number representations.

---

## 1. Binary to Decimal Conversion (`BinaryToDecimal.c`)

### Purpose

Converts between binary and decimal number systems.

### Key Functions

#### `convertToDecimal()`

Converts binary to decimal using positional notation.

```c
while (num > 0) {
  rem = num % 10;           // Extract rightmost digit
  decimal = decimal + rem * base;  // Multiply by power of 2
  base = base * 2;          // Next power of 2
  num = num / 10;           // Remove rightmost digit
}
```

**Example:** Binary `1011` → `1×8 + 0×4 + 1×2 + 1×1` = Decimal `11`

#### `convertToBinary()`

Converts decimal to binary using repeated division by 2.

```c
while (decimal > 0) {
  arr[i] = decimal % 2;     // Store remainder (0 or 1)
  decimal = decimal / 2;    // Divide by 2
  i++;
}
```

**Example:** Decimal `13` → `13÷2=6r1, 6÷2=3r0, 3÷2=1r1, 1÷2=0r1` → Binary `1101`

---

## 2. Binary Operations (`BinaryOperations.c`)

### Purpose

Performs binary addition and subtraction on two binary numbers.

### Key Functions

#### `binaryAddition()`

Adds two binary numbers digit by digit with carry propagation.

```c
int s = rem1 + rem2 + carry;
sum = sum + (s % 2) * place;  // Current bit
carry = s / 2;                 // Carry for next position
```

**Binary Addition Rules:**
| A | B | Carry In | Sum | Carry Out |
|---|---|----------|-----|-----------|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 | 1 |

#### `binarySubtraction()`

Subtracts using **2's complement method**: `A - B = A + (2's complement of B)`

**Steps:**

1. Find 1's complement of B (flip all bits)
2. Add 1 to get 2's complement
3. Add A + 2's complement of B

---

## 3. Complements (`Complements.c`)

### Purpose

Calculates 1's complement and 2's complement of binary numbers.

### Key Concepts

#### 1's Complement

Flip all bits: `0 → 1` and `1 → 0`

```c
if(remainder == 0)
  result = result + 1 * place;  // 0 becomes 1
else
  result = result + 0 * place;  // 1 becomes 0
```

**Example:** `1010` → `0101`

#### 2's Complement

1's complement + 1

```c
int twos = ones;  // Start with 1's complement
// Add 1 with carry propagation
while(carry) {
  if((twos/place) % 10 == 0) {
    twos += place;
    carry = 0;
  } else {
    twos -= place;
    place *= 10;
  }
}
```

**Example:** `1010` → 1's: `0101` → 2's: `0110`

### Why 2's Complement?

- Represents negative numbers in binary
- Simplifies subtraction (use addition instead)
- Single representation for zero

---

## 4. Signed Magnitude Representation (`SignedMagnitude.c`)

### Purpose

Performs arithmetic operations using signed magnitude representation.

### Representation Format

```
[Sign Bit] [Magnitude]
   0/1      |value|
```

- Sign `0` = Positive (+)
- Sign `1` = Negative (-)

### Key Functions

#### Addition

```c
if (signA == signB) {
  resultMagnitude = magnitudeA + magnitudeB;  // Same signs: add magnitudes
  resultSign = signA;
} else {
  // Different signs: subtract smaller from larger
  if (magnitudeA > magnitudeB) {
    resultMagnitude = magnitudeA - magnitudeB;
    resultSign = signA;  // Result takes sign of larger magnitude
  }
}
```

#### Subtraction

Converts to addition: `A - B = A + (-B)`

```c
signB = (signB == 0) ? 1 : 0;  // Flip sign of B
```

#### Multiplication & Division

```c
resultSign = (signA == signB) ? 0 : 1;  // Same signs = +, Different = -
resultMagnitude = magnitudeA * magnitudeB;  // or divide
```

### Signed Magnitude Rules Summary

| Operation      | Same Signs                            | Different Signs              |
| -------------- | ------------------------------------- | ---------------------------- |
| Addition       | Add magnitudes, keep sign             | Subtract, take larger's sign |
| Subtraction    | Convert to addition with flipped sign |
| Multiplication | Multiply magnitudes, XOR signs        |
| Division       | Divide magnitudes, XOR signs          |

---

## 5. Signed 2's Complement Operations (`SignedTwos.c`)

### Purpose

Demonstrates how 2's complement simplifies signed arithmetic.

### Key Advantage

Direct addition/subtraction works for both positive and negative numbers!

```c
sum = num1 + num2;   // Works for signed numbers directly
diff = num1 - num2;  // No special handling needed
```

### Why This Works

In 2's complement:

- Positive numbers: normal binary
- Negative numbers: 2's complement of absolute value
- Hardware uses same circuit for signed/unsigned operations

**Example:** `-3 + 5` in 4-bit 2's complement:

```
-3 = 1101 (2's complement)
+5 = 0101
---------
   10010 → discard carry → 0010 = 2 ✓
```

---

## 6. Booth's Multiplication Algorithm (`BoothMultiplication.c`)

### Purpose

Efficient multiplication algorithm that handles signed numbers and reduces operations for sequences of 1s.

### Algorithm Overview

Uses **Arithmetic Right Shift** and examines pairs of bits (Q₀, Q₋₁):

| Q₀  | Q₋₁ | Operation           |
| --- | --- | ------------------- |
| 0   | 0   | No operation, shift |
| 0   | 1   | A = A + M, shift    |
| 1   | 0   | A = A - M, shift    |
| 1   | 1   | No operation, shift |

### Key Components

```c
int A = 0;      // Accumulator (initially 0)
int Q;          // Multiplier
int Q_1 = 0;    // Previous LSB (Q₋₁)
int M;          // Multiplicand
int n = 4;      // Number of bits
```

### Masking Function

Ensures proper sign extension for n-bit arithmetic:

```c
int mask(int x, int bits) {
  int m = (1 << bits) - 1;
  x &= m;
  if (x & (1 << (bits - 1)))  // If sign bit is 1
    x |= ~m;                   // Sign extend
  return x;
}
```

### Algorithm Steps

1. Initialize: A=0, Q=multiplier, Q₋₁=0, M=multiplicand
2. Repeat n times:
   - Check Q₀ and Q₋₁
   - Perform operation (add/subtract/none)
   - Arithmetic right shift (A, Q, Q₋₁)
3. Result = A concatenated with Q

### Booth's Advantage

Reduces additions for consecutive 1s:

- `0111` (three 1s) → only 2 operations instead of 3
- Treats `0111` as `1000 - 0001`

---

## Compilation & Execution

### Compile Any Program

```bash
gcc source_file.c -o output_filename
```

### Examples

```bash
# Binary Conversion
gcc BinaryToDecimal.c -o binary
./binary

# Booth's Multiplication
gcc BoothMultiplication.c -o booth
./booth
```

---

## Quick Reference Table

| Concept           | Key Formula/Rule                  |
| ----------------- | --------------------------------- |
| Binary → Decimal  | Σ(bit × 2^position)               |
| Decimal → Binary  | Repeated ÷2, collect remainders   |
| 1's Complement    | Flip all bits                     |
| 2's Complement    | 1's complement + 1                |
| Signed Magnitude  | [sign][magnitude]                 |
| 2's Comp Negation | Invert bits, add 1                |
| Booth's Algorithm | Q₀Q₋₁: 01→Add, 10→Sub, else→Shift |

---

## Important Exam Notes

✔ **2's complement** is preferred in modern computers (single zero, simpler hardware)
✔ **Booth's algorithm** efficiently handles signed multiplication
✔ **Signed magnitude** has two representations for zero (+0 and -0)
✔ **Overflow** occurs when result exceeds bit width capacity
✔ **Arithmetic right shift** preserves sign bit (used in Booth's)

---

## One-Line Summary

> These programs demonstrate fundamental computer arithmetic: number system conversions, complement representations, and multiplication algorithms that form the basis of ALU operations in modern processors.
