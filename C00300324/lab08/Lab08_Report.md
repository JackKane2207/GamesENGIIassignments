# Lab 08 — Report

**Name:** <YOUR NAME>
**Registration:** <SETU-CODE>

Show your working throughout. A correct answer with no derivation earns little credit.

---

## Part 1 — Determination

### 1.1 Truth table

Fill in F from R1–R4, then mark T in each p column where that clause determines F (leave the others blank or write F).

| Row | m | A | B | C | D | F | p<sub>A</sub> | p<sub>B</sub> | p<sub>C</sub> | p<sub>D</sub> |
|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 1 | 15 | T | T | T | T | T | F | F | F | F |
| 2 | 14 | T | T | T | F | T | F | T | F | F |
| 3 | 13 | T | T | F | T | T | T | T | F | F |
| 4 | 12 | T | T | F | F | T | T | T | F | F |
| 5 | 11 | T | F | T | T | T | T | F | T | T |
| 6 | 10 | T | F | T | F | F | F | T | F | T |
| 7 | 9 | T | F | F | T | F | F | T | T | F |
| 8 | 8 | T | F | F | F | F | F | T | F | F |
| 9 | 7 | F | T | T | T | T | F | T | T | F |
| 10 | 6 | F | T | T | F | T | F | T | T | F |
| 11 | 5 | F | T | F | T | F | T | F | T | F |
| 12 | 4 | F | T | F | F | F | T | F | T | F |
| 13 | 3 | F | F | T | T | F | T | T | F | F |
| 14 | 2 | F | F | T | F | F | F | T | F | F |
| 15 | 1 | F | F | F | T | F | F | F | F | F |
| 16 | 0 | F | F | F | F | F | F | F | F | F |

### 1.2 Determination conditions (XOR method)

For each clause, show every step from p<sub>X</sub> = F<sub>X=true</sub> ⊕ F<sub>X=false</sub> to the simplified result.

**p<sub>A</sub>**

```
p_A = F(A=true) ⊕ F(A=false)
    =
```

**p<sub>B</sub>**

```
p_B =
```

**p<sub>C</sub>**

```
p_C =
```

**p<sub>D</sub>**

```
p_D =
```

### 1.3 Tabulation check

For each clause, list the pairs of rows that differ only in that clause and say whether F changes. Confirm that the rows where F changes are exactly the rows where your p<sub>X</sub> is true.

### 1.4 GACC, CACC and RACC pairs

| Clause | GACC pairs | CACC pairs | RACC pairs |
|:--:|---|---|---|
| A | | | |
| B | | | |
| C | | | |
| D | | | |

### 1.5 Chosen pairs

| Clause | RACC pair (row with X true, row with X false) | Minor clause values |
|:--:|:--:|---|
| A | | |
| B | | |
| C | | |
| D | | |

Resulting set of rows: { } — size:

---

## Part 2 — Karnaugh maps

### 2.1 Minterms

| Requirement | Minterms |
|---|---|
| R1  A ∧ B | |
| R2  A ∧ C ∧ D | |
| R3  B ∧ C | |
| R4  A ∧ B ∧ C ∧ D | |

Σm(F) =

### 2.2 K-map of F

Mark each group. A screenshot or photo of a hand-drawn map is fine, but fill in the tables below as well.

| AB \ CD | 00 | 01 | 11 | 10 |
|:--:|:--:|:--:|:--:|:--:|
| **00** | | | | |
| **01** | | | | |
| **11** | | | | |
| **10** | | | | |

| Group | Minterms | Implicant | Essential? |
|---|---|---|---|
| | | | |

Minimal DNF: F =

### 2.3 What disappeared

Which requirement was removed by minimisation, and why does removing it not change the behaviour? Can any remaining term be dropped?

### 2.4 K-map of F̄

| AB \ CD | 00 | 01 | 11 | 10 |
|:--:|:--:|:--:|:--:|:--:|
| **00** | | | | |
| **01** | | | | |
| **11** | | | | |
| **10** | | | | |

Minimal DNF: F̄ =

### 2.5 Unique true points

| Expression | Implicant | Unique true points (minterm and row) |
|---|---|---|
| F | | |
| F̄ | | |

### 2.6 Near false points

| Implicant of F | Literal flipped | Near false points (minterm and row) |
|---|---|---|
| | | |

### 2.7 CUTPNFP set

| Implicant | Literal | Unique true point | Near false point |
|---|---|---|---|
| | | | |

Resulting set: { } — size:

---

## Part 3 — Test suites

| Test row label | Suite | Row | m | A B C D | Expected F | Came from |
|---|---|:--:|:--:|:--:|:--:|---|
| | | | | | | |

Number of tests: Determination = ___ , DNF = ___ , all passing? ___

---

## Part 4 — Automation

* Command used to run your script:
* What your oracle is, and why it is independent of the C++ code:
* Summary of the run against the starter (how many conditions failed):
* Summary of the final run:

Paste the table your script printed for the final run here.

---

## Part 5 — Comparison of the two methods (300–500 words)

Which conditions does each suite use that the other does not? What kind of fault in `evaluateSmokePurge()` could pass every test in the Determination suite but fail the DNF suite? Give a concrete faulty expression and show, using your conditions table, which row exposes it. Which suite would you keep if you could only keep one, and why?

---

## Screenshots

* `screenshots/vscode.png`
* `screenshots/terminal.png`
