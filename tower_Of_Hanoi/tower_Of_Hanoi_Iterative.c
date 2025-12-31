#include <stdio.h>
#include <math.h>

int main() {
    int n, total_moves = 1, i, j;
    int pegA[10], pegB[10], pegC[10];  // Arrays to represent the three pegs
    int topA, topB, topC;  // Top indices for each peg (-1 means empty)
    int from, to;
    char peg_names[3] = {'A', 'B', 'C'};
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of disks must be positive!\n");
        return 1;
    }
    
    // Initialize pegs
    topA = n - 1;
    topB = -1;
    topC = -1;
    
    // Put all disks on peg A (largest at bottom)
    for (i = 0; i < n; i++) {
        pegA[i] = n - i;  // Disk n at bottom, disk 1 at top
    }
    // Calculate pow(2, n) - 1
    for (int j = 1; j <= n; j++) {
        total_moves = total_moves * 2;
    }

    // Total number of moves required
    total_moves = total_moves - 1;
    
    printf("\nSolution for %d disks:\n\n", n);
    
    for (i = 1; i <= total_moves; i++) {

        //print the disk no 
        int count = 1;
        int temp = i;

        while (temp % 2 == 0) {
            temp = temp / 2;
            count++;
        }
 
        // For odd moves, move the smallest disk
        if (i % 2 == 1) {
            // Find where disk 1 is and move it
            if (topA >= 0 && pegA[topA] == 1) {
                // Disk 1 is on A
                if (n % 2 == 1) {
                    // Odd n: move A -> C
                    pegC[++topC] = pegA[topA--];
                    printf("Move disk %d from A to C\n", count);
                } else {
                    // Even n: move A -> B
                    pegB[++topB] = pegA[topA--];
                    printf("Move disk %d from A to B\n", count);
                }
            } else if (topB >= 0 && pegB[topB] == 1) {
                // Disk 1 is on B
                if (n % 2 == 1) {
                    // Odd n: move B -> A
                    pegA[++topA] = pegB[topB--];
                    printf("Move disk %d from B to A\n", count);
                } else {
                    // Even n: move B -> C
                    pegC[++topC] = pegB[topB--];
                    printf("Move disk %d from B to C\n", count);
                }
            } else {
                // Disk 1 is on C
                if (n % 2 == 1) {
                    // Odd n: move C -> B
                    pegB[++topB] = pegC[topC--];
                    printf("Move disk %d from C to B\n", count);
                } else {
                    // Even n: move C -> A
                    pegA[++topA] = pegC[topC--];
                    printf("Move disk %d from C to A\n", count);
                }
            }
        } else {
            // For even moves, make the only legal move not involving disk 1
            // Try all pairs of pegs (excluding the one with disk 1)
            int moved = 0;
            
            // Check A and B
            if ((topA < 0 || pegA[topA] != 1) && (topB < 0 || pegB[topB] != 1)) {
                if (topA < 0 && topB >= 0) {
                    pegA[++topA] = pegB[topB--];
                    printf("Move disk %d from B to A\n", count);
                    moved = 1;
                } else if (topB < 0 && topA >= 0) {
                    pegB[++topB] = pegA[topA--];
                    printf("Move disk %d from A to B\n", count);
                    moved = 1;
                } else if (topA >= 0 && topB >= 0) {
                    if (pegA[topA] < pegB[topB]) {
                        pegB[++topB] = pegA[topA--];
                        printf("Move disk %d from A to B\n", count);
                        moved = 1;
                    } else {
                        pegA[++topA] = pegB[topB--];
                        printf("Move disk %d from B to A\n", count);
                        moved = 1;
                    }
                }
            }
            
            // Check B and C
            if (!moved && (topB < 0 || pegB[topB] != 1) && (topC < 0 || pegC[topC] != 1)) {
                if (topB < 0 && topC >= 0) {
                    pegB[++topB] = pegC[topC--];
                    printf("Move disk %d from C to B\n", count);
                    moved = 1;
                } else if (topC < 0 && topB >= 0) {
                    pegC[++topC] = pegB[topB--];
                    printf("Move disk %d from B to C\n", count);
                    moved = 1;
                } else if (topB >= 0 && topC >= 0) {
                    if (pegB[topB] < pegC[topC]) {
                        pegC[++topC] = pegB[topB--];
                        printf("Move disk %d from B to C\n", count);
                        moved = 1;
                    } else {
                        pegB[++topB] = pegC[topC--];
                        printf("Move disk %d from C to B\n", count);
                        moved = 1;
                    }
                }
            }
            
            // Check A and C
            if (!moved && (topA < 0 || pegA[topA] != 1) && (topC < 0 || pegC[topC] != 1)) {
                if (topA < 0 && topC >= 0) {
                    pegA[++topA] = pegC[topC--];
                    printf("Move disk %d from C to A\n", count);
                } else if (topC < 0 && topA >= 0) {
                    pegC[++topC] = pegA[topA--];
                    printf("Move disk %d from A to C\n", count);
                } else if (topA >= 0 && topC >= 0) {
                    if (pegA[topA] < pegC[topC]) {
                        pegC[++topC] = pegA[topA--];
                        printf("Move disk %d from A to C\n", count);
                    } else {
                        pegA[++topA] = pegC[topC--];
                        printf("Move disk %d from C to A\n", count);
                    }
                }
            }
        }
    }
    
    printf("\nTotal moves: %d\n", total_moves);
    
    return 0;
}
