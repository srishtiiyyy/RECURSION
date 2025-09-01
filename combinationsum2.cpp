#include <bits/stdc++.h>
using namespace std;

void func(int ind, int target, vector<int> &nums, vector<int> &candidates, vector<vector<int>> &ans) {
    // Base case: Found a valid combination
    if (target == 0) {
        ans.push_back(nums);
        return;
    }

    for (int i = ind; i < candidates.size(); i++) {
        // Skip duplicates at the same recursion level
        if (i > ind && candidates[i] == candidates[i - 1]) continue;

        // If candidate exceeds target, stop exploring further
        if (candidates[i] > target) break;

        // Choose current number
        nums.push_back(candidates[i]);
        // Move to next index (i+1) because each element can be used at most once
        func(i + 1, target - candidates[i], nums, candidates, ans);
        // Backtrack
        nums.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> nums;
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    func(0, target, nums, candidates, ans);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; i++) cin >> candidates[i];
    int target;
    cin >> target;

    vector<vector<int>> result = combinationSum2(candidates, target);

    for (auto &comb : result) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }
    return 0;
}
