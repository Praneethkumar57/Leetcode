class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i=0;
        stack<int> st;
        int n = tokens.size();
        while(i<n){
            if(tokens[i]=="+"){
                int s1=st.top();
                st.pop();
                int s2 = st.top();
                st.pop();
                st.push(s2+s1);
            }
            else if(tokens[i]=="-"){
                int s1=st.top();
                st.pop();
                int s2 = st.top();
                st.pop();
                st.push(s2-s1);
            }
            else if(tokens[i]=="*"){
                int s1=st.top();
                st.pop();
                int s2 = st.top();
                st.pop();
                st.push(s2*s1);
            }
            else if(tokens[i]=="/"){
                int s1=st.top();
                st.pop();
                int s2 = st.top();
                st.pop();
                st.push(s2/s1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        return(st.top());
    }
};