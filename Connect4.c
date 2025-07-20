#include <stdio.h>

void InitializeBoard();
void NewMoveX();
void NewMoveO();
void NewBoard();
int Selecting();
int EndGame();

char Board[7][6];

int main(int argc, char const *argv[]) {
    int End = 0, CurrentPlayer = 0;

    InitializeBoard();

    while (1) {
        CurrentPlayer = 0;
        printf("\nPlayer X select a column: ");
        NewMoveX();
        End = EndGame();
        if (End == 1 || End == 2) break;

        CurrentPlayer = 1;
        printf("\nPlayer O select a column: ");
        NewMoveO();
        End = EndGame();
        if (End == 1 || End == 2) break;
    }

    if (End == 2) {
        printf("\nDraw!");
    } else if (End == 1) {
        (CurrentPlayer == 0) ? printf("\nPlayer X wins!!") : printf("\nPlayer O wins!!");
    }

    getchar();
    return 0;
}

void InitializeBoard() {
    for (int row = 0; row < 6; row++) {
        for (int column = 0; column < 7; column++) {
            Board[column][row] = '.';
            printf("%c ", Board[column][row]);
        }
        printf("\n");
    }
    for (int column = 1; column <= 7; column++) {
        printf("%d ", column);
    }
    printf("\n");
}

void NewBoard() {
    for (int row = 5; row >= 0; row--) {
        for (int column = 0; column < 7; column++) {
            printf("%c ", Board[column][row]);
        }
        printf("\n");
    }
    for (int column = 1; column <= 7; column++) {
        printf("%d ", column);
    }
    printf("\n");
}

int Selecting() {
    int Column = 0;
    while (1) {
        Column = getchar() - '0';
        getchar();
        if (Column >= 1 && Column <= 7) {
            if (Board[Column - 1][5] == '.') {
                return Column;
            } else {
                printf("\nSelect a valid position: ");
            }
        } else {
            printf("\nSelect a valid position: ");
        }
    }
}

void NewMoveX() {
    int Selected = Selecting();
    for (int row = 0; row < 6; row++) {
        if (Board[Selected - 1][row] == '.') {
            Board[Selected - 1][row] = 'X';
            break;
        }
    }
    NewBoard();
}

void NewMoveO() {
    int Selected = Selecting();
    for (int row = 0; row < 6; row++) {
        if (Board[Selected - 1][row] == '.') {
            Board[Selected - 1][row] = 'O';
            break;
        }
    }
    NewBoard();
}

int EndGame() {
    int Win = 0, i = 0;

    for (int column = 0; column < 6; column++) {
        for (int row = 0; row < 4; row++) {
            if (Board[column][row] != '.' &&
                Board[column][row] == Board[column][row + 1] &&
                Board[column][row] == Board[column][row + 2] &&
                Board[column][row] == Board[column][row + 3]) {
                return 1;
            }
        }
    }

    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 4; column++) {
            if (Board[column][row] != '.' &&
                Board[column][row] == Board[column + 1][row] &&
                Board[column][row] == Board[column + 2][row] &&
                Board[column][row] == Board[column + 3][row]) {
                return 1;
            }
        }
    }

    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 4; column++) {
            if (Board[column][row] != '.' &&
                Board[column][row] == Board[column + 1][row + 1] &&
                Board[column + 1][row + 1] == Board[column + 2][row + 2] &&
                Board[column + 2][row + 2] == Board[column + 3][row + 3]) {
                return 1;
            }
        }
    }

    for (int row = 5; row >= 3; row--) {
        for (int column = 0; column < 4; column++) {
            if (Board[column][row] != '.' &&
                Board[column][row] == Board[column + 1][row - 1] &&
                Board[column + 1][row - 1] == Board[column + 2][row - 2] &&
                Board[column + 2][row - 2] == Board[column + 3][row - 3]) {
                return 1;
            }
        }
    }

    for (int row = 0; row < 6; row++) {
        for (int column = 0; column < 7; column++) {
            if (Board[column][row] != '.') {
                i++;
            }
        }
    }

    if (i == 42) {
        return 2;
    }

    return 0;
}
