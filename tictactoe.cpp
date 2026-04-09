#include <iostream>
using namespace std;

char board[3][3];
char player = 'X';

void resetBoard() {
    char count = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = count++;
        }
    }
}

void displayBoard() {
    cout << endl;
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        if(i < 2) cout << "\n---+---+---\n";
    }
    cout << endl;
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

void makeMove() {
    int choice;
    cout << "Player " << player << ", enter position (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
    } else {
        cout << "Invalid move! Try again.\n";
        makeMove();
    }
}

void switchPlayer() {
    player = (player == 'X') ? 'O' : 'X';
}

void instructions() {
    cout << "\nChoose numbers from 1 to 9 like this:\n";
    cout << " 1 | 2 | 3\n";
    cout << "---+---+---\n";
    cout << " 4 | 5 | 6\n";
    cout << "---+---+---\n";
    cout << " 7 | 8 | 9\n\n";
}

void startGame() {
    resetBoard();
    player = 'X';
    int moves = 0;
    bool win = false;

    while(!win && moves < 9) {
        displayBoard();
        makeMove();
        moves++;

        if(checkWin()) {
            win = true;
            displayBoard();
            cout << "Player " << player << " wins!\n";
        } else {
            switchPlayer();
        }
    }

    if(!win) {
        displayBoard();
        cout << "It's a draw!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== TIC TAC TOE =====\n";
        cout << "1. Start Game\n";
        cout << "2. Instructions\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: startGame(); break;
            case 2: instructions(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}
