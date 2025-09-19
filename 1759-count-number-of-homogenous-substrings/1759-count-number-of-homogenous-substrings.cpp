long long mod = 1e9+7;

class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        long long cnt=1;
        long long res=0;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                cnt++;
            }
            else{
                long long val = ((cnt*(cnt+1))/2)%mod;
                res = (res+val)%mod;
                cnt=1;
            }
        }
        long long val = ((cnt*(cnt+1))/2)%mod;
        res =(res+ val)%mod;
        return (int)res;
    }
};