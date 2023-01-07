class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<3)return points.size();
        int ans=0;

        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];

                int count=2;
                for(int k=j+1; k<points.size(); k++){
                    int x3=points[k][0];
                    int y3=points[k][1];

                    if((y2-y1)*(x3-x1)==(y3-y1)*(x2-x1))
                        count++;
                }
                ans=max(count, ans);
            }
        
        }
        return ans;
    }
};