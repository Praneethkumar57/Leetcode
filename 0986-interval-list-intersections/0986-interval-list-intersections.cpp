class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n=firstList.size();
        int m = secondList.size();

        vector<vector<int>> res;
        int i=0,j=0;
        while(i<n && j<m){
            int val1 = max(firstList[i][0],secondList[j][0]);
            int val2 = min(firstList[i][1],secondList[j][1]);
            if(val2>=val1){
                res.push_back({val1,val2});
            }
            if(firstList[i][1]==val2){
                i=i+1;
            }
            if(secondList[j][1]==val2){
                j=j+1;
            }
            
        }
        return res;
    }
};