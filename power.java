/*
==========================================================
Problem: Pow(x, n) (LeetCode 50)

Implement pow(x, n), which calculates x raised to n.
==========================================================
*/

class Solution {

    // ---------------- Brute Force Approach ----------------
    public double myPowBruteForce(double x, int n) {
        if (n == 0) return 1.0;

        long exp = n; // to handle Integer.MIN_VALUE
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double ans = 1.0;
        for (long i = 0; i < exp; i++) {
            ans *= x;
        }
        return ans;
    }

    // ---------------- Optimal Approach (Fast Exponentiation) ----------------
    public double myPowOptimal(double x, int n) {
        if (n == 0) return 1.0;

        long exp = n; // handle overflow
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        return fastPow(x, exp);
    }

    // Helper recursive function
    private double fastPow(double x, long n) {
        if (n == 0) return 1.0;
        if (n % 2 == 0) return fastPow(x * x, n / 2);
        else return x * fastPow(x, n - 1);
    }

    // ---------------- Main ----------------
    public static void main(String[] args) {
        Solution sol = new Solution();
        double x = 2.0;
        int n = -3;

        System.out.println("Brute Force Result: " + sol.myPowBruteForce(x, n));
        System.out.println("Optimal Result: " + sol.myPowOptimal(x, n));
    }
}
