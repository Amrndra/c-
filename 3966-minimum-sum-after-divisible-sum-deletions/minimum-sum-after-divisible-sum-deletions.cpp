#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& v, int k) {
        int n = v.size();
        vector<long long> x(k, LLONG_MAX);
        vector<long long> dp(n+1, LLONG_MAX);

        dp[0] = 0;          // empty prefix
        x[0]  = 0;          // remainder 0 at index 0

        for (int i = 1; i <= n; i++) {          // process full array
            // build candidate dp[i] from previous
            if (v[i-1] % k == 0)
                dp[i] = min(dp[i], dp[i-1]);
            else if (dp[i-1] != LLONG_MAX)
                dp[i] = min(dp[i], dp[i-1] + v[i-1]);

            // same-remainder shortcut: remove a k-divisible segment
            if (dp[i] != LLONG_MAX) {
                long long r = dp[i] % k;
                if (x[r] != LLONG_MAX)
                    dp[i] = min(dp[i], dp[x[r]]);

                // keep index with smallest dp for this remainder
                if (x[r] == LLONG_MAX || dp[i] < dp[x[r]])
                    x[r] = i;
            }
        }
        return dp[n];
    }
};
