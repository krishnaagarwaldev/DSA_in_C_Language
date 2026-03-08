#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int num, vector<vector<char>>& board, int i, int j) {
        char c = '0' + num;
        // check at same row
        for (int col = 0; col < 9; col++) {
            if (board[i][col] == c)
                return false;
        }
        // check at same col
        for (int row = 0; row < 9; row++) {
            if (board[row][j] == c)
                return false;
        }
        // check at same box
        int row = i / 3 * 3;
        int col = j / 3 * 3;

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (board[a + row][b + col] == c)
                    return false;
            }
        }

        return true;
    }

    bool find(int i, int j, vector<vector<char>>& board) {
        if (i == 9)
            return true;

        if (j == 9)
            return find(i + 1, 0, board);

        if (board[i][j] != '.')
            return find(i, j + 1, board);

        for (int num = 1; num <= 9; num++) {
            if (check(num, board, i, j)) {
                board[i][j] = '0' + num;
                if (find(i, j + 1, board))
                    return true;

                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        find(0, 0, board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '8', '8', '6', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution sol;
    sol.solveSudoku(board);

    for (auto it : board) {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
