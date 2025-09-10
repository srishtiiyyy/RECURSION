#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 1922: Count Good Numbers

Idea:
- Even index → 5 choices
- Odd index → 4 choices
- Answer = (5^((n+1)/2)) * (4^(n/2)) % MOD
- Use fast exponentiation for efficiency.

Time: O(log n)
Space: O(1)
*/

const int MOD = 1e9 + 7;

long long powerfunc(long long a, long long b) {
    if (b == 0) return 1;
    long long half = powerfunc(a, b / 2);
    long long result = (half * half) % MOD;
    if (b % 2 == 1) result = (result * a) % MOD;
    return result;
}

int countGoodNumbers(long long n) {
    long long part1 = powerfunc(5, (n + 1) / 2);
    long long part2 = powerfunc(4, n / 2);
    return (part1 * part2) % MOD;
}

int main() {
    long long n;
    cin >> n;
    cout << countGoodNumbers(n) << "\n";
    return 0;
}
