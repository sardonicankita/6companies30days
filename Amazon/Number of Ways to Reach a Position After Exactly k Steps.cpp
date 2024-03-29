class Solution {
public:
    int mod = (int)(1e9+7);
    int numberOfWays(int startPos, int endPos, int k) {

        int step = k - abs(startPos-endPos);
        if(step%2!=0 || k<abs(startPos-endPos)){
            return 0;
        }


        unordered_map<int,unordered_map<int, int>> dp;
        std::function<int(int, int)> get_bin = [&](int n, int m) {
            if(n==m || m==0){
                return 1;
            }
            if(m == 1) {
                return n;
            }
            if(dp.count(n)>0 && dp[n].count(m)>0) {
                return dp[n][m];
            }
            long long res = get_bin(n-1, m) + get_bin(n-1, m-1);
            res %= mod;
            dp[n][m] = (int)res;
            return (int)res;
        };


        return (int)get_bin(k, step/2);
    }


};