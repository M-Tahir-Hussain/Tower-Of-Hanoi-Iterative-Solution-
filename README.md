# Tower-Of-Hanoi-Iterative-Solution
📌 Overview

This project implements an iterative (non-recursive) solution to the Tower of Hanoi problem in C.

Instead of using recursion, the program:

Simulates the three pegs using arrays

Calculates the total number of moves using 
2
𝑛
−
1
2
n
−1

Uses the ruler pattern to determine which disk moves at each step

This approach demonstrates how recursion can be replaced with iteration and mathematical patterns.

🎯 Features

✅ Fully iterative solution

✅ No recursion used

✅ Uses ruler pattern to identify disk numbers

✅ Handles odd and even number of disks correctly

✅ Displays every move step-by-step

🧠 Key Concepts Used
1. Tower of Hanoi Rules

Only one disk can be moved at a time

A larger disk cannot be placed on a smaller disk

Goal: move all disks from Peg A → Peg C

2. Ruler Pattern (Disk Identification)

The ruler pattern is:

1 2 1 3 1 2 1 4 1 2 1 3 ...


In this program:

The disk number moved at step i is calculated by:

Counting how many times i is divisible by 2

Adding 1 to that count

Example
Move Number	Disk Moved
1	1
2	2
3	1
4	3
5	1

This logic replaces recursive depth tracking.

3. Iterative Move Strategy

Odd moves → Always move the smallest disk

Even moves → Make the only legal move that does not involve the smallest disk

The direction of movement depends on whether n is odd or even

🗂️ Data Structures
int pegA[10], pegB[10], pegC[10];
int topA, topB, topC;


Each peg is implemented as a stack

topX = -1 means the peg is empty

Disks are represented by integers (1 = smallest disk)

🧮 Total Moves Calculation

The total number of moves is calculated iteratively:

2^n - 1


This avoids using the pow() function.

▶️ How to Compile and Run
Compile
gcc hanoi.c -o hanoi

Run
./hanoi

🖥️ Sample Input
Enter the number of disks: 3

📤 Sample Output
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C

Total moves: 7

📚 Learning Outcomes

By studying this program, you will understand:

How to convert recursive algorithms into iterative ones

How the ruler pattern works

Stack implementation using arrays

Legal move validation in Tower of Hanoi

Bit-based mathematical patterns in algorithms

🛠️ Limitations

Maximum number of disks is 10 (array size limit) the maximum no of disks can be increased by increasing the array size and vice versa

No dynamic memory allocation used

📄 License

This project is for educational purposes and is free to use, modify, and share.
