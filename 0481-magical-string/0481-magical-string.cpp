class Solution {
public:
    int magicalString(int n) {
        if(n<=3){
            return 1;
        }
        queue<int> que;
        que.push(2);
        int next=1;
        int cnt_ones=1;
        for(int i=2;i<n;i++){
            int top=que.front();
            if(top==2){
                if(next==1){
                    que.push(1);
                    que.push(1);
                    next=2;
                }
                else{
                    que.push(2);
                    que.push(2);
                    next=1;
                }
            }
            else{
                cnt_ones++;
                if(next==1){
                    que.push(1);
                    next=2;
                }
                else{
                    que.push(2);
                    next=1;
                }
            }
            que.pop();
        }
        return cnt_ones;
    }
};