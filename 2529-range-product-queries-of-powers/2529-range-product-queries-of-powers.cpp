class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>res;
        vector<int> power;
        long long MOD = 1000000007;
        for(int i=0;i<32;i++){
            if((n & (1<<i))>=1){
                power.push_back((int)(pow(2,i)));
            }
        }
        cout<<"power:";
        for(auto it:power){
            cout<<it<<" ";
        }
        for(int i=0;i<queries.size();i++){
            long long prod=1;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                prod = (prod*power[j])%(MOD);
            }
            res.push_back((int)prod);
        }
        return res;
    }
};