class Solution {
public:
    long long minArraySum(vector<int>& v, int k) {
        int n = v.size();
        const long long INF = 1e18; // big number for impossible states
        vector<long long> x(k, INF);
        vector<long long> dp(n+1, INF);

        dp[0] = 0;          // empty prefix
        x[0]  = 0;          // remainder 0 at index 0

        for (int i = 1; i <= n; i++) {
            if (v[i-1] % k == 0) 
                dp[i] = min(dp[i], dp[i-1]);
            else if (dp[i-1] != INF) 
                dp[i] = min(dp[i], dp[i-1] + v[i-1]);

            if (dp[i] != INF) {  // ✅ only if dp[i] is valid
                int r = dp[i] % k;
                if (x[r] != INF) 
                    dp[i] = min(dp[i], dp[x[r]]);
                if (x[r] == INF || dp[i] < dp[x[r]]) 
                    x[r] = i;
            }
        }
        return dp[n];
    }
};
