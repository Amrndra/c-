class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        map<int,int>mpp;
        int n=nums.size();
        if(n%k!=0) return false;
        int val=n/k;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>val) return false;
        }
        return true;
    }
};