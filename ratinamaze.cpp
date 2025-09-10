#include <bits/stdc++.h>
using namespace std;

/*
GeeksForGeeks: Rat in a Maze Problem
- Rat starts at (0,0) and must reach (n-1,n-1)
- Can move: Down (D), Left (L), Right (R), Up (U)
- Only moves to cells with value 1 and inside the grid
- Return all possible paths in lexicographical order
*/

bool safe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && !visited[x][y]);
}

void solve(int x, int y, vector<vector<int>>& maze, int n, vector<string>& ans,
           vector<vector<int>>& visited, string path) {
    if (x == n - 1 && y == n - 1) { // reached destination
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Move Down
    if (safe(x + 1, y, maze, visited, n))
        solve(x + 1, y, maze, n, ans, visited, path + "D");

    // Move Left
    if (safe(x, y - 1, maze, visited, n))
        solve(x, y - 1, maze, n, ans, visited, path + "L");

    // Move Right
    if (safe(x, y + 1, maze, visited, n))
        solve(x, y + 1, maze, n, ans, visited, path + "R");

    // Move Up
    if (safe(x - 1, y, maze, visited, n))
        solve(x - 1, y, maze, n, ans, visited, path + "U");

    visited[x][y] = 0; // backtrack
}

vector<string> findPath(vector<vector<int>>& maze, int n) {
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    if (maze[0][0] == 1) solve(0, 0, maze, n, ans, visited, "");
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> res = findPath(maze, n);
    for (auto& path : res) cout << path << endl;
}
