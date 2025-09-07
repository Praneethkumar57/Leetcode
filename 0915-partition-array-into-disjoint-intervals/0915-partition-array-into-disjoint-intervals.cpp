class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> mini;
        int n=nums.size();
        int least = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini.push_back(least);
            least = min(least,nums[i]);
        }
        reverse(mini.begin(),mini.end());
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<=mini[i] && maxi<=mini[i]){
                return(i+1);
            }
            maxi = max(maxi,nums[i]);
        }
        return n;
    }
};