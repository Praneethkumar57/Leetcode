void seqn(vector<int>& candidates, int target, int index, vector<int>& arr, vector<vector<int>>& res,int n){
    if(index == n){
        if(target == 0){
            res.push_back(arr);
        }
        return;
    }

    if(candidates[index]<=target){
        arr.push_back(candidates[index]);
        seqn(candidates, target-candidates[index], index, arr, res,n);
        arr.pop_back();
        
    }
    seqn(candidates, target, index+1, arr, res,n);
    
    
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        seqn(candidates, target, 0, arr,res, candidates.size());
        return res;
    }
};