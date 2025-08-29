class Solution {
public:
    long long flowerGame(int n, int m) {
       long long fodd=(n+1)/2;
       long long feven=(m+1)/2;
       long long val=fodd*(m-feven)+feven*(n-fodd);
       return val;
    }
};