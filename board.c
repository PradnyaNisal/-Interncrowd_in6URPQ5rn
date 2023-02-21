#include <stdio.h>

char board[3][3]; // the game board

void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

int check_win() {
    int i;
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    // check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    return 0;
}

int main() {
    int row, col, player = 1, i;
    char mark;
    init_board();
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    for (i = 1; i <= 9; i++) {
        printf("Player %d's turn:\n", player);
        printf("Enter row number (1-3): ");
        scanf("%d", &row);
        printf("Enter column number (1-3): ");
        scanf("%d", &col);
        mark = (player == 1) ? 'X' : 'O';
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input, please try again.\n");
            i--;
        } else if (board[row-1][col-1] != ' ') {
            printf("That cell is already occupied, please try again.\n");
            i--;
        } else {
            board[row-1][col-1] = mark;
            print_board();
            if (check_win()) {
                printf("Congratulations! Player %d wins!\n", player);
                return 0;
            }
            player = (player == 1) ? 2 : 1;
        }
    }
    printf("It's a tie!\n");
    return 0;
}
