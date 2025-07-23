void printseqn(vector<int>& nums,int n, vector<vector<int>>& seqn,int index,vector<int>& vals){
    if(index == n){
        seqn.push_back(vals);
        return;
    }
    vals.push_back(nums[index]);
    printseqn(nums,n,seqn,index+1,vals);
    vals.pop_back();

    printseqn(nums,n,seqn,index+1,vals);
    return;
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> seqn;
        vector<int> vals;
        int n = nums.size();
        printseqn(nums,n,seqn,0,vals);
        return seqn;
    }
};