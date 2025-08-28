class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int i=n-1;
        while(i>=0){
            int r=i;
            int c=0;
            vector<int>v;
            int newr=i;
            int newc=0;
            while(r<n && c<n){
                v.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(v.begin(),v.end(),greater<int>());
            int cnt=0;
            while(newr<n && newc<n){
                grid[newr][newc]=v[cnt];
                cnt++;
                newr++;
                newc++;
            }
            i--;

        }
        int c=n-1;
        while(c>0){
            int r=0;
            int col=c;
            vector<int>v;
            int newr=0;
            int newc=c;
            while(r<n && col<n){
                v.push_back(grid[r][col]);
                r++;
                col++;
            }
            sort(v.begin(),v.end());

             int cnt=0;
            while(newr<n && newc<n){
                grid[newr][newc]=v[cnt];
                cnt++;
                newr++;
                newc++;
            }
            c--;

        }
        return grid;

    }
};