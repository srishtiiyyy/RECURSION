#include <bits/stdc++.h>
using namespace std;

/*
   Problem: Letter Combinations of a Phone Number (LeetCode 17)

   Approach:
   - Use backtracking to explore all possible letter sequences
   - Mapping: digits 2–9 → corresponding letters
   - Stop recursion when index reaches digits.size()

   Complexity:
   - Time: O(4^n) (each digit maps to at most 4 letters)
   - Space: O(n) recursion + O(#answers)
*/

void backtrack(int index, string current, string &digits, string combos[], vector<string> &ans) {
    if (index == digits.size()) {
        ans.push_back(current);
        return;
    }
    int digit = digits[index] - '0';
    for (char c : combos[digit]) {
        backtrack(index + 1, current + c, digits, combos, ans);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty()) return ans;
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    backtrack(0, "", digits, combos, ans);
    return ans;
}

// Driver
int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);
    cout << "Combinations:\n";
    for (auto &s : result) cout << s << " ";
    return 0;
}
