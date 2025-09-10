import java.util.*;

/*
   Problem: Letter Combinations of a Phone Number (LeetCode 17)

   Approach:
   - Use backtracking to explore all possible letter sequences
   - Mapping: digits 2–9 → corresponding letters
   - Stop recursion when index reaches digits.length()

   Complexity:
   - Time: O(4^n) (each digit maps to at most 4 letters)
   - Space: O(n) recursion + O(#answers)
*/

class phonenumber {
    static String[] combos = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public static void backtrack(int index, String current, String digits, List<String> ans) {
        if (index == digits.length()) {
            ans.add(current);
            return;
        }
        int digit = digits.charAt(index) - '0';
        for (char c : combos[digit].toCharArray()) {
            backtrack(index + 1, current + c, digits, ans);
        }
    }

    public static List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits.equals("")) return ans;
        backtrack(0, "", digits, ans);
        return ans;
    }

    // Driver
    public static void main(String[] args) {
        String digits = "23";
        List<String> result = letterCombinations(digits);
        System.out.println("Combinations: " + result);
    }
}
