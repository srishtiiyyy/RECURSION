import java.util.*;

class ratinamaze {

    static boolean safe(int x, int y, int[][] maze, int[][] visited, int n) {
        return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && visited[x][y] == 0);
    }

    static void solve(int x, int y, int[][] maze, int n, List<String> ans, int[][] visited, String path) {
        if (x == n - 1 && y == n - 1) { // reached destination
            ans.add(path);
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

    static List<String> findPath(int[][] maze, int n) {
        List<String> ans = new ArrayList<>();
        int[][] visited = new int[n][n];
        if (maze[0][0] == 1) solve(0, 0, maze, n, ans, visited, "");
        Collections.sort(ans);
        return ans;
    }

    public static void main(String[] args) {
        int n = 4;
        int[][] maze = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}
        };

        List<String> res = findPath(maze, n);
        for (String path : res) System.out.println(path);
    }
}
