class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = INT_MAX, high = INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }
        int index = -1;
        while(low<=high){
            int mid = (low + high)/2;
            int cnt =0;
            int bqt = 0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    cnt = cnt + 1;
                }
                else{
                    bqt = bqt + (cnt/k);
                    cnt = 0;
                }
            }
            bqt = bqt + (cnt/k);
            if(bqt>=m){
                index = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return(index);
    }
};