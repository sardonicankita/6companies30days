#define ppi pair<int,pair<int,int>>
class Solution {
public:
    bool checkPrime(int n){
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans;
        int prevPrime=0; // Initialising the prevPrime to 0
        priority_queue<ppi,vector<ppi>,greater<ppi>>mini;
        for(int i=left;i<=right;i++){
            if(checkPrime(i)){
                mini.push({i-prevPrime,{prevPrime,i}});
                prevPrime=i; // Updating prevPrime
            }
        }
        // if size of heap is 1 then only one prime
        // if size of heap is 0 then no prime 
        if(mini.size()<=1){   
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            auto temp=mini.top();
            ans.push_back(temp.second.first);
            ans.push_back(temp.second.second);
        }
        return ans;
    }
};