class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int val =0;
        for(auto it:nums){
            if(!(it&1))val+=it;
        }
        vector<int> ans;
        for(auto it:queries){
            int v= it[0], ind = it[1];
            if(!(nums[ind]&1)){
                int k=nums[ind]+v;
                if(!(k&1))val+=v;
                else val-=nums[ind];
            }
            else{
                int k=nums[ind]+v;
                if(!(k&1))val+=k;
            }
            nums[ind]=nums[ind]+v;
            ans.push_back(val);
        }
        return ans;
    }
};