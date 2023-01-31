class TweetCounts {
public:
    map<string,vector<int>>m;
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int temp = (endTime-startTime+1);
        auto x = m[tweetName];
        int time;
        if(freq=="minute"){
            time = 60;
        }
        else if(freq=="hour"){
            time = 3600; 
        }
        else{
            time = 86400;
        }
        int n = temp/time + (temp%time ?1:0);
        vector<int> ans(n);
        for(auto it:x){
            if(it>=startTime && it<=endTime){
                ans[(it-startTime)/time]+=1;
            }
        }
        return ans;
    }
};