class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<int> v;
        int n = prices.size();
        vector<long long> c(n, 0);
        v.resize(n, 0);
        for (int i = 0; i < n; i++) {
            v[i] = strategy[i] * prices[i];
            c[i] = prices[i];
        }
        vector<long long> pre(n);
        vector<long long> cre(n);
        pre[0] = v[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i-1] + v[i];
        cre[0] = c[0];
        for (int i = 1; i < n; i++) cre[i] = cre[i-1] + c[i];

        long long total = pre[n-1];

        int i = 1;
        int j = k;
        long long value = total - pre[k-1] + cre[k-1] - cre[(k-1)/2];

        while (j < n && i < j) {
            long long y = total - pre[j] + pre[i-1] + cre[j] - cre[(j+i)/2];  
            value = max(value, y);
            j++;
            i++;
        }
        value = max(value, total);
        return value;
    }
};
