class Solution {
public:
    bool valid(string st)
    {
        if(st.size()>3 || st.size()==0) return false;
        if(st.size()>1 && st[0]=='0') return false;
        if(st.size() && stoi(st)>255) return false;
        return true;
    }
    
    void fun(int ind, int dot, string s, string ss, vector<string> &ans)
    {
        if(dot == 3)
        {
            if(valid(s.substr(ind)))
            {
                ans.push_back(ss+s.substr(ind));
            }
            return;
        }

        int ln=s.size();
        for(int i=ind;i<min(ind+3,ln);i++)
        {
            if(valid(s.substr(ind,i-ind+1)))
            {
                ss.push_back(s[i]);
                ss.push_back('.');
                fun(i+1,dot+1,s,ss,ans);
                ss.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string ss;

        fun(0,0,s,ss,ans);
        return ans;
    }
};