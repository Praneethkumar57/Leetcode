class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        // sort(inter.begin(),inter.end());
        sort(inter.begin(), inter.end(), [](auto &a, auto &b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int n=inter.size();
        int st=inter[0][0], en=inter[0][1],ans=1;
        for(int i=1;i<n;i++){
            int st1=inter[i][0], en1=inter[i][1];
            if(st<=st1 && en>=en1)continue;
            else{
                ans++;
                st=min(st,st1);
                en=max(en,en1);
            }
        }
        return ans;
    }
};