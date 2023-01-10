class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size()<=2)return 0;
         
        int ans=0;
        unordered_map<int, int>mpp;
        for(int i=0; i<points.size(); i++){
              unordered_map<int, int>mpp;
            for(int j=0; j<points.size(); j++){
                int dis=pow((points[j][0]-points[i][0]),2)+pow((points[j][1]-points[i][1]),2);
                mpp[dis]++;
            }
            for(auto &l:mpp){
                ans+=(l.second)*(l.second-1);
            }
        }
        return ans;
    }
};