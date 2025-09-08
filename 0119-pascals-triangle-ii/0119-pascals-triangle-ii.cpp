int find_ncr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return (int)res;
}

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=1;i<=rowIndex+1;i++){
            res.push_back(find_ncr(rowIndex,i-1));
        }
        return res;
    }
};