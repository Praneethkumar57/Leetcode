class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='['){
                st.push(it);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char c=st.top();
                st.pop();
                if((it==')' && c!='(') || (it=='}' && c!='{') || (it==']' && c!='[')){
                    return false;
                }
            }
            
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};