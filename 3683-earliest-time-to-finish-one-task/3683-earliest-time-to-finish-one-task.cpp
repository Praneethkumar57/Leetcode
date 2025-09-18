class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(tasks[i][0]+tasks[i][1]);
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,arr[i]);
        }
        return mini;
    }
};