/*
Subset Sum Problem

Given an array of integers `nums`, return all possible subset sums.

Approach:
- Use recursion (backtracking).
- At each index:
    1. Include the element in the sum.
    2. Exclude the element from the sum.
- When we reach the end of the array, store the sum.

Time Complexity: O(2^n) (every element can be included or excluded)
Space Complexity: O(2^n) for storing sums
*/

#include <bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int> &nums, vector<int> &ans) {
    if (ind == nums.size()) {
        ans.push_back(sum);
        return;
    }
    // Include current element
    func(ind + 1, sum + nums[ind], nums, ans);

    // Exclude current element
    func(ind + 1, sum, nums, ans);
}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> ans;
    func(0, 0, nums, ans);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> result = subsetSums(nums);

    for (int sum : result) cout << sum << " ";
    cout << endl;
    return 0;
}
