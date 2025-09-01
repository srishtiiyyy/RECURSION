import java.util.*;

/*
==========================================================
Problem: Subset Sum Problem
==========================================================

Given an array of integers nums and an integer k,
determine if there exists a subsequence whose sum equals k.

Example:
Input:
nums = [1,2,3], k = 5
Output: true  (because [2,3] sums to 5)

Approach:
- At each index, we have two choices:
  1. Include the current element in the sum.
  2. Exclude the current element.
- Recursively check both possibilities.
==========================================================
*/

public class SubsetSum {

    static boolean solve(int i, int n, int[] arr, int k) {
        if (k == 0) return true;
        if (k < 0) return false;
        if (i == n) return k == 0;

        return solve(i + 1, n, arr, k - arr[i]) || solve(i + 1, n, arr, k);
    }

    static boolean checkSubsequenceSum(int[] nums, int k) {
        int n = nums.length;
        return solve(0, n, nums, k);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();

        System.out.println(checkSubsequenceSum(nums, k));
    }
}
