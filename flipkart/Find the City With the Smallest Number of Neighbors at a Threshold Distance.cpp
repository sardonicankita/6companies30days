class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<int>>mat(n,vector<int>(n,1e8));
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1],dis=edges[i][2];
            mat[u][v]=dis;
            mat[v][u]=dis;
        }
        for(int i=0;i<n;i++)
            mat[i][i]=0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        int ans(n),val(n);
        for(int i=0;i<n;i++){
            int cnt{};
            for(int j=0;j<n;j++){
                if(i!=j && mat[i][j]<=dT)cnt++;
            }
            if(cnt<val){
                ans=i;
                val=cnt;
            }else if(cnt==val){
                ans=max(ans,i);
            }
        }
        return ans;
    }
};