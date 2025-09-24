class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        if(n<k){
            reverse(s.begin(),s.end());
            return s;
        }
        int end=0;
        for(int start=0;start<n;start+=2*k){
            int end = min(start + k, n);  // reverse first k chars (or less if not enough left)
            reverse(s.begin() + start, s.begin() + end);
        }
        return s;
    }
};