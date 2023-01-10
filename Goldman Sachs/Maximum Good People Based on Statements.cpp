class Solution {
public:
    int maximumGood(vector<vector<int>>& S) {
        int n = size(S), ans = 0;
        auto valid = [&](int cur) {
            for(int i = 0; i < n; i++)
                if(cur & 1 << n-1-i)
                    for(int j = 0; j < n; j++)
                        if(S[i][j] != 2 && S[i][j] != bool(cur & 1 << n-1-j)) return false;
            return true;
        };
        for(int i = 0; i < 1 << n; i++)                            // bits in i denotes person configuration
            if(valid(i)) ans = max(ans, __builtin_popcount(i));    // update ans if valid config
        return ans;
    }
};