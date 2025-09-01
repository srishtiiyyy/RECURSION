 import java.util.*;

/*
==========================================================
Problem: Power Set (LeetCode 78)
==========================================================

Given an array of unique integers nums, return all possible
subsets (the power set).

Example:
Input:  nums = [1,2,3]
Output: [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]

Approach (Backtracking):
- At each index, we have two choices:
  1. Exclude the current element.
  2. Include the current element.
- Recursively explore both choices until the end.
==========================================================
*/

public class PowerSet {

    static void backtrack(int index, int n, int[] nums, List<Integer> current, List<List<Integer>> ans) {
        if (index == n) {
            ans.add(new ArrayList<>(current));
            return;
        }

        // Exclude current element
        backtrack(index + 1, n, nums, current, ans);

        // Include current element
        current.add(nums[index]);
        backtrack(index + 1, n, nums, current, ans);

        // Backtrack
        current.remove(current.size() - 1);
    }

    static List<List<Integer>> powerSet(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
        backtrack(0, nums.length, nums, current, ans);
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

        List<List<Integer>> result = powerSet(nums);
        for (List<Integer> subset : result) {
            System.out.print(subset + " ");
        }
        System.out.println();
    }
}
 