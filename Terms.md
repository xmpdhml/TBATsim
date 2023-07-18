# Terminology

| Term | Definition |
| ---- | ---------- |
| Ternary | Balanced, unlesse specified, ternary numeral system |
| Ternary digit | Ternary digit, or trit, is a single digit in ternary numeral system. In this project we use 0, 1, and T to represent the three possible values |

## Operators

| Operator | Description |
| -------- | ----------- |
| `~` | Unary negation |
| `&` | Ternary and |
| `\|` | Ternary or |
| `^` | Ternary xor |
| `+` | Ternary add |
| `-` | Ternary subtract |
| `*` | Ternary multiply |
| `/` | Ternary divide |

## Ternary

| Ternary | Decimal |
| ------- | ------- |
| 0 | 0 |
| 1 | 1 |
| T | -1 |

## Unary negation

Unary negation (or complement) is an unary operator that inverts the value of a ternary digit.

| Input | Output |
| ----- | ------ |
| 0 | 0 |
| 1 | T |
| T | 1 |

## Ternary and

| Row & Col | T | 0 | 1 |
| --------- | - | - | - |
| T | T | T | T |
|
