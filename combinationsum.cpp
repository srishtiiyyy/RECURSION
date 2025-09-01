#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int target, int index, 
           vector<int> &current, vector<vector<int>> &ans) {
    // Base case: target reached
    if (target == 0) {
        ans.push_back(current);
        return;
    }
    
    // If target < 0 OR index exceeds array -> stop
    if (target < 0 || index == nums.size()) return;

    // Choice 1: Pick current number and stay (since unlimited reuse allowed)
    current.push_back(nums[index]);
    solve(nums, target - nums[index], index, current, ans);

    // Backtrack
    current.pop_back();

    // Choice 2: Skip current number, move to next index
    solve(nums, target, index + 1, current, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    solve(candidates, target, 0, current, ans);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; i++) cin >> candidates[i];
    int target;
    cin >> target;

    vector<vector<int>> result = combinationSum(candidates, target);

    // Printing result
    for (auto &comb : result) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }
    return 0;
}
