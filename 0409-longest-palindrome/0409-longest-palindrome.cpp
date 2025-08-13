class Solution {
public:
    int longestPalindrome(string s) {
        int cnt=0;
        map<char,int> mpp;
        for(auto it:s){
            mpp[it]++;
        }
        
        int odd=0;
        for(auto it:mpp){
            if((it.second)%2 == 0){
                cnt = cnt+it.second;
            }
            else{
                cnt = cnt+(it.second-1);
                odd=1;
            }
        }
        if(odd==1){
            cnt = cnt+1;
        }
        return cnt;
        
    }
};