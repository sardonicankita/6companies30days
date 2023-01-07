class Solution {
public:
    int dist(vector<int>& p1, vector<int>& p2){
        return pow(abs(p1[0] - p2[0]), 2)+ pow(abs(p1[1] - p2[1]), 2);
    }


    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int a=dist(p1, p2);
        int b=dist(p2, p3);
        int c=dist(p4, p3);
        int d=dist(p1, p4);

        int e=dist(p1, p3);
        int f=dist(p4, p2);

        unordered_set<int>st;

        st.insert({a, b, c, d, e, f});

        return !st.count(0) && st.size()==2;
    }
};