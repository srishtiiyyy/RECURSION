#include <bits/stdc++.h>
using namespace std;

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

bool solve(int i, int n, vector<int> &arr, int k) {
    if (k == 0) return true;
    if (k < 0) return false;
    if (i == n) return (k == 0);

    return solve(i + 1, n, arr, k - arr[i]) || solve(i + 1, n, arr, k);
}

bool checkSubsequenceSum(vector<int> &nums, int k) {
    int n = nums.size();
    return solve(0, n, nums, k);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;

    cout << (checkSubsequenceSum(nums, k) ? "true" : "false") << endl;
    return 0;
}
