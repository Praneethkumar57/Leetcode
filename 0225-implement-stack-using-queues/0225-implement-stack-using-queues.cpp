class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        queue<int> q1;
        queue<int> q2;
    }
    
    void push(int x) {
        if(q1.empty() && q2.empty()){
            q1.push(x);
        }
        else if(!q1.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        int val;
        if(!q1.empty()){
            int n = q1.size();
            for(int i=0;i<n-1;i++){
                q2.push(q1.front());
                q1.pop();
            }
            val = q1.front();
            q1.pop();
        }
        else{
            int n = q2.size();
            for(int i=0;i<n-1;i++){
                q1.push(q2.front());
                q2.pop();
            }
            val = q2.front();
            q2.pop();
        }
        return val;
    }
    
    int top() {
        if(!q1.empty()){
            return (q1.back());
        }
        else{
            return(q2.back());
        }
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */