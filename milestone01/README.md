# Project Overview

This project aims to determine the minimum distance path on a map following specific constraints. The implementation involves parsing a map input, represented as a string, into a 2D array and calculating the shortest path from a starting point to an endpoint under defined movement conditions.

## Features

- Parse the map input string into a 2D array of characters representing terrain altitudes.
- Calculate ASCII-based movement constraints:
- Climbing: ASCII(C2) - ASCII(C1) <= 2
- Descending: ASCII(C1) - ASCII(C2) <= 3
- Find the shortest path between two points using allowed moves (up, down, left, right).
- Handle edge cases, including scenarios where no path exists.

## Example

**Sample Input**


5 5
0 0
4 2
ABCCDGLCKEZZBLFXYCMGDVEGH

