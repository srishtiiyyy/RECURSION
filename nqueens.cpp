#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 51: N-Queens
Place n queens on an n x n chessboard such that no two queens attack each other.
Return all distinct solutions.

Approach: Backtracking
- Place queens column by column.
- Use a safe() function to check if the queen placement is valid.
*/

bool safe(vector<string>& board, int r, int c) {
    int n = board.size();

    // check same row leftwards
    for (int j = 0; j < c; j++) {
        if (board[r][j] == 'Q') return false;
    }

    // check upper-left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // check lower-left diagonal
    for (int i = r, j = c; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

void func(int col, vector<vector<string>>& ans, vector<string>& board) {
    int n = board.size();
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (safe(board, row, col)) {
            board[row][col] = 'Q';
            func(col + 1, ans, board);
            board[row][col] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    func(0, ans, board);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);
    for (auto& board : res) {
        for (auto& row : board) cout << row << endl;
        cout << endl;
    }
}
