#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 7;  
vector<vector<char>> board(SIZE, vector<char>(SIZE, '.')); 

void displayBoard() {
    cout << "  ";
    for (int i = 0; i < SIZE; i++) cout << i << " ";
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << string(i, ' ') << i << " ";  
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool isValidMove(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == '.';
}

// Player move
void playerMove() {
    int x, y;
    while (true) {
        cout << "Enter your move (row col): ";
        cin >> x >> y;
        if (isValidMove(x, y)) {
            board[x][y] = 'B';  
            break;
        }
        cout << "Invalid move. Try again.\n";
    }
}

void aiMove() {
    int x, y;
    srand(time(0)); 
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (!isValidMove(x, y));

    board[x][y] = 'R'; 
    cout << "AI plays at: " << x << " " << y << endl;
}

int main() {
    cout << "Hex Game - You (B) vs AI (R)\n";
    displayBoard();

   for (int moves = 0; moves < SIZE*SIZE; moves++)
   {
    if (moves % 2 == 0) {
        playerMove();
    } else {
        aiMove();
    }
    displayBoard();
   }
   cout<<"game over";
      
    

  
    return 0;
}
