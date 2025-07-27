void seqn(vector<vector<char>>& list, vector<string>& res,int n,int index,string s){
    if(n==0){
        return;
    }
    if(index == n){
        res.push_back(s);
        return;
    }

    for(int i=0;i<list[index].size();i++){
        s = s+list[index][i];
        seqn(list,res,n,index+1,s);
        s.pop_back();
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int,vector<char>> mpp;
        mpp[2] = {'a','b','c'};
        mpp[3] = {'d','e','f'};
        mpp[4] = {'g','h','i'};
        mpp[5] = {'j','k','l'};
        mpp[6] = {'m','n','o'};
        mpp[7] = {'p','q','r','s'};
        mpp[8] = {'t','u','v'};
        mpp[9] = {'w','x','y','z'};
        vector<string> res;
        vector<vector<char>> list;
        string s;
        for(int i=0;i<digits.size();i++){
            list.push_back(mpp[digits[i]-'0']);
        }

        seqn(list,res,digits.size(),0,s);
        return res;
    }
};