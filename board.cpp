#include <iostream>
#include <vector>
using namespace std;

class HexBoard {
private:
    int size;
    vector<vector<char>> board;

public:
    HexBoard(int n) : size(n), board(n, vector<char>(n, '.')) {}

    void display() {
        for (int i = 0; i < size; i++) {
            cout << string(i, ' ');
            for (int j = 0; j < size; j++) {
                cout << board[i][j];
                if (j < size - 1) cout << " - ";
            }
            cout << endl;
            if (i < size - 1) {
                cout << string(i + 1, ' ');
                for (int j = 0; j < size - 1; j++) {
                    cout << "\\ / ";
                }
                cout << "\\" << endl;
            }
        }
    }
};

int main() {
    
    HexBoard hex(7);
    hex.display();
    return 0;
}