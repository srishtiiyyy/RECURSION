import java.util.*;

public class PalindromePartitioning {

    // Main function to return all partitions
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        backtrack(0, s, new ArrayList<>(), ans);
        return ans;
    }

    private void backtrack(int index, String s, List<String> path, List<List<String>> ans) {
        // Base case: reached end
        if (index == s.length()) {
            ans.add(new ArrayList<>(path));
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (isPalindrome(s, index, i)) {
                // Choose substring
                path.add(s.substring(index, i + 1));
                // Recurse
                backtrack(i + 1, s, path, ans);
                // Backtrack
                path.remove(path.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s, int start, int end) {
        while (start <= end) {
            if (s.charAt(start++) != s.charAt(end--)) return false;
        }
        return true;
    }

    // User input main
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        PalindromePartitioning obj = new PalindromePartitioning();
        List<List<String>> result = obj.partition(s);

        for (List<String> partition : result) {
            System.out.println(partition);
        }
    }
}
