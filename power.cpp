#include <bits/stdc++.h>
using namespace std;

/*
==========================================================
Problem: Pow(x, n) (LeetCode 50)

Implement pow(x, n), which calculates x raised to n.
==========================================================
*/

class Solution {
public:
    // ---------------- Brute Force Approach ----------------
    double myPowBruteForce(double x, int n) {
        if (n == 0) return 1.0;
        
        long long exp = n; // use long long to handle INT_MIN case
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double ans = 1.0;
        for (long long i = 0; i < exp; i++) {
            ans *= x;
        }
        return ans;
    }

    // ---------------- Optimal Approach (Fast Exponentiation) ----------------
    double myPowOptimal(double x, int n) {
        if (n == 0) return 1.0;

        long long exp = n; // avoid overflow
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        return fastPow(x, exp);
    }

private:
    // Helper recursive function for fast exponentiation
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        if (n % 2 == 0) return fastPow(x * x, n / 2);
        else return x * fastPow(x, n - 1);
    }
};

// ------------------- Main Function -------------------
int main() {
    Solution sol;

    double x = 2.0;
    int n = -3;

    cout << "Brute Force Result: " << sol.myPowBruteForce(x, n) << endl;
    cout << "Optimal Result: " << sol.myPowOptimal(x, n) << endl;

    return 0;
}
