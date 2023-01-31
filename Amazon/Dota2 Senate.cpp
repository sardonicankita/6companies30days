class Solution {
public:
    string predictPartyVictory(string senate) {
        //Create Two Pointers for R and D and Two for BanR and BanD
        int r=0,d=0,banR=0,banD=0;
        //Create a queue and push the char into it and count the R and D
        queue<char>q;
        for(auto it:senate){
            q.push(it);
            if(it=='R')r++;
            else d++;
        }
        // Iterate the queue
        while(!q.empty()){
            if(d==0)return "Radiant";
            else if(r==0) return "Dire";
            auto it=q.front();q.pop();
            if(it=='R'){
                if(banR){
                    banR--;
                    r--;
                    continue;
                }
                banD++;
                q.push('R');
            }
            else{
                if(banD){
                    banD--;
                    d--;
                    continue;
                }
                banR++;
                q.push('D');
            }
        }
        if(d==0)return "Radiant";
        return "Dire";
    }
};