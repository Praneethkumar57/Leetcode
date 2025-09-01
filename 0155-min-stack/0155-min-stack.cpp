class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val>mini){
                st.push(val);
            }
            else{
                //st.push(2*val - mini);
                long long val2 = val;
                st.push(2*val2 - mini);
                mini=val;
            }
        }
        return;
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long x= st.top();
        st.pop();
        if(x<mini){
            mini = 2*mini - x;
        }
        return;
    }
    
    int top() {
        if(!st.empty()){
            long long x=st.top();
            if(x<mini){
                return (int)mini;
            }
            return (int)x;
        }
        return -1;
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */