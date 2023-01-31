class Solution {
public:

    int ans = 1; 
    int count(string s , int index , set < string > & st ){
        if(index == s.size()){
            return 0; 
        }
        int maxi = -1*1e9 ; 
        string temp = ""; 
        bool tt = false; 
        int curr = 0 ; 
        for(int i = index ; i < s.size() ; i++){
            temp += s[i]; 
            if(st.find(temp) == st.end()){
                st.insert(temp); 
                int p = count(s , i+1 , st); 
                st.erase(temp); 
                tt = true;
               maxi = max(maxi , p+1);  
            }
        }
        return maxi ;     
    }
    int maxUniqueSplit(string s) {
        set < string > st ; 
        return count(s, 0 , st ); 
        return ans ;         
    }
};

 