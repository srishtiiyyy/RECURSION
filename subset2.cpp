#include <bits/stdc++.h>
using namespace std;

/*
   Problem: Subsets II (LeetCode 90)
   Given an integer array nums that may contain duplicates,
   return all possible subsets (the power set).

   Approach:
   - Sort the array so duplicates are adjacent
   - Use recursion with backtracking
   - Skip duplicates at the same recursion level
   - Add current subset at every recursive step
*/

void backtrack(int ind, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
    ans.push_back(curr); // store subset at each step

    for (int i = ind; i < nums.size(); i++) {
        // skip duplicates
        if (i > ind && nums[i] == nums[i-1]) continue;

        curr.push_back(nums[i]);
        backtrack(i + 1, nums, curr, ans);
        curr.pop_back();
    }
}
void func(int ind,vector<int>&nums,vector<int>&arr,vector<vector<int>>&ans){
    if(ind==nums.size()){
        ans.push_back(arr);
        return;
    }
    arr.push_back(nums[ind]);
    func(ind+1,nums,arr,ans);
    arr.pop_back();
    for(int j=ind+1;j<nums.size();j++){
        if(nums[j]!=nums[ind]){
            func(j,nums,arr,ans);
            return;
        }
    }
    func(nums.size(),nums,arr,ans);
  }

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> curr;
    backtrack(0, nums, curr, ans);
    return ans;
}

// Driver
int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsetsWithDup(nums);

    cout << "Unique Subsets:\n";
    for (auto &subset : result) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}