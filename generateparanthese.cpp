#include <bits/stdc++.h>
using namespace std;

/*
==========================================================
Problem: Generate Parentheses (LeetCode 22)
==========================================================

Given n pairs of parentheses, generate all combinations
of well-formed parentheses.

Example:
Input:  n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Approach (Backtracking):
- Keep track of 'open' and 'close' counts.
- Add '(' if open < n.
- Add ')' if close < open.
- Stop when length = 2*n.
==========================================================
*/

void func(string s, int open, int close, int n, vector<string>& result) {
    if (open + close == 2 * n && open == close) {
        result.push_back(s);
        return;
    }
    if (open < n) {
        func(s + '(', open + 1, close, n, result);
    }
    if (close < open) {
        func(s + ')', open, close + 1, n, result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    func("", 0, 0, n, ans);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> result = generateParenthesis(n);
    for (auto &str : result) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
