void seqn(vector<int>& candidates, int target, int n, vector<int>& arr, vector<vector<int>>& res, int index){
    if(target == 0){
        res.push_back(arr);
        return;
    }
    for(int i=index;i<n;i++){
        if(i>index && candidates[i-1]==candidates[i]) continue;
        if(candidates[i]>target) break;
        arr.push_back(candidates[i]);
        seqn(candidates,target-candidates[i],n,arr,res,i+1);
        arr.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        seqn(candidates,target,candidates.size(),arr,res,0);
        return res;
    }
};