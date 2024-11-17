#include <iostream>
#include <ctime>
using namespace std;

class TicTacToe {
private:
    char board[9];
    char player1;
    char player2;
    int difficulty; // 1: Easy, 2: Medium, 3: Hard

public:
    TicTacToe() {
        for (int i = 0; i < 9; i++) board[i] = ' ';
        player1 = 'X';
        player2 = 'O';
        difficulty = 1; // Default to easy
    }

    void setDifficulty(int level) {
        difficulty = level;
    }

    void drawBoard() {
        cout << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
        cout << "     |     |     " << endl;
        cout << endl;
    }

    void playerMove(char player) {
        int num;
        do {
            cout << "Player " << player << ", enter a spot to place a marker (1-9): ";
            cin >> num;
            --num;
            if (num >= 0 && num < 9 && board[num] == ' ') {
                board[num] = player;
                break;
            }
        } while (true);
    }

    void computerMoveEasy() {
        srand(time(0));
        int num;
        while (true) {
            num = rand() % 9;
            if (board[num] == ' ') {
                board[num] = player2;
                break;
            }
        }
    }

    void computerMoveMedium() {
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = player2;
                if (checkWinner()) return; // If it creates a win, keep the move
                board[i] = ' '; 

                board[i] = player1;
                if (checkWinner()) {
                    board[i] = player2; 
                    return;
                }
                board[i] = ' '; 
            }
        }
        computerMoveEasy(); 
    }


    void computerMoveHard() {
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = player2;
                if (checkWinner()) return; 
                board[i] = ' ';
            }
        }

        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = player1;
                if (checkWinner()) {
                    board[i] = player2;
                    return;
                }
                board[i] = ' ';
            }
        }

        computerMoveEasy();
    }

    bool checkWinner() {
        int winCombos[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
        };

        for (auto &it : winCombos) {
            if (board[it[0]] != ' ' && board[it[0]] == board[it[1]] && board[it[1]] == board[it[2]]) {
                cout << "Player " << board[it[0]] << " wins!" << endl;
                return true;
            }
        }
        return false;
    }

    bool checkTie() {
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') return false;
        }
        cout << "It's a Tie!\n";
        return true;
    }

    void PlayerVsPlayer() {
        drawBoard();
        while (true) {
            playerMove(player1);
            drawBoard();
            if (checkWinner() || checkTie()) break;

            playerMove(player2);
            drawBoard();
            if (checkWinner() || checkTie()) break;
        }
        cout << "THANKS FOR PLAYING :)\n";
    }

    void PlayerVsComputer() {
        drawBoard();
        while (true) {
            playerMove(player1);
            drawBoard();
            if (checkWinner() || checkTie()) break;

            switch (difficulty) {
                case 1: computerMoveEasy(); break;
                case 2: computerMoveMedium(); break;
                case 3: computerMoveHard(); break;
            }

            drawBoard();
            if (checkWinner() || checkTie()) break;
        }
        cout << "THANKS FOR PLAYING :)\n";
    }
};

int main() {
    TicTacToe game;
    int choice, level;

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Choose game mode:" << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs Computer" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        game.PlayerVsPlayer();
    } 
    
    else if (choice == 2) {
        cout << "Choose difficulty level:" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        cout << "Enter your choice: ";
        cin >> level;

        if (level < 1 || level > 3) {
            cout << "Invalid difficulty. Defaulting to Easy.\n";
            level = 1;
        }

        game.setDifficulty(level);
        game.PlayerVsComputer();
    } 
    
    else {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
