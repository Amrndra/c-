class FenwickTree {
    vector<int> bits;
    int n;
public:
    FenwickTree(int size) {
        n = size;
        bits.assign(n+1, 0);
    }
    void update(int i, int val) {
        for (; i <= n; i += i & -i) bits[i] += val;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += bits[i];
        return sum;
    }
    int rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();

        
        for (auto &it : nums) if (it < 0) it = -it;

        map<int,int> mpp;
        set<int> s(nums.begin(), nums.end());
        int cnt = 1;
        for (auto x : s) {
            mpp[x] = cnt++;
        }

        FenwickTree ft(cnt+2);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            
            auto itR = s.upper_bound(2*val);
            if (itR == s.begin()) continue;
            --itR;
            int maxVal = *itR;

            auto itL = s.lower_bound((val+1)/2);
            if (itL == s.end()) continue;
            int minVal = *itL;

           
            total += ft.rangeQuery(mpp[minVal], mpp[maxVal]);

            
            ft.update(mpp[val], 1);
        }
        return total;
    }
};
