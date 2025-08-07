void seqn(int n,int k,vector<int>& vec,vector<vector<int>>& res,int index){
    if(vec.size()==k){
        res.push_back(vec);
        return;
    }
    for(int i=index;i<=n;i++){
        vec.push_back(i);
        seqn(n,k,vec,res,i+1);
        vec.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        seqn(n,k,vec,res,1);
        return res;
    }
};