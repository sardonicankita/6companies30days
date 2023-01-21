class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>dir{{0,1}, {0, -1}, {1, 0}, {-1,0}};
        int m=grid.size(), n=grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    queue<pair<int, int>>q;
                    q.push(make_pair(i, j));
                    int a=1;
                    grid[i][j]=0;
                    while(!q.empty()){
                        pair<int, int> pos=q.front();
                        q.pop();
                        for(auto d:dir){
                            int u=pos.first + d[0];
                            int v=pos.second + d[1];
                            if(u>=0 && u<m && v>=0 && v<n && grid[u][v]){
                                a++;
                                grid[u][v]=0;
                                q.push(make_pair(u, v));
                            }
                        }
                    }
                    ans=max(a, ans);
                }
            }
        return ans;
    }
};