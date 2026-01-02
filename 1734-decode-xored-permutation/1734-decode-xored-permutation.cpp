class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        int xr=0;
        for(int i=1;i<=n+1;i++){
            xr = xr^i;
        }
        vector<int> ans(n+1);
        for(int i=1;i<n;i=i+2){
            xr = xr^encoded[i];
        }
        ans[0]=xr;
        for(int i=0;i<n;i++){
            ans[i+1]=ans[i]^encoded[i];
        }
        return ans;
    }
};