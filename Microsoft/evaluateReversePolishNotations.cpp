class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<char>st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int b= st.top();
                st.pop();
                int a=st.top();
                st.pop();
                 cout<<a<<" "<<b<<endl;
                if(tokens[i]=="+"){
                    st.push(a+b);
                }
                else if(tokens[i]=="-")
                    st.push(a-b);

                else if(tokens[i]=="*")
                    st.push(a*b);

                else
                    st.push(a/b);
            }
            else 
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};