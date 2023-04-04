#include <stdio.h>

int main() {
    int size, rows, cols, spaces, blocks, height, row, col, symbol;
    printf("Enter the size of the pyramid: ");
    scanf("%d", &size);

    // Calculate the height of the pyramid
    height = 3 + ((size - 1) * 2);

    // Loop through each row of the pyramid
    for (row = 1; row <= height; row++) {
        // Calculate the number of blocks and spaces for the current row
        if (row <= 3) {
            blocks = row;
            spaces = height - (blocks * 2);
        } else {
            blocks = 3 + ((row - 4) / 2) + size;
            spaces = height - (blocks * 2);
        }

        // Loop through each column of the pyramid row
        for (col = 1; col <= (spaces / 2); col++) {
            printf(" ");
        }
        printf("/");
        for (col = 1; col <= blocks; col++) {
            // Determine the symbol to print for the current block
            if (row <= 3) {
                symbol = '*';
            } else {
                if (col <= 2 + ((row - 4) / 2)) {
                    symbol = '*';
                } else {
                    symbol = '|';
                }
            }
            printf("%c", symbol);
        }
        printf("\\");
        for (col = 1; col <= (spaces / 2); col++) {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
