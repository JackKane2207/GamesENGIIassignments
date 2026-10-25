# Lab 07 — Report

**Name:** <Jack Kane>
*StudentID:** <C00300324>

## Build and run

```
cmake -S . -B build
cmake --build build --target lab07_tests
.\build\Debug\lab07_tests.exe --gtest_color=yes
```

## My CACC rows

Fill in the pairs you added:

| Major | Row 1 (major = T) | Row 2 (major = F) |
|-------|-------------------|-------------------|
| G     | T, F, T, T, T = T | T, F, T, F, T = F |
| D     | T, F, T, T, T = T | T, F ,T, T, F = F |

## Report (150–250 words)

Explain, in your own words, why the disjunction `(A ∨ B)` needs two determining pairs — one for A and one for B — instead of one shared pair. What value must the *minor* take to make the major "matter"?

The disjunction `(A ∨ B)` needs two determining pairs as the statement is only looking for one to be true.
For example if condition A is true, the statement will be true no matter what B is or if condition B is true the statement will be true no matter what A is, due to this there needs to be 2 separate determining pairs to show that A and B can independently change the result.
To ensure A and B are tested, when testing A, B must be false and to test B, A must be false. 
The minor must be false in this example for the major to matter.
This shows that each condition can independently affect the outcome of the statement.
C, G and D must also be true to test A and B as if any of them are false the overall payment decision will always return false.

## Screenshots

* `screenshots/vscode.png`
* `screenshots/terminal.png`
