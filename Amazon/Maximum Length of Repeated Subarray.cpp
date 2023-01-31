class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int n=nums1.size();
        int m=nums2.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        //vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(nums1[i-1]==nums2[j-1]){
                   dp[i][j]=dp[i-1][j-1]+1;
                   ans=max(ans, dp[i][j]);
                }
                else{
                   dp[i][j]=0; 
                }
            }
        }
        return ans;
    }
};