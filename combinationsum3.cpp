#include <bits/stdc++.h>
using namespace std;

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

void backtrack(int sum, int last, vector<int> &curr, int k, vector<vector<int>> &ans) {
    if (sum == 0 && curr.size() == k) {
        ans.push_back(curr);
        return;
    }
    if (sum <= 0 || curr.size() > k) return;

    for (int i = last; i <= 9; i++) {
        if (i > sum) break;  // pruning
        curr.push_back(i);
        backtrack(sum - i, i + 1, curr, k, ans);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> curr;
    backtrack(n, 1, curr, k, ans);
    return ans;
}

// Driver
int main() {
    int k = 3, n = 7;
    vector<vector<int>> result = combinationSum3(k, n);

    cout << "Combinations:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
