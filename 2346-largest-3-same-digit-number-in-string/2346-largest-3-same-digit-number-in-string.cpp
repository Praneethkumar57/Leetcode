class Solution {
public:
    string largestGoodInteger(string num) {
        int cnt=1;
        set<int> arr;
        
        for(int i=1;i<num.size();i++){
            if(num[i-1]==num[i]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=3){
                arr.insert((int)(num[i]-'0'));
            }
        }
        int maxi = -1;
        for(auto it:arr){
            if(it>maxi){
                maxi = it;
            }
        }
        if(maxi==-1){
            return("");
        }
        string res(3,maxi+'0');
        return res;
    }
};