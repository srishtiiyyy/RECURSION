import java.util.*;

/*
   Problem: Combination Sum III (LeetCode 216)
   Find all valid combinations of k numbers that sum up to n,
   using only numbers from 1 to 9, each at most once.

   Approach:
   - Use backtracking
   - At each step, choose numbers from "last" to 9
   - Stop if sum < 0 or size > k
   - Store when sum == 0 && size == k
   Complexity:
   - Time: O(C(9, k)) (bounded search space, at most 9Ck combinations)
   - Space: O(k) recursion + O(#answers)
*/

class combinationsum3 {
    public static void backtrack(int sum, int last, int k, List<Integer> curr, List<List<Integer>> ans) {
        if (sum == 0 && curr.size() == k) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        if (sum <= 0 || curr.size() > k) return;

        for (int i = last; i <= 9; i++) {
            if (i > sum) break; // pruning
            curr.add(i);
            backtrack(sum - i, i + 1, k, curr, ans);
            curr.remove(curr.size() - 1);
        }
    }

    public static List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(n, 1, k, new ArrayList<>(), ans);
        return ans;
    }

    // Driver
    public static void main(String[] args) {
        int k = 3, n = 7;
        List<List<Integer>> result = combinationSum3(k, n);
        System.out.println("Combinations: " + result);
    }
}
