#include <bits/stdc++.h>
using namespace std;

/*
Generate binary strings of length n with NO consecutive 1s
*/

void backtrack(int pos, int n, string &curr, int prevOne) {
    if (pos == n) {
        cout << curr << '\n';
        return;
    }
    // place '0'
    curr.push_back('0');
    backtrack(pos + 1, n, curr, 0);
    curr.pop_back();

    // place '1' only if previous wasn't '1'
    if (!prevOne) {
        curr.push_back('1');
        backtrack(pos + 1, n, curr, 1);
        curr.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    string curr;
    backtrack(0, n, curr, 0);
    return 0;
}
