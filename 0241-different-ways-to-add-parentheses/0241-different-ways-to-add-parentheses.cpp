class Solution {
public:
    //vector<int> ans;
    vector<int> fn(vector<int>& val,vector<char>& opr,int i,int j,int loc){
        if(i==j)return {val[i]};
        int v = 0;
        vector<int> ar;
        for(int k=i;k<j;k++){
            if(opr[k]=='+'){
                vector<int> l = fn(val,opr,i,k,loc+1);
                vector<int> r =fn(val,opr,k+1,j,loc+1);
                for(auto it1:l){
                    for(auto it2:r){
                        ar.push_back(it1+it2);
                    }
                }
            }
            else if(opr[k]=='-'){
                vector<int> l = fn(val,opr,i,k,loc+1);
                vector<int> r =fn(val,opr,k+1,j,loc+1);
                for(auto it1:l){
                    for(auto it2:r){
                        ar.push_back(it1-it2);
                    }
                }
            }
            else if(opr[k]=='*'){
                vector<int> l = fn(val,opr,i,k,loc+1);
                vector<int> r =fn(val,opr,k+1,j,loc+1);
                for(auto it1:l){
                    for(auto it2:r){
                        ar.push_back(it1*it2);
                    }
                }
            }
            
        }
        return ar;
    }

    vector<int> diffWaysToCompute(string exp) {
        int n=exp.size();
        vector<int> val;
        vector<char> opr;
        string s="";
        for(int i=0;i<n;i++){
            if(exp[i]>='0' && exp[i]<='9')s+=exp[i];
            else{
                int v=stoi(s);
                val.push_back(v);
                opr.push_back(exp[i]);
                s="";
            }
        }
        int v=stoi(s);
        val.push_back(v);
        int m=val.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        //ans.resize(0);
        vector<int> ans = fn(val,opr,0,m-1,1);
        return ans;
    }
};