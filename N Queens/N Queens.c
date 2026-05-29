#include <stdio.h>
#include <stdbool.h>

int N;

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
    printf("\n");
}

int solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        printBoard(board);
        return 1;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            count += solveNQueens(board, col + 1);
            board[i][col] = 0;
        }
    }
    return count;
}

int main() {
    printf("Enter N: ");
    scanf("%d", &N);

    int board[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    int solutions = solveNQueens(board, 0);

    if (solutions == 0)
        printf("No solutions for N = %d\n", N);
    else
        printf("Total solutions: %d\n", solutions);

    return 0;
}
