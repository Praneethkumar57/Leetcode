int find_ncr(int n,int r){
    int ans = 1;
    for(int i=0;i<r;i++){
        ans = ans *(n-i);
        ans = ans/(i+1);
    }
    return(ans);
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            for(int col=1;col<=i;col++){
                temp.push_back(find_ncr(i-1,col-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};