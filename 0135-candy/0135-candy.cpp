class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1){
            return 1;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            pq.push(ratings[i]);
        }

        while(!pq.empty()){
            int ele = pq.top();
            pq.pop();
            for(int i=0;i<n;i++){
                if(vis[i]==0 && ratings[i]==ele){
                    //int ind =i;
                    if(i-1>=0 && vis[i-1]!=0){
                        if(ratings[i]>ratings[i-1]){
                            vis[i] = max(vis[i],vis[i-1]+1);
                        }
                        else if(ratings[i]==ratings[i-1]){
                            vis[i]=1;
                        }
                        
                    }
                    if(i+1<n && vis[i+1]!=0){
                        if(ratings[i]>ratings[i+1]){
                            vis[i] = max(vis[i],vis[i+1]+1);
                        }
                        else if(ratings[i]==ratings[i+1]){
                            vis[i]=1;
                        }
                    }

                    if(i==0 && i+1<n && vis[i+1]==0){
                        vis[i]=1;
                    }
                    else if(i==n-1 && i-1>=0 && vis[i-1]==0){
                        vis[i]=1;
                    }
                    else if(i-1>=0 && vis[i-1]==0 && i+1<n && vis[i+1]==0){
                        vis[i]=1;
                    }
                    break;
                }
            }
        }
        int cnt=0;
        for(auto it:vis){
            cout<<it<<" ";
        }
        for(int i=0;i<n;i++){
            cnt += vis[i];
        }
        return cnt;
    }
};