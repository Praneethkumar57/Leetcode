class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> mpp;
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int m=nums[i].size();
            for(int j=0;j<m;j++){
                mpp[nums[i][j]]++;
            }
        }
        for(auto it:mpp){
            if(it.second == n){
                res.push_back(it.first);
            }
        }
        return res;
    }
};