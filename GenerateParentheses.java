import java.util.*;

/*
==========================================================
Problem: Generate Parentheses (LeetCode 22)
==========================================================

Given n pairs of parentheses, generate all combinations
of well-formed parentheses.

Example:
Input:  n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Approach (Backtracking):
- Keep track of 'open' and 'close' counts.
- Add '(' if open < n.
- Add ')' if close < open.
- Stop when length = 2*n.
==========================================================
*/

public class GenerateParentheses {

    static void func(String s, int open, int close, int n, List<String> result) {
        if (open + close == 2 * n && open == close) {
            result.add(s);
            return;
        }
        if (open < n) {
            func(s + "(", open + 1, close, n, result);
        }
        if (close < open) {
            func(s + ")", open, close + 1, n, result);
        }
    }

    static List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        func("", 0, 0, n, result);
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        List<String> result = generateParenthesis(n);
        for (String str : result) {
            System.out.print(str + " ");
        }
        System.out.println();
    }

}
