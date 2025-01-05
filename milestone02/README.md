# Project Overview - Milestone 2
Building upon the foundation laid in Milestone 1, this milestone introduces teleportation doors to the map. The task involves identifying these teleportation doors based on mathematical calculations, determining the shortest path, and implementing teleportation logic.

## Features

- Magical Teleportation Doors: Identify two teleportation doors using Fibonacci-based calculations.
- Shortest Path Calculation:
  - From the starting point to the endpoint, consider or ignore teleportation.
  - Between various key points, including teleportation doors.
- Modular Implementation: Tasks are divided into three components to ensure clarity and scalability.

## Tasks

**Task 1: Fibonacci Matching**
- Calculate the Fibonacci number of a given integer and check if it matches any of the two provided numbers.
- Input: Three integers (calculation base, two numbers for matching).
- Output: TRUE or FALSE.
  
**Task 2: Minimum Distance Calculation with Teleportation**
- Compute the shortest paths between key points:
  1. Starting point → Endpoint (no teleportation).
  2. Starting point → Teleportation Door 1.
  3. Starting point → Teleportation Door 2.
  4. Teleportation Door 1 → Endpoint.
  5. Teleportation Door 2 → Endpoint.
- Input: Map dimensions, starting/ending points, teleportation door positions, and map data.
- Output: Five minimum distances or -1 if no path exists.
  
**Task 3: Combined Minimum Distance with Teleportation Logic**
- Identify teleportation doors using Fibonacci logic and calculate the minimum distance between the starting point and the endpoint, considering teleportation if beneficial.
- Input: Map dimensions, starting/ending points, teleportation door data, and additional door positions.
- Output: Shortest path distance or a message indicating no path.

**Example**

Input:

    5 5
    0 0
    4 2
    ABCCDGLCKEZZBLFXYCMGDVEGH
    1
    144
    5
    0 2
    4 4
    2 3
    1 2
    2 2
    
Output:

    The minimum distance from A to E is 4
