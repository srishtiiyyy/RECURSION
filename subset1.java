/*
Subset Sum Problem

Given an array of integers `nums`, return all possible subset sums.

Approach:
- Use recursion (backtracking).
- At each index:
    1. Include the element in the sum.
    2. Exclude the element from the sum.
- When we reach the end of the array, store the sum.

Time Complexity: O(2^n)
Space Complexity: O(2^n) for storing sums
*/

import java.util.*;

public class SubsetSums {
    public static void func(int ind, int sum, int[] nums, List<Integer> ans) {
        if (ind == nums.length) {
            ans.add(sum);
            return;
        }
        // Include current element
        func(ind + 1, sum + nums[ind], nums, ans);

        // Exclude current element
        func(ind + 1, sum, nums, ans);
    }

    public static List<Integer> subsetSums(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        func(0, 0, nums, ans);
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

        List<Integer> result = subsetSums(nums);

        for (int sum : result) System.out.print(sum + " ");
        System.out.println();
    }
}
