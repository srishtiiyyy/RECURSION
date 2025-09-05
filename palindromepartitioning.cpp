#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        dfs(0, s, path, ans);
        return ans;
    }

    // Backtracking DFS
    void dfs(int index, string s, vector<string>& path, vector<vector<string>>& ans) {
        // If we reached end, push the current path
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                // Choose substring
                path.push_back(s.substr(index, i - index + 1));
                // Recurse
                dfs(i + 1, s, path, ans);
                // Backtrack
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    vector<vector<string>> result = obj.partition(s);

    for (auto &partition : result) {
        cout << "[ ";
        for (auto &str : partition) cout << str << " ";
        cout << "]\n";
    }
    return 0;
}
