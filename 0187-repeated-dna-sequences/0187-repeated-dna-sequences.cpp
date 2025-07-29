class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size()<=10){
            return res;
        }
        map<string,int> mpp;
        for(int i=0;i<=s.size()-10;i++){
            string str="";
            for(int j=i;j<i+10;j++){
                str += s[j];
            }
            mpp[str]++;
            if(mpp[str]==2){
                res.push_back(str);
            }
        }
        return res;
    }
};