// bool comp(const vector<int>&a, const vector<int>& b){
//     return(a[1]<b[1]);
// }

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int cnt=1;
        int n=pairs.size();
        int start=pairs[0][1];
        //int maxi = -1e9;
        for(int i=1;i<n;i++){
            if(start<pairs[i][0]){
                cnt++;
                start = pairs[i][1];
            }
            else{
                start = min(start,pairs[i][1]);
            }
        }
        return cnt;
    }
};