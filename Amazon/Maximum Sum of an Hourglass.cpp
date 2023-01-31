class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ma=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j-1<0||j+1>=m||i+2>=n)
                continue;
                int val=grid[i][j-1]+grid[i][j]+grid[i][j+1]+grid[i+1][j]+grid[i+2][j-1]+grid[i+2][j]+grid[i+2][j+1];
                ma=max(ma,val);
            }

        }
        return ma;
    }
};