import java.util.*;

class NQueens {

    static boolean safe(List<String> board, int r, int c) {
        int n = board.size();

        // check row leftwards
        for (int j = 0; j < c; j++) {
            if (board.get(r).charAt(j) == 'Q') return false;
        }

        // check upper-left diagonal
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (board.get(i).charAt(j) == 'Q') return false;
        }

        // check lower-left diagonal
        for (int i = r, j = c; i < n && j >= 0; i++, j--) {
            if (board.get(i).charAt(j) == 'Q') return false;
        }

        return true;
    }

    static void func(int col, List<List<String>> ans, List<String> board) {
        int n = board.size();
        if (col == n) {
            ans.add(new ArrayList<>(board));
            return;
        }

        for (int row = 0; row < n; row++) {
            if (safe(board, row, col)) {
                char[] temp = board.get(row).toCharArray();
                temp[col] = 'Q';
                board.set(row, new String(temp));

                func(col + 1, ans, board);

                temp[col] = '.';
                board.set(row, new String(temp));
            }
        }
    }

    static List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        List<String> board = new ArrayList<>();
        for (int i = 0; i < n; i++) board.add(".".repeat(n));
        func(0, ans, board);
        return ans;
    }

    public static void main(String[] args) {
        int n = 4;
        List<List<String>> res = solveNQueens(n);
        for (List<String> board : res) {
            for (String row : board) System.out.println(row);
            System.out.println();
        }
    }
}
