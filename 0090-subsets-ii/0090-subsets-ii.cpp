void seqn(vector<int>& nums,int n,vector<vector<int>>& res,vector<int>& arr,int index){
    res.push_back(arr);
    for(int i=index;i<n;i++){
        if(i!=index && nums[i]==nums[i-1]){
            continue;
        }
        arr.push_back(nums[i]);
        seqn(nums,n,res,arr,i+1);
        arr.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        seqn(nums,nums.size(),res,arr,0);
        return res;
    }
};