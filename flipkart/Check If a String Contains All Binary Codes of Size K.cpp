class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k)return false;//s=5 and k=10

        unordered_set<string>st;

        for(int i=0;i<=s.size()-k;i++){
            st.insert(s.substr(i,k)); // sliding window storing all the substrings of s of  size k in set
        }
        return(st.size()==pow(2,k));//if set size==pow(2,k) means if the set contains all possible substring of size k we will return true;
    }
};