void seqn(vector<int>& list,int k,int n,vector<int>& arr, vector<vector<int>>& res,int index,int sum){
    if(arr.size() == k){
        if(sum == n){
            res.push_back(arr);
        }
        return;
    }
    if(sum>n || index>8){
        return;
    }
    arr.push_back(list[index]);
    seqn(list,k,n,arr,res,index+1,sum+list[index]);
    arr.pop_back();
    seqn(list,k,n,arr,res,index+1,sum);
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>list = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> arr;

        seqn(list,k,n,arr,res,0,0);
        return res;
    }
};