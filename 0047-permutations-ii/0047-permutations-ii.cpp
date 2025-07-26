void permutations(vector<int>& nums,int n,vector<int>& arr, vector<int>& freq,set<vector<int>>& res){
    if(arr.size()==n){
        res.insert(arr);
        return;
    }

    for(int i=0;i<n;i++){
        if(!freq[i]){
            arr.push_back(nums[i]);
            freq[i]=1;
            permutations(nums,n,arr,freq,res);
            freq[i]=0;
            arr.pop_back();
        }
    }
}


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> arr;
        vector<int> freq(nums.size(),0);
        permutations(nums,nums.size(),arr,freq,res);
        vector<vector<int>> res2;
        for(auto it:res){
            res2.push_back(it);
        }
        return res2;
    }
};