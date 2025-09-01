#include <bits/stdc++.h>
using namespace std;

/*
==========================================================
Problem: Count Subsequences with Target Sum
==========================================================

Given an array of integers nums and an integer k,
count how many subsequences exist such that their sum = k.

Example:
Input:
nums = [1,2,3], k = 3
Output: 2
Explanation: Subsequences are [1,2], [3]

Approach:
- At each index, we have two choices:
  1. Include the current element in the sum.
  2. Exclude the current element.
- Recursively explore both and count the valid subsequences.
==========================================================
*/

int count(vector<int> &nums, int ind, int k) {
    if (k == 0) return 1;
    if (k < 0 || ind == nums.size()) return 0;

    int path1 = count(nums, ind + 1, k - nums[ind]); // include
    int path2 = count(nums, ind + 1, k);             // exclude

    return path1 + path2;
}

int countSubsequenceWithTargetSum(vector<int> &nums, int k) {
    return count(nums, 0, k);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;

    cout << countSubsequenceWithTargetSum(nums, k) << endl;
    return 0;
}
