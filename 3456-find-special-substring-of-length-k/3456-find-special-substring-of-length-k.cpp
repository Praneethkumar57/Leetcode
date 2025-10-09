class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.size();
        int start = 0;
        int end=k-1;
        while(end<n){
            int cnt=1;
            for(int i=start+1;i<=end;i++){
                if(s[i-1]!=s[i]){
                    cnt=2;
                    break;
                }
            }
            if(cnt==1){
                // int i=start;
                // int j=end;
                if(start-1>=0 && s[start-1]!=s[start] && end+1<n && s[end+1]!=s[start]){
                    return true;
                }
                else if(start-1<0 && end+1<n && s[end+1]!=s[start]){
                    return true;
                }
                else if(end+1>=n && start-1>=0 && s[start-1]!=s[start]){
                    return true;
                }
                else if(start-1<0 && end+1>=n){
                    return true;
                }
                // if(i-1<0 && i+1<n && s[i+1]==s[i]){
                //     break;
                // }
                // if(i+1>=n && i-1>=0 && s[i-1]==s[i]){
                //     break;
                // }
            }
            start = start+1;
            end=end+1;
        }
        return false;
    }
};