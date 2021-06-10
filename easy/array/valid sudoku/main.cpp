#include <iostream>
#include <vector>

using namespace std;

bool is_valid(vector<vector<char>>&);

int main() {
    char carr[81] = {'.','.','4','.','.','.','6','3','.',
                     '.','.','.','.','.','.','.','.','.',
                     '5','.','.','.','.','.','.','9','.',
                     '.','.','.','5','6','.','.','.','.',
                     '4','.','3','.','.','.','.','.','1',
                     '.','.','.','7','.','.','.','.','.',
                     '.','.','.','5','.','.','.','.','.',
                     '.','.','.','.','.','.','.','.','.',
                     '.','.','.','.','.','.','.','.','.'};
    vector<vector<char>> board(9);
    for (int i = 0; i < 9; i++) {
        board[i] = vector<char>(9);
        for (int j = 0; j < 9; j++) {
            board[i][j] = carr[i*9+j];
        }
    }
    cout << is_valid(board) << endl;
    return 0;
}

bool is_valid(vector<vector<char>>& board) {
    // row
    for (int i = 0; i < 9; i++) {
        int ascrr[58] = {0};
        for (int j = 0; j < 9; j++) {
            ascrr[board[i][j]]++;
        }
        for (int j = 49; j < 58; j++) {
            if (ascrr[j] > 1)
                return false;
        }
    }
    // column
    for (int i = 0; i < 9; i++) {
        int ascrr[58] = {0};
        for (int j = 0; j < 9; j++) {
            ascrr[board[j][i]]++;
        }
        for (int j = 49; j < 58; j++) {
            if (ascrr[j] > 1)
                return false;
        }
    }
    // block
    for (int i = 0; i < 7; i+=3) {
        for (int j = 0; j < 7; j+=3) {
            int ascrr[58] = {0};
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    ascrr[board[i+k][j+l]]++;
                }
            }
            for (int k = 49; k < 58; k++) {
                if (ascrr[k] > 1)
                    return false;
            }
        }
    }
    return true;
}