class Solution {
public:
    int maxPower(string s) {
        int maxi =1;
        int cnt=1;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]){
                cnt++;
            }
            else{
                maxi = max(cnt,maxi);
                cnt=1;
            }
        }
        maxi = max(cnt,maxi);
        return maxi;
    }
};