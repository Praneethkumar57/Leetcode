class Solution {
public:   
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi=0, n=nums.size();
        map<int,long long> freq;
        for(auto it:nums){
            maxi=max(maxi,it);
            freq[it]++;
        }
        vector<long long> cnt(maxi+1);
        for(int i=1;i<=maxi;i++){
            long long c=0;
            for(int j=i;j<=maxi;j=j+i){
                c+=freq[j];
            }
            cnt[i]=c;
        }
        vector<long long> g(maxi+1);
        for(int i=1;i<=maxi;i++){
            long long v=(cnt[i]*(cnt[i]-1))/2;
            g[i]=v;
        }
        for(int i=maxi;i>=1;i--){
            for(int j=2*i;j<=maxi;j+=i){
                g[i]-=g[j];
            }
        }
        vector<long long> pre(maxi+1);
        pre[0]=-1;
        for(int i=1;i<=maxi;i++){
            pre[i]=pre[i-1]+g[i];
        }
        vector<int> ans;
        for(auto it:queries){
            int ind = lower_bound(pre.begin(),pre.end(),it)-pre.begin();
            ans.push_back(ind);
        }
        return ans;
    }
};