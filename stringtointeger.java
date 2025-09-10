import java.util.*;

class Solution {
    /*
    LeetCode 8: String to Integer (atoi)

    Steps:
    1. Ignore leading spaces.
    2. Check sign.
    3. Convert digits until non-digit.
    4. Clamp result within [-2^31, 2^31-1].
    */
    public int myAtoi(String s) {
        if (s == null || s.length() == 0) return 0;

        int i = 0, n = s.length();

        // 1. Skip leading spaces
        while (i < n && s.charAt(i) == ' ') i++;
        if (i == n) return 0;

        // 2. Check sign
        int sign = 1;
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        long ans = 0;
        int MAX = Integer.MAX_VALUE, MIN = Integer.MIN_VALUE;

        while (i < n && Character.isDigit(s.charAt(i))) {
            ans = ans * 10 + (s.charAt(i) - '0');

            // 4. Clamp result
            if (sign == 1 && ans > MAX) return MAX;
            if (sign == -1 && -ans < MIN) return MIN;

            i++;
        }

        return (int)(sign * ans);
    }
}

public class stringtointeger {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.myAtoi("   -42"));  // -42
        System.out.println(sol.myAtoi("4193 with words")); // 4193
        System.out.println(sol.myAtoi("2147483648")); // 2147483647
    }
}
