#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int x) {
        int r = sqrt(x);
        return r * r == x;
    }

    int numSquares(int n) {
        // Case 1: n is a perfect square
        if (isPerfectSquare(n)) return 1;

        // Case 2: sum of 2 perfect squares
        for (int i = 1; i * i <= n; i++) {
            int rem = n - i * i;
            if (isPerfectSquare(rem)) return 2;
        }

        // Case 3 or 4: use number theory result
        // Remove factors of 4
        int m = n;
        while (m % 4 == 0) m /= 4;

        // If m ≡ 7 (mod 8), then answer = 4
        if (m % 8 == 7) return 4;

        // Otherwise, answer = 3
        return 3;
    }
};
