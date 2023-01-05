class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rect) {
        map<pair<int, int>, int>mpp;
        // we are going to map the values for the four points 
        for(auto x:rect){
            mpp[{x[0], x[1]}]++;  //bottom left point
            mpp[{x[2], x[3]}]++;    //top right point
            mpp[{x[0], x[3]}]--;    //top left point
            mpp[{x[2], x[1]}]--;       //bottom right point
        }
         int corner =0;
        for (auto i= mpp.begin(); i!=mpp.end(); i++){
            if(i->second!=0){
                // meaning it should be a corner point
                if((i->second!=1) && (i->second!=-1))
                    return false;
                corner++;
            }
        }

        if(corner==4)return true;
        return false;
    }
};