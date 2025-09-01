#include <bits/stdc++.h>
using namespace std;

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

void func(int ind, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans) {
    if (ind == n) {
        ans.push_back(arr);
        return;
    }

    // Exclude current element
    func(ind + 1, n, nums, arr, ans);

    // Include current element
    arr.push_back(nums[ind]);
    func(ind + 1, n, nums, arr, ans);

    // Backtrack
    arr.pop_back();
}

vector<vector<int>> powerSet(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> arr;
    func(0, nums.size(), nums, arr, ans);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> result = powerSet(nums);

    for (auto &subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
