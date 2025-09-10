#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 8: String to Integer (atoi)

Steps:
1. Ignore leading spaces.
2. Check sign.
3. Convert digits until non-digit.
4. Clamp result within [-2^31, 2^31-1].
*/

class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;

        int i = 0, n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;

        // 2. Check sign
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        long long ans = 0;
        int MAX = INT_MAX, MIN = INT_MIN;

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // 4. Clamp result
            if (sign == 1 && ans > MAX) return MAX;
            if (sign == -1 && -ans < MIN) return MIN;

            i++;
        }

        return (int)(sign * ans);
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("   -42") << "\n";   // -42
    cout << sol.myAtoi("4193 with words") << "\n"; // 4193
    cout << sol.myAtoi("2147483648") << "\n"; // 2147483647 (clamped)
}
