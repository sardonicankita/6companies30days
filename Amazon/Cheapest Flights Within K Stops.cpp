class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        vector<int> d(n, numeric_limits<int>::max());
        d[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> temp(d);
            for (auto& f : fl) {
                if (d[f[0]] != numeric_limits<int>::max()) {
                    temp[f[1]] = min(temp[f[1]], d[f[0]] + f[2]);
                }
            }
            d = temp;
        }
        return d[dst] == numeric_limits<int>::max() ? -1 : d[dst];
    }
};