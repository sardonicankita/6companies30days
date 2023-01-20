class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        map<string, int>mpp;
        
        for(int i=0; i<words.size(); i++)mpp[words[i]]++;
        
        vector<pair<string, int>>m(mpp.begin(), mpp.end());
        sort(m.begin(), m.end(),[] (auto a, auto b){
            if(a.second == b.second)
                return a.first < b.first;
            
            return a.second > b.second;
        });
        
        int i=0; 
        while(k--){
            ans.push_back(m[i].first);
            i++;
        }
        return ans;
    }
};